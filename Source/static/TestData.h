#pragma once
#include <juce_graphics/juce_graphics.h>

struct OutputInfo
{
    juce::String name;
    juce::Colour colour;
};

struct SourceInfo
{
    juce::String name;
    juce::String subtitle;
    float gainDb = 0.0f;
    bool muted = false;
    juce::StringArray routedTo;   // output names this source is sent to
};

namespace TestData
{
    inline const std::vector<OutputInfo> outputs
    {
        { "Stream", juce::Colour (0xff4a9eff) },
        { "VOD",    juce::Colour (0xffff9f43) },
        { "Phones", juce::Colour (0xffd9dde3) },
    };

    inline const std::vector<SourceInfo> sources
    {
        { "Mic",   "USB mic · mono", 0.4f,  false, { "Stream", "VOD" } },
        { "Music", "Spotify",        -6.8f, false, { "Stream", "Phones" } },
        { "Game",  "Game audio",     -2.0f, false, { "Stream", "VOD", "Phones" } },
    };
}



