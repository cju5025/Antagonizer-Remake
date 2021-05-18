#pragma once

#include "PanelBase.h"
#include "SliderParameter.h"

class GainPanel
:   public PanelBase
{
public:
    
    GainPanel(AntagonizerRemakeAudioProcessor* inProcessor);
    ~GainPanel();
    
    void paint(Graphics& g) override;
    void setParameterID(int inParameterID);
    
private:
    
    std::unique_ptr<SliderParameter> mSlider;
};
