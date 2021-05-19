#pragma once

#include "AudioHelpers.h"

class LFO
{
public:
    LFO();
    ~LFO();
    
    void reset();
    
    void setSampleRate(double sampleRate);
    void process(float rate, float depth, int numSamples);
    
    float* getBuffer();
    
private:
    
    double mSampleRate;
    
    float mPhase;
    float mBuffer[maxBufferSize];
};
