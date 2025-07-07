#include <iostream>
#include "DAWProject.h"


DAWProject::VirtualStudioTechnology::VirtualStudioTechnology(std::string vstn) :
vstName(vstn),
vstManufacturer("Toontrack"),
vstType("virtual instrument")
{
    numOfPresets = 100;
    std::cout << "\n[CTOR VirtualStudioTechnology] " << vstName << std::endl;
}

DAWProject::VirtualStudioTechnology::~VirtualStudioTechnology()
{
    std::cout << "\n[DTOR VirtualStudioTechnology] " << vstName << std::endl;
}

DAWProject::DAWProject(std::string dawProjectName) :
numOfSections(8),
isQuantized(true),
projectName(dawProjectName)
{
    std::cout << "\n[CTOR DAWProject] " << projectName << std::endl;
}

DAWProject::~DAWProject()
{
    std::cout << "\n[DTOR DAWProject] " << projectName << std::endl;
}

void DAWProject::playBack() const
{
    std::cout << "\nNow playing..." << std::endl;
}

void DAWProject::playBackComposition() const
{
    for (int i = 0; i < numOfSections; ++i)
    {
        playBack();
    }
}

void DAWProject::applyAudioEffects(std::string effectName, VirtualStudioTechnology vstInUse) const
{
    std::cout << "\nApply " << effectName << " of " << vstInUse.vstName << std::endl;
}

void DAWProject::quantizeNotes() const
{
    std::cout << "\nAre the MIDI notes quantized? " << (isQuantized ? "Yes" : "No") << std::endl;
}

std::string DAWProject::getTrackType() const
{
    return "midi track";
}

void DAWProject::printDetailedMemberInfo() const
{
    std::cout << "\n[DAWProject] track type: " << this->getTrackType() << " \ntime signature: " << this->timeSignature << std::endl;
}

void DAWProject::VirtualStudioTechnology::acceptMIDIInput() const
{
    std::cout << "\nCurrent VST accepts MIDI input? " << (supportsMIDI ? "Yes" : "No") << std::endl;
}

void DAWProject::VirtualStudioTechnology::outputAudio(double outputVolume) const
{
    std::cout << "\nOutput audio at " << outputVolume << "db" << std::endl;
}

std::string DAWProject::VirtualStudioTechnology::changePreset(std::string presetName) const
{
    return presetName;
}

void DAWProject::VirtualStudioTechnology::testMIDIInputChannels(int numOfMIDIInputChannels) const
{
    std::cout << "Testing MIDI input channels..." << std::endl;
    for (int i = 1; i < numOfMIDIInputChannels; ++i)
    {
        std::cout << "\n[Loop] Now testing MIDI input channel [" << i + 1 << "]" << std::endl;
    }
    std::cout << "\n[Loop] MIDI input channels test complete!" << std::endl;
}

std::string DAWProject::VirtualStudioTechnology::getVstManufacturer() const
{
    return "Spitfire Audio";
}

void DAWProject::VirtualStudioTechnology::printDetailedMemberInfo() const
{
    std::cout << "\n[VirtualStudioTechnology] manufacturer: " << this->getVstManufacturer() << " \nvst name: " << this->vstName << std::endl;
}