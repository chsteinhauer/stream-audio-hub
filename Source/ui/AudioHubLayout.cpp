#include "AudioHubLayout.h"
#include "static/Theme.h"

AudioHubLayout::AudioHubLayout(RoutingModel& routing) : panel(routing)
{
    addAndMakeVisible (panel);
}

void AudioHubLayout::paint (juce::Graphics& g)
{
    g.fillAll (Theme::background);
}

void AudioHubLayout::resized()
{
    auto area = getLocalBounds().reduced (Theme::pagePadding);
    panel.setBounds (area);
}