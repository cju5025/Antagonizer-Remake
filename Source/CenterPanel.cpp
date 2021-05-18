#include "CenterPanel.h"

CenterPanel::CenterPanel(AntagonizerRemakeAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mFXPanel = std::make_unique<FXPanel>(processor);
    mFXPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    mFXPanel->addSliders();
    addAndMakeVisible(mFXPanel.get());
}

CenterPanel::~CenterPanel()
{
    
}
