//
// Created by Joshua Hodge on 6/24/25.
//

#include "SineWave.h"

void SineWave::prepare (const double rate)
{
    sampleRate = static_cast<float>(rate);
    timeIncrement = 1.0f / sampleRate;
}

void SineWave::process (juce::AudioBuffer<float>& buffer)
{
    // You didn't call prepare!
    assert (sampleRate > 0.0f && timeIncrement > 0.0f);

    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            channelData[sample] = amplitude * std::sin(doublePi * frequency * currentTime);

            currentTime += timeIncrement;

            if (currentTime >= 1.0f)
            {
                currentTime -= 1.0f;
            }
        }
    }
}