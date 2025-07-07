#include "Wrappers.h"

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