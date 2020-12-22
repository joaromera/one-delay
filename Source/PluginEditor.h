/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <memory>
#include <JuceHeader.h>
#include "PluginProcessor.h"

#include "MainPanel.h"

//==============================================================================
/**
*/
class OneDelayAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    OneDelayAudioProcessorEditor (OneDelayAudioProcessor&);
    ~OneDelayAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    OneDelayAudioProcessor& audioProcessor;
    MainPanel mMainPanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OneDelayAudioProcessorEditor)
};
