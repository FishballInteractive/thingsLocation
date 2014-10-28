

#ifndef __CNotificationCenter__
#define __CNotificationCenter__

#include "INotificationCenter.h"
#include <map>
#include <set>

class CNotificationCenter
    : public cocos2d::CCObject
    , public INotificationCenter
{
public:
    CNotificationCenter();

    virtual ~CNotificationCenter();

    virtual void notify(int aEvent, CCObject* aParam);

    virtual void addObserver(int aEvent, INotificationObserver* aObserver);

    virtual void removeObserver(int aEvent, INotificationObserver* aObserver);

    virtual void removeObserver(INotificationObserver* aObserver);

    virtual void removeObserversByEvent(int aEvent);

    virtual void removeAllObserver();

private:
    std::map< int,std::set<INotificationObserver*>* >    mObservers;
};

#endif /* defined(__CNotificationCenter__) */
