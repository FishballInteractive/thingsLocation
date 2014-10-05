//
//  CGPSControllerNative_android.cpp
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 10/5/14.
//
//

#include "CGPSControllerNative_android.h"
#include "Utils.h"
#include "Log.h"

USING_NS_CC;

CGPSControllerNative_android::CGPSControllerNative_android()
{
    TRACE_ALLOC
}

CGPSControllerNative_android::~CGPSControllerNative_android()
{
    TRACE_DEALLOC
}

IGPSControllerNative* IGPSControllerNative::create()
{
    IGPSControllerNative* obj = utils::createObject<CGPSControllerNative_android>();
    
    return obj;
}

void CGPSControllerNative_android::initWithDelegate(IGPSControllerNativeDelegate* aDelegate)
{
    mNativeDelegate = aDelegate;
}

void CGPSControllerNative_android::startMonitoring(GPSTargetsId aTarget)
{
    
}

void CGPSControllerNative_android::stopMonitoring(GPSTargetsId aTarget)
{
    
}