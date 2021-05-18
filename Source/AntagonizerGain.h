#pragma once

class AntagonizerGain
{
public:
    AntagonizerGain();
    ~AntagonizerGain();
    
    void process(float* inAudio, float inGain, float* outAudio, int numSamplesToRender);
    
private:
    
};
