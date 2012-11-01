/*
 * Cocos2dFacade.cpp
 *
 *  Created on: 2012. 10. 31.
 *      Author: GmRyuj
 */

#include "Cocos2dFacade.h"


using namespace cocos2d;
using namespace CocosDenshion;

CCSprite* Cocos2dFacade::CreateSprite(const char* file_name)
{
	CCSprite* sp = CCSprite::spriteWithFile(file_name);
	return sp;
}

CCSprite* Cocos2dFacade::CreateSprite(const char* file_name,const CCRect& rect)
{
	CCSprite* sp = CCSprite::create(file_name,rect);
	return sp;
}

CCSprite* Cocos2dFacade::CreateSprite(const char* file_name,const CCRect& rect,const CCSize& size)
{
	CCSprite* sp = CCSprite::create(file_name,rect);
	sp->setContentSize(size);
	return sp;
}
CCSprite* Cocos2dFacade::CreateSprite(const char* file_name,const cocos2d::CCRect& rect,const cocos2d::CCSize& size,const cocos2d::CCPoint& loc)
{
	CCSprite* sp = CCSprite::create(file_name,rect);
	sp->setContentSize(size);
	sp->setPosition(loc);
	return sp;
}
CCSprite* Cocos2dFacade::CreateSprite(const char* file_name,const cocos2d::CCRect& rect,const cocos2d::CCSize& size,const cocos2d::CCPoint& loc,const int tag)
{
	CCSprite* sp = CCSprite::create(file_name,rect);
	sp->setContentSize(size);
	sp->setPosition(loc);
	sp->setTag(tag);
	return sp;
}
void Cocos2dFacade::AddChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node)
{
	layer->addChild(node);
}

void Cocos2dFacade::AddChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node,int tag)
{
	node->setTag(tag);
	layer->addChild(node);
}

void Cocos2dFacade::AddChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node,int zOrder,int tag)
{
	layer->addChild(node,zOrder,tag);
}

void Cocos2dFacade::RemoveChild(cocos2d::CCLayer* layer,cocos2d::CCNode* node,bool cleanup)
{
	layer->removeChild(node,cleanup);
}


void Cocos2dFacade::RemoveChild(cocos2d::CCLayer* layer,int tag,bool cleanup)
{
	layer->removeChildByTag(tag,cleanup);
}

void Cocos2dFacade::RemoveAll(cocos2d::CCLayer* layer,bool cleanup)
{
	layer->removeAllChildrenWithCleanup(cleanup);
}

void Cocos2dFacade::SetTouchEnable(CCLayer* layer,bool enable)
{
	layer->setTouchEnabled(enable);
}

void Cocos2dFacade::SetAccelerate(CCLayer* layer,bool enable)
{
	layer->setAccelerometerEnabled(enable);
}

void Cocos2dFacade::SetSchedule(CCLayer* layer,SEL_SCHEDULE seletor)
{
	layer->schedule(seletor);
}

CCNode* Cocos2dFacade::FindChildByTag(CCLayer* layer,int tag)
{
	return layer->getChildByTag(tag);
}

CCNode* Cocos2dFacade::FindChildByPoint(cocos2d::CCNode** array,int length,float x,float y,int* out_number)
{
	for(int i = 0 ; i < length ; i++){
		if(array[i] == 0)	continue;
		CCSize size = array[i]->getContentSize();
		float ox,oy;
		float width = size.width;
		float height = size.height;
		array[i]->getPosition(&ox,&oy);

		if(ox <= x && x <= ox + width){
			if(oy <= y && y <= oy + height){
				if(out_number != 0){
					*out_number = i;
				}
				return array[i];
			}
		}
	}
	return 0;
}

void Cocos2dFacade::MoveTo(CCNode* target,const float duration,const float x,const float y)
{
	CCFiniteTimeAction* action = CCMoveTo::actionWithDuration(duration,ccp(x,y));
	target->runAction(CCSequence::actions(action,0));
}

bool Cocos2dFacade::CheckRectIntersectPoint(CCNode* node,const CCPoint& point)
{
	float x,y,width,height;
	CCSize size = node->getContentSize();
	width = size.width;
	height = size.height;
	node->getPosition(&x,&y);
	CCRect rect = CCRectMake(x - width/2,y - height/2,width,height);

	CCLOG("%lf %lf %lf %lf",x,y,width,height);

	return rect.containsPoint(point) ? true : false;
}

bool Cocos2dFacade::CheckRectIntersectsRect(CCNode* nodeA,CCNode* nodeB)
{
	float x,y,width,height;
	float x1,y1,width1,height1;
	CCSize size,size1;

	CCRect rect1,rect2;

	nodeA->getPosition(&x,&y);
	size = nodeA->getContentSize();
	width = size.width;
	height = size.height;
	rect1 = CCRectMake(x,y,width,height);

	nodeB->getPosition(&x1,&y1);
	size1 = nodeB->getContentSize();
	width1 = size1.width;
	height1 = size1.height;
	rect2 = CCRectMake(x1,y1,width1,height1);

	return CCRect::CCRectIntersectsRect(rect1,rect2) ? true : false;
}

void Cocos2dFacade::PlayEffectSound(const char* fileName,bool bLoop)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(fileName, bLoop);
}
void Cocos2dFacade::PlayBackgroundSound(const char* fileName,bool bLoop)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(fileName,bLoop);
}

CCAnimate* Cocos2dFacade::CreateTextureFrameAnimate(float delay,VAR_TYPE_PCHARES)
{
	CCAnimation* anim = CCAnimation::create();
	anim->setDelayPerUnit(delay);
	va_list ap;

	va_start(ap,delay);
	char* fileName = 0;
	do{
		 fileName = va_arg(ap,char*);
		 if(fileName == 0) break;
		 anim->addSpriteFrameWithFileName(fileName);
	}while(1);
	va_end(ap);

	CCAnimate* animate = CCAnimate::create(anim);

	return animate;
}

void Cocos2dFacade::SetTextureFrameAnimationForever(CCNode* target,CCAnimate* anim)
{
	CCRepeatForever* forever = CCRepeatForever::create(anim);
	target->runAction(forever);
}

void Cocos2dFacade::SetTextureFrameAction(CCNode* target,CCAction* act)
{
	target->runAction(act);
}

CCAction* Cocos2dFacade::CreateReverseTextureFrame(CCAnimate* anim)
{
	CCRepeatForever* forever = CCRepeatForever::create(anim);
	return forever->reverse();
}
CCAction* Cocos2dFacade::CreateReverseTextureFrame(CCActionInterval* act)
{
	return act->reverse();
}


