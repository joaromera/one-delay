/*
  ==============================================================================

    TopPanel.h
    Created: 21 Dec 2020 11:34:26pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "PluginProcessor.h"

class TopPanel : public PanelBase
{
public:
    TopPanel(OneDelayAudioProcessor* inProcessor);
    ~TopPanel();
    
    void paint(juce::Graphics& g);

protected:
};
