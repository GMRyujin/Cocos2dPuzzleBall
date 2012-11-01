#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "npLinkNode.h"

using namespace cocos2d;
using namespace CocosDenshion;

class StartScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(StartScene);
    /* Touches */
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
private:
    CCSprite* startBtn;
};



#endif // __START_SCENE_H__
