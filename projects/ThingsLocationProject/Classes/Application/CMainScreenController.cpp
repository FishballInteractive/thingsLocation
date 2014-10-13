//
//  CMainScreenController.cpp
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 10/11/14.
//
//

#include "CMainScreenController.h"
#include "Utils.h"
#include "Log.h"
#include "CAppCore.h"
#include "CGPSPoint.h"

USING_NS_CC;

CMainScreenController::CMainScreenController()
{
    TRACE_ALLOC
}

CMainScreenController::~CMainScreenController()
{
    TRACE_DEALLOC
}

CMainScreenController* CMainScreenController::scene()
{
    CMainScreenController* controller = utils::createObject<CMainScreenController>();
    controller->init();
    
    return controller;
}

bool CMainScreenController::init()
{
    if(!CCScene::init())
        return false;
    
    mView = CMainScreenView::create(this,NULL);
    this->addChild(mView);
    
    CAppCore::shared()->getGPSManager()->addObserver(eGPSMyLocationId, this);

    return true;
}

void CMainScreenController::onEnterTransitionDidFinish()
{
    CCScene::onEnterTransitionDidFinish();
    
    CAppCore::shared()->getGPSManager()->startMonitoring(eGPSMyLocationId);
}

void CMainScreenController::onDidChangeCoordinate(GPSTargetsId aTarget, const CGPSPoint& aNewPoint)
{
    TRACE_METHOD
    
    switch ((int)aTarget)
    {
        case eGPSMyLocationId:
        {
            TRACE("case eGPSMyLocationId:")
            CAppCore::shared()->getAppData()->setMyCoordinate(aNewPoint);
            
            mView->doUpdateView();
        }
            break;
            
        default:
            break;
    }
}

std::string CMainScreenController::getKeyCoordinate()
{
    return CAppCore::shared()->getAppData()->getKeyCoordinate().toString();
}

std::string CMainScreenController::getMyCoordinate()
{
    return CAppCore::shared()->getAppData()->getMyCoordinate().toString();
}

std::string CMainScreenController::getCarCoordinate()
{
    return CAppCore::shared()->getAppData()->getCarCoordinate().toString();
}