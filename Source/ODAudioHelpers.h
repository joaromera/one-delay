/*
  ==============================================================================

    ODAudioHelpers.h
    Created: 19 Dec 2020 4:42:41pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

constexpr static double parameterSmoothingCoeffGeneric = 0.04;
constexpr static double parameterSmoothingCoeffFine = 0.002;
constexpr static double PI = 3.14159265359;
constexpr static double TWO_PI = 6.28318530718;
constexpr static int maxBufferSize = 192000;

inline float linear_interp(float v0, float v1, float t)
{
    return ((1 - t) * v0) + (t * v1);
}
