#include "RoutingModel.h"
#include "static/TestData.h"

RoutingModel::RoutingModel()
{
    // 1. skeleton: the two container nodes
    state.appendChild (juce::ValueTree { IDs::Outputs }, nullptr);
    state.appendChild (juce::ValueTree { IDs::Sources }, nullptr);

    // 2. default content, from TestData for now
    for (auto& output : TestData::outputs)
    {
        getOutputs().appendChild (juce::ValueTree { IDs::Output, {
            { IDs::id,     output.name.toLowerCase() },
            { IDs::name,   output.name },
            { IDs::colour, output.colour.toString() },
        } }, nullptr);
    }

    for (auto& source : TestData::sources)
    {
        juce::ValueTree node { IDs::Source, {
            { IDs::id,       source.name.toLowerCase() },
            { IDs::name,     source.name },
            { IDs::subtitle, source.subtitle },
            { IDs::gainDb,   source.gainDb },
            { IDs::muted,    source.muted },
        } };

        for (auto& outputName : source.routedTo)
            node.appendChild (juce::ValueTree { IDs::Send, { { IDs::outputId, outputName.toLowerCase() } } }, nullptr);

        getSources().appendChild (node, nullptr);
    }
}


juce::Colour RoutingModel::getColour (const juce::ValueTree& output)
{
    return juce::Colour::fromString (output[IDs::colour].toString());
}

