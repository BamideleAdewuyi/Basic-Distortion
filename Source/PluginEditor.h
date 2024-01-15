/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BasicDistortionAudioProcessorEditor  : public juce::AudioProcessorEditor,
private juce::ComboBox::Listener,
juce::Slider::Listener
{
public:
    BasicDistortionAudioProcessorEditor (BasicDistortionAudioProcessor&);
    ~BasicDistortionAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // Method for changing combo box and sliders
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (juce::Slider* sliderThatHasChanged) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BasicDistortionAudioProcessor& audioProcessor;
    
    // Create combo box for switching between distortion types
    juce::ComboBox disChoice;
    // Create sliders
    juce::Slider Threshold;
    juce::Slider Mix;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicDistortionAudioProcessorEditor)
};
