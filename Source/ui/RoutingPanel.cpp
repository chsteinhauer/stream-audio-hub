#include "RoutingPanel.h"
#include "static/Theme.h"

RoutingPanel::RoutingPanel(RoutingModel& r) : header(r), matrix(r)
{
    addAndMakeVisible(header);
    addAndMakeVisible(matrix);
}

void RoutingPanel::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().toFloat();
    g.setColour (Theme::panel);
    g.fillRoundedRectangle (bounds, Theme::radius);
    g.setColour (Theme::panelBorder);
    g.drawRoundedRectangle (bounds.reduced (0.5f), Theme::radius, 1.0f);
}

void RoutingPanel::resized()
{
    auto area = getLocalBounds();
    header.setBounds (area.removeFromTop (68));
    matrix.setBounds (area);
}