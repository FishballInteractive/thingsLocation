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
#include "IGPSObserver.h"

USING_NS_CC;

typedef std::pair<GPSTargetsId, IGPSObserver*> pair_observer;

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
    mNativeController = IGPSControllerNative::create();
    mNativeController->initWithDelegate(this);
}

void CGPSManager::onDidChangeCoordinate(GPSTargetsId aTarget, const CGPSPoint& aNewPoint)
{
    std::map<GPSTargetsId , std::vector<IGPSObserver*> >::iterator it = mObservers.find(aTarget);
    
    if(it != mObservers.end())
    {
        for(int i = 0; i < it->second.size(); i++)
        {
            it->second[i]->onDidChangeCoordinate(aTarget, aNewPoint);
        }
    }
}

void CGPSManager::startMonitoring(GPSTargetsId aTarget)
{
    mNativeController->startMonitoring(aTarget);
}

void CGPSManager::stopMonitoring(GPSTargetsId aTarget)
{
    mNativeController->stopMonitoring(aTarget);
}

void CGPSManager::addObserver(GPSTargetsId aTarget, IGPSObserver* aObserver)
{
    mObservers.insert(pair_observer(aTarget,aObserver));
}

void CGPSManager::removeObserver(GPSTargetsId aTarget, IGPSObserver* aObserver)
{
    
}