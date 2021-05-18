#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "InterfaceDefines.h"

class PanelBase
:   public Component
{
public:

    PanelBase(AntagonizerRemakeAudioProcessor* processor);
    ~PanelBase();
    
    void paint (Graphics& g) override;

protected:

    AntagonizerRemakeAudioProcessor* mProcessor;

};
