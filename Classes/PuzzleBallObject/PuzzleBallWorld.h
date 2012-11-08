/*
 * PuzzleBallWorld.h
 *
 *  Created on: 2012. 11. 5.
 *      Author: NitroPigSoft02
 */

#ifndef PUZZLEBALLWORLD_H_
#define PUZZLEBALLWORLD_H_

#include "PuzzleBallDef.h"
#include "cocos2d.h"

using namespace cocos2d;

class PuzzleBallWorld{
public:
	virtual CCSprite* getBlocks(){
	}

	virtual int getBlocksLength(){

	}
private:
	PlayerBall* ball;
};



#endif /* PUZZLEBALLWORLD_H_ */
