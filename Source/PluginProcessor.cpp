#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Parameters.h"

AntagonizerRemakeAudioProcessor::AntagonizerRemakeAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
                    parameters(*this, nullptr, Identifier("Antagonizer"), createParameterLayout())
#endif
{
    initializeDSP();
}

AntagonizerRemakeAudioProcessor::~AntagonizerRemakeAudioProcessor()
{
}

//==============================================================================
const juce::String AntagonizerRemakeAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AntagonizerRemakeAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AntagonizerRemakeAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AntagonizerRemakeAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AntagonizerRemakeAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AntagonizerRemakeAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AntagonizerRemakeAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AntagonizerRemakeAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String AntagonizerRemakeAudioProcessor::getProgramName (int index)
{
    return {};
}

void AntagonizerRemakeAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void AntagonizerRemakeAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void AntagonizerRemakeAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AntagonizerRemakeAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AntagonizerRemakeAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        float inputGain = *parameters.getRawParameterValue(ParameterID[parameter_InputGain]);
        mInputGain[channel]->process(channelData,
                                     inputGain,
                                     channelData,
                                     buffer.getNumSamples());
        
        float outputGain = *parameters.getRawParameterValue(ParameterID[parameter_OutputGain]);
        mOutputGain[channel]->process(channelData,
                                     outputGain,
                                     channelData,
                                     buffer.getNumSamples());

    }
}

//==============================================================================
bool AntagonizerRemakeAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* AntagonizerRemakeAudioProcessor::createEditor()
{
    return new AntagonizerRemakeAudioProcessorEditor (*this);
}

//==============================================================================
void AntagonizerRemakeAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{

}

void AntagonizerRemakeAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{

}

void AntagonizerRemakeAudioProcessor::initializeDSP()
{
    for (int i = 0; i < 2; i++)
    {
        mInputGain[i] = std::make_unique<AntagonizerGain>();
        mOutputGain[i] = std::make_unique<AntagonizerGain>();
    }
}

AudioProcessorValueTreeState::ParameterLayout AntagonizerRemakeAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<AudioParameterFloat>> params;
    
    for (int i = 0; i < parameter_TotalNumParameters; i++)
    {
        params.push_back(std::make_unique<AudioParameterFloat>(ParameterID[i],
                                                               ParameterID[i],
                                                               NormalisableRange<float>(0.f, 1.f),
                                                               0.5f));
    }
    return { params.begin(), params.end() };
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AntagonizerRemakeAudioProcessor();
}
