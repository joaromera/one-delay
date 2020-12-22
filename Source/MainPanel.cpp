/*
  ==============================================================================

    MainPanel.cpp
    Created: 21 Dec 2020 11:33:55pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "MainPanel.h"

MainPanel::MainPanel(OneDelayAudioProcessor* inProcessor)
    : PanelBase(inProcessor)
    , mInputGainPanel(inProcessor, ODParameters::InputGain)
    , mOutputGainPanel(inProcessor, ODParameters::OutputGain)
    , mTopPanel(inProcessor)
    , mCentralPanel(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mInputGainPanel.setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mInputGainPanel);

    mOutputGainPanel.setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mOutputGainPanel);

    mTopPanel.setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel);
    
    mCentralPanel.setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mCentralPanel);
}

MainPanel::~MainPanel()
{
}
