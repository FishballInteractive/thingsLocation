//
//  CAppData.cpp
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#include "CAppData.h"
#include "Utils.h"
#include "Log.h"

USING_NS_CC;

CAppData::CAppData()
: mIsTakeKey(0)
{
    TRACE_ALLOC

}

CAppData::~CAppData()
{
    TRACE_DEALLOC

}


void CAppData::setKeyCoordinate(const CGPSPoint& aPoint)
{
    if(!aPoint.getIsValid())
        return;
    
    mKeyCoordinate = aPoint;
}

void CAppData::setCarCoordinate(const CGPSPoint& aPoint)
{
    if(!aPoint.getIsValid())
        return;
    
    mCarCoordinate = aPoint;
}

void CAppData::setMyCoordinate(const CGPSPoint& aPoint)
{
    if(!aPoint.getIsValid())
        return;
    
    mMyCoordinate = aPoint;
}