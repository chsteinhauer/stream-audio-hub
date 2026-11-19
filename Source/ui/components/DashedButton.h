// Source/ui/components/DashedButton.h
#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "static/Theme.h"

class DashedButton : public juce::Button
{
public:
    explicit DashedButton (const juce::String& text) : juce::Button (text) {}

    // lets the parent size the button to fit its text
    int getIdealWidth() const
    {
        return juce::GlyphArrangement::getStringWidthInt (juce::Font (font), getButtonText()) + 2 * paddingX;
    }

    void paintButton (juce::Graphics& g, bool isHighlighted, bool isDown) override
    {
        auto bounds = getLocalBounds().toFloat().reduced (0.5f);

        // faint fill on hover/press
        if (isHighlighted || isDown)
        {
            g.setColour (Theme::controlBackground.withAlpha (isDown ? 0.8f : 0.5f));
            g.fillRoundedRectangle (bounds, 8.0f);
        }

        // dashed border
        juce::Path outline, dashed;
        outline.addRoundedRectangle (bounds, 8.0f);
        const float dashes[] = { 4.0f, 3.0f };
        juce::PathStrokeType (1.0f).createDashedStroke (dashed, outline, dashes, 2);
        g.setColour (Theme::textMuted.withAlpha (isHighlighted ? 0.8f : 0.5f));
        g.fillPath (dashed);

        // text
        g.setColour (Theme::textPrimary);
        g.setFont (font);
        g.drawText (getButtonText(), getLocalBounds(), juce::Justification::centred);
    }

private:
    static constexpr int paddingX = 14;
    juce::FontOptions font { 13.0f, juce::Font::bold };
};
