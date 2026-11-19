// AppAudioCapture_Mac.mm
#include "AppAudioCapture.h"
#include "AppCaptureStream.h"
#include <CoreAudio/CoreAudio.h>
#include <AppKit/AppKit.h>   // for NSRunningApplication (names, icons)



namespace   // "anonymous namespace": these classes are private to this file
{
    static std::vector<AudioObjectID> getAudioProcessObjects()
    {
        AudioObjectPropertyAddress addr { kAudioHardwarePropertyProcessObjectList,
                                        kAudioObjectPropertyScopeGlobal,
                                        kAudioObjectPropertyElementMain };
        UInt32 size = 0;
        if (AudioObjectGetPropertyDataSize (kAudioObjectSystemObject, &addr, 0, nullptr, &size) != noErr)
            return {};

        std::vector<AudioObjectID> ids (size / sizeof (AudioObjectID));
        AudioObjectGetPropertyData (kAudioObjectSystemObject, &addr, 0, nullptr, &size, ids.data());
        return ids;
    }

    // Reads a fixed-size property (numbers, flags) from an audio object
    template <typename T>
    static bool getProperty (AudioObjectID obj, AudioObjectPropertySelector selector, T& result)
    {
        AudioObjectPropertyAddress addr { selector, kAudioObjectPropertyScopeGlobal,
                                        kAudioObjectPropertyElementMain };
        UInt32 size = sizeof (T);
        return AudioObjectGetPropertyData (obj, &addr, 0, nullptr, &size, &result) == noErr;
    }

    // Reads a string property (Core Audio returns CFStringRef, which we must release)
    static juce::String getStringProperty (AudioObjectID obj, AudioObjectPropertySelector selector)
    {
        CFStringRef cfString = nullptr;
        if (! getProperty (obj, selector, cfString) || cfString == nullptr)
            return {};

        auto result = juce::String::fromCFString (cfString);
        CFRelease (cfString);
        return result;
    }

    class MacAppCaptureStream : public AppCaptureStream
    {
    public:
        
        bool isCapturing() const override             { return capturing; }
        void stopCapture() override { return; }
        int  readSamples (juce::AudioBuffer<float>& dest, int start, int num) override
        {
            // later: pull from the FIFO the Core Audio tap writes into
            dest.clear (start, num);
            return 0;
        }
        juce::String getLastError() const override    { return {}; }

    private:
        bool capturing = false;
    };

    class MacAppAudioCapture : public AppAudioCapture
    {
    public:
        juce::Array<CapturableApp> getAvailableApps() override { 
            juce::Array<CapturableApp> apps;

            for (auto obj : getAudioProcessObjects())
            {
                UInt32 isPlaying = 0;
                getProperty (obj, kAudioProcessPropertyIsRunningOutput, isPlaying);
                if (!isPlaying)
                    continue;                                   // skip silent processes

                pid_t pid = 0;
                if (!getProperty (obj, kAudioProcessPropertyPID, pid) || pid == getpid())
                    continue;                                   // skip errors, and ourselves

                CapturableApp app;
                app.id = juce::String (pid);
                app.bundleOrExe = getStringProperty (obj, kAudioProcessPropertyBundleID);

                if (auto* running = [NSRunningApplication runningApplicationWithProcessIdentifier: pid])
                    app.name = juce::String::fromCFString ((__bridge CFStringRef) running.localizedName);

                if (app.name.isEmpty())
                    app.name = app.bundleOrExe;                 // helpers often have no display name

                apps.add (app);
            }

            return apps;
        }

        void requestPermission (std::function<void (bool granted)> onResult) override {
            return;
        }

        bool hasPermission() override { return false; }

        std::unique_ptr<AppCaptureStream> startCapture (const CapturableApp& app, double, int) override
        {
            return std::make_unique<MacAppCaptureStream>();
        }
    };
}

// The one function the outside world calls
std::unique_ptr<AppAudioCapture> AppAudioCapture::create()
{
    return std::make_unique<MacAppAudioCapture>();
}
