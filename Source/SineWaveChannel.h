//
// Created by Joshua Hodge on 6/29/25.
//

#ifndef SINEWAVECHANNEL_H
#define SINEWAVECHANNEL_H

#include <cmath>
#include <numbers>

// Sine Wave Class with no JUCE dependencies
class SineWaveChannel
{
public:
    void prepare(double sampleRate);
    void process(float* output, int numSamples);

    [[nodiscard]] float getAmplitude() const { return amplitude; }
    [[nodiscard]] float getFrequency() const { return frequency; }
    void setAmplitude(const float newAmplitude) { amplitude = newAmplitude; }
    void setFrequency(const float newFrequency) { frequency = newFrequency; }

private:
    float amplitude = 0.2f;
    float frequency = 440.0f;
    float currentSampleRate = 0.0f;
    float timeIncrement = 0.0f;
    float currentTime = 0.0f;
};

#endif //SINEWAVECHANNEL_H
