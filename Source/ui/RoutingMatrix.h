#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "components/MatrixHeader.h"
#include "components/MatrixRow.h"

class RoutingMatrix : public juce::Component
{
public:
    RoutingMatrix();

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    MatrixHeader header;
    juce::OwnedArray<MatrixRow> rows;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoutingMatrix)
};