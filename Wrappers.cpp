#include <iostream>
#include "Wrappers.h"
#include "DAWProject.h"
#include "BackstageArea.h"
#include "LightingRig.h"
#include "AlbumRemake.h"
#include "ConcertHall.h"

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