#include <iostream>
#include "BackstageArea.h"

BackstageArea::BackstageArea(double size) :
numOfEmptyLockers(5),
numOfDressingRooms(3),
numOfEquimentStorageShelves(10),
numOfAllLockers(8),
backStageSize(size)
{
    std::cout << "\n[CTOR BackstageArea] A " << backStageSize << "-square-meters backstage area is being constructed!" << std::endl;
}

BackstageArea::~BackstageArea()
{
    std::cout << "\n[DTOR BackstageArea] A " << backStageSize << "-square-meters backstage area is being destructed!" << std::endl;
}

void BackstageArea::provideRestingSpaceForPerformers() const
{
    std::cout << "\nProvide " << backStageSize << " squre metres of resting space for performers" << std::endl;
}

void BackstageArea::storeCablesAndInstruments() const
{
    std::cout << "\nStore cables and instruments with " << numOfEquimentStorageShelves << " storeage shelves" << std::endl;
}

void BackstageArea::provideStorageForPersonalBelongings() const
{
    std::cout << "\nProvide storage for personal belongings with " << numOfAllLockers << " lockers" << std::endl;
}

int BackstageArea::storePersonalBelongings()//modifies a member variable
{
    if (numOfEmptyLockers != 0)
    {
        while (numOfEmptyLockers > 0)
        {
            --numOfEmptyLockers;
            std::cout << "\n[Loop] 1 locker allocated. Remaining: " << numOfEmptyLockers << std::endl;
        }
    }
    std::cout << "\n[Loop] Sorry, there are no empty lockers left" << std::endl;
    return numOfEmptyLockers;
}

int BackstageArea::getCapacity() const
{
    return 500;
}

void BackstageArea::printDetailedMemberInfo() const
{
    std::cout << "\n[BackstageArea] can accomadate: " << this->getCapacity() << " people" << "\nbackstage size: " << this->backStageSize << std::endl;
}
