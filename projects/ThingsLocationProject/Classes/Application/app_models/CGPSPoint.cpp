//
//  CGPSPoint.cpp
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#include "CGPSPoint.h"
#include "Utils.h"
#include "Log.h"

USING_NS_CC;

CGPSPoint::CGPSPoint(int aWidth, int aHeight, int aLenght)
: mHeight(mHeight)
, mWidth(mWidth)
, mLenght(aLenght)
{
    TRACE_ALLOC
}

CGPSPoint::CGPSPoint(const std::string& aPointStr)
: mHeight(0)
, mWidth(0)
, mLenght(0)
{
    TRACE_ALLOC
    
    parseStringFormat(aPointStr);
}

CGPSPoint::CGPSPoint(const CGPSPoint& aVal)
: mHeight(0)
, mWidth(0)
, mLenght(0)
{
    TRACE_ALLOC
    
    mHeight = aVal.getHeight();
    mWidth = aVal.getWidth();
    mLenght = aVal.getLenght();
}

CGPSPoint::CGPSPoint()
: mHeight(0)
, mWidth(0)
, mLenght(0)
{
    TRACE_ALLOC
}

CGPSPoint::~CGPSPoint()
{
    TRACE_DEALLOC
}

std::string CGPSPoint::toString()
{
    std::string str_format = utils::stringWithFormat("%d.%d.%d", mWidth, mLenght, mHeight);
    
    return str_format;
}

const CGPSPoint& CGPSPoint::operator=(const CGPSPoint& aVal)
{
    mHeight = aVal.getHeight();
    mWidth = aVal.getWidth();
    mLenght = aVal.getLenght();
    
    return *this;
}


bool CGPSPoint::parseStringFormat(const std::string& aPointStr)
{
    bool is_valid = false;
    
    int tmp_w = 0;
    int tmp_h = 0;
    int tmp_l = 0;
    
    if(aPointStr != "")
    {
    
    }
    
    return is_valid;
}