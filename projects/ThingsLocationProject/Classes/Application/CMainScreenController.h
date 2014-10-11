//
//  CMainScreenController.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 10/11/14.
//
//

#ifndef __ThingsLocationProject__CMainScreenController__
#define __ThingsLocationProject__CMainScreenController__

#include "cocos2d.h"
#include "CMainScreenView.h"
#include "IGPSObserver.h"

class CMainScreenController
    : public cocos2d::CCScene
    , public IGPSObserver
    , public IMainScreenDataProtocol
{
public:
    CMainScreenController();
    
    virtual ~CMainScreenController();
    
    static CMainScreenController* scene();
    
    virtual bool init();
    
    virtual void onDidChangeCoordinate(GPSTargetsId aTarget, const CGPSPoint& aNewPoint);
    
    virtual const CGPSPoint* getKeyCoordinate();
    
    virtual const CGPSPoint* getMyCoordinate();
    
    virtual const CGPSPoint* getCarCoordinate();
private:
    CMainScreenView* mView;
};

#endif /* defined(__ThingsLocationProject__CMainScreenController__) */