/////////////////////////////////////////////

#include "StageTwoScene.h"
#include "SimpleAudioEngine.h"
#include "../../menu_nodes/CCMenuItem.h"
#include "../touch_dispatcher/CCTouch.h"
#include <ryAndroidLib/Cobo2d/Facade/Cocos2dFacade.h>
#include "npLinkNode.h"
#include "CCControlButton.h"
#include "CCControlButtonLoader.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace extension;

CCScene* StageTwoScene::scene() {
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	StageTwoScene *layer = StageTwoScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool StageTwoScene::init() {
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init()) {
		return false;
	}

	CCLabelTTF* pLabel = CCLabelTTF::create("Start Puzzle Game Main Scene", "Thonburi",
			34);
	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	// position the label on the center of the screen
	pLabel->setPosition(ccp(size.width / 2, size.height - 20));

	// TODO : 여기서 초기화한다.

	// TODO 백그라운드를 설정한다.
	background = Cocos2dFacade::CreateSprite("game_background_two.png");
	//Layer의 중앙에 background를 오게하면 중앙에 배경이 오게된다.
	CCSize layerSize = this->getContentSize();
	CCSize backgroundSize = background->getContentSize();
	background->setScaleX(layerSize.width/backgroundSize.width);
	background->setScaleY(layerSize.height/backgroundSize.height);
	background->setPosition(ccp(layerSize.width/2,layerSize.height/2));
	Cocos2dFacade::AddChild(this,background);


	//TODO 물리 설정과 볼 설정을 한다.


	return true;
}

void StageTwoScene::menuCloseCallback(CCObject* pSender) {
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void StageTwoScene::ccTouchesEnded(CCSet *pTouch, CCEvent *pEvent) {
	//터치를하면 불러온다.
	cocos2d::CCTouch* touch = (CCTouch*) (pTouch->anyObject());

	//현재 좌표를 오픉지넬 좌표로 변환한다.
	CCPoint location = touch->locationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	CCLOG("Touch %lf %lf",location.x,location.y);
}
