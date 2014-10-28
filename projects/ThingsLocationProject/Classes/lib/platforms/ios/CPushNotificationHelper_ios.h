

#ifndef __CPushNotificationHelper_ios__
#define __CPushNotificationHelper_ios__

#include "IPushNotificationHelper.h"


class CPushNotificationHelper_ios
    : public IPushNotificationHelper
{
public:
    CPushNotificationHelper_ios();
    
    virtual ~CPushNotificationHelper_ios();
    
    virtual void startServerPush();
    
    virtual void registrationPushNotification(IPushNotification* aNotification);
    
    virtual void unregistrationPushNotification(IPushNotification* aNotification);
    
    virtual void unregistrationPushNotification(int aPushId);
    
    virtual void unregistrationAllPushNotification();
    
    virtual std::vector<int> getActivePushNotification();
    
    virtual void resume();
};

#endif