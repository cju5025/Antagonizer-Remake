#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "MainPanel.h"

class AntagonizerRemakeAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AntagonizerRemakeAudioProcessorEditor (AntagonizerRemakeAudioProcessor&);
    ~AntagonizerRemakeAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    std::unique_ptr<MainPanel> mMainPanel;
    AntagonizerRemakeAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AntagonizerRemakeAudioProcessorEditor)
};
