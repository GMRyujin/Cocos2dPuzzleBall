/*
 * MenuScene.cpp
 *
 *  Created on: 2012. 11. 2.
 *      Author: NitroPigSoft02
 */
#include "MenuScene.h"


/*
 * StartScene.cpp
 *
 *  Created on: 2012. 11. 1.
 *      Author: 류진영
 */
#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "Scene/StageOneScene.h"
#include "Scene/StageTwoScene.h"
#include "Scene/StageThreeScene.h"
#include "../../menu_nodes/CCMenuItem.h"
#include "../touch_dispatcher/CCTouch.h"
#include "npLinkNode.h"
#include "CCControlButton.h"
#include "CCControlButtonLoader.h"



using namespace cocos2d;
using namespace CocosDenshion;
using namespace extension;

CCScene* MenuScene::scene() {
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	MenuScene *layer = MenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init() {
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


	/* 환경설정  터치를 받게한다.*/
	Cocos2dFacade::SetTouchEnable(this,true);

	// TODO 여기에서 씬을 추가한다. 여기에 씬을 추가하게 되면  Start 버튼을 누르면 게임의 스테이지가 정렬되어 보일것이다.
	for(int i = 0 ; i < 6 ; i ++){
		menuScene[i] = 0;
	}


	//현재 스테이지 하나의 크기를 구한다.
	CCSize menuSize = this->getContentSize();
	menuSize.width = menuSize.width/3;
	menuSize.height = menuSize.height/2;

	// TODO: 1 스테이지의 사이즈를 조절한다.
	menuScene[0] = StageOneScene::scene();
	//게임 스테이지의 크기를 구한다.
	CCSize layerSize = menuScene[0]->getContentSize();
	menuScene[0]->setScaleX(menuSize.width/layerSize.width);
	menuScene[0]->setScaleY(menuSize.height/layerSize.height);

	//메뉴 씬의 실제 사이즈 :  ContentSize실제 이미지의 크기를 나타내며, 이 크기로 지정된 사이즈로 피벗이 결정된다.
	CCSize menuSceneSize = CCSizeMake(menuSize.width/layerSize.width,menuSize.height/layerSize.height);

	menuScene[0]->setContentSize(menuSceneSize);
	menuScene[0]->setPosition(0,size.height/2);

	// TODO 2 스테이지의 사이즈를 조절한다.
	menuScene[1] = StageTwoScene::scene();
	//게임 스테이지의 크기를 구한다.
	layerSize = menuScene[1]->getContentSize();
	menuScene[1]->setScaleX(menuSize.width/layerSize.width);
	menuScene[1]->setScaleY(menuSize.height/layerSize.height);

	//메뉴 씬의 실제 사이즈 :  ContentSize실제 이미지의 크기를 나타내며, 이 크기로 지정된 사이즈로 피벗이 결정된다.
	menuSceneSize = CCSizeMake(menuSize.width/layerSize.width,menuSize.height/layerSize.height);

	menuScene[1]->setContentSize(menuSceneSize);
	menuScene[1]->setPosition(size.width/3,size.height/2);


	// TODO 3 스테이지의 사이즈를 조절한다.
	menuScene[2] = StageThreeScene::scene();
	//게임 스테이지의 크기를 구한다.
	layerSize = menuScene[2]->getContentSize();
	menuScene[2]->setScaleX(menuSize.width/layerSize.width);
	menuScene[2]->setScaleY(menuSize.height/layerSize.height);

	//메뉴 씬의 실제 사이즈 :  ContentSize실제 이미지의 크기를 나타내며, 이 크기로 지정된 사이즈로 피벗이 결정된다.
	menuSceneSize = CCSizeMake(menuSize.width/layerSize.width,menuSize.height/layerSize.height);

	menuScene[2]->setContentSize(menuSceneSize);
	menuScene[2]->setPosition(size.width*2/3,size.height/2);


	// TODO 씬의 사이즈를 조절하고 씬을 배치한다. 여기에서 씬을 누르면 현재 배경이 페이드 아웃되고 페이드인되면서 씬이 바뀐다.
	for(int i = 0 ; i < 6 ; i ++){
		if(menuScene[i] != 0){
			this->addChild(menuScene[i]);
		}
	}



	return true;
}

void MenuScene::menuCloseCallback(CCObject* pSender) {
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void MenuScene::ccTouchesEnded(CCSet *pTouch, CCEvent *pEvent) {
	//터치를하면 불러온다.
	cocos2d::CCTouch* touch = (CCTouch*) (pTouch->anyObject());

	//현재 좌표를 오픉지넬 좌표로 변환한다.
	CCPoint location = touch->locationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	CCLOG("Touch MenuScene");

	// TODO 스테이지를 클릭했는지 체크한다. 그리고 클릭했으면  FadeOut 한다.
	// TODO 스테이지를 클릭했는지 체크한다. 그리고 클릭했으면  FadeOut 한다. 우선 이건 끝
	//씬의 크기가 일정치가 않아서 직접 충돌 사각형을 설정해주었다.
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCRect stage_rect1  = CCRectMake(0,winSize.height/2,winSize.width/3,winSize.height/2);
	CCRect stage_rect2  = CCRectMake(winSize.width/3,winSize.height/2,winSize.width/3,winSize.height/2);
	CCRect stage_rect3  = CCRectMake(winSize.width*2/3,winSize.height/2,winSize.width/3,winSize.height/2);

	CCRect stage_rect4  = CCRectMake(0,0,winSize.width/3,winSize.height/2);
	CCRect stage_rect5  = CCRectMake(winSize.width/3,0,winSize.width/3,winSize.height/2);
	CCRect stage_rect6  = CCRectMake(winSize.width*2/3,0,winSize.width/3,winSize.height/2);


	// TODO 장면전환 효과를 적용하였음.
	CCScene* pScene;
	if(stage_rect1.containsPoint(location)){//Select Stage 1
		pScene = CCTransitionPageTurn::transitionWithDuration(0.5f,StageOneScene::scene(),true);
		CCDirector::sharedDirector()->replaceScene(pScene);
		//CCDirector::sharedDirector()->pushScene(pScene);

	}
	if(stage_rect2.containsPoint(location)){//Select Stage 2
		//CCDirector::sharedDirector()->replaceScene(StageTwoScene::scene());
		pScene = CCTransitionPageTurn::transitionWithDuration(0.5f,StageTwoScene::scene(),true);
		CCDirector::sharedDirector()->replaceScene(pScene);
	}
	if(stage_rect3.containsPoint(location)){//Select Stage 3
		//CCDirector::sharedDirector()->replaceScene(StageThreeScene::scene());
		pScene = CCTransitionPageTurn::transitionWithDuration(0.5f,StageThreeScene::scene(),true);
		CCDirector::sharedDirector()->replaceScene(pScene);
	}if(stage_rect4.containsPoint(location)){
	}if(stage_rect5.containsPoint(location)){
	}if(stage_rect6.containsPoint(location)){
	}
}
