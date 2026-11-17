#include "MatrixRow.h"
#include "static/Theme.h"

MatrixRow::MatrixRow(juce::ValueTree src, juce::ValueTree outputs) : source (src)
{
    name.setText(source[IDs::name].toString(), juce::dontSendNotification);
    addAndMakeVisible (name);
    
    level.setSliderStyle (juce::Slider::LinearHorizontal);
    level.setTextBoxStyle (juce::Slider::TextBoxRight, false, 60, 20);  // false = editable by typing
    level.setRange (-60.0, 12.0, 0.1);                 // min dB, max dB, step
    level.setSkewFactorFromMidPoint (-12.0);           // more slider travel near 0 dB
    level.setDoubleClickReturnValue (true, 0.0);       // double-click resets to 0 dB
    level.setTextValueSuffix (" dB");
    level.setValue (source[IDs::gainDb], juce::dontSendNotification);

    level.setColour (juce::Slider::trackColourId,      Theme::accent);
    level.setColour (juce::Slider::backgroundColourId, Theme::controlBackground);
    level.setColour (juce::Slider::thumbColourId,      Theme::thumb);

    level.onValueChange = [this] { source.setProperty (IDs::gainDb, level.getValue(), nullptr); };

    addAndMakeVisible (level);

    meter.setText("Test", juce::dontSendNotification);
    addAndMakeVisible (meter);

    mute.onClick = [this] { source.setProperty (IDs::muted, mute.getToggleState(), nullptr); };
    addAndMakeVisible(mute);

    for (auto output : outputs)
    {
        auto id     = output[IDs::id].toString();
        auto colour = juce::Colour::fromString (output[IDs::colour].toString());

        auto* toggle = outputToggles.add (new OutputToggle (output[IDs::name].toString(), colour));
        toggle->setToggleState (source.getChildWithProperty (IDs::outputId, id).isValid(),
                                juce::dontSendNotification);
        
        toggle->onClick = [this, id, toggle]
        {
            if (toggle->getToggleState())
                source.appendChild (juce::ValueTree { IDs::Send, { { IDs::outputId, id } } }, nullptr);
            else
                source.removeChild (source.getChildWithProperty (IDs::outputId, id), nullptr);
        };
        
        addAndMakeVisible (toggle);
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

    name.setBounds (area.removeFromLeft (MatrixInfo::source));
    level.setBounds (area.removeFromLeft (MatrixInfo::level));
    meter.setBounds (area.removeFromLeft (MatrixInfo::meter));

    for (auto* toggle : outputToggles)
        toggle->setBounds (area.removeFromLeft (MatrixInfo::toggle).reduced (8));

    mute.setBounds (area.removeFromLeft (MatrixInfo::mute).reduced (8));
}