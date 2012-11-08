/*
 * GameLayer.h
 *
 *  Created on: 2012. 11. 2.
 *      Author: NitroPigSoft02
 */

#ifndef GAMELAYER_H_
#define GAMELAYER_H_

#include "cocos2d.h"
using namespace cocos2d;

class GameLayer : public CCLayer{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);
	CREATE_FUNC (GameLayer);

	//플레이어의 볼을 설정한다.
	void SetPlayerBall(float x,float y);
	//백그라운드를 설정한다.
	void SetBackground(char* background_name);

	/* Touches */
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);

	/* Update */
	void ccUpdate(float dt);
private:
	CCSprite* background;
	bool bTouchDown;
	CCSprite* playerBall;
};


#endif /* GAMELAYER_H_ */
