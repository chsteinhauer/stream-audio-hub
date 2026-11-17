#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "RoutingMatrix.h"

class AudioHubLayout : public juce::Component
{
public:
    AudioHubLayout();

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    RoutingMatrix matrix;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioHubLayout)
};