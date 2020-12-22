/*
  ==============================================================================

    ParameterSlider.cpp
    Created: 22 Dec 2020 6:32:03pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "ParameterSlider.h"

ParameterSlider::ParameterSlider(juce::AudioProcessorValueTreeState& stateToControl, ODParameters parameterType)
    : juce::Slider(ODParameterID[static_cast<int>(parameterType)])
    , mAttachment(stateToControl, getName(), *this)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    setRange(0.0f, 1.0f, 0.001f);
}

ParameterSlider::~ParameterSlider()
{
    
}
