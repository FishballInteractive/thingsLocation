//
//  CMainScreenView.h
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 10/11/14.
//
//

#ifndef __ThingsLocationProject__CMainScreenView__
#define __ThingsLocationProject__CMainScreenView__

#include "cocos2d.h"
#include "IMainScreenDataProtocol.h"

class IMainScreenViewDelegate
{
public:
    virtual ~IMainScreenViewDelegate() {}
    
    virtual void onDidSetNewCarCoordinate(const std::string& aCoordinate) = 0;
    
    virtual void onDidSetNewKeyCoordinate(const std::string& aCoordinate) = 0;
};

class CMainScreenView
    : public cocos2d::CCLayer
{
public:
    CMainScreenView();
    
    virtual ~CMainScreenView();
    
    static CMainScreenView* create(IMainScreenDataProtocol* aProtocol, IMainScreenViewDelegate* aDelegate);
    
    bool initWithProtocol(IMainScreenDataProtocol* aProtocol, IMainScreenViewDelegate* aDelegate);
    
    void doUpdateView();
    
private:
    cocos2d::CCNode* createCoordinateNode(const std::string& aDescrText);
    
    IMainScreenDataProtocol* mDataProtocol;
    
    std::vector<cocos2d::CCLabelTTF*> mCoordinateLabels;
};

#endif /* defined(__ThingsLocationProject__CMainScreenView__) */
