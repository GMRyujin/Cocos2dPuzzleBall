/*
 * MenuScene.h
 *
 *  Created on: 2012. 11. 2.
 *      Author: NitroPigSoft02
 */

#ifndef MENUSCENE_H_
#define MENUSCENE_H_


#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

class MenuScene : public CCLayer{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);
	CREATE_FUNC (MenuScene);
	/* Touches */
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
private:
	CCScene* menuScene[6];
};

#endif /* MENUSCENE_H_ */
