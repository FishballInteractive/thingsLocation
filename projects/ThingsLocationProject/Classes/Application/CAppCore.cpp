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