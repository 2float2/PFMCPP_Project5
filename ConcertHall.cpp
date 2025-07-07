#include <iostream>
#include "ConcertHall.h"


ConcertHall::ConcertHall(std::string name)
{
    std::cout << "\n[CTOR ConcertHall] " << name << " is being constructed!" << std::endl;
}

ConcertHall::~ConcertHall()
{
    std::cout << "\n[DTOR ConcertHall] The concert hall is being destructed!" << std::endl;
}

void ConcertHall::displayAllBackstageAreaSize() const
{
    std::cout << "\nThe left backstage area is " << leftBackstageArea.backStageSize << " square meters" << std::endl;
    std::cout << "\nThe right backstage area is " << rightBackstageArea.backStageSize << " square meters" << std::endl;
}

void ConcertHall::displayAllLightingRigType() const
{
    std::cout << "\nThe main lighting rig is " << mainRig.lightingConsoleType << std::endl;
    std::cout << "\nThe sub lighting rig is " << subRig.lightingConsoleType << std::endl;
}