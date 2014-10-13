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
    
private:
    CC_SYNTHESIZE(CGPSPoint, mKeyCoordinate, KeyCoordinate)
    
    CC_SYNTHESIZE(CGPSPoint, mCarCoordinate, CarCoordinate)
    
    CC_SYNTHESIZE(CGPSPoint, mMyCoordinate, MyCoordinate)
    
    CC_SYNTHESIZE(bool, mIsTakeKey, IsTakeKey)
};

#endif /* defined(__ThingsLocationProject__CAppData__) */
