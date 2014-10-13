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
#include "CGPSPoint.h"

USING_NS_CC;

#include "android/jni/JniHelper.h"
#include <android/log.h>
#include <jni.h>

const static char* className = "com/test/location/GPSTracker";


CGPSControllerNative_android* inst = 0;

CGPSControllerNative_android::CGPSControllerNative_android()
{
    TRACE_ALLOC
    
    inst = this;
}

CGPSControllerNative_android::~CGPSControllerNative_android()
{
    TRACE_DEALLOC
    
    inst = NULL;
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
    TRACE("CGPSControllerNative_android::startMonitoring");
    
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, className, "nativeStartMonitoring",
                                        "(I)V"))
	       return;
    

    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, aTarget);

}

void CGPSControllerNative_android::stopMonitoring(GPSTargetsId aTarget)
{
    
}

extern "C"
{
    void Java_com_test_location_GPSTracker_nativeDidLocationChanged(JNIEnv* env, jobject thiz, jdouble aLatitude, jdouble aLongitude, jdouble aAltitude)
    {
        
        CGPSPoint point(aLatitude, aLongitude, aAltitude);
        
        if(inst)
            inst->getNativeDelegate()->onDidChangeCoordinate(eGPSMyLocationId, point);
    }
    
//    void Java_com_test_location_GPSTraker_nativeDidLocationChanged(JNIEnv* env, jobject thiz, jint aLatitude, jint aLongitude, jint aAltitude)
//    {
//        CGPSPoint point(aLatitude, aLongitude, aAltitude);
//        
//        if(inst)
//            inst->getNativeDelegate()->onDidChangeCoordinate(eGPSMyLocationId, point);
//    }
}