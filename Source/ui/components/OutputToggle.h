#pragma once
#include <juce_gui_basics/juce_gui_basics.h>

class OutputToggle : public juce::ToggleButton
{
public:
    OutputToggle (const juce::String& name, juce::Colour colour);

    void paintButton (juce::Graphics& g, bool isHighlighted, bool isDown) override;

private:
    juce::Colour colour;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutputToggle)
};