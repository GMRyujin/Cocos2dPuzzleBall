#ifndef _COCOS2DFACADE_H_
#define _COCOS2DFACADE_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "../../menu_nodes/CCMenuItem.h"
#include "../touch_dispatcher/CCTouch.h"



class Cocos2dFacade
{
public:
	/* Create */
	static cocos2d::CCSprite* CreateSprite(char* file_name,cocos2d::CCRect& rect);
	static cocos2d::CCSprite* CreateSprite(char* file_name,cocos2d::CCRect& rect,cocos2d::CCSize& size);
	static cocos2d::CCSprite* CreateSprite(char* file_name,cocos2d::CCRect& rect,cocos2d::CCSize& size,cocos2d::CCPoint& loc);
	static cocos2d::CCSprite* CreateSprite(char* file_name,cocos2d::CCRect& rect,cocos2d::CCSize& size,cocos2d::CCPoint& loc,int tag);

	/* Add */
	static void AddChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node);
	static void AddChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node,int tag);
	static void AddChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node,int zOrder,int tag);

	/* Remove */
	static void RemoveChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node,bool cleanup);
	static void RemoveChild(cocos2d::CCLayer* layer,int tag,bool cleanup);
	static void RemoveAll(cocos2d::CCLayer* layer,bool cleanup);

	/* Environment Setting */
	static void SetTouchEnable(cocos2d::CCLayer* layer,bool enable);
	/*
	 *   virtual void CCLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	 *	 virtual void CCLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	 *	 virtual void CCLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	 *	 virtual void CCLayer::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
	 * */
	static void SetAccelerate(cocos2d::CCLayer* layer, bool enable);
	/*
	 * virtual void CCLayer::didAccelerate(CCAcceleration* pAccelerationValue);
	 * */

	/* Logic */
	static void SetSchedule(cocos2d::CCLayer* layer,cocos2d::SEL_SCHEDULE seletor);
	static cocos2d::CCNode* FindChildByTag(cocos2d::CCLayer* layer,int tag);
	static cocos2d::CCNode* FindChildByPoint(cocos2d::CCNode** array,int length,float x,float y);
	static cocos2d::CCNode* FindChildByPoint(cocos2d::CCNode*** array,int firstLength,int secondLength,float x,float y);

private:
};



#endif
