#pragma once

#include "JuceHeader.h"
#include "AudioHelpers.h"

class AntagonizerMain{
    
public:
    AntagonizerMain();
    ~AntagonizerMain();
    
    void process(float* inAudio,
                 float time,
                 float feedback,
                 float dryWet,
                 float type,
                 float* inModBuffer,
                 float* outAudio,
                 int numSamplesToRender);
    
private:

};
