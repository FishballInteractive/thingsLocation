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

class CMainScreenView
    : public cocos2d::CCLayer
{
public:
    CMainScreenView();
    
    virtual ~CMainScreenView();
    
    static CMainScreenView* create(IMainScreenDataProtocol* aProtocol);
    
    bool initWithProtocol(IMainScreenDataProtocol* aProtocol);
    
    void doUpdateView();
    
private:
    cocos2d::CCNode* createCoordinateNode(const std::string& aDescrText);
    
    IMainScreenDataProtocol* mDataProtocol;
    
    std::vector<cocos2d::CCLabelTTF*> mCoordinateLabels;
};

#endif /* defined(__ThingsLocationProject__CMainScreenView__) */
