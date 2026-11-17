#include "MatrixRow.h"
#include "static/Theme.h"

MatrixRow::MatrixRow(const SourceInfo& info, const std::vector<OutputInfo>& outputs)
{
    source.setText(info.name, juce::dontSendNotification);
    addAndMakeVisible (source);
    
    level.setSliderStyle (juce::Slider::LinearHorizontal);
    level.setTextBoxStyle (juce::Slider::TextBoxRight, false, 60, 20);  // false = editable by typing
    level.setRange (-60.0, 12.0, 0.1);                 // min dB, max dB, step
    level.setSkewFactorFromMidPoint (-12.0);           // more slider travel near 0 dB
    level.setDoubleClickReturnValue (true, 0.0);       // double-click resets to 0 dB
    level.setTextValueSuffix (" dB");
    level.setValue (info.gainDb, juce::dontSendNotification);

    level.setColour (juce::Slider::trackColourId,      Theme::accent);
    level.setColour (juce::Slider::backgroundColourId, Theme::controlBackground);
    level.setColour (juce::Slider::thumbColourId,      Theme::thumb);

    level.onValueChange = [this] { /* later: write level.getValue() to the model */ };
    addAndMakeVisible (level);

    meter.setText("Test", juce::dontSendNotification);
    addAndMakeVisible (meter);

    addAndMakeVisible(mute);

    for (auto& output : outputs) 
    {
        auto toggle = new OutputToggle (output.name, output.colour);
        outputToggles.add (toggle);
        addAndMakeVisible(toggle);
    }
}

void MatrixRow::paint (juce::Graphics& g)
{
    g.setColour (Theme::panelBorder);
    g.drawHorizontalLine (getHeight() - 1, 0.0f, (float) getWidth());
}

void MatrixRow::resized()
{
    auto area = getLocalBounds().removeFromTop (MatrixInfo::rowHeight);

    source.setBounds (area.removeFromLeft (MatrixInfo::source));
    level.setBounds (area.removeFromLeft (MatrixInfo::level));
    meter.setBounds (area.removeFromLeft (MatrixInfo::meter));

    for (auto* toggle : outputToggles)
        toggle->setBounds (area.removeFromLeft (MatrixInfo::toggle).reduced (8));

    mute.setBounds (area.removeFromLeft (MatrixInfo::mute).reduced (8));
}