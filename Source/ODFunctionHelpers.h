/*
  ==============================================================================

    ODFunctionHelpers.h
    Created: 24 Dec 2020 12:36:53am
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

inline void paintComponentLabel(juce::Graphics& g, juce::Component* inComponent)
{
    const int x = inComponent->getX();
    const int y = inComponent->getY() + inComponent->getHeight();
    const int w = inComponent->getWidth();
    const int h = 20;
    
    const juce::String label = inComponent->getName();
    
    g.setColour(juce::Colours::darkgrey);
    g.drawFittedText(label, x, y, w, h, juce::Justification::centred, 1);
}
