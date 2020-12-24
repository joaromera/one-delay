/*
  ==============================================================================

    CentralPanel.cpp
    Created: 21 Dec 2020 11:33:22pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "CentralPanel.h"

CentralPanel::CentralPanel(OneDelayAudioProcessor* inProcessor)
    : PanelBase(inProcessor)
    , mMenuBar(inProcessor)
    , mFxPanel(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mMenuBar.setTopLeftPosition(0, 0);
    addAndMakeVisible(mMenuBar);
    
    mFxPanel.setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(mFxPanel);
    
    mMenuBar.addFxTypeComboBoxListener(&mFxPanel);
}

CentralPanel::~CentralPanel()
{
    mMenuBar.removeFxTypeComboBoxListener(&mFxPanel);
}
