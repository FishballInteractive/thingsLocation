//
//  CGPSManager.cpp
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#include "CGPSManager.h"
#include "Utils.h"
#include "Log.h"

USING_NS_CC;

CGPSManager::CGPSManager()
{
    TRACE_ALLOC
}

CGPSManager::~CGPSManager()
{
    TRACE_DEALLOC
}

void CGPSManager::init()
{
    
}

void CGPSManager::onDidChangeCoordinate(GPSTargetsId aTarget, const CGPSPoint& aNewPoint)
{
    
}

void CGPSManager::startMonitoring(GPSTargetsId aTarget)
{
    
}

void CGPSManager::stopMonitoring(GPSTargetsId aTarget)
{
    
}

void CGPSManager::addObserver(GPSTargetsId aTarget, IGPSObserver* aObserver)
{
    
}

void CGPSManager::removeObserver(GPSTargetsId aTarget, IGPSObserver* aObserver)
{
    
}