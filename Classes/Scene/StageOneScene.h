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
	void SetPlayerBall(float x,float y);
	void SetBlocks();
	void SetB2Box();//물리 박스의 추가
	b2Body* AddCrate();//떨어지는 공 추가

	GETTER(bool,bTouchDown);
	SETTER(bool,bTouchDown);

private:
	CCSprite* playerBall;
	CCSprite* sp[BLOCK_SIZE];
	CCSprite* background;
	bool bTouchDown;

	float power;

	/* B2 Settings */
};

#endif /* STAGEONESCENE_H_ */
