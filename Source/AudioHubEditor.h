#pragma once

#include "AudioHubProcessor.h"
#include "ui/AudioHubLayout.h"

//==============================================================================
class AudioHubProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioHubProcessorEditor (AudioHubProcessor&);
    ~AudioHubProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioHubProcessor& processorRef;

    AudioHubLayout layout;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioHubProcessorEditor)
};
