/*
  ==============================================================================

    CentralPanelMenuBar.h
    Created: 21 Dec 2020 11:33:35pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "ParameterComboBox.h"

class CentralPanelMenuBar : public PanelBase
{
public:
    CentralPanelMenuBar(OneDelayAudioProcessor* inProcessor);
    ~CentralPanelMenuBar();
    
    void addFxTypeComboBoxListener(juce::ComboBox::Listener* inListener);
    void removeFxTypeComboBoxListener(juce::ComboBox::Listener* inListener);
    
private:
    ParameterComboBox mFxTypeComboBox;
};
