/*
  ==============================================================================

    ODGain.cpp
    Created: 19 Dec 2020 4:43:04pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "ODGain.h"
#include "JuceHeader.h"

ODGain::ODGain()
{
}

ODGain::~ODGain()
{
}

void ODGain::process(float *inAudio,
                     float inGain,
                     float *outAudio,
                     int inNumSamplesToRender)
{
    float gainMapped = juce::jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = juce::Decibels::decibelsToGain(gainMapped, -24.0f);
    
    for (int i = 0; i < inNumSamplesToRender; ++i)
    {
        outAudio[i] = inAudio[i] * gainMapped;
    }
}
