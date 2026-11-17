// OutputHeaderCell.h
#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "static/Theme.h"

class OutputHeaderCell : public juce::Component
{
public:
    OutputHeaderCell (const juce::String& name, juce::Colour col)
        : text (name.toUpperCase()), colour (col) {}

    void paint (juce::Graphics& g) override
    {
        auto area = getLocalBounds();

        // the square: 8×8, vertically centred
        auto square = area.removeFromLeft (8).withSizeKeepingCentre (8, 8).toFloat();
        g.setColour (colour);
        g.fillRoundedRectangle (square, 2.0f);

        area.removeFromLeft (6);   // space between square and text

        g.setColour (Theme::textMuted);
        g.setFont (Theme::headerFont());
        g.drawText (text, area, juce::Justification::centredLeft);
    }

private:
    juce::String text;
    juce::Colour colour;
};
