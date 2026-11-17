cmake_minimum_required(VERSION 3.22)

# Universal binary: native on Apple Silicon, still runs on Intel Macs
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "")
set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0" CACHE STRING "")

project(AudioHub VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(JUCE)

juce_add_plugin(AudioHub
    COMPANY_NAME "Auda"
    PLUGIN_MANUFACTURER_CODE Aurc     # 4 chars, at least one uppercase
    PLUGIN_CODE Ahub                  # 4 chars, unique per plugin
    FORMATS AU VST3 Standalone
    PRODUCT_NAME "Audio Hub"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE)     # copies into ~/Library/Audio/Plug-Ins

target_sources(AudioHub PRIVATE
    Source/AudioHubProcessor.cpp
    Source/AudioHubEditor.cpp
    Source/ui/AudioHubLayout.cpp
    Source/ui/RoutingMatrix.cpp
    Source/ui/components/MatrixHeader.cpp
    Source/ui/components/MatrixRow.cpp
    Source/ui/components/OutputToggle.cpp)

target_include_directories(AudioHub PRIVATE Source)

target_compile_definitions(AudioHub PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(AudioHub
    PRIVATE juce::juce_audio_utils
    PUBLIC  juce::juce_recommended_config_flags
            juce::juce_recommended_lto_flags
            juce::juce_recommended_warning_flags)