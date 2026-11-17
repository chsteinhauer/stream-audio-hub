#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "../../static/MatrixInfo.h"
#include "OutputToggle.h"
#include "model/IDs.h"
class MatrixRow : public juce::Component
{
public:
    MatrixRow(juce::ValueTree source, juce::ValueTree outputs);

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    juce::ValueTree  source;

    juce::Label  name;
    juce::Slider level;
    juce::Label  meter;
    juce::OwnedArray<OutputToggle> outputToggles;
    juce::ToggleButton mute;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MatrixRow)
};