#include "LightingRig.h"
#include <iostream>

LightingRig::LightingConsole::LightingConsole(std::string name) :
hasInternetConnectivity(true),
consoleName(name)
{
    std::cout << "\n[CTOR LightingConsole] A " << consoleName << " console is being constructed!" << std::endl;
}

LightingRig::LightingConsole::~LightingConsole()
{
    std::cout << "\n[DTOR LightingConsole] A " << consoleName << " console is being destructed!" << std::endl;
}

LightingRig::LightingRig(std::string type) :
lightingConsoleType(type)
{
    std::cout << "\n[CTOR LightingRig] A " << lightingConsoleType << " lighitng rig is being constructed!" << std::endl;
}

LightingRig::~LightingRig()
{
    std::cout << "\n[DTOR LightingRig] A " << lightingConsoleType << " lighitng rig is being destructed!" << std::endl;
}

void LightingRig::illuminateTheStage() const
{
    std::cout << "\nIlluminate the stage from " << heightOfRig << " metres high" << std::endl;
}

void LightingRig::changeLightingColorsAndPatterns(LightingConsole consoleInUse) const
{
    std::cout << "\nChange lighting colors and patterns with " << consoleInUse.consoleName << std::endl;
}

void LightingRig::synchronizeLightingWithMusic(LightingConsole consoleInUse) const
{
    std::cout << "\nSynchronize lighting with music using " << consoleInUse.consoleName << std::endl;
}

void LightingRig::testDMXChannels() const
{
    std::cout << "Testing DMX channels..." << std::endl;
    for (int i = 0; i < numOfDMXChannels; ++i)
    {
        std::cout << "\n[Loop] Now testing DMX channel [" << i + 1 << "]" << std::endl;
    }
    std::cout << "\n[Loop] DMX channel test complete!" << std::endl;
}

int LightingRig::getNumOfScreens() const
{
    return 3;
}

void LightingRig::printDetailedMemberInfo() const
{
    std::cout << "\nThe [LightingRig] has " << this->getNumOfScreens() << " screens" << "\nlighting rig height: " << this->heightOfRig << std::endl;
}

void LightingRig::LightingConsole::panAndTiltLights(int lightNumber, double panAngle, double tiltAngle) const
{
    std::cout << "\nPan and tilt light " << lightNumber << " to " << panAngle << " and " << tiltAngle << std::endl;
}

void LightingRig::LightingConsole::adjustLightIntensity(int lightNumber, double intensity) const
{
    std::cout << "\nAdjust the intensity of light " << lightNumber << " to " << intensity << std::endl;
}

void LightingRig::LightingConsole::changeGoboPattern(int lightNumber, std::string patternName) const
{
    std::cout << "\nChange the gobo pattern of light " << lightNumber << " to " << consoleName << "'s default pattern: " << patternName << std::endl;
}

void LightingRig::LightingConsole::testFaders() const
{
    std::cout << "Testing faders..." << std::endl;
    for (int i = 0; i < numOfFaders; ++i)
    {
        std::cout << "\n[Loop] Now testing faders [" << i + 1 << "]" << std::endl;
    }
    std::cout << "\n[Loop] Faders channel test complete!" << std::endl;
}

int LightingRig::LightingConsole::getNumOfUsbPort() const
{
    return 4;
}

void LightingRig::LightingConsole::printDetailedMemberInfo() const
{
    std::cout << "\nThe [LightingConsole] has " << this->getNumOfUsbPort() << " usb ports" << "\nlighting console weight: " << this->weightOfConsole << std::endl;
}