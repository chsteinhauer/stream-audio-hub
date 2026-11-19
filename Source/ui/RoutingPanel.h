#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "model/RoutingModel.h"
#include "RoutingMatrix.h"
#include "components/RoutingPanelHeader.h"

class RoutingPanel : public juce::Component
{
public:
    RoutingPanel(RoutingModel& r);

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    RoutingPanelHeader header;
    RoutingMatrix matrix;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoutingPanel)
};