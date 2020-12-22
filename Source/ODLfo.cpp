/*
  ==============================================================================

    ODLfo.cpp
    Created: 19 Dec 2020 4:43:17pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "ODLfo.h"
#include "JuceHeader.h"

ODLfo::ODLfo()
{
    reset();
}

ODLfo::~ODLfo()
{
}

void ODLfo::reset()
{
    mPhase = 0.0f;
    juce::zeromem(mBuffer, sizeof(float) * maxBufferSize);
}

void ODLfo::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void ODLfo::process(float inRate, float inDepth, int inNumSamples)
{
    const float rate = juce::jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    
    for (int i = 0; i < inNumSamples; ++i)
    {
        mPhase += rate / mSampleRate;
        
        if (mPhase > 1.0f)
        {
            mPhase -= 1.0f;
        }
        
        const float lfoPosition = sinf(mPhase * TWO_PI) * inDepth;
        mBuffer[i] = lfoPosition;
    }
}

float* ODLfo::getBuffer()
{
    return mBuffer;
}
