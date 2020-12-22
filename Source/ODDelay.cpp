/*
  ==============================================================================

    ODDelay.cpp
    Created: 19 Dec 2020 4:43:10pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "ODDelay.h"

#include "JuceHeader.h"

ODDelay::ODDelay()
    : mSampleRate(-1)
    , mFeedbackSample(0.0)
    , mTimeSmoothed(0)
    , mDelayIndex(0)
{
}

ODDelay::~ODDelay()
{
}

void ODDelay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void ODDelay::reset()
{
    mTimeSmoothed = 0;
    juce::zeromem(mBuffer, sizeof(double) * maxBufferSize);
}

double ODDelay::getInterpolatedSample(float inDelayTimeInSamples)
{
    double readPosition = static_cast<double>(mDelayIndex) - inDelayTimeInSamples;

    if (readPosition < 0.0f)
    {
        readPosition += maxBufferSize;
    }

    int index_y0 = static_cast<int>(readPosition) - 1;

    if (index_y0 <= 0.0f)
    {
        index_y0 += maxBufferSize;
    }

    int index_y1 = static_cast<int>(readPosition);

    if (index_y1 > maxBufferSize)
    {
        index_y1 -= maxBufferSize;
    }

    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    const float t = readPosition - static_cast<int>(readPosition);

    const double outSample = linear_interp(sample_y0, sample_y1, t);
    return outSample;
}

void ODDelay::process(float *inAudio,
                      float inTime,
                      float inFeedback,
                      float inWetDry,
                      float* inModulationBuffer,
                      float *outAudio,
                      int inNumSamplesToRender)
{
    const float wet = inWetDry;
    const float dry = 1.0f - wet;
    const float feedbackMapped = juce::jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f);
    
    for (int i = 0; i < inNumSamplesToRender; ++i)
    {
        const double delayTimeModulation = (inTime + (0.002f * inModulationBuffer[i]));
        mTimeSmoothed -= parameterSmoothingCoeffGeneric * (mTimeSmoothed - delayTimeModulation);
        const double delayTimeInSamples = mTimeSmoothed * delayTimeModulation * mSampleRate;
        const double sample = getInterpolatedSample(delayTimeInSamples);
        mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);
        mFeedbackSample = sample;
        outAudio[i] = inAudio[i] * dry + sample * wet;
        ++mDelayIndex;
        
        if (mDelayIndex >= maxBufferSize)
        {
            mDelayIndex -= maxBufferSize;
        }
    }
}
