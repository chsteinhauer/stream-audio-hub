#include "RoutingMatrix.h"
#include "static/Theme.h"

RoutingMatrix::RoutingMatrix(RoutingModel& r) : routing(r), header(r.getOutputs())
{
    addAndMakeVisible (header);

    for (auto source : routing.getSources()) 
    {
        auto row = new MatrixRow (source, routing.getOutputs());
        rows.add(row);
        addAndMakeVisible(row);
    }
}

void RoutingMatrix::paint (juce::Graphics& g)
{
    
}

void RoutingMatrix::resized()
{
    auto area = getLocalBounds().reduced (Theme::panelPadding);
    header.setBounds (area.removeFromTop (30));

    for (auto* row : rows)
        row->setBounds (area.removeFromTop (MatrixInfo::rowHeight));
}