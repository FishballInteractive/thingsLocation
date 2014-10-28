//
//  IMainScreenDataProtocol.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 10/11/14.
//
//

#ifndef ThingsLocationProject_IMainScreenDataProtocol_h
#define ThingsLocationProject_IMainScreenDataProtocol_h

#include "CGPSPoint.h"

class IMainScreenDataProtocol
{
public:
    virtual ~IMainScreenDataProtocol() {}
    
    virtual std::string getKeyCoordinate() = 0;
    
    virtual std::string getMyCoordinate() = 0;
    
    virtual std::string getCarCoordinate() = 0;
    
    virtual void onInputKeyCoordinate(const std::string& aStr) = 0;
    
    virtual void onInputCarCoordinate(const std::string& aStr) = 0;
};

#endif
