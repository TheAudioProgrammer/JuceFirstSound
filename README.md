# JuceFirstSound

A simple audio plugin built with JUCE framework that generates a sine wave at 440Hz.

## Overview

JuceFirstSound is an audio plugin that demonstrates basic audio processing using the JUCE framework.  This is designed to help teach the first implementation of an audio processing class.

## Build Requirements

- CMake (minimum version 3.24)
- C++20 compatible compiler
- JUCE framework (automatically fetched via CPM)

## Building the Project

1. Clone the repository
2. Create a build directory:
```bash
mkdir build && cd build
```
3. Generate build files:
```bash
cmake ..
```
4. Build the project:
```bash
cmake --build .
```

## Project Structure

- `Source/`
  - `SineWave.h/cpp` - Core sine wave generation implementation
  - `PluginProcessor.h/cpp` - Audio plugin processing logic
  - `PluginEditor.h/cpp` - GUI implementation

## Technical Details

The plugin is built using:
- JUCE framework
- C++20
- CMake build system
- CPM for package management

## Plugin Formats

The plugin builds for:
- VST3
- AU (Audio Unit)
- Standalone application

## Credits

Created using the JUCE framework
Company: theaudioprogrammer
