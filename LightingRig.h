#pragma once

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

        void panAndTiltLights(int lightNumber, double panAngle = 135.0, double tiltAngle = 45.0) const;
        void adjustLightIntensity(int lightNumber, double intensity = 100.0) const;
        void changeGoboPattern(int lightNumber, std::string patternName = "star") const;
        void testFaders() const;
        int getNumOfUsbPort() const;
        void printDetailedMemberInfo() const;

    };

    void illuminateTheStage() const;
    void changeLightingColorsAndPatterns(LightingConsole consoleInUse) const;
    void synchronizeLightingWithMusic(LightingConsole consoleInUse) const;
    void testDMXChannels() const;
    int getNumOfScreens() const;
    void printDetailedMemberInfo() const;

    LightingConsole mainConsole{ "Tiger Touch" };

    JUCE_LEAK_DETECTOR(LightingRig)

};