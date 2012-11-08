/*
 * NormalBlock.h
 *
 *  Created on: 2012. 11. 5.
 *      Author: NitroPigSoft02
 */

#ifndef NORMALBLOCK_H_
#define NORMALBLOCK_H_

#include "cocos2d.h"
#include "PuzzleBallDef.h"
#include <ryAndroidLib/Cobo2d/Facade/Cocos2dFacade.h>

using namespace cocos2d;


/**
 * @brief 보통 블록이다.
 * */
class NormalBlock{
public:
	NormalBlock(CCLayer* layer){
		Init(layer,0,0);
	}

	NormalBlock(CCLayer* layer,float x,float y){
		Init(layer,x,y);
	}

	void Init(CCLayer* layer,float x,float y){
		this->layer = layer;
		sp = Cocos2dFacade::CreateSprite("small_concrete_block.jpg");
		sp->setPosition(ccp(x,y));
	}

	void Update(float dt){
		//여기서  PlayerBall과 부딛힐경우를 처리한다.
	}
private:
	CCLayer* layer;
	CCSprite* sp;
};




#endif /* NORMALBLOCK_H_ */
