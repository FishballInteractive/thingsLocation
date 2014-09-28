//
//  IGPSManager.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#ifndef ThingsLocationProject_IGPSManager_h
#define ThingsLocationProject_IGPSManager_h

#include "GPSTargetsId.h"

class IGPSObserver;

class IGPSManager
{
public:
    virtual ~IGPSManager() {}
    
    virtual void init() = 0;
    
    virtual void startMonitoring(GPSTargetsId aTarget) = 0;
    
    virtual void stopMonitoring(GPSTargetsId aTarget) = 0;
    
    virtual void addObserver(GPSTargetsId aTarget, IGPSObserver* aObserver) = 0;
    
    virtual void removeObserver(GPSTargetsId aTarget, IGPSObserver* aObserver) = 0;
};

#endif
