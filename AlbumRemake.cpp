#include <iostream>
#include "AlbumRemake.h"

AlbumRemake::AlbumRemake(std::string name, std::string vst1, std::string vst2, std::string vst3) :
albumName(name)
{
    std::cout << "\n[CTOR AlbumRemake] '" << albumName << "' remake project is being constructed!" << std::endl;

    betcover.vst.vstName = vst1;
    maruja.vst.vstName = vst2;
    bcnr.vst.vstName = vst3;

    displayOneDAWProject(maruja);
}

AlbumRemake::~AlbumRemake()
{
    std::cout << "\n[DTOR AlbumRemake] The " << albumName << " remake project is being destructed!" << std::endl;
}

void AlbumRemake::displayOneDAWProject(const DAWProject& p) const
{
    std::cout << "\nYou are viewing the project: " << p.projectName << std::endl;
}

void AlbumRemake::displayAllProjectName() const
{
    std::cout << "\nWhat are we working on?\n";
    std::cout << "\nFirst project: " << betcover.projectName << std::endl;
    std::cout << "\nSecond project: " << maruja.projectName << std::endl;
    std::cout << "\nThird project: " << bcnr.projectName << std::endl;
}
