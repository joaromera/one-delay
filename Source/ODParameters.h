/*
  ==============================================================================

    ODParameters.h
    Created: 22 Dec 2020 4:48:32pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

#include <string>

enum class ODParameters
{
    InputGain = 0,
    DelayTime,
    DelayFeedback,
    DelayWetDry,
    DelayType,
    OutputGain,
    ModulationRate,
    ModulationDepth,
    _TotalNumParameters
};

static std::string ODParameterID[static_cast<int>(ODParameters::_TotalNumParameters)] = {
    "Input Gain",
    "Time",
    "Feedback",
    "Wet Dry",
    "Type",
    "Output Gain",
    "Modulation Rate",
    "Modulation Depth"
};
