/*
  ==============================================================================

    ParameterComboBox.cpp
    Created: 22 Dec 2020 6:32:10pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "ParameterComboBox.h"

ParameterComboBox::ParameterComboBox(juce::AudioProcessorValueTreeState& stateToControl, const juce::String& parameterID)
    : juce::ComboBox(parameterID)
    , mAttachment(stateToControl, parameterID, *this)
{
}

ParameterComboBox::~ParameterComboBox()
{
}
