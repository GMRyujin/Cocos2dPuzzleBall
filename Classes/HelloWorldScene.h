#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "npLinkNode.h"

#define BLOCK_WIDTH 30
#define BLOCK_HEIGHT 13
#define BLOCK_TAG 1

/* CCLOG를 활성화시키는 선언문이다. 배포할때에는 반드시
 * CCPlatformMacros.h  에 있는 #define COCOS2D_DEBUG 1 구문을 없애주기 바란다.
 * */
#define COCOS2D_DEBUG 1

#if COCOS2D_DEBUG == 1
#define MYLOG(str)	CCLog(str)
#else
#define MYLOG(str)  do {} while (0)
#endif


using namespace cocos2d;
using namespace CocosDenshion;

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

    /* Touches */
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

    /* 가속도 센서 */
    virtual void didAccelerate(CCAcceleration* pAccelerationValue);

    void Update(float dt);//없데이트 타이머
private:
    CCSprite* playerBall;
    CCSprite* block[BLOCK_HEIGHT][BLOCK_WIDTH];
private:
    void SetPlayerBall();			//플레이어의 볼을 설정한다.
    void SetCreateNormalBlock();	//벽을 만든다.
};

#endif // __HELLOWORLD_SCENE_H__
