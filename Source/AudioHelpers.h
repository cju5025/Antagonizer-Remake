#pragma once

#define parameterSmoothingCoefficient_Generic 0.04
#define parameterSmoothingCoefficient_Fine 0.002

const static int maxBufferSize = 192000;

const static double PI = 3.141592653589;
const static double TWO_PI = 6.28318530718;

inline float linearInterpolation(float y0, float y1, float d)
{
    return (1 - d) * y0 + d * y1;
}