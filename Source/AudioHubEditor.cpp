#include "AudioHubProcessor.h"
#include "AudioHubEditor.h"
#include "static/Theme.h"

//==============================================================================
AudioHubProcessorEditor::AudioHubProcessorEditor (AudioHubProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1000, 600);

    addAndMakeVisible(layout);
}

AudioHubProcessorEditor::~AudioHubProcessorEditor()
{
}

//==============================================================================
void AudioHubProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Theme::background);

}

void AudioHubProcessorEditor::resized()
{
    layout.setBounds (getLocalBounds());    
}
