/*
 * Cocos2dFacade.cpp
 *
 *  Created on: 2012. 10. 31.
 *      Author: GmRyuj
 */

#include "Cocos2dFacade.h"


using namespace cocos2d;
using namespace CocosDenshion;

CCSprite* Cocos2dFacade::CreateSprite(char* file_name,CCRect& rect)
{
	CCSprite* sp = CCSprite::create(file_name,rect);
	return sp;
}

CCSprite* Cocos2dFacade::CreateSprite(char* file_name,CCRect& rect,CCSize& size)
{
	CCSprite* sp = CCSprite::create(file_name,rect);
	sp->setContentSize(size);
	return sp;
}
cocos2d::CCSprite* Cocos2dFacade::CreateSprite(char* file_name,cocos2d::CCRect& rect,cocos2d::CCSize& size,cocos2d::CCPoint& loc)
{
	CCSprite* sp = CCSprite::create(file_name,rect);
	sp->setContentSize(size);
	sp->setPosition(loc);
	return sp;
}
cocos2d::CCSprite* Cocos2dFacade::CreateSprite(char* file_name,cocos2d::CCRect& rect,cocos2d::CCSize& size,cocos2d::CCPoint& loc,int tag)
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

CCNode* Cocos2dFacade::(cocos2d::CCNode** array,int length,float x,float y)
{
	for(int i = 0 ; i < length ; i++){
		CCSize size = array[i]->getContentSize();
		float ox,oy;
		float width = size.width;
		float height = size.height;
		array[i]->getPosition(&ox,&oy);

		if(ox <= x && x <= ox + width){
			if(oy <= y && y <= oy + height){
				return array[i];
			}
		}
	}
	return 0;
}

CCNode* Cocos2dFacade::FindChildByPoint(cocos2d::CCNode*** array,int firstLength,int secondLength,float x,float y)
{
	for(int h = 0 ; h < firstLength ; y++){
		for(int w = 0 ; w < secondLength ; w++){
			float ox,oy;
			float width,height;
			CCSize size = (array[h][w])->getContentSize();
			width = size.width;
			height = size.height;
			(array[h][w]->getPosition(&ox,&oy));


			if(ox <= x && x <= ox + width){
				if(oy <= y && y <= oy + height){
					return array[h][w];
				}
			}
		}
	}
	return 0;
}

