#pragma once


#include "JuceHeader.h"

class SliderParameter
:   public Slider
{
public:
    
    SliderParameter(AudioProcessorValueTreeState& stateToControl, const String& parameterID);
    ~SliderParameter();
    
private:
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderParameter);
};
