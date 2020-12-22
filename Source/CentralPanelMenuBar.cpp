/*
  ==============================================================================

    CentralPanelMenuBar.cpp
    Created: 21 Dec 2020 11:33:35pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "CentralPanelMenuBar.h"

CentralPanelMenuBar::CentralPanelMenuBar(OneDelayAudioProcessor* inProcessor)
    : PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
}

CentralPanelMenuBar::~CentralPanelMenuBar()
{
}
