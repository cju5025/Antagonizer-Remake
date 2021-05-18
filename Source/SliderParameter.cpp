#include "SliderParameter.h"

SliderParameter::SliderParameter(AudioProcessorValueTreeState& stateToControl, const String& parameterID)
:       Slider(parameterID)
{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    setRange(0.f, 1.f, 0.001f);
    
    mAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(stateToControl, parameterID, *this);
}

SliderParameter::~SliderParameter()
{
    
}
