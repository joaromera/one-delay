/*
  ==============================================================================

    ODLfo.h
    Created: 19 Dec 2020 4:43:17pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "ODAudioHelpers.h"

class ODLfo
{
public:

    ODLfo();
    ~ODLfo();
    
    void reset();
    void setSampleRate(double inSampleRate);
    void process(float inRate, float inDepth, int inNumSamples);
    float* getBuffer();

private:
    
    double mSampleRate;
    float mPhase;
    float mBuffer[maxBufferSize];
};
