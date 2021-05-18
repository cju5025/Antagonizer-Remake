#include "PanelBase.h"

PanelBase::PanelBase(AntagonizerRemakeAudioProcessor* processor)
:   mProcessor(processor)
{
    
}

PanelBase::~PanelBase()
{
    
}

void PanelBase::paint (Graphics& g)
{
    g.setColour(Colours::whitesmoke);
    g.fillAll();
    
    g.setColour(Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight());
}
