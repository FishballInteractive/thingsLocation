#include "AppDelegate.h"

#include <vector>
#include <string>

#include "AppMacros.h"
#include "CCEGLView.h"
#include "cocos-ext.h"
#include "Log.h"

#include "Utils.h"

USING_NS_CC;
USING_NS_CC_EXT;


using namespace std;

AppDelegate::AppDelegate()
{
    TRACE_ALLOC
}

AppDelegate::~AppDelegate() 
{
    TRACE_DEALLOC
}


bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
    
    CCSize frameSize = pEGLView->getFrameSize();

    
    // Set the design resolution
    //pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
    
    CCDirector::sharedDirector()->setDepthTest(false);
    
    vector<string> searchPath;
    
    TRACE_VAR_STR(CCFileUtils::sharedFileUtils()->getWritablePath().c_str())
   
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

        if(frameSize.height > mediumResource.size.height) // ipad hd
        {
            searchPath.push_back(largeResource.directory);
            pEGLView->setDesignResolutionSize(frameSize.width/4, frameSize.height/4, kResolutionShowAll);
            pDirector->setContentScaleFactor(4);
            
        }
        else if(frameSize.height > smallResource.size.height) // ipad, iphone retina
        {
            searchPath.push_back(mediumResource.directory);
            pEGLView->setDesignResolutionSize(frameSize.width/2, frameSize.height/2, kResolutionShowAll);
            pDirector->setContentScaleFactor(2);
           
        }
        else // iphone 3GS
        {
            pEGLView->setDesignResolutionSize(frameSize.width, frameSize.height, kResolutionShowAll);
            searchPath.push_back(smallResource.directory);
            pDirector->setContentScaleFactor(1);
        }
#endif  // CC_PLATFORM_IOS
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        
        float w = 512;
        float h = 384;
        
        
        TRACE_VAR_FLOAT(w)
        TRACE_VAR_FLOAT(h)
        TRACE_VAR_SIZE(frameSize)
        
        //float w = ((frameSize.width / frameSize.height) / 1.775f) * 508;
        pEGLView->setDesignResolutionSize((int)(w + 0.5f), h, kResolutionFixedHeight);
        
        if(frameSize.width > mediumResource.size.width ) // ipad hd
        {
            TRACE("largeResource")
            searchPath.push_back(largeResource.directory);
            searchPath.push_back(CCFileUtils::sharedFileUtils()->getWritablePath());
            
            pDirector->setContentScaleFactor(4);
            
        }
        else if(frameSize.width > smallResource.size.width) // ipad, iphone retina
        {
            TRACE("mediumResource")
            
            searchPath.push_back(CCFileUtils::sharedFileUtils()->getWritablePath());
            
            searchPath.push_back(mediumResource.directory);
            pDirector->setContentScaleFactor(2.0);
        }
        else // iphone 3GS
        {
            TRACE("smallResource")
            searchPath.push_back(smallResource.directory);
            pDirector->setContentScaleFactor(1);
        }
        
#endif
   
    searchPath.push_back("res");
    searchPath.push_back(CCFileUtils::sharedFileUtils()->getWritablePath());

    // set searching path
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);
	
    // turn on display FPS
    pDirector->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this

    pDirector->setAnimationInterval(1.0 / 60);
    
//    pDirector->runWithScene(scene);
    


    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();

}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();

    CCTextureCache::sharedTextureCache()->reloadAllTextures();

}
