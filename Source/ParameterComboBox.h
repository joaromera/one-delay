/*
  ==============================================================================

    ParameterComboBox.h
    Created: 22 Dec 2020 6:32:10pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "ODParameters.h"

class ParameterComboBox : public juce::ComboBox
{
public:
    ParameterComboBox(juce::AudioProcessorValueTreeState& stateToControl, ODParameters parameterType);
    ~ParameterComboBox();

private:
    juce::AudioProcessorValueTreeState::ComboBoxAttachment mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParameterComboBox);
};
