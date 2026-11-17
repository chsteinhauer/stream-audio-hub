#pragma once
#include <juce_graphics/juce_graphics.h>

namespace Theme
{
    // backgrounds
    inline const juce::Colour background   { 0xff0e1014 };
    inline const juce::Colour panel        { 0xff171a20 };
    inline const juce::Colour panelBorder  { 0xff262a32 };

    // text
    inline const juce::Colour textPrimary  { 0xffe8eaed };
    inline const juce::Colour textMuted    { 0xff8a919c };

    // controls
    inline const juce::Colour controlBackground { 0xff2a2e35 };
    inline const juce::Colour thumb             { 0xffffffff };
    inline const juce::Colour onAccent          { 0xff000000 };   // ticks/icons drawn on top of accent colours

    // accents
    inline const juce::Colour accent       { 0xff4a9eff };
    inline const juce::Colour meterGreen   { 0xff3ddc84 };
    inline const juce::Colour live         { 0xffff5a5a };

    inline constexpr int pagePadding  = 24;
    inline constexpr int panelPadding = 20;
    inline constexpr int gap          = 16;
    inline constexpr float radius     = 12.0f;

    inline juce::FontOptions headerFont()
    {
        return juce::FontOptions (11.0f, juce::Font::bold);
    }
}