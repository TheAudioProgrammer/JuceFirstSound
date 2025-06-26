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
    void prepare (double rate);
    void process (juce::AudioBuffer<float>& buffer);

private:
    float currentTime = 0.0f;
    float frequency = 440.0f;
    float amplitude = 0.5f;
    float sampleRate = 0.0f;
    float timeIncrement = 0.0f;
    constexpr float doublePi = 2.0f * std::numbers::pi_v<float>;
};

#endif //SINEWAVE_H
