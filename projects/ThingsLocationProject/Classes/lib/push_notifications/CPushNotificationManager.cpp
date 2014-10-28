
#include "CPushNotificationManager.h"
#include "Utils.h"
#include "Log.h"
#include "CPushNotification.h"
#include <algorithm>

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "CPushNotificationHelper_ios.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "CPushNotificationHelper_android.h"
#endif

USING_NS_CC;

CPushNotificationManager::CPushNotificationManager()
: mNotificationHelper(0)
{
    TRACE_ALLOC
}

CPushNotificationManager::~CPushNotificationManager()
{
    TRACE_DEALLOC
    
    CC_SAFE_DELETE(mNotificationHelper);
}

void CPushNotificationManager::init()
{
    mNotificationHelper = IPushNotificationHelper::create();
    
    resume();
    unregistrationAllPushNotification();
}

IPushNotification* CPushNotificationManager::registrationPushNotification(const SPushData& aData)
{
    IPushNotification* notification = utils::createObject<CPushNotification>();
    notification->initWithData(aData);
    
    mNotificationHelper->registrationPushNotification(notification);
    
    addToMap(notification);
    
    return notification;
}

void CPushNotificationManager::addToMap(IPushNotification* aNotification, bool aIsSave)
{
    utils::retainObject(aNotification);
    mMapActiveNotifications.insert(std::pair<int, IPushNotification*>(aNotification->getPushId(), aNotification));
}

void CPushNotificationManager::removeFromMap(IPushNotification* aNotification, bool aIsSave)
{
    std::map<int, IPushNotification*>::iterator it = mMapActiveNotifications.find(aNotification->getPushId());
    
    if(it != mMapActiveNotifications.end())
    {
        mMapActiveNotifications.erase(it);
        utils::releaseObject(aNotification);
    }
}

void CPushNotificationManager::activateServerPush()
{
    
}

void CPushNotificationManager::resume()
{
    std::vector<int> ids = mNotificationHelper->getActivePushNotification();
    std::vector<IPushNotification*> need_remove;
    
    for(std::map<int, IPushNotification*>::iterator it = mMapActiveNotifications.begin(); it != mMapActiveNotifications.end(); it++)
    {
        std::vector<int>::iterator it_find = std::find(ids.begin(), ids.end(), it->first);
        
        if(it_find == ids.end())
        {
            need_remove.push_back(it->second);
        }
    }
    
    for(std::vector<IPushNotification*>::iterator it = need_remove.begin(); it != need_remove.end(); it++)
    {
        removeFromMap(*it,false);
    }
    
    mNotificationHelper->resume();
}

IPushNotification* CPushNotificationManager::registrationPushNotification(CValue* aData)
{
    IPushNotification* notification = utils::createObject<CPushNotification>();
    notification->initWithData(aData);
    
    mNotificationHelper->registrationPushNotification(notification);
    
    addToMap(notification);
    
    return notification;
}

void CPushNotificationManager::unregistrationPushNotification(IPushNotification* aNotification)
{
    mNotificationHelper->unregistrationPushNotification(aNotification);
    removeFromMap(aNotification);
}

void CPushNotificationManager::unregistrationPushNotification(int aPushId)
{
    IPushNotification* notification = getPushNotificationById(aPushId);
    unregistrationPushNotification(notification);
}

void CPushNotificationManager::unregistrationAllPushNotification()
{
    mNotificationHelper->unregistrationAllPushNotification();
    
    std::vector<IPushNotification*> need_remove;
    
    for(std::map<int, IPushNotification*>::iterator it = mMapActiveNotifications.begin(); it != mMapActiveNotifications.end(); it++)
    {
        need_remove.push_back(it->second);
    }
    
    for(std::vector<IPushNotification*>::iterator it = need_remove.begin(); it != need_remove.end(); it++)
    {
        removeFromMap(*it,false);
    }
}

IPushNotification* CPushNotificationManager::getPushNotificationById(int aPushId)
{
    std::map<int, IPushNotification*>::iterator it = mMapActiveNotifications.find(aPushId);
    
    if(it != mMapActiveNotifications.end())
    {
        return it->second;
    }
    
    return NULL;
}
