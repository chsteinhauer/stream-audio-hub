#include "MatrixHeader.h"
#include "static/Theme.h"

MatrixHeader::MatrixHeader(const std::vector<OutputInfo>& _outputs)
{
    source.setText(MatrixInfo::sourceTitle, juce::dontSendNotification);
    
    addAndMakeVisible (source);
    level.setText(MatrixInfo::levelTitle, juce::dontSendNotification);
    addAndMakeVisible (level);
    meter.setText(MatrixInfo::meterTitle, juce::dontSendNotification);
    addAndMakeVisible (meter);
    mute.setText(MatrixInfo::muteTitle, juce::dontSendNotification);
    addAndMakeVisible (mute);

    for (auto& output : _outputs) 
    {
        auto cell = new OutputHeaderCell(output.name, output.colour);
        outputs.add(cell);
        addAndMakeVisible(cell);
    }

    // set font styles to the rest of the labels
    for (auto* label : { &source, &level, &meter, &mute })
    {
        label->setFont (Theme::headerFont());
        label->setColour (juce::Label::textColourId, Theme::textMuted);
        label->setJustificationType (juce::Justification::centredLeft);
    }
}

void MatrixHeader::paint (juce::Graphics& g)
{
    g.setFont (juce::FontOptions (11.0f, juce::Font::bold));
}

void MatrixHeader::resized()
{
    auto area = getLocalBounds().removeFromTop (MatrixInfo::rowHeight);

    source.setBounds (area.removeFromLeft (MatrixInfo::source));
    level.setBounds (area.removeFromLeft (MatrixInfo::level));
    meter.setBounds (area.removeFromLeft (MatrixInfo::meter));

    for (auto* output : outputs)
        output->setBounds (area.removeFromLeft (MatrixInfo::toggle).reduced (8));

    mute.setBounds (area.removeFromLeft (MatrixInfo::mute).reduced (8));
}