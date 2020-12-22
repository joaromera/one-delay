/*
  ==============================================================================

    FxPanel.h
    Created: 21 Dec 2020 11:33:44pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

enum class FxPanelStyle
{
    Delay,
    Chorus,
    TotalNumStyles
};

class FxPanel : public PanelBase
{
public:
    FxPanel(OneDelayAudioProcessor* inProcessor);
    ~FxPanel();
    
    void paint(juce::Graphics& g) override;
    void setFxPanelStyle(FxPanelStyle inStyle);

private:
    FxPanelStyle mStyle;
};
