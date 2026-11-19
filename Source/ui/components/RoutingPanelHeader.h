#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "model/RoutingModel.h"
#include "DashedButton.h"

class RoutingPanelHeader : public juce::Component
{
public:
    RoutingPanelHeader(RoutingModel& r);

    void paint (juce::Graphics& g) override;
    void resized() override;

private:

    DashedButton addSourceButton { "+ Add source" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoutingPanelHeader)
};