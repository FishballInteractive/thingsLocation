//
//  CAppData.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#ifndef __ThingsLocationProject__CAppData__
#define __ThingsLocationProject__CAppData__

#include "cocos2d.h"
#include "CGPSPoint.h"

class CAppData
    : public cocos2d::CCObject
{
public:
    CAppData();
    
    virtual ~CAppData();
    
    void setKeyCoordinate(const CGPSPoint& aPoint);
    
    void setCarCoordinate(const CGPSPoint& aPoint);
    
    void setMyCoordinate(const CGPSPoint& aPoint);
    
private:
    CC_SYNTHESIZE_READONLY(CGPSPoint, mKeyCoordinate, KeyCoordinate)
    
    CC_SYNTHESIZE_READONLY(CGPSPoint, mCarCoordinate, CarCoordinate)
    
    CC_SYNTHESIZE_READONLY(CGPSPoint, mMyCoordinate, MyCoordinate)
    
    CC_SYNTHESIZE(bool, mIsTakeKey, IsTakeKey)
};

#endif /* defined(__ThingsLocationProject__CAppData__) */
