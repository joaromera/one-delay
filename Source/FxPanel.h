/*
  ==============================================================================

    FxPanel.h
    Created: 21 Dec 2020 11:33:44pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "ParameterSlider.h"
#include "JuceHeader.h"

enum class FxPanelStyle
{
    Delay,
    Chorus,
    _TotalNumStyles
};

class FxPanel : public PanelBase, public juce::ComboBox::Listener
{
public:
    FxPanel(OneDelayAudioProcessor* inProcessor);
    ~FxPanel();
    
    void comboBoxChanged(juce::ComboBox* comboBoxChanged) override;
    void paint(juce::Graphics& g) override;
    void setFxPanelStyle(FxPanelStyle inStyle);

private:
    FxPanelStyle mStyle;
    juce::OwnedArray<ParameterSlider> mSliders;
};
