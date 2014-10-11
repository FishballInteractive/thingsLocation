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
    
    virtual const CGPSPoint* getKeyCoordinate() = 0;
    
    virtual const CGPSPoint* getMyCoordinate() = 0;
    
    virtual const CGPSPoint* getCarCoordinate() = 0;
};

#endif
