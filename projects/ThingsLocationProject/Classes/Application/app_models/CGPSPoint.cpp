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

CGPSPoint::CGPSPoint(double aLatitude, double aLongitude, double aAltitude)
: mLatitude(aLatitude)
, mLongitude(aLongitude)
, mAltitude(aAltitude)
{
    TRACE_ALLOC
}

CGPSPoint::CGPSPoint(const std::string& aPointStr)
: mLatitude(0)
, mLongitude(0)
, mAltitude(0)
{
    TRACE_ALLOC
    
    parseStringFormat(aPointStr);
}

CGPSPoint::CGPSPoint(const CGPSPoint& aVal)
: mLatitude(0)
, mLongitude(0)
, mAltitude(0)
{
    TRACE_ALLOC
    
    mLatitude = aVal.getLatitude();
    mLongitude = aVal.getLongitude();
    mAltitude = aVal.getAltitude();
    
    TRACE_VAR_INT(mLatitude)
    TRACE_VAR_INT(mLongitude)
    TRACE_VAR_INT(mAltitude)
}

CGPSPoint::CGPSPoint()
: mLatitude(0)
, mLongitude(0)
, mAltitude(0)
{
    TRACE_ALLOC
}

CGPSPoint::~CGPSPoint()
{
    TRACE_DEALLOC
}

std::string CGPSPoint::toString()
{
    std::string str_format = utils::stringWithFormat("%.2lf - %.2lf - %.2lf",mLatitude, mLongitude, mAltitude);
    
    return str_format;
}

CGPSPoint CGPSPoint::operator=(const CGPSPoint& aVal)
{
    mLatitude = aVal.getLatitude();
    mLongitude = aVal.getLongitude();
    mAltitude = aVal.getAltitude();
    
    return *this;
}


bool CGPSPoint::parseStringFormat(const std::string& aPointStr)
{
    bool is_valid = false;
    
    
    return is_valid;
}