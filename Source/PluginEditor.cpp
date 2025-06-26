#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);

    juce::MemoryInputStream imageStream(BinaryData::tap_logo_png, BinaryData::tap_logo_pngSize, false);
    tapLogo = juce::ImageFileFormat::loadFrom(imageStream);

    setSize (400, 400);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);

    if (tapLogo.isValid())
    {
        const auto bounds = getLocalBounds();
        const auto imageWidth = tapLogo.getWidth() / 12;
        const auto imageHeight = tapLogo.getHeight() / 12;

        // Calculate the position to center the scaled image
        const auto x = bounds.getCentreX() - imageWidth / 2;
        const auto y = bounds.getCentreY() - imageHeight / 2;

        // Draw the image, scaled
        g.drawImage(tapLogo,
                    x, y,
                    imageWidth, imageHeight,
                    0, 0,
                    tapLogo.getWidth(),
                    tapLogo.getHeight());
    }
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
