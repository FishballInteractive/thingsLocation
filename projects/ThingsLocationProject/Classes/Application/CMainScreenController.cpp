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
    
    mView = CMainScreenView::create(this);
    this->addChild(mView);
    
//    CAppCore::shared()->getGPSManager()->addObserver(eGPSMyLocationId, this);

    return true;
}

void CMainScreenController::onDidChangeCoordinate(GPSTargetsId aTarget, const CGPSPoint& aNewPoint)
{
    switch ((int)aTarget)
    {
        case eGPSMyLocationId:
        {
            
        }
            break;
            
        default:
            break;
    }
}

const CGPSPoint* CMainScreenController::getKeyCoordinate()
{
    return CAppCore::shared()->getAppData()->getKeyCoordinate();
}

const CGPSPoint* CMainScreenController::getMyCoordinate()
{
    return CAppCore::shared()->getAppData()->getMyCoordinate();
}

const CGPSPoint* CMainScreenController::getCarCoordinate()
{
    return CAppCore::shared()->getAppData()->getCarCoordinate();
}