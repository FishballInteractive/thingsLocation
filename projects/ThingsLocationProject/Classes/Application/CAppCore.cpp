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

USING_NS_CC;

static CAppCore* inst = NULL;

CAppCore::CAppCore()
: mAppData(0)
, mGPSManager(0)
{
    TRACE_ALLOC
    
    init();
}

CAppCore::~CAppCore()
{
    TRACE_DEALLOC
    
    utils::releaseObject(mAppData);
    utils::releaseObject(mGPSManager);
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
    
    return true;
}


CAppData* CAppCore::getAppData()
{
    return mAppData;
}

IGPSManager* CAppCore::getGPSManager()
{
    return mGPSManager;
}