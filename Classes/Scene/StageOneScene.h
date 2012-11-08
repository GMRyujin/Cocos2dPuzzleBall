/*
 * StageOneScene.h
 *
 *  Created on: 2012. 11. 2.
 *      Author: NitroPigSoft02
 */

#ifndef STAGEONESCENE_H_
#define STAGEONESCENE_H_

#include <Box2D/Box2D.h>
#include "cocos2d.h"
#include "PuzzleBallObject/PuzzleBallDef.h"

using namespace cocos2d;

#define BALL_START_POS ccp(layerSize.width/2,layerSize.height/2)

#define FLAG_APPLY_PHYSICS
#define PHYSICS_BLOCK_NUM 20

class StageOneScene : public CCLayer{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);
	CREATE_FUNC (StageOneScene);
	/* Touches */

	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	void ccUpdate(float dt);
	void SetBackground();

	//World를 추가
	void SetWorld();
	//플레이어 추가ㅣ
	void SetPlayerBall(float x,float y);
	//블록 추가
	void SetBlocks();

	GETTER(bool,bTouchDown);
	SETTER(bool,bTouchDown);

private:
	CCSprite* background;
	bool bTouchDown;
	float power;

	CCLabelTTF* powerLabel;

#ifndef FLAG_APPLY_PHYSICS
	CCSprite* playerBall;
	CCSprite* sp[BLOCK_SIZE];
#else
	/* B2 Settings */
	b2World* world;
	b2Body* playerBall;
	b2Body* ground;

	b2Body* blocks[PHYSICS_BLOCK_NUM];
#endif
};

#endif /* STAGEONESCENE_H_ */
