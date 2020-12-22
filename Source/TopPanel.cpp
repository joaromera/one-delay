/*
  ==============================================================================

    TopPanel.cpp
    Created: 21 Dec 2020 11:34:26pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "TopPanel.h"

TopPanel::TopPanel(OneDelayAudioProcessor* inProcessor)
    : PanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}

TopPanel::~TopPanel()
{
}

void TopPanel::paint(juce::Graphics& g)
{
    PanelBase::paint(g);
    g.drawFittedText("AUDIO PLUGIN", 0, 0, getWidth() - 10, getHeight(), juce::Justification::centredRight, 1);
}
