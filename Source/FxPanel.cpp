/*
  ==============================================================================

    FxPanel.cpp
    Created: 21 Dec 2020 11:33:44pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "FxPanel.h"

FxPanel::FxPanel(OneDelayAudioProcessor* inProcessor)
    : PanelBase(inProcessor)
    , mStyle(FxPanelStyle::Delay)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
}

FxPanel::~FxPanel()
{
}

void FxPanel::paint(juce::Graphics& g)
{
    PanelBase::paint(g);
    
    switch (mStyle)
    {
        case FxPanelStyle::Delay:
        {
            g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight(), juce::Justification::centred, 1);
        }
        break;
            
        case FxPanelStyle::Chorus:
        {
            g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight(), juce::Justification::centred, 1);
        }
        break;
            
        case FxPanelStyle::TotalNumStyles:
        {
            jassertfalse;
        }
        break;
    }
}

void FxPanel::setFxPanelStyle(FxPanelStyle inStyle)
{
    mStyle = inStyle;
}
