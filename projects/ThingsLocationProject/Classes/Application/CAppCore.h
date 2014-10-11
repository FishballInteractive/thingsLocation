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
    
private:
    CAppData* mAppData;
    
    IGPSManager* mGPSManager;
};

#endif /* defined(__ThingsLocationProject__CAppCore__) */
