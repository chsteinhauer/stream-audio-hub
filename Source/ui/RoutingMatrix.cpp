#include "RoutingMatrix.h"
#include "static/Theme.h"

RoutingMatrix::RoutingMatrix() : header(TestData::outputs)
{
    addAndMakeVisible (header);

    for (auto& source : TestData::sources) 
    {
        auto row = new MatrixRow (source, TestData::outputs);
        rows.add(row);
        addAndMakeVisible(row);
    }
}

void RoutingMatrix::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().toFloat();
    g.setColour (Theme::panel);
    g.fillRoundedRectangle (bounds, Theme::radius);
    g.setColour (Theme::panelBorder);
    g.drawRoundedRectangle (bounds.reduced (0.5f), Theme::radius, 1.0f);
}

void RoutingMatrix::resized()
{
    auto area = getLocalBounds().reduced (Theme::panelPadding);
    header.setBounds (area.removeFromTop (30));

    for (auto* row : rows)
        row->setBounds (area.removeFromTop (MatrixInfo::rowHeight));
}