/*
  ==============================================================================

    CentralPanelMenuBar.cpp
    Created: 21 Dec 2020 11:33:35pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "CentralPanelMenuBar.h"
#include "ODParameters.h"

CentralPanelMenuBar::CentralPanelMenuBar(OneDelayAudioProcessor* inProcessor)
    : PanelBase(inProcessor)
    , mFxTypeComboBox(mProcessor->parameters, ODParameters::DelayType)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);

    const int width = 85;
    mFxTypeComboBox.setBounds(getWidth() - width, 0, width, getHeight());
    mFxTypeComboBox.addItem("DELAY", 1);
    mFxTypeComboBox.addItem("CHORUS", 2);
    mFxTypeComboBox.setSelectedItemIndex(
        mProcessor->getParameter(static_cast<int>(ODParameters::DelayType)),
        juce::dontSendNotification
    );
    addAndMakeVisible(mFxTypeComboBox);
}

CentralPanelMenuBar::~CentralPanelMenuBar()
{
}

void CentralPanelMenuBar::addFxTypeComboBoxListener(juce::ComboBox::Listener* inListener)
{
    mFxTypeComboBox.addListener(inListener);
}

void CentralPanelMenuBar::removeFxTypeComboBoxListener(juce::ComboBox::Listener* inListener)
{
    mFxTypeComboBox.removeListener(inListener);
}
