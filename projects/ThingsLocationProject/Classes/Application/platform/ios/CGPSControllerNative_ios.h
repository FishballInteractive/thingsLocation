//
//  CGPSControllerNative_ios.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 10/5/14.
//
//

#ifndef __ThingsLocationProject__CGPSControllerNative_ios__
#define __ThingsLocationProject__CGPSControllerNative_ios__

#include "IGPSControllerNative.h"
#include "cocos2d.h"

class CGPSControllerNative_ios
    : public cocos2d::CCObject
    , public IGPSControllerNative
{
public:
    CGPSControllerNative_ios();
    
    virtual ~CGPSControllerNative_ios();
        
    virtual void initWithDelegate(IGPSControllerNativeDelegate* aDelegate);
    
    virtual void startMonitoring(GPSTargetsId aTarget);
    
    virtual void stopMonitoring(GPSTargetsId aTarget);
    
private:
    IGPSControllerNativeDelegate* mNativeDelegate;
};

#endif /* defined(__ThingsLocationProject__CGPSControllerNative_ios__) */
