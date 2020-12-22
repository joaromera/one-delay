/*
  ==============================================================================

    ODInterfaceDefines.h
    Created: 21 Dec 2020 11:41:01pm
    Author:  Joaquin Romera

  ==============================================================================
*/

#pragma once

constexpr int MAIN_PANEL_WIDTH = 750;
constexpr int MAIN_PANEL_HEIGHT = 300;

constexpr int TOP_PANEL_WIDTH = MAIN_PANEL_WIDTH;
constexpr int TOP_PANEL_HEIGHT = 45;

constexpr int GAIN_PANEL_WIDTH = 100;
constexpr int GAIN_PANEL_HEIGHT = MAIN_PANEL_HEIGHT - TOP_PANEL_HEIGHT;

constexpr int CENTER_PANEL_WIDTH = MAIN_PANEL_WIDTH - (GAIN_PANEL_WIDTH * 2);
constexpr int CENTER_PANEL_HEIGHT = GAIN_PANEL_HEIGHT;

constexpr int CENTER_PANEL_MENU_BAR_WIDTH = CENTER_PANEL_WIDTH;
constexpr int CENTER_PANEL_MENU_BAR_HEIGHT = 35;

constexpr int FX_PANEL_WIDTH = CENTER_PANEL_WIDTH;
constexpr int FX_PANEL_HEIGHT = CENTER_PANEL_HEIGHT - CENTER_PANEL_MENU_BAR_HEIGHT;
