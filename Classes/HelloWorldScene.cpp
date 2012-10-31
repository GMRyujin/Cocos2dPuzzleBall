#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "../../menu_nodes/CCMenuItem.h"
#include "../touch_dispatcher/CCTouch.h"


using namespace cocos2d;
using namespace CocosDenshion;

#define COCOS2D_DEBUG 1

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    ///////////////////////////// 이거 왜안되지
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
   /* CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);*/

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello Puzzle Ball", "Thonburi", 34);

    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    // position the label on the center of the screen
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    


    MYLOG("Test Setting the player and blocks");
  	MYLOG("Test");
    CCLog("Test Log");

    //환경설정을 한다.
    this->setTouchEnabled(true);//텊치를 허용한다/.
    this->setAccelerometerEnabled(true);//센서값 입력을 허용한다.

    //플레이어의 볼을 셋업한다.
    SetPlayerBall();
    SetCreateNormalBlock();

    //없데이트 구문을 추가한다.
    this->schedule(schedule_selector(HelloWorld::Update));

    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}



void HelloWorld::SetPlayerBall()
{
	//플레이어의 볼을 설정한다.
	CCDirector* director = CCDirector::sharedDirector();

	 // add "HelloWorld" splash screen"
	playerBall = CCSprite::create("small_auq_ball.png",CCRectMake(0,0,64,64));
	playerBall->setContentSize(CCSize(64,64));

	//플레이어 볼의 위치설정
	CCSize winSize = director->getWinSize();
	playerBall->setPosition(
			ccp(winSize.width/2,
					winSize.height - playerBall->getContentSize().height/2)
					);

	this->addChild(playerBall);
}
void HelloWorld::SetCreateNormalBlock() {
	CCDirector* director = CCDirector::sharedDirector();

	CCSize winSize = director->getWinSize();

	for(int h = 0 ; h < BLOCK_HEIGHT ; h++){
		for(int w = 0 ; w < BLOCK_WIDTH ; w++){
			block[h][w] = CCSprite::create("small_concrete_block.png",
					CCRectMake(0,0,64,49));
			block[h][w]->setPosition(ccp(w * 64,h * 49));
			block[h][w]->setTag(BLOCK_TAG);//태그를 설정하여 오브젝트가 충돌오브젝트를 할수있게한다.
			this->addChild(block[h][w]);
		}
	}
}

void HelloWorld::ccTouchesEnded(CCSet *pTouch, CCEvent *pEvent)
{
	//터치를하면 불러온다.
	cocos2d::CCTouch* touch =
			(CCTouch*)(pTouch->anyObject());

	//현재 좌표를 오픉지넬 좌표로 변환한다.
	CCPoint location = touch->locationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);


	for(int h = 0 ; h < BLOCK_HEIGHT ; h ++){
		for(int w = 0 ; w < BLOCK_WIDTH ; w++){
			float x,y;
			float width,height;
			if(this->block[h][w] == 0) continue;

			this->block[h][w]->getPosition(&x,&y);
			CCSize size = this->block[h][w]->getContentSize();
			width = size.width;
			height = size.height;

			if(x <= location.x && location.x <= x + width){
				if(y <= location.y && location.y <= y+height){
					this->removeChild(block[h][w],false);
					block[h][w] = 0;
					MYLOG("노드 하나를 삭제하였음");
					goto exitRemoveCode;
				}
			}
		}
	}
exitRemoveCode:

	MYLOG("Test Touch it");
	//CCSize winSize = CCDirector::sharedDirector()->getWinSize();

}

void HelloWorld::Update(float dt)
{
	static float currentTime = 0;
	static float updateLogPrintTime = 0;
	currentTime += dt;
	updateLogPrintTime += dt;

	if(updateLogPrintTime > 5){
		updateLogPrintTime = 0;
		MYLOG("Updating");
		CCLOG("CurrentTime : %lf",currentTime);

	}
}

void HelloWorld::didAccelerate(CCAcceleration* pAccelerationValue)
{
	float x = pAccelerationValue->x;
	float y = pAccelerationValue->y;
	float z = pAccelerationValue->z;

	CCLog("CurrentTime : %lf,%lf,%f",x,y,z);
}
