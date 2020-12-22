/*
  ==============================================================================

    ODGain.h
    Created: 19 Dec 2020 4:43:04pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

class ODGain
{
public:
    ODGain();
    ~ODGain();
    
    void process(float* inAudio,
                 float inGain,
                 float* outAudio,
                 int inNumSamplesToRender);
private:
};
