#include "RoutingPanelHeader.h"
#include "static/Theme.h"

RoutingPanelHeader::RoutingPanelHeader(RoutingModel& r)
{
    addSourceButton.onClick = [this] { };
    addAndMakeVisible(addSourceButton);
}

void RoutingPanelHeader::paint (juce::Graphics& g)
{
    g.setColour (Theme::panelBorder);
    g.drawHorizontalLine (getHeight() - 1, 0.0f, (float) getWidth());
}

void RoutingPanelHeader::resized()
{
    auto area = getLocalBounds().reduced (Theme::panelPadding, 0);

    auto buttonArea = area.removeFromRight (addSourceButton.getIdealWidth());
    addSourceButton.setBounds (buttonArea.withSizeKeepingCentre (buttonArea.getWidth(), 34));
}