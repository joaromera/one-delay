/*
  ==============================================================================

    GainPanel.cpp
    Created: 21 Dec 2020 11:33:50pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "GainPanel.h"
#include "ODParameters.h"

GainPanel::GainPanel(OneDelayAudioProcessor* inProcessor, ODParameters inParameterID)
    : PanelBase(inProcessor)
    , mSlider(mProcessor->parameters, inParameterID)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}

GainPanel::~GainPanel()
{
}
