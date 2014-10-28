
#ifndef __CPushNotificationManager__
#define __CPushNotificationManager__

#include "cocos2d.h"
#include <map>
#include "IPushNotification.h"
#include "IPushNotificationHelper.h"

class CPushNotificationManager
    : public cocos2d::CCObject
{
public:
    CPushNotificationManager();
    
    virtual ~CPushNotificationManager();
    
    void init();
    
    void activateServerPush();
    
    IPushNotification* registrationPushNotification(const SPushData& aData);
    
    IPushNotification* registrationPushNotification(CValue* aData);
    
    void unregistrationPushNotification(IPushNotification* aNotification);
    
    void unregistrationPushNotification(int aPushId);
    
    void unregistrationAllPushNotification();
    
    IPushNotification* getPushNotificationById(int aPushId);
    
    std::vector<IPushNotification*> getAllActiveNotifications();
    
    void resume();
    
private:
    void addToMap(IPushNotification* aNotification, bool aIsSave = true);
    
    void removeFromMap(IPushNotification* aNotification, bool aIsSave = true);
    
    std::map<int, IPushNotification*> mMapActiveNotifications;
    
    IPushNotificationHelper* mNotificationHelper;
};

#endif /* defined(__CPushNotificationManager__) */
