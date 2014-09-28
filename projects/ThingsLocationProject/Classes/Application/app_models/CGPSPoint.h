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
    CGPSPoint(int aWidth, int mHeight, int mLenght);
    
    CGPSPoint(const std::string& aPointStr);
    
    CGPSPoint(const CGPSPoint& aVal);
    
    CGPSPoint();
    
    virtual ~CGPSPoint();
    
    std::string toString();
    
    const CGPSPoint& operator=(const CGPSPoint& aVal);
    
private:
    bool parseStringFormat(const std::string& aPointStr);
        
    CC_SYNTHESIZE(int, mWidth, Width);
    
    CC_SYNTHESIZE(int, mHeight, Height);
    
    CC_SYNTHESIZE(int, mLenght, Lenght);
    
};

#endif /* defined(__ThingsLocationProject__CGPSPoint__) */
