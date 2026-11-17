#include "AudioHubLayout.h"
#include "static/Theme.h"

AudioHubLayout::AudioHubLayout(RoutingModel& routing) : matrix(routing)
{
    addAndMakeVisible (matrix);
}

void AudioHubLayout::paint (juce::Graphics& g)
{
    g.fillAll (Theme::background);
}

void AudioHubLayout::resized()
{
    auto area = getLocalBounds().reduced (Theme::pagePadding);
    matrix.setBounds (area);
}