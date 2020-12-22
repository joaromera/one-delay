/*
  ==============================================================================

    MainPanel.h
    Created: 21 Dec 2020 11:33:55pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"
#include "PluginProcessor.h"
#include "TopPanel.h"
#include "GainPanel.h"
#include "CentralPanel.h"

class MainPanel : public PanelBase
{
public:
    MainPanel(OneDelayAudioProcessor* inProcessor);
    ~MainPanel();
    
protected:
    
    GainPanel mInputGainPanel;
    GainPanel mOutputGainPanel;
    TopPanel mTopPanel;
    CentralPanel mCentralPanel;
};
