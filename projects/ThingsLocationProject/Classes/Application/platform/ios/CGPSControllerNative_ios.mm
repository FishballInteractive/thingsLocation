//
//  CGPSControllerNative_ios.cpp
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 10/5/14.
//
//

#include "CGPSControllerNative_ios.h"
#include "Utils.h"
#include "Log.h"

USING_NS_CC;

CGPSControllerNative_ios::CGPSControllerNative_ios()
{
    TRACE_ALLOC
}

CGPSControllerNative_ios::~CGPSControllerNative_ios()
{
    TRACE_DEALLOC
}

IGPSControllerNative* IGPSControllerNative::create()
{
    IGPSControllerNative* obj = utils::createObject<CGPSControllerNative_ios>();
    
    return obj;
}

void CGPSControllerNative_ios::initWithDelegate(IGPSControllerNativeDelegate* aDelegate)
{
    mNativeDelegate = aDelegate;
}

void CGPSControllerNative_ios::startMonitoring(GPSTargetsId aTarget)
{
    
}

void CGPSControllerNative_ios::stopMonitoring(GPSTargetsId aTarget)
{
    
}