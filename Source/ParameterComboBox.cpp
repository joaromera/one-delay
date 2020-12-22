/*
  ==============================================================================

    ParameterComboBox.cpp
    Created: 22 Dec 2020 6:32:10pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "ParameterComboBox.h"

ParameterComboBox::ParameterComboBox(juce::AudioProcessorValueTreeState& stateToControl, ODParameters parameterType)
    : juce::ComboBox(ODParameterID[static_cast<int>(parameterType)])
    , mAttachment(stateToControl, getName(), *this)
{
}

ParameterComboBox::~ParameterComboBox()
{
}
