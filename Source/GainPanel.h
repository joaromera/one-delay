/*
  ==============================================================================

    GainPanel.h
    Created: 21 Dec 2020 11:33:50pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "ParameterSlider.h"
#include "JuceHeader.h"

class GainPanel : public PanelBase
{
public:
    GainPanel(OneDelayAudioProcessor* inProcessor, ODParameters inParameterID);
    ~GainPanel();
    
    void paint(juce::Graphics& g) override;
    
private:
    ParameterSlider mSlider;
};
