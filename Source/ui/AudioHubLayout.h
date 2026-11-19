#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "RoutingPanel.h"
#include "model/RoutingModel.h"

class AudioHubLayout : public juce::Component
{
public:
    AudioHubLayout(RoutingModel& routing);

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    RoutingPanel panel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioHubLayout)
};