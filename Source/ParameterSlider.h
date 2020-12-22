/*
  ==============================================================================

    ParameterSlider.h
    Created: 22 Dec 2020 6:32:03pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "ODParameters.h"

class ParameterSlider : public juce::Slider
{
public:
    ParameterSlider(juce::AudioProcessorValueTreeState& stateToControl, ODParameters parameterType);
    ~ParameterSlider();

private:
    juce::AudioProcessorValueTreeState::SliderAttachment mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParameterSlider);
};
