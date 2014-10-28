//
//  CMainScreenView.cpp
//  ThingsLocationProject
//
//  Created by Kirill_Mag on 10/11/14.
//
//

#include "CMainScreenView.h"
#include "Log.h"
#include "Utils.h"
#include "CGPSPoint.h"
#include "cocos-ext.h"
#include "CAppCore.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define TAG_LABEL_COORDINATE 12

enum EOrderNode
{
    eBgOrder = 0,
    eLabelNodeOrder = 1,
    eButtonOrder = 2
};

enum ELabelIndex
{
    eCarLabelIndex = 0,
    eKeyLabelIndex,
    eMyLabelIndex,
    eLabelIndexCount
};
CMainScreenView::CMainScreenView()
: mDataProtocol(0)
, mCurrentOpen(0)
{
    TRACE_ALLOC
}

CMainScreenView::~CMainScreenView()
{
    TRACE_DEALLOC
    
    utils::releaseObject(mDataProtocol);
}

bool CMainScreenView::onTextFieldAttachWithIME(CCTextFieldTTF * sender)
{
    sender->setString("");
    
    return false;
}


bool CMainScreenView::onTextFieldDetachWithIME(CCTextFieldTTF * sender)
{
    int tag = sender->getTag();
    
    switch (tag)
    {
        case eCarLabelIndex:
        {
            std::string str = sender->getString();
            mDataProtocol->onInputCarCoordinate(str);
        }
            break;
            
        case eKeyLabelIndex:
        {
            std::string str = sender->getString();
            mDataProtocol->onInputKeyCoordinate(str);
        }
            break;

            
        default:
            break;
    }
    return false;
}


bool CMainScreenView::onTextFieldInsertText(CCTextFieldTTF * sender, const char * text, int nLen)
{

    return false;
}


bool CMainScreenView::onTextFieldDeleteBackward(CCTextFieldTTF * sender, const char * delText, int nLen)
{

    return false;
}

CMainScreenView* CMainScreenView::create(IMainScreenDataProtocol* aProtocol, IMainScreenViewDelegate* aDelegate)
{
    CMainScreenView* view = utils::createObject<CMainScreenView>();
    bool res = view->initWithProtocol(aProtocol,aDelegate);
    
    if(res)
    {
        return view;
    }
    
    return NULL;
}

cocos2d::CCNode* CMainScreenView::createCoordinateNode(const std::string& aDescrText)
{
    CCNode* node = CCNode::create();
    CCSprite* bg_input = CCSprite::create("input_field.png");
    
    if (bg_input)
    {
        bg_input->setAnchorPoint(ccp(0.5f,0.5f));
        node->setContentSize(bg_input->getContentSize());
        bg_input->setPosition(ccp(node->getContentSize().width / 2.f, node->getContentSize().height / 2.f));
        node->addChild(bg_input);
    }
    
    CCTextFieldTTF* label_coordinate = CCTextFieldTTF::textFieldWithPlaceHolder("", "", 6.f * CC_CONTENT_SCALE_FACTOR());
    
    if(label_coordinate)
    {
        label_coordinate->setAnchorPoint(ccp(0.5f, 0.5f));
        label_coordinate->setPosition(ccp(node->getContentSize().width / 2.f, node->getContentSize().height / 2.f));
        label_coordinate->setTag(TAG_LABEL_COORDINATE);
        label_coordinate->setDelegate(this);
        node->addChild(label_coordinate);
    }
    
    CCLabelTTF* label_descr = CCLabelTTF::create(aDescrText.c_str(), "", 6.f * CC_CONTENT_SCALE_FACTOR());
    
    if(label_descr)
    {
        label_descr->setPosition(ccp(node->getContentSize().width / 2.f, node->getContentSize().height + label_descr->getContentSize().height / 2.f));
        label_descr->setTag(TAG_LABEL_COORDINATE);
        
        CCSize new_size = node->getContentSize();
        new_size.height = label_descr->getContentSize().height;
        node->setContentSize(new_size);
        node->addChild(label_descr);
    }
    
    
    return node;
}

bool CMainScreenView::initWithProtocol(IMainScreenDataProtocol* aProtocol, IMainScreenViewDelegate* aDelegate)
{
    if(!CCLayer::init())
        return false;
    
    mDataProtocol = aProtocol;
    utils::retainObject(mDataProtocol);
    
    CCSize win_size = CCDirector::sharedDirector()->getWinSize();
    CCSprite* bg_spr = CCSprite::create("bg.jpg");
    CCPoint center_pos = ccp(win_size.width/2.f, win_size.height/2.f);
    
    if(bg_spr)
    {
        bg_spr->setPosition(center_pos);
        this->addChild(bg_spr, eBgOrder);
    }
    
    CCNode* node = NULL;
    mCoordinateLabels.resize(eLabelIndexCount);
    
    std::string text_arr[eLabelIndexCount] =
    {
        "Car's coordinates",
        "Key's coordinates",
        "My coordinates"
    };
    
    CCPoint pos_arr[eLabelIndexCount] =
    {
        ccp(win_size.width * 0.3f, win_size.height * 0.75f),
        ccp(win_size.width * 0.7f, win_size.height * 0.75f),
        ccp(win_size.width * 0.5f, win_size.height * 0.6f)
    };
    
    for(int i = 0; i < eLabelIndexCount; i++)
    {
        node = createCoordinateNode(text_arr[i]);
        
        if(node)
        {
            CCTextFieldTTF* label = dynamic_cast<CCTextFieldTTF*>(node->getChildByTag(TAG_LABEL_COORDINATE));
            
            if(label)
            {
                mCoordinateLabels[i] = label;
                label->setTag(i);
            }
            
            CCPoint pos = pos_arr[i];
            node->setPosition(pos);
            node->setAnchorPoint(ccp(0.5f,0.5f));
            
            extension::CCScale9Sprite* spr = extension::CCScale9Sprite::create("btn_opacity.png");
            
            if(spr)
            {
                cocos2d::extension::CCControlButton* btn = cocos2d::extension::CCControlButton::create(spr);
                CCSize size = node->getContentSize();
                
                btn->setPreferredSize(size);
                btn->setPosition(ccp(size.width/2.f, size.height));

                btn->setTag(i);
                btn->setEnabled(true);
                btn->addTargetWithActionForControlEvents(this, cccontrol_selector(CMainScreenView::onBtnClick), CCControlEventTouchDown);
                
                node->addChild(btn);
            }

            this->addChild(node, eLabelNodeOrder);
        }
    }
    
    return true;
}

void CMainScreenView::onBtnClick(cocos2d::CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent)
{
    TRACE_METHOD
    CCControlButton* btn = dynamic_cast<CCControlButton*>(pSender);
    TRACE_VAR_INT(btn->getTag())
    int tag = btn->getTag();
    
    if(tag == eMyLabelIndex)
        return;
    
    closeTextField();
    
    mCurrentOpen = mCoordinateLabels[tag];
    mCurrentOpen->attachWithIME();

}

void CMainScreenView::closeTextField()
{
    if(mCurrentOpen)
    {
        mCurrentOpen->detachWithIME();
        mCurrentOpen = NULL;
    }
}

void CMainScreenView::doUpdateView()
{
    TRACE_METHOD
    TRACE("CMainScreenView::doUpdateView 1")
    
    if(CAppCore::shared()->getIsBackground())
        return;
    
    TRACE("CMainScreenView::doUpdateView 2")
    std::string str = mDataProtocol->getKeyCoordinate();
    mCoordinateLabels[eKeyLabelIndex]->setString(str.c_str());
    
    str = mDataProtocol->getCarCoordinate();
    mCoordinateLabels[eCarLabelIndex]->setString(str.c_str());
    
    str = mDataProtocol->getMyCoordinate();
    mCoordinateLabels[eMyLabelIndex]->setString(str.c_str());
}