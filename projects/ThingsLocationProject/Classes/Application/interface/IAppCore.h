//
//  IAppCore.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 9/28/14.
//
//

#ifndef ThingsLocationProject_IAppCore_h
#define ThingsLocationProject_IAppCore_h

class CAppData;
class IGPSManager;

class IAppCore
{
public:
    virtual ~IAppCore() {};
    
    virtual CAppData* getAppData() = 0;
    
    virtual IGPSManager* getGPSManager() = 0;
};

#endif
