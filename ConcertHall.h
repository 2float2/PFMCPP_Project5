#pragma once

/*
 new UDT 5:
 with 2 member functions
 */
struct ConcertHall
{
    ConcertHall(std::string name);
    ~ConcertHall();

    BackstageArea leftBackstageArea{ 375.5 };
    BackstageArea rightBackstageArea{ 525.5 };
    LightingRig mainRig{ "MA Lighting" };
    LightingRig subRig{ "Avolites" };

    void displayAllBackstageAreaSize() const;
    void displayAllLightingRigType() const;

    JUCE_LEAK_DETECTOR(ConcertHall)
};