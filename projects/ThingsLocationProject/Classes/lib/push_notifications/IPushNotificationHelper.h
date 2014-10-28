
#ifndef _IPushNotificationHelper_h
#define _IPushNotificationHelper_h

#include "IPushNotification.h"

class IPushNotificationHelper
{
public:
    virtual ~IPushNotificationHelper() {}
    
    static IPushNotificationHelper* create();
    
    virtual void startServerPush() = 0;
    
    virtual void registrationPushNotification(IPushNotification* aNotification) = 0;
    
    virtual void unregistrationPushNotification(IPushNotification* aNotification) = 0;
    
    virtual void unregistrationPushNotification(int aPushId) = 0;
    
    virtual void unregistrationAllPushNotification() = 0;
    
    virtual std::vector<int> getActivePushNotification() = 0;
    
    virtual void resume() = 0;
};

#endif
