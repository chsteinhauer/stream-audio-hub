#pragma once
#include <juce_core/juce_core.h>

namespace IDs
{
    #define DECLARE_ID(name) inline const juce::Identifier name { #name };

    // node types (the "tags")
    DECLARE_ID (Routing)    // root
    DECLARE_ID (Outputs)
    DECLARE_ID (Output)
    DECLARE_ID (Sources)
    DECLARE_ID (Source)
    DECLARE_ID (Send)       // one "source → output" connection

    // properties (the "attributes")
    DECLARE_ID (id)
    DECLARE_ID (name)
    DECLARE_ID (subtitle)
    DECLARE_ID (colour)
    DECLARE_ID (gainDb)
    DECLARE_ID (muted)
    DECLARE_ID (outputId)   // on a Send: which output it goes to

    #undef DECLARE_ID
}