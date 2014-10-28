
#ifndef _INotificationCenter_h
#define _INotificationCenter_h

#include "cocos2d.h"
#include "INotificationObserver.h"


class INotificationCenter
{
public:
    virtual ~INotificationCenter() {}
    
    virtual void notify(int aEvent, cocos2d::CCObject* aParam = 0) = 0;
    
    virtual void addObserver(int aEvent, INotificationObserver* aObserver) = 0;
    
    virtual void removeObserver(int aEvent, INotificationObserver* aObserver) = 0;
    
    virtual void removeObserver(INotificationObserver* aObserver) = 0;

    virtual void removeObserversByEvent(int aEvent) = 0;
    
    virtual void removeAllObserver() = 0;
};

#endif
