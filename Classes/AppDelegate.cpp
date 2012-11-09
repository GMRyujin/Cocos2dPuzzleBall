#include "AppDelegate.h"

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "Scene/StartScene.h"
#include "Scene/MenuScene.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
    //TODO  Cocos2d의 환경설정을 한다.
    //pDirector->enableRetinaDisplay(true);
    //cocos2d::CCEGLView* view = cocos2d::CCEGLView::sharedOpenGLView();
    //view->setFrameSize(400,100);
    //view->setViewPortInPoints(0,0,400,100);
    //view->setContentScaleFactor(0.5f);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    //CCScene *pScene = HelloWorld::scene();


    //시작 화면으로 시작.
    CCScene* pScene = StartScene::scene();


    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
