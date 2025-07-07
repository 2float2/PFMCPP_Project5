#pragma once

#include "LeakedObjectDetector.h"

/*
 copied UDT 3:
 */
struct LightingRig //9, Nested UDT
{
    LightingRig(std::string type);
    ~LightingRig();

    int numOfDMXChannels = 4;
    int numOfTraditionalLights = 12;
    int numOfComputerLights = 35;
    int numOfControlChannels = 512;
    double heightOfRig = 10.5;
    std::string lightingConsoleType;

    struct LightingConsole
    {
        LightingConsole(std::string name);
        ~LightingConsole();

        int numOfScreens = 3;
        int numOfFaders = 8;
        bool hasInternetConnectivity;
        double weightOfConsole = 120.0;
        std::string consoleName;

        void panAndTiltLights(const int& lightNumber, const double& panAngle = 135.0, double tiltAngle = 45.0) const;
        void adjustLightIntensity(const int& lightNumber, const double& intensity = 100.0) const;
        void changeGoboPattern(const int& lightNumber, const std::string& patternName = "star") const;
        void testFaders() const;
        int getNumOfUsbPort() const;
        void printDetailedMemberInfo() const;

    };

    void illuminateTheStage() const;
    void changeLightingColorsAndPatterns(const LightingConsole& consoleInUse) const;
    void synchronizeLightingWithMusic(const LightingConsole& consoleInUse) const;
    void testDMXChannels() const;
    int getNumOfScreens() const;
    void printDetailedMemberInfo() const;

    LightingConsole mainConsole{ "Tiger Touch" };

    JUCE_LEAK_DETECTOR(LightingRig)

};
