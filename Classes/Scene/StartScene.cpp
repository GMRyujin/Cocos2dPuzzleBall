/*
 * StartScene.cpp
 *
 *  Created on: 2012. 11. 1.
 *      Author: NitroPigSoft02
 */
#include "HelloWorldScene.h"
#include "Scene/StartScene.h"
#include "Scene/MenuScene.h"
#include "Scene/StageOneScene.h"
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

CCScene* StartScene::scene() {
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	StartScene *layer = StartScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool StartScene::init() {
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

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	//환경설정을 한다.
	this->setTouchEnabled(true);    //텊치를 허용한다/.
	this->setAccelerometerEnabled(true);    //센서값 입력을 허용한다.


	startBtn = Cocos2dFacade::CreateSprite("start_button.png");
	startBtn->setPosition(ccp(size.width/2,size.height/1.4f));
	Cocos2dFacade::AddChild(this,startBtn);

	return true;
}

void StartScene::menuCloseCallback(CCObject* pSender) {
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void StartScene::ccTouchesEnded(CCSet *pTouch, CCEvent *pEvent) {
	//터치를하면 불러온다.
	cocos2d::CCTouch* touch = (CCTouch*) (pTouch->anyObject());

	//현재 좌표를 오픉지넬 좌표로 변환한다.
	CCPoint location = touch->locationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	CCLOG("Touch %lf %lf",location.x,location.y);

	if(Cocos2dFacade::CheckRectIntersectPoint(startBtn,location)){
		CCLOG("Button Clicked");
		// TODO : 여기에서 씬을 시작한다.
		CCDirector::sharedDirector()->replaceScene(MenuScene::scene());

	}else{
		CCLOG("Button No Touch");
	}
}
