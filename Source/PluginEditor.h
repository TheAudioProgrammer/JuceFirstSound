#pragma once

#include "PluginProcessor.h"
#include "BinaryData.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Image tapLogo;
    juce::Slider frequencySlider;
    juce::Label frequencyLabel { "Freq Label", "Frequency" };

    juce::TextButton playButton;
    AudioPluginAudioProcessor& processorRef;
    juce::AudioProcessorValueTreeState::SliderAttachment frequencySliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
