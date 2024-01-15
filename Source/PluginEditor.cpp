/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicDistortionAudioProcessorEditor::BasicDistortionAudioProcessorEditor (BasicDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    // Make combo box visible and set up options
    addAndMakeVisible(&disChoice); // 1
    disChoice.addItem("Hard Clip", 1);
    disChoice.addItem("Soft Clip", 2);
    disChoice.addItem("Half-Wave Rect", 3);
    disChoice.setSelectedId(1);
    disChoice.addListener(this);
    
    // Make sliders visible
    addAndMakeVisible(&Threshold);
    Threshold.setRange(0.0f, 1.0f, 0.001);
    Threshold.addListener(this);

    addAndMakeVisible(&Mix);
    Mix.setRange(0.0f, 1.0f, 0.001);
    Mix.addListener(this);
}

BasicDistortionAudioProcessorEditor::~BasicDistortionAudioProcessorEditor()
{
}

//==============================================================================
void BasicDistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    
}

void BasicDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    disChoice.setBounds(50, 50, 200, 50);
    Threshold.setBounds(50, 100, 200, 50);
    Mix.setBounds(50, 150, 200, 50);
}

void BasicDistortionAudioProcessorEditor::comboBoxChanged(juce::ComboBox *comboBoxThatHasChanged)
{
    audioProcessor.menuChoice = comboBoxThatHasChanged->getSelectedId();
}

void BasicDistortionAudioProcessorEditor::sliderValueChanged(juce::Slider *sliderThatHasChanged)
{
    if (&Mix == sliderThatHasChanged)
    {
        audioProcessor.mix = sliderThatHasChanged->getValue();
    }
    if (&Threshold == sliderThatHasChanged)
    {
        audioProcessor.thresh = sliderThatHasChanged->getValue();
    }
}
