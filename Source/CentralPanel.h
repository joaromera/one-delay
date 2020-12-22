/*
  ==============================================================================

    CentralPanel.h
    Created: 21 Dec 2020 11:33:22pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "CentralPanelMenuBar.h"
#include "FxPanel.h"

class CentralPanel : public PanelBase
{
public:

    CentralPanel(OneDelayAudioProcessor* inProcessor);
    ~CentralPanel();
    
private:
    
    CentralPanelMenuBar mMenuBar;
    FxPanel mFxPanel;
};
