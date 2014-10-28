//
//  CAppCore.cpp
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#include "CAppCore.h"
#include "Utils.h"
#include "Log.h"
#include "CGPSManager.h"
#include "CPushNotificationManager.h"
#include "CNotificationCenter.h"

USING_NS_CC;

static CAppCore* inst = NULL;

CAppCore::CAppCore()
: mAppData(0)
, mGPSManager(0)
, mPushNotificationManager(0)
, mIsBackground(false)
, mNotificationCenter(0)
{
    TRACE_ALLOC
    
    init();
}

CAppCore::~CAppCore()
{
    TRACE_DEALLOC
    
    utils::releaseObject(mAppData);
    utils::releaseObject(mGPSManager);
    utils::releaseObject(mPushNotificationManager);
    utils::releaseObject(mNotificationCenter);
}

CAppCore* CAppCore::shared()
{
    if(!inst)
    {
        inst = new CAppCore();
    }
    
    return inst;
}

bool CAppCore::init()
{
    mGPSManager = utils::createObject<CGPSManager>();
    mGPSManager->init();
    utils::retainObject(mGPSManager);
    
    mAppData = utils::createObject<CAppData>();
    utils::retainObject(mAppData);
    
    mPushNotificationManager = utils::createObject<CPushNotificationManager>();
    mPushNotificationManager->init();
    utils::retainObject(mPushNotificationManager);
    
    mNotificationCenter = utils::createObject<CNotificationCenter>();
    utils::retainObject(mNotificationCenter);
    
    return true;
}

INotificationCenter* CAppCore::getNotificationCenter()
{
    return mNotificationCenter;
}

CAppData* CAppCore::getAppData()
{
    return mAppData;
}

CPushNotificationManager* CAppCore::getPushNotificationManager()
{
    return mPushNotificationManager;
}

IGPSManager* CAppCore::getGPSManager()
{
    return mGPSManager;
}