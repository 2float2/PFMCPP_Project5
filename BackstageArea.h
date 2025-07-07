#pragma once

#include "LeakedObjectDetector.h"
/*
 copied UDT 2:
 */
struct BackstageArea //2
{
    BackstageArea(double size);
    ~BackstageArea();

    int numOfEmptyLockers,
    numOfDressingRooms, numOfEquimentStorageShelves, numOfAllLockers;
    double backStageSize;
    bool hasEquipmentLoadingAccess = true;

    void provideRestingSpaceForPerformers() const;
    void storeCablesAndInstruments() const;
    void provideStorageForPersonalBelongings() const;
    int storePersonalBelongings();//modifies a member variable
    int getCapacity() const;
    void printDetailedMemberInfo() const;

    JUCE_LEAK_DETECTOR(BackstageArea)
};
