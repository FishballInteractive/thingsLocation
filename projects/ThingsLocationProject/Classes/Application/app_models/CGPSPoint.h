//
//  CGPSPoint.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#ifndef __ThingsLocationProject__CGPSPoint__
#define __ThingsLocationProject__CGPSPoint__

#include "cocos2d.h"

class CGPSPoint
    : public cocos2d::CCObject
{
public:
    CGPSPoint(double aLatitude, double mLongitude, double mAltitude);
    
    CGPSPoint(const std::string& aPointStr);
    
    CGPSPoint(const CGPSPoint& aVal);
    
    CGPSPoint();
    
    virtual ~CGPSPoint();
    
    std::string toString();
    
    CGPSPoint operator=(const CGPSPoint& aVal);
    
private:
    bool parseStringFormat(const std::string& aPointStr);
        
    CC_SYNTHESIZE(double, mLatitude, Latitude);
    
    CC_SYNTHESIZE(double, mLongitude, Longitude);
    
    CC_SYNTHESIZE(double, mAltitude, Altitude);
    
    CC_SYNTHESIZE_READONLY(bool, mIsValid, IsValid);
};

#endif /* defined(__ThingsLocationProject__CGPSPoint__) */
