#include "PluginProcessor.h"
#include "PluginEditor.h"

AntagonizerRemakeAudioProcessorEditor::AntagonizerRemakeAudioProcessorEditor (AntagonizerRemakeAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    mMainPanel = std::make_unique<MainPanel>(&audioProcessor);
    addAndMakeVisible(mMainPanel.get());
}

AntagonizerRemakeAudioProcessorEditor::~AntagonizerRemakeAudioProcessorEditor()
{
    
}

void AntagonizerRemakeAudioProcessorEditor::paint (juce::Graphics& g)
{

}

void AntagonizerRemakeAudioProcessorEditor::resized()
{

}
