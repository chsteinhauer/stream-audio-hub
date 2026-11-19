#pragma once
#include <juce_audio_basics/juce_audio_basics.h>
#include "AppCaptureStream.h"

// One app that can be captured
struct CapturableApp
{
    juce::String id;          // stable key: PID on Windows/macOS, node id on PipeWire
    juce::String name;        // "Spotify"
    juce::String bundleOrExe; // "com.spotify.client" / "Spotify.exe", useful for remembering choices
};

class AppAudioCapture
{
public:
    virtual ~AppAudioCapture() = default;

    //==================================================================
    // Discovery
    virtual juce::Array<CapturableApp> getAvailableApps() = 0;

    // Permissions (macOS asks the user; other platforms can just return true)
    virtual bool hasPermission() = 0;
    virtual void requestPermission (std::function<void (bool granted)> onResult) = 0;

    //==================================================================
    // Capture
    virtual std::unique_ptr<AppCaptureStream> startCapture (const CapturableApp& app, double sampleRate, int numChannels) = 0;
    
    //==================================================================
    // Creates the right implementation for the current OS (defined per platform)
    static std::unique_ptr<AppAudioCapture> create();
};
