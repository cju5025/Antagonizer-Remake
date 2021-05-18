#pragma once

enum Parameters
{
    parameter_InputGain = 0,
    parameter_DryWet,
    parameter_Feedback,
    parameter_Depth,
    parameter_Rate,
    parameter_Antagonize,
    parameter_OutputGain,
    parameter_TotalNumParameters,
};

static String ParameterID [parameter_TotalNumParameters] = 
{
    "Input Gain",
    "Dry / Wet",
    "Feedback",
    "Depth",
    "Rate",
    "Antagonize",
    "Output Gain"
};

// TODO: add default values