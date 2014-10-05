//
//  CGPSManager.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#ifndef __ThingsLocationProject__CGPSManager__
#define __ThingsLocationProject__CGPSManager__

#include "cocos2d.h"
#include "IGPSManager.h"
#include "IGPSControllerNative.h"
#include "IGPSObserver.h"

class CGPSManager
    : public cocos2d::CCObject
    , public IGPSManager
    , public IGPSControllerNativeDelegate
{
public:
    CGPSManager();
    
    virtual ~CGPSManager();
    
    virtual void init();
    
    virtual void startMonitoring(GPSTargetsId aTarget);
    
    virtual void stopMonitoring(GPSTargetsId aTarget);
    
    virtual void addObserver(GPSTargetsId aTarget, IGPSObserver* aObserver);
    
    virtual void removeObserver(GPSTargetsId aTarget, IGPSObserver* aObserver);
    
    virtual void onDidChangeCoordinate(GPSTargetsId aTarget, const CGPSPoint& aNewPoint);
    
private:
    std::map<GPSTargetsId , std::vector<IGPSObserver*> > mObservers;
    
    std::vector<int> mActiveMonitoring;
    
    IGPSControllerNative* mNativeController;
};

#endif /* defined(__ThingsLocationProject__CGPSManager__) */
