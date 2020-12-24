/*
  ==============================================================================

    ODDelay.h
    Created: 19 Dec 2020 4:43:10pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "ODAudioHelpers.h"

enum DelayType
{
    Delay = 0,
    Chorus
};

class ODDelay
{
public:

    ODDelay();
    ~ODDelay();

    void setSampleRate(double inSampleRate);
    void reset();
    void process(float* inAudio,
                 float inTime,
                 float inFeedback,
                 float inWetDry,
                 float inType,
                 float* inModulationBuffer,
                 float* outAudio,
                 int inNumSamplesToRender);

private:
    
    double getInterpolatedSample(float inDelayTimeInSamples);

    double mSampleRate;
    double mBuffer[maxBufferSize];
    double mFeedbackSample;
    
    float mTimeSmoothed;
    
    int mDelayIndex;
};
