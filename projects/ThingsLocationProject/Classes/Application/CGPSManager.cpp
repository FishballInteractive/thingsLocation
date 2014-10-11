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

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "CGPSControllerNative_ios.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "CGPSControllerNative_android.h"
#endif

USING_NS_CC;

typedef std::pair<GPSTargetsId, std::vector<IGPSObserver*> > pair_observer;

CGPSManager::CGPSManager()
{
    TRACE_ALLOC
}

CGPSManager::~CGPSManager()
{
    TRACE_DEALLOC
    
    utils::releaseObject(mNativeController);
}

void CGPSManager::init()
{
    mNativeController = IGPSControllerNative::create();
    utils::retainObject(mNativeController);
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
    std::map<GPSTargetsId , std::vector<IGPSObserver*> >::iterator it = mObservers.find(aTarget);
    
    if(it != mObservers.end())
    {
        it->second.push_back(aObserver);
    }
    else
    {
        std::vector<IGPSObserver*> arr;
        arr.push_back(aObserver);
        
        mObservers.insert(pair_observer(aTarget, arr));
    }
}

void CGPSManager::removeObserver(GPSTargetsId aTarget, IGPSObserver* aObserver)
{
    
}