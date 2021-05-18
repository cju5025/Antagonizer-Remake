#include "TopPanel.h"

TopPanel::TopPanel(AntagonizerRemakeAudioProcessor* processor)
:   PanelBase(processor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}

TopPanel::~TopPanel()
{
    
}

void TopPanel::paint(Graphics& g)
{
    PanelBase::paint(g);
    
    g.drawFittedText("Antagonizer", 0, 0, getWidth() - 10, getHeight(), Justification::centredRight, 1);
}
