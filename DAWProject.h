#pragma once

#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */
struct DAWProject //1, Nested UDT
{
    DAWProject(std::string dawProjectName);
    ~DAWProject();


    std::string timeSignature = "3/4";
    std::string musicalMode = "minor";
    std::string keySignature = "A";
    int numOfSections;
    bool isQuantized;
    std::string projectName;

    struct VirtualStudioTechnology
    {
        VirtualStudioTechnology(std::string vst);
        ~VirtualStudioTechnology();

        std::string vstName;
        std::string vstManufacturer;
        std::string vstType;
        bool supportsMIDI = true;
        int numOfPresets;

        void acceptMIDIInput() const;
        void outputAudio(const double& outputVolume = 80.0) const;
        std::string changePreset(const std::string& presetName) const;
        void testMIDIInputChannels(const int& numOfMIDIInputChannels = 2) const;
        std::string getVstManufacturer() const;
        void printDetailedMemberInfo() const;
    };

    void playBack() const;
    void playBackComposition() const;
    void applyAudioEffects(const std::string& effectName, const VirtualStudioTechnology& vstInUse) const;
    void quantizeNotes() const;
    std::string getTrackType() const;
    void printDetailedMemberInfo() const;

    VirtualStudioTechnology vst{"Kontakt"};

    JUCE_LEAK_DETECTOR(DAWProject)

};
