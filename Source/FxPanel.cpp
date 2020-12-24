/*
  ==============================================================================

    FxPanel.cpp
    Created: 21 Dec 2020 11:33:44pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#include "FxPanel.h"
#include "ODParameters.h"
#include "ODFunctionHelpers.h"

FxPanel::FxPanel(OneDelayAudioProcessor* inProcessor)
    : PanelBase(inProcessor)
    , mStyle(FxPanelStyle::Chorus)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
    setFxPanelStyle(FxPanelStyle::Delay);
}

FxPanel::~FxPanel()
{
}

void FxPanel::comboBoxChanged(juce::ComboBox* comboBoxChanged)
{
    FxPanelStyle newStyle = static_cast<FxPanelStyle>(comboBoxChanged->getSelectedItemIndex());
    setFxPanelStyle(newStyle);
}

void FxPanel::paint(juce::Graphics& g)
{
    PanelBase::paint(g);
    
    switch (mStyle)
    {
        case FxPanelStyle::Delay:
        {
            g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight() * 0.75f, juce::Justification::centred, 1);
        }
        break;
            
        case FxPanelStyle::Chorus:
        {
            g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight() * 0.75f, juce::Justification::centred, 1);
        }
        break;
            
        case FxPanelStyle::_TotalNumStyles:
        {
            jassertfalse;
        }
        break;
    }

    for (int i = 0; i < mSliders.size(); ++i)
    {
        paintComponentLabel(g, mSliders[i]);
    }
}

void FxPanel::setFxPanelStyle(FxPanelStyle inStyle)
{
    mStyle = inStyle;
    
    mSliders.clear();
    
    const int sliders_size = 56;
    int x = 130;
    int y = 0.5f * (getHeight() - sliders_size);
    
    switch (mStyle)
    {
        case FxPanelStyle::Delay:
        {
            ParameterSlider* time = new ParameterSlider(mProcessor->parameters, ODParameters::DelayTime);
            time->setBounds(x, y, sliders_size, sliders_size);
            addAndMakeVisible(time);
            mSliders.add(time);
            x = x + (sliders_size * 2);
            
            ParameterSlider* feedback = new ParameterSlider(mProcessor->parameters, ODParameters::DelayFeedback);
            feedback->setBounds(x, y, sliders_size, sliders_size);
            addAndMakeVisible(feedback);
            mSliders.add(feedback);
            x = x + (sliders_size * 2);
            
            ParameterSlider* wetdry = new ParameterSlider(mProcessor->parameters, ODParameters::DelayWetDry);
            wetdry->setBounds(x, y, sliders_size, sliders_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);
        }
        break;
            
        case FxPanelStyle::Chorus:
        {
            ParameterSlider* rate = new ParameterSlider(mProcessor->parameters, ODParameters::ModulationRate);
            rate->setBounds(x, y, sliders_size, sliders_size);
            addAndMakeVisible(rate);
            mSliders.add(rate);
            x = x + (sliders_size * 2);
            
            ParameterSlider* depth = new ParameterSlider(mProcessor->parameters, ODParameters::ModulationDepth);
            depth->setBounds(x, y, sliders_size, sliders_size);
            addAndMakeVisible(depth);
            mSliders.add(depth);
            x = x + (sliders_size * 2);
            
            ParameterSlider* wetdry = new ParameterSlider(mProcessor->parameters, ODParameters::DelayWetDry);
            wetdry->setBounds(x, y, sliders_size, sliders_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);
        }
        break;
            
        case FxPanelStyle::_TotalNumStyles:
        {
            jassertfalse;
        }
        break;
    }
}
