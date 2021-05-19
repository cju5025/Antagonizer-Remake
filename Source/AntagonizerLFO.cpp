#include "AntagonizerLFO.h"
#include "JuceHeader.h"

LFO::LFO()
{
    reset();
}

LFO::~LFO()
{
    
}

void LFO::reset()
{
    mPhase = 0.f;
    zeromem(mBuffer, sizeof(float) * maxBufferSize);
}

void LFO::setSampleRate(double sampleRate)
{
    mSampleRate = sampleRate;
}

void LFO::process(float inRate, float inDepth, int inNumSamples)
{
    const float rate = jmap(inRate, 0.f, 1.f, 0.01f, 10.f);
    
    for (int i = 0; i < inNumSamples; i++)
    {
        mPhase += rate / mSampleRate;
        
        if (mPhase > 1)
        {
            mPhase -= 1.f;
        }
        
        const float lfoPosition = sinf(mPhase * TWO_PI) * inDepth;
        mBuffer[i] = lfoPosition;
    }
}

float* LFO::getBuffer()
{
    return mBuffer;
}
