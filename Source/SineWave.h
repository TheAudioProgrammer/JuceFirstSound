//
// Created by Joshua Hodge on 6/24/25.
//

#ifndef SINEWAVE_H
#define SINEWAVE_H

#include <cassert>
#include <numbers>
#include "juce_audio_basics/juce_audio_basics.h"

class SineWave
{
public:
    void prepare (double rate, int numChannels);
    void process (juce::AudioBuffer<float>& buffer);

    [[nodiscard]] float getAmplitude() const { return amplitude; }
    [[nodiscard]] float getFrequency() const { return frequency; }
    void setAmplitude(const float newAmplitude) { amplitude = newAmplitude; }
    void setFrequency(const float newFrequency) { frequency = newFrequency; }

private:
    // Need to keep track of time separately for each channel of audio
    std::vector<float> currentTime;
    float frequency = 440.0f;
    float amplitude = 0.05f;
    float sampleRate = 0.0f;
    float timeIncrement = 0.0f;
    static constexpr float doublePi = 2.0f * std::numbers::pi_v<float>;
};

#endif //SINEWAVE_H
