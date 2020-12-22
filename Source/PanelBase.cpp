/*
  ==============================================================================

    PanelBase.cpp
    Created: 21 Dec 2020 11:34:01pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "PanelBase.h"

PanelBase::PanelBase(OneDelayAudioProcessor* inProcessor)
    : mProcessor(inProcessor)
{
}

PanelBase::~PanelBase()
{
}

void PanelBase::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::whitesmoke);
    g.fillAll();

    g.setColour(juce::Colours::black);
    g.drawRect(0, 0, getWidth() - 1, getHeight() - 1, 2);
}
