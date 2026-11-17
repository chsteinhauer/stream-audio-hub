#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "../../static/MatrixInfo.h"
#include "../../static/TestData.h"
#include "OutputHeaderCell.h"

class MatrixHeader : public juce::Component
{
public:
    MatrixHeader(const std::vector<OutputInfo>& outputs);

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    juce::Label source;
    juce::Label level;
    juce::Label meter;
    juce::OwnedArray<OutputHeaderCell> outputs;
    juce::Label mute;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MatrixHeader)
};