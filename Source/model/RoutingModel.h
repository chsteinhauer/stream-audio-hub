#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include "IDs.h"

class RoutingModel
{
public:
    RoutingModel();

    juce::ValueTree getState()   { return state; }  
    juce::ValueTree getSources() { return state.getChildWithName (IDs::Sources); }
    juce::ValueTree getOutputs() { return state.getChildWithName (IDs::Outputs); }

    static juce::Colour getColour (const juce::ValueTree& output);


private:
    juce::ValueTree state { IDs::Routing };
};