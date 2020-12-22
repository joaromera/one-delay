/*
  ==============================================================================

    PanelBase.h
    Created: 21 Dec 2020 11:34:01pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "ODInterfaceDefines.h"

class PanelBase : public juce::Component
{
public:
    
    PanelBase(OneDelayAudioProcessor* inProcessor);
    ~PanelBase();

    void paint(juce::Graphics& g) override;

protected:
    
    OneDelayAudioProcessor* mProcessor;

};
