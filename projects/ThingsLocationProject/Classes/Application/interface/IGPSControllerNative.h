//
//  IGPSControllerNative.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#ifndef ThingsLocationProject_IGPSControllerNative_h
#define ThingsLocationProject_IGPSControllerNative_h

#include "GPSTargetsId.h"

class CGPSPoint;

class IGPSControllerNativeDelegate
{
public:
    virtual ~IGPSControllerNativeDelegate() {};
    
    virtual void onDidChangeCoordinate(GPSTargetsId aTarget, const CGPSPoint& aNewPoint) = 0;
};

class IGPSControllerNative
{
public:
    static IGPSControllerNative* create();
    
    virtual ~IGPSControllerNative() {}
    
    virtual void initWithDelegate(IGPSControllerNativeDelegate* aDelegate) = 0;
    
    virtual void startMonitoring(GPSTargetsId aTarget) = 0;
    
    virtual void stopMonitoring(GPSTargetsId aTarget) = 0;
};

#endif
