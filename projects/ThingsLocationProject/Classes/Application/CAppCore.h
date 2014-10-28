//
//  CAppCore.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#ifndef __ThingsLocationProject__CAppCore__
#define __ThingsLocationProject__CAppCore__

#include "IAppCore.h"
#include "cocos2d.h"
#include "CAppData.h"
#include "IGPSManager.h"
#include "CPushNotificationManager.h"
#include "INotificationCenter.h"

class CAppCore
    : public cocos2d::CCObject
    , public IAppCore
{
    CAppCore();
public:
    virtual ~CAppCore();
    
    virtual bool init();
    
    static CAppCore* shared();
    
    virtual CAppData* getAppData();
    
    virtual IGPSManager* getGPSManager();
    
    virtual INotificationCenter* getNotificationCenter();
    
    virtual CPushNotificationManager* getPushNotificationManager();
    
private:
    CC_SYNTHESIZE(bool, mIsBackground, IsBackground)
    
    INotificationCenter* mNotificationCenter;
    
    CAppData* mAppData;
    
    IGPSManager* mGPSManager;
    
    CPushNotificationManager* mPushNotificationManager;
};

#endif /* defined(__ThingsLocationProject__CAppCore__) */
