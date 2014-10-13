//
//  CGPSControllerNative_android.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 10/5/14.
//
//

#ifndef __ThingsLocationProject__CGPSControllerNative_android__
#define __ThingsLocationProject__CGPSControllerNative_android__

#include "IGPSControllerNative.h"
#include "cocos2d.h"

class CGPSControllerNative_android
    : public cocos2d::CCObject
    , public IGPSControllerNative
{
public:
    CGPSControllerNative_android();
    
    virtual ~CGPSControllerNative_android();
        
    virtual void initWithDelegate(IGPSControllerNativeDelegate* aDelegate);
    
    virtual void startMonitoring(GPSTargetsId aTarget);
    
    virtual void stopMonitoring(GPSTargetsId aTarget);
    
private:
    CC_SYNTHESIZE_READONLY(IGPSControllerNativeDelegate*, mNativeDelegate, NativeDelegate);
};

#endif /* defined(__ThingsLocationProject__CGPSControllerNative_android__) */
