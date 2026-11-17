#include "OutputToggle.h"
#include "static/Theme.h"

OutputToggle::OutputToggle (const juce::String& name, juce::Colour c)
    : juce::ToggleButton (name), colour (c)
{
}

void OutputToggle::paintButton (juce::Graphics& g, bool isHighlighted, bool isDown)
{
    auto bounds = getLocalBounds().toFloat().reduced (2.0f);
    const float corner = 6.0f;

    if (getToggleState())   // ON: filled box + tick
    {
        g.setColour (isDown ? colour.darker (0.2f) : colour);
        g.fillRoundedRectangle (bounds, corner);

        juce::Path tick;
        auto c = bounds.getCentre();
        tick.startNewSubPath (c.x - 6, c.y);
        tick.lineTo (c.x - 2, c.y + 4);
        tick.lineTo (c.x + 6, c.y - 4);
        g.setColour (Theme::onAccent.withAlpha (0.8f));
        g.strokePath (tick, juce::PathStrokeType (2.0f, juce::PathStrokeType::curved,
                                                        juce::PathStrokeType::rounded));
    }
    else                    // OFF: dashed outline
    {
        juce::Path outline;
        outline.addRoundedRectangle (bounds, corner);

        juce::Path dashed;
        const float dashes[] = { 4.0f, 3.0f };
        juce::PathStrokeType (1.0f).createDashedStroke (dashed, outline, dashes, 2);

        g.setColour (Theme::textPrimary.withAlpha (isHighlighted ? 0.5f : 0.25f));
        g.fillPath (dashed);
    }
}