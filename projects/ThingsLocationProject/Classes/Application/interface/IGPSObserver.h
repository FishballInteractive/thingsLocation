//
//  IGPSObserver.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#ifndef ThingsLocationProject_IGPSObserver_h
#define ThingsLocationProject_IGPSObserver_h

#include "cocos2d.h"
#include "CGPSPoint.h"
#include "GPSTargetsId.h"

class IGPSObserver
{
public:
    virtual ~IGPSObserver() {}
    
    virtual void onDidChangeCoordinate(GPSTargetsId aTarget, const CGPSPoint& aNewPoint) = 0;
};

#endif
