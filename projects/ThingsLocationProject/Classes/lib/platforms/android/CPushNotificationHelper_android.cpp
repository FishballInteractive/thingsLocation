
#include "CPushNotificationHelper_android.h"
#include "Log.h"

#include "android/jni/JniHelper.h"
#include <android/log.h>
#include <jni.h>

const static char* className = "com/test/location/CPushJavaHelper";


CPushNotificationHelper_android::CPushNotificationHelper_android()
{
    TRACE_ALLOC
    
}

CPushNotificationHelper_android::~CPushNotificationHelper_android()
{
    TRACE_DEALLOC
}

IPushNotificationHelper* IPushNotificationHelper::create()
{
    return new CPushNotificationHelper_android();
}

void CPushNotificationHelper_android::registrationPushNotification(IPushNotification* aNotification)
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, className, "nativeRegisterPush",
                                        "(Ljava/lang/String;II)V"))
        return;
    
   
    jstring jData = methodInfo.env->NewStringUTF(aNotification->getMessage().c_str());
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jData, aNotification->getScheduleTime(), aNotification->getPushId());
    
    methodInfo.env->DeleteLocalRef(jData);
}

void CPushNotificationHelper_android::unregistrationAllPushNotification()
{
    
}

void CPushNotificationHelper_android::unregistrationPushNotification(IPushNotification* aNotification)
{
    int push_id = aNotification->getPushId();
    
    unregistrationPushNotification(push_id);
}

std::vector<int> CPushNotificationHelper_android::getActivePushNotification()
{
    std::vector<int> push_ids;
   
    return push_ids;
}

void CPushNotificationHelper_android::startServerPush()
{
   
}

void CPushNotificationHelper_android::resume()
{
    
}

void CPushNotificationHelper_android::unregistrationPushNotification(int aPushId)
{
    
}