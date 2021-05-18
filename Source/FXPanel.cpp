#include "FXPanel.h"
#include "Parameters.h"
#include "GUIHelpers.h"

FXPanel::FXPanel(AntagonizerRemakeAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
}

FXPanel::~FXPanel()
{
    
}

void FXPanel::paint(Graphics& g)
{
        PanelBase::paint(g);
        
        if (mDryWetSlider)
            {
                paintComponentLabel(g, mDryWetSlider.get());
            }
            
        if (mFeedbackSlider)
            {
                paintComponentLabel(g, mFeedbackSlider.get());
            }
            
        if (mDepthSlider)
            {
                paintComponentLabel(g, mDepthSlider.get());
            }
            
        if (mRateSlider)
            {
                paintComponentLabel(g, mRateSlider.get());
            }
            
        if (mAntagonizeSlider)
            {
                paintComponentLabel(g, mAntagonizeSlider.get());
            }
}

void FXPanel::addSliders()
{
    const int sliderSize = 60;
    int x = 30;
    int y = (getHeight() * 0.5) - (sliderSize * 0.5);
    
    mDryWetSlider = std::make_unique<SliderParameter>(mProcessor->parameters, ParameterID[parameter_DryWet]);
    mDryWetSlider->setBounds(x, y, sliderSize, sliderSize);
    addAndMakeVisible(*mDryWetSlider);
    x += sliderSize * 1.75;
    
    mFeedbackSlider = std::make_unique<SliderParameter>(mProcessor->parameters, ParameterID[parameter_Feedback]);
    mFeedbackSlider->setBounds(x, y, sliderSize, sliderSize);
    addAndMakeVisible(*mFeedbackSlider);
    x += sliderSize * 1.75;
    
    mDepthSlider = std::make_unique<SliderParameter>(mProcessor->parameters, ParameterID[parameter_Depth]);
    mDepthSlider->setBounds(x, y, sliderSize, sliderSize);
    addAndMakeVisible(*mDepthSlider);
    x += sliderSize * 1.75;
    
    mRateSlider = std::make_unique<SliderParameter>(mProcessor->parameters, ParameterID[parameter_Rate]);
    mRateSlider->setBounds(x, y, sliderSize, sliderSize);
    addAndMakeVisible(*mRateSlider);
    x += sliderSize * 1.75;
    
    mAntagonizeSlider = std::make_unique<SliderParameter>(mProcessor->parameters, ParameterID[parameter_Antagonize]);
    mAntagonizeSlider->setBounds(x, y, sliderSize, sliderSize);
    addAndMakeVisible(*mAntagonizeSlider);
    x += sliderSize * 1.75;
}
