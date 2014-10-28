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
, mIsValid(true)
{
    TRACE_ALLOC
}

CGPSPoint::CGPSPoint(const std::string& aPointStr)
: mLatitude(0)
, mLongitude(0)
, mAltitude(0)
, mIsValid(true)
{
    TRACE_ALLOC
    
    mIsValid = parseStringFormat(aPointStr);
    
    TRACE_VAR_INT(mIsValid)
    TRACE_VAR_FLOAT(mLatitude)
    TRACE_VAR_FLOAT(mLongitude)
    TRACE_VAR_FLOAT(mAltitude)
}

CGPSPoint::CGPSPoint(const CGPSPoint& aVal)
: mLatitude(0)
, mLongitude(0)
, mAltitude(0)
, mIsValid(true)
{
    TRACE_ALLOC
    
    mLatitude = aVal.getLatitude();
    mLongitude = aVal.getLongitude();
    mAltitude = aVal.getAltitude();
}

CGPSPoint::CGPSPoint()
: mLatitude(0)
, mLongitude(0)
, mAltitude(0)
, mIsValid(true)
{
    TRACE_ALLOC
}

CGPSPoint::~CGPSPoint()
{
    TRACE_DEALLOC
}

std::string CGPSPoint::toString()
{
    std::string str_format = utils::stringWithFormat("%.2lf:%.2lf:%.2lf",mLatitude, mLongitude, mAltitude);
    
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
    int current_index = 0;
    int end_index = aPointStr.size();
    int index = current_index;
    int count = 0;
    std::string str_copy = aPointStr;
    
    while (index != -1)
    {
        index = str_copy.find(":", current_index);
        
        if(index != -1)
        {
            std::string str = str_copy.substr(current_index,index);
            
            switch (count)
            {
                case 0:
                {
                    mLatitude = atof(str.c_str());
                }
                    break;
                    
                case 1:
                {
                    mLongitude = atof(str.c_str());
                }
                    break;
                    
                case 2:
                {
                    mAltitude = atof(str.c_str());
                }
                    break;
                    
                default:
                    break;
            }

            str_copy.erase(current_index, index+1);
            count++;
        }
        else
        {
            std::string str = str_copy;
            
            switch (count)
            {
                case 0:
                {
                    mLatitude = atof(str.c_str());
                }
                    break;
                    
                case 1:
                {
                    mLongitude = atof(str.c_str());
                }
                    break;
                    
                case 2:
                {
                    mAltitude = atof(str.c_str());
                }
                    break;
                    
                default:
                    break;
            }
            
            count++;
        }
    }
    
    is_valid = (count == 3);
    
    return is_valid;
}