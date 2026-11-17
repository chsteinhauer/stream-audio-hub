#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "../../static/MatrixInfo.h"
#include "OutputToggle.h"
#include "../../static/TestData.h"

class MatrixRow : public juce::Component
{
public:
    MatrixRow(const SourceInfo& info, const std::vector<OutputInfo>& outputs);

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    juce::Label  source;
    juce::Slider level;
    juce::Label  meter;
    juce::OwnedArray<OutputToggle> outputToggles;
    juce::ToggleButton mute;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MatrixRow)
};