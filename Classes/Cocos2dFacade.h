#ifndef _COCOS2DFACADE_H_
#define _COCOS2DFACADE_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "../../menu_nodes/CCMenuItem.h"
#include "../touch_dispatcher/CCTouch.h"
#include "SimpleAudioEngine.h"


#define VAR_TYPE_PCHARES ...


class Cocos2dFacade
{
public:
	/* Create */
	static cocos2d::CCSprite* CreateSprite(const char* file_name,const cocos2d::CCRect& rect);
	static cocos2d::CCSprite* CreateSprite(const char* file_name,const cocos2d::CCRect& rect,const cocos2d::CCSize& size);
	static cocos2d::CCSprite* CreateSprite(const char* file_name,const cocos2d::CCRect& rect,const cocos2d::CCSize& size,const cocos2d::CCPoint& loc);
	static cocos2d::CCSprite* CreateSprite(const char* file_name,const cocos2d::CCRect& rect,const cocos2d::CCSize& size,const cocos2d::CCPoint& loc,const int tag);

	/* Add */
	static void AddChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node);
	static void AddChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node,int tag);
	static void AddChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node,int zOrder,int tag);

	/* Remove */
	static void RemoveAll(cocos2d::CCLayer* layer,bool cleanup);
	static void RemoveChild(cocos2d::CCLayer* layer,int tag,bool cleanup);
	static void RemoveChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node,bool cleanup);



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

	/* 맨 뒤의 아웃풋 인인자는 해당오브젝트이 배열 번호이다. */
	static cocos2d::CCNode* FindChildByPoint(cocos2d::CCNode** array,int length,float x,float y,int* out_number = 0);
	//static cocos2d::CCNode* FindChildByPoint(cocos2d::CCNode** array,int firstLength,int secondLength,float x,float y,int* out_f = 0,int* out_s = 0);

	static void MoveTo(cocos2d::CCNode* target,const float duration,const float x,const float y);

	static bool CheckRectIntersectsRect(cocos2d::CCNode* nodeA,cocos2d::CCNode* nodeB);

	static void PlayEffectSound(const char* fileName,bool bLoop = true);
	static void PlayBackgroundSound(const char* fileName,bool bLoop = false);

	//Animation되는 CCAnimate를 만든다. VAR_TYPE_PCHAR 는 가변인자로써 텍스쳐의 이름이 오게 된다.
	static cocos2d::CCAnimate* CreateTextureFrameAnimate(float delay,VAR_TYPE_PCHARES);
	static cocos2d::CCAction* CreateReverseTextureFrame(cocos2d::CCAnimate* anim);
	static cocos2d::CCAction* CreateReverseTextureFrame(cocos2d::CCActionInterval* act);

	//애니메이션을  target에 설정한다.
	static void SetTextureFrameAnimationForever(cocos2d::CCNode* target,cocos2d::CCAnimate* anim);
	static void SetTextureFrameAction(cocos2d::CCNode* target,cocos2d::CCAction* act);
private:
};



#endif
