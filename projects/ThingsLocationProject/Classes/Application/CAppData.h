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
    
    friend class CAppCore;
private:
    CC_SYNTHESIZE_READONLY(CGPSPoint, mKeyCoordinate, KeyCoordinate)
    
    CC_SYNTHESIZE_READONLY(CGPSPoint, mCarCoordinate, CarCoordinate)
    
    CC_SYNTHESIZE_READONLY(CGPSPoint, mMyCoordinate, MyCoordinate)
};

#endif /* defined(__ThingsLocationProject__CAppData__) */
