/*
 * StartScene.cpp
 *
 *  Created on: 2012. 11. 1.
 *      Author: NitroPigSoft02
 */
#include "StageOneScene.h"
#include "SimpleAudioEngine.h"
#include "../../menu_nodes/CCMenuItem.h"
#include "../touch_dispatcher/CCTouch.h"
#include "../npLinkNode.h"
#include <ryAndroidLib/Cobo2d/Facade/Cocos2dFacade.h>
#include "math.h"
#include <PuzzleBallObject/PuzzleBallDef.h>

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* StageOneScene::scene() {
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
	// 'layer' is an autorelease object
	StageOneScene *layer = StageOneScene::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool StageOneScene::init() {
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

	int maxWidth = size.width - 100;
	int maxHeight = size.height - 100;

	/* TODO 환경 설정 */
	Cocos2dFacade::SetTouchEnable(this,true);
	bTouchDown = false;
	Cocos2dFacade::SetSchedule(this,schedule_selector(StageOneScene::ccUpdate));

	//TODO 파워를 표시해주는 라벨을 만든다.
	powerLabel = CCLabelTTF::create("Power : ","Thonburi",34);
	pLabel->setPosition(ccp(size.width/2,size.height-20));
	this->addChild(powerLabel);

	//백그라운드 설정
	SetBackground();
	//TODO 물리월드 생성
	SetWorld();
	//TODO 플레이어 설정
	SetPlayerBall(30,500);
	//TODO 블록을 설정
	SetBlocks();


	return true;
}

void StageOneScene::menuCloseCallback(CCObject* pSender) {
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}


void StageOneScene::SetWorld()
{
#ifdef FLAG_APPLY_PHYSICS
	world = new b2World(b2Vec2(0,-9.8f));
	world->SetAllowSleeping(false);
#endif
}

void StageOneScene::SetBackground(){
	// TODO 백그라운드를 설정한다.
	background = Cocos2dFacade::CreateSprite("game_background.png");
	//Layer의 중앙에 background를 오게하면 중앙에 배경이 오게된다.
	CCSize layerSize = this->getContentSize();
	CCSize backgroundSize = background->getContentSize();
	background->setScaleX(layerSize.width/backgroundSize.width);
	background->setScaleY(layerSize.height/backgroundSize.height);
	background->setPosition(ccp(layerSize.width/2,layerSize.height/2));
	Cocos2dFacade::AddChild(this,background);
}

void StageOneScene::SetPlayerBall(float x,float y) {
	//플레이어의 볼을 설정한다.
	CCDirector* director = CCDirector::sharedDirector();
	CCSize winSize = director->getWinSize();
#ifndef FLAG_APPLY_PHYSICS
	playerBall = Cocos2dFacade::CreateSprite("small_auq_ball.png");
	playerBall->setPosition(ccp(x,y));
	Cocos2dFacade::AddChild(this, playerBall);
#else
	//TODO 플레이어 생성
	playerBall = cbFacade::CreateDynamicSpriteCircle("small_auq_ball.png",this,world,b2Vec2(50,50),1,1,1);
	cbFacade::SetTransform(playerBall,50,50,0);
	cbFacade::ApplyBodyInLayer(this,playerBall);

	//TODO 플레이어를 받칠 그라운드를 만든다.
	ground = cbFacade::CreateStaticSpriteBody("small_concrete_block.jpg",this,world,b2Vec2(100,30));
	cbFacade::SetTransform(ground,30,10,0);
	cbFacade::ApplyBodyInLayer(this,ground);
#endif
}

void StageOneScene::SetBlocks(){
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	int maxWidth = size.width - 100;
	int maxHeight = size.height - 100;

	// TODO 스프라이트들을 초기화하고 초기위치를 지정한다.
#ifndef FLAG_APPLY_PHYSICS

#define IF_SETTING_THE_RANDOM_BLOCK_THEN_THIS_CHANGED
#ifdef FALG_STAGEONE_RANDOM_BLOCK
	for(int i= 0 ; i < BLOCK_SIZE ; i++){
		//노드들을 만든다.
		sp[i] = Cocos2dFacade::CreateSprite("small_concrete_block.jpg");
		//위치를 지정한다.

		int x,y,width,height;

		x = rand()%maxWidth;
		y = rand()%maxHeight;
		width = sp[i]->getContentSize().width;
		height = sp[i]->getContentSize().height;
		CCRect rect = CCRectMake(x,y,width,height);

		sp[i]->setPosition(ccp(rand()%maxWidth,rand()%maxHeight));
		Cocos2dFacade::AddChild(this,sp[i]);
	}
#else
	int i = 0;
	while(i < 10){
		i++;
		sp[i] = Cocos2dFacade::CreateSprite("small_concrete_block.jpg");

		int x,y,width,height;
		x = size.width/2;
		y = i * sp[i]->getContentSize().height;
		width = sp[i]->getContentSize().width;
		height = sp[i]->getContentSize().height;

		CCRect rect = CCRectMake(x,y,width,height);
		sp[i]->setPosition(ccp(x,y));
		Cocos2dFacade::AddChild(this,sp[i]);
	}
#endif
#else
	//TODO 블록을 초기화 시켜준다.
	for(int i = 0 ; i < PHYSICS_BLOCK_NUM ; i++)	blocks[i] = NULL;

	//TODO 물리 박스 추가
	int width,height;
	width = 100;
	height = 60;
	for(int i = 0 ; i < 10 ; i++){
		blocks[i] = cbFacade::CreateStaticSpriteBody("small_concrete_block.jpg",this,world,b2Vec2(width,height));
		cbFacade::SetTransform(blocks[i],size.width/2.0f,(float)(height*i),0);
		cbFacade::ApplyBodyInLayer(this,blocks[i]);
	}
#endif
}


void StageOneScene::ccTouchesBegan(CCSet* pTouch,CCEvent* pEvent)
{
	//터치를하면 불러온다.
	cocos2d::CCTouch* touch = (CCTouch*) (pTouch->anyObject());
	//현재 좌표를 오픉지넬 좌표로 변환한다.
	CCPoint location = touch->locationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	//TODO 터치를 처리한다.
	power = 0;
	bTouchDown = true;
	CCLOG("Touch %lf %lf",location.x,location.y);
}

void StageOneScene::ccTouchesEnded(CCSet *pTouch, CCEvent *pEvent) {
	//터치를하면 불러온다.
	cocos2d::CCTouch* touch = (CCTouch*) (pTouch->anyObject());
	//현재 좌표를 오픉지넬 좌표로 변환한다.
	CCPoint location = touch->locationInView();
	location = CCDirector::sharedDirector()->convertToGL(location);

	b2Vec2 direction(location.x,location.y);
	direction.Normalize();
	//TODO 터치가 끝나면 파워를 공에게 준다.
	bTouchDown = false;
	//cbFacade::ApplyForce(playerBall,b2Vec2(direction.x*power,direction.y*power));
	cbFacade::ApplyForce(playerBall,b2Vec2(location.x*power,location.y*power));

	CCLOG("Touch %lf %lf",direction.x*power,direction.y*power);
}

void StageOneScene::ccUpdate(float dt)
{
	//TODO 수학라이브러리를 이용한 중력처리 (볼 플레이어)

	//TODO 계속 누르는 상태라면 파워를 올려준다.
	if(bTouchDown == true){
		power+=10000.0f*dt;
		char buffer[128];
		sprintf(buffer,"Power : %lf",power);
		powerLabel->setString(buffer);
		CCLOG(buffer);
	}else{

	}

	//TODO 오브젝트들을의 업데이트 구문들을 추가한다.

	//TODO 월드를 업데이트 해준다.
#ifdef FLAG_APPLY_PHYSICS
	world->Step(dt,8,3);
	for(b2Body* b = world->GetBodyList() ; b ; b = b->GetNext()){
		cbFacade::UpdateSpriteByBody(b);
	}
#endif

}
