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
#include "cocos-ext.h"
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
    , public cocos2d::CCTextFieldDelegate
{
public:
    CMainScreenView();
    
    virtual ~CMainScreenView();
    
    virtual bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF * sender);
    
    virtual bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF * sender);
    
    virtual bool onTextFieldInsertText(cocos2d::CCTextFieldTTF * sender, const char * text, int nLen);
    
    virtual bool onTextFieldDeleteBackward(cocos2d::CCTextFieldTTF * sender, const char * delText, int nLen);
    
    static CMainScreenView* create(IMainScreenDataProtocol* aProtocol, IMainScreenViewDelegate* aDelegate);
    
    bool initWithProtocol(IMainScreenDataProtocol* aProtocol, IMainScreenViewDelegate* aDelegate);
    
    void onBtnClick(cocos2d::CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    
    void doUpdateView();
    
private:
    void closeTextField();
    
    cocos2d::CCNode* createCoordinateNode(const std::string& aDescrText);
    
    IMainScreenDataProtocol* mDataProtocol;
    
    std::vector<cocos2d::CCTextFieldTTF*> mCoordinateLabels;
    
    cocos2d::CCTextFieldTTF* mCurrentOpen;
};

#endif /* defined(__ThingsLocationProject__CMainScreenView__) */
