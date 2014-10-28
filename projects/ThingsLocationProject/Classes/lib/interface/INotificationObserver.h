
#ifndef _INotificationObserver_h
#define _INotificationObserver_h

#include "cocos2d.h"

class INotificationCenter;

class INotificationObserver
{
public:
    virtual ~INotificationObserver(){}
    
    virtual void handleNotification(INotificationCenter* aNotificationCenter,int aEvent, cocos2d::CCObject* aParam = 0) = 0;
};

#endif
