#pragma once
#include "DAWProject.h"

/*
 new UDT 4:
 with 2 member functions
 */
struct AlbumRemake
{
    AlbumRemake(std::string name, std::string vst1, std::string vst2, std::string vst3);
    ~AlbumRemake();

    std::string albumName;
    DAWProject betcover{ "野猿" };
    DAWProject maruja{ "Drift Like Cloud, Flow Like Water" };
    DAWProject bcnr{ "For the Cold Country" };

    void displayOneDAWProject(const DAWProject& p) const;
    void displayAllProjectName() const;

    JUCE_LEAK_DETECTOR(AlbumRemake)
};