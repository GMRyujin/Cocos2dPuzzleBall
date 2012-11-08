/*
 * StageThreeScene.h
 *
 *  Created on: 2012. 11. 2.
 *      Author: NitroPigSoft02
 */

#ifndef STAGETHREESCENE_H_
#define STAGETHREESCENE_H_

#include "cocos2d.h"

using namespace cocos2d;

class StageThreeScene: public CCLayer{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);
	CREATE_FUNC (StageThreeScene);
	/* Touches */
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
private:
	CCSprite* background;
};


#endif /* STAGETHREESCENE_H_ */
