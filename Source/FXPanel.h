#pragma once

#include "PanelBase.h"
#include "SliderParameter.h"

class FXPanel
:   public PanelBase
{
public:
    
    FXPanel(AntagonizerRemakeAudioProcessor* inProcessor);
    ~FXPanel();
    
    void paint(Graphics& g) override;
    void addSliders();
    
private:
    
    std::unique_ptr<SliderParameter> mDryWetSlider;
    std::unique_ptr<SliderParameter> mFeedbackSlider;
    std::unique_ptr<SliderParameter> mDepthSlider;
    std::unique_ptr<SliderParameter> mRateSlider;
    std::unique_ptr<SliderParameter> mAntagonizeSlider;
};
