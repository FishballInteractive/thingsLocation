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
#include "NoticationEvents.h"

USING_NS_CC;

#define MAX_DISTANCE 10
#define MAX_KEY_DISTANCE 2


CMainScreenController::CMainScreenController()
{
    TRACE_ALLOC
}

CMainScreenController::~CMainScreenController()
{
    TRACE_DEALLOC
}

void CMainScreenController::onExit()
{
    CCScene::onExit();
    CAppCore::shared()->getNotificationCenter()->removeObserver(this);
    
}

CMainScreenController* CMainScreenController::scene()
{
    CMainScreenController* controller = utils::createObject<CMainScreenController>();
    controller->init();
    
    return controller;
}

void CMainScreenController::scheduleFunc(float aTime)
{
    TRACE_METHOD
    mView->doUpdateView();
}

void CMainScreenController::handleNotification(INotificationCenter* aNotificationCenter,int aEvent, cocos2d::CCObject* aParam)
{
    switch (aEvent)
    {
        case eApplicationDidEnterBackground:
        {
            
        }
            break;
            
        case eApplicationWillEnterForeground:
        {
            TRACE("CMainScreenController::handleNotification eApplicationWillEnterForeground")
            this->scheduleOnce(schedule_selector(CMainScreenController::scheduleFunc), 1/60.f);
        }
            break;
            
        default:
            break;
    }
}
bool CMainScreenController::init()
{
    if(!CCScene::init())
        return false;
    
    mView = CMainScreenView::create(this,NULL);
    this->addChild(mView);
    
    CAppCore::shared()->getGPSManager()->addObserver(eGPSMyLocationId, this);

    for(int i = 0; i < eNotificationEventsCount; i++)
    {
        CAppCore::shared()->getNotificationCenter()->addObserver(i, this);
    }
    
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
            
            checkDistance();
            
        }
            break;
            
        default:
            break;
    }
}

void CMainScreenController::checkDistance()
{
    int dist = utils::gpsDistance(CAppCore::shared()->getAppData()->getMyCoordinate(), CAppCore::shared()->getAppData()->getCarCoordinate());
    
    TRACE_VAR_INT(dist);
    
    if(dist < MAX_DISTANCE)
    {
        TRACE("YEEEH");
        int key_dist = utils::gpsDistance(CAppCore::shared()->getAppData()->getMyCoordinate(), CAppCore::shared()->getAppData()->getKeyCoordinate());
        
        
        SPushData push;
        
        if(key_dist > MAX_KEY_DISTANCE)
        {
            push.setMessage("You forgot the keys from car");
        }
        else
        {
            push.setMessage("We wish you good travel");
        }
        
        
        push.setScheduleTime(1);
        push.setPushId(1);
        
        CAppCore::shared()->getPushNotificationManager()->registrationPushNotification(push);
    }
}

void CMainScreenController::onInputKeyCoordinate(const std::string& aStr)
{
    CAppCore::shared()->getAppData()->setKeyCoordinate(aStr);
    
    mView->doUpdateView();
    
    checkDistance();
}

void CMainScreenController::onInputCarCoordinate(const std::string& aStr)
{
    CAppCore::shared()->getAppData()->setCarCoordinate(aStr);
    
    mView->doUpdateView();
    
    checkDistance();
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