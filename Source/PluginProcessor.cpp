/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "ODParameters.h"

//==============================================================================
OneDelayAudioProcessor::OneDelayAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
    , parameters(*this, nullptr)
#endif
{
    initializeParameters();
    initializeDSP();
}

OneDelayAudioProcessor::~OneDelayAudioProcessor()
{
}

//==============================================================================
const juce::String OneDelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool OneDelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool OneDelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool OneDelayAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double OneDelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int OneDelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int OneDelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void OneDelayAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String OneDelayAudioProcessor::getProgramName (int index)
{
    return {};
}

void OneDelayAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void OneDelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    for (int i = 0; i < 2; ++i)
    {
        mDelay[i]->setSampleRate(sampleRate);
        mLFO[i]->setSampleRate(sampleRate);
    }
}

void OneDelayAudioProcessor::releaseResources()
{
    for (int i = 0; i < 2; ++i)
    {
        mDelay[i]->reset();
        mLFO[i]->reset();
    }
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool OneDelayAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
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

void OneDelayAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        mGain[channel]->process(channelData,
                                getParameter(static_cast<int>(ODParameters::InputGain)),
                                channelData,
                                buffer.getNumSamples());
        
        const float rate = (channel == 0) ? 0.0f : getParameter(static_cast<int>(ODParameters::ModulationRate));

        mLFO[channel]->process(rate,
                               getParameter(static_cast<int>(ODParameters::ModulationDepth)),
                               buffer.getNumSamples());
        
        mDelay[channel]->process(channelData,
                                 getParameter(static_cast<int>(ODParameters::DelayTime)),
                                 getParameter(static_cast<int>(ODParameters::DelayFeedback)),
                                 getParameter(static_cast<int>(ODParameters::DelayWetDry)),
                                 mLFO[channel]->getBuffer(),
                                 channelData,
                                 buffer.getNumSamples());
    }
}

//==============================================================================
bool OneDelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* OneDelayAudioProcessor::createEditor()
{
    return new OneDelayAudioProcessorEditor (*this);
}

//==============================================================================
void OneDelayAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void OneDelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void OneDelayAudioProcessor::initializeParameters()
{
    for (int i = 0; i < static_cast<int>(ODParameters::_TotalNumParameters); ++i)
    {
        parameters.createAndAddParameter(ODParameterID[i],
                                         ODParameterID[i],
                                         ODParameterID[i],
                                         juce::NormalisableRange<float>(0.0f, 1.0f),
                                         0.5f,
                                         nullptr,
                                         nullptr);
    }
}

void OneDelayAudioProcessor::initializeDSP()
{
    for (int i = 0; i < 2; ++i)
    {
        mGain[i]    = std::make_unique<ODGain>();
        mDelay[i] = std::make_unique<ODDelay>();
        mLFO[i] = std::make_unique<ODLfo>();
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new OneDelayAudioProcessor();
}
