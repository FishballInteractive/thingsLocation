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

USING_NS_CC;

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
{
    TRACE_ALLOC
}

CMainScreenView::~CMainScreenView()
{
    TRACE_DEALLOC
    
    utils::releaseObject(mDataProtocol);
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
    
    CCLabelTTF* label_coordinate = CCLabelTTF::create("192.168.122", "", 6.f * CC_CONTENT_SCALE_FACTOR());
    
    if(label_coordinate)
    {
        label_coordinate->setAnchorPoint(ccp(0.5f, 0.5f));
        label_coordinate->setPosition(ccp(node->getContentSize().width / 2.f, node->getContentSize().height / 2.f));
        label_coordinate->setTag(TAG_LABEL_COORDINATE);
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
            CCLabelTTF* label = dynamic_cast<CCLabelTTF*>(node->getChildByTag(TAG_LABEL_COORDINATE));
            
            if(label)
            {
                mCoordinateLabels[i] = label;
            }
            
            CCPoint pos = pos_arr[i];
            node->setPosition(pos);
            node->setAnchorPoint(ccp(0.5f,0.5f));
            
            this->addChild(node, eLabelNodeOrder);
        }
    }
    
    return true;
}

void CMainScreenView::doUpdateView()
{
    TRACE_METHOD
    
    std::string str = mDataProtocol->getKeyCoordinate();
    mCoordinateLabels[eKeyLabelIndex]->setString(str.c_str());
    
    str = mDataProtocol->getCarCoordinate();
    mCoordinateLabels[eCarLabelIndex]->setString(str.c_str());
    
    str = mDataProtocol->getMyCoordinate();
    mCoordinateLabels[eMyLabelIndex]->setString(str.c_str());
}