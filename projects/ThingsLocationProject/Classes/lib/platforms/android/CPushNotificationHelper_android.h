

#ifndef __CPushNotificationHelper_android__
#define __CPushNotificationHelper_android__

#include "IPushNotificationHelper.h"


class CPushNotificationHelper_android
    : public IPushNotificationHelper
{
public:
    CPushNotificationHelper_android();
    
    virtual ~CPushNotificationHelper_android();
    
    virtual void startServerPush();
    
    virtual void registrationPushNotification(IPushNotification* aNotification);
    
    virtual void unregistrationPushNotification(IPushNotification* aNotification);
    
    virtual void unregistrationPushNotification(int aPushId);
    
    virtual void unregistrationAllPushNotification();
    
    virtual std::vector<int> getActivePushNotification();
    
    virtual void resume();
};

#endif