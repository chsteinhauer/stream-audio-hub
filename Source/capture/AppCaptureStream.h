#pragma once
#include <juce_audio_basics/juce_audio_basics.h>


class AppCaptureStream
{
public:
    virtual ~AppCaptureStream() = default;
    virtual bool isCapturing() const = 0;
    virtual void stopCapture() = 0;
    virtual int  readSamples (juce::AudioBuffer<float>& dest, int startSample, int numSamples) = 0;
    virtual juce::String getLastError() const = 0;
};