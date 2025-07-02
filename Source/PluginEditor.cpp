#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), frequencySliderAttachment (processorRef.parameters, "frequency", frequencySlider)
{
    juce::ignoreUnused (processorRef);

    juce::MemoryInputStream imageStream(BinaryData::tap_logo_png, BinaryData::tap_logo_pngSize, false);
    tapLogo = juce::ImageFileFormat::loadFrom(imageStream);

    frequencySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    frequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 24);
    addAndMakeVisible (frequencySlider);

    frequencyLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible (frequencyLabel);

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
        const auto imageWidth = tapLogo.getWidth() / 36;
        const auto imageHeight = tapLogo.getHeight() / 36;

        const auto x = 10;
        const auto y = 10;

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
    frequencyLabel.setBounds (getWidth() / 2 - 50, getHeight() / 2 - 120, 100, 20);
    frequencySlider.setBounds (getWidth() / 2 - 100, getHeight() / 2 - 100, 200, 200);
}
