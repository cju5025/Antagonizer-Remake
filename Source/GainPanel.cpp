#include "GainPanel.h"
#include "Parameters.h"
#include "GUIHelpers.h"

GainPanel::GainPanel(AntagonizerRemakeAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}

GainPanel::~GainPanel()
{
    
}

void GainPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    if(mSlider)
    {
        paintComponentLabel(g, mSlider.get());
    }
\
}

void GainPanel::setParameterID(int inParameterID)
{
    mSlider = std::make_unique<SliderParameter>(mProcessor->parameters, ParameterID[inParameterID]);
    
    const int slider_size = 54;
    
    mSlider->setBounds((getWidth() * 0.5) - (slider_size * 0.5), (getHeight() * 0.5) - (slider_size * 0.5), slider_size, slider_size);
    addAndMakeVisible(*mSlider);
}
