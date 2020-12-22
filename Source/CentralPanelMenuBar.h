/*
  ==============================================================================

    CentralPanelMenuBar.h
    Created: 21 Dec 2020 11:33:35pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "PanelBase.h"

class CentralPanelMenuBar : public PanelBase
{
public:
    CentralPanelMenuBar(OneDelayAudioProcessor* inProcessor);
    ~CentralPanelMenuBar();
};
