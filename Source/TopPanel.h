#pragma once

#include "PanelBase.h"

class TopPanel
:   public PanelBase
{
public:
    
        TopPanel(AntagonizerRemakeAudioProcessor* processor);
        ~TopPanel();
        
        void paint(Graphics& g) override;
        
private:
    
};
