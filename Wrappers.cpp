#include <iostream>
#include "Wrappers.h"

struct DAWProject;
struct LightingRig;
struct BackstageArea;
struct AlbumRemake;
struct ConcertHall;

DAWProjectWrapper::DAWProjectWrapper(DAWProject* ptr)
    : dawpPtr(ptr)
{
}

DAWProjectWrapper::~DAWProjectWrapper()
{
    delete dawpPtr;
}

LightingRigWrapper::LightingRigWrapper(LightingRig* ptr)
    : ltrPtr(ptr)
{
}

LightingRigWrapper::~LightingRigWrapper() 
{
    delete ltrPtr;
}

BackstageAreaWrapper::BackstageAreaWrapper(BackstageArea* ptr)
    :bsaPtr(ptr)
{
}

BackstageAreaWrapper::~BackstageAreaWrapper()
{
    delete bsaPtr;
}

LightingRigWrapper::LightingRigWrapper(LightingRig* ptr)
    : ltrPtr(ptr)
{
}

LightingRigWrapper::~LightingRigWrapper()
{
    delete ltrPtr;
}

AlbumRemakeWrapper::AlbumRemakeWrapper(AlbumRemake* ptr)
    : arPtr(ptr)
{
}

AlbumRemakeWrapper::~AlbumRemakeWrapper() 
{
    delete arPtr;
}

ConcertHallWrapper::ConcertHallWrapper(ConcertHall* ptr)
    : chPtr(ptr)
{
}

ConcertHallWrapper::~ConcertHallWrapper() 
{
    delete chPtr;
}