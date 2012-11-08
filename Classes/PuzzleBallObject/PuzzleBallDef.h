/*
 * PuzzleBallDef.h
 *
 *  Created on: 2012. 11. 5.
 *      Author: NitroPigSoft02
 */

#ifndef PUZZLEBALLDEF_H_
#define PUZZLEBALLDEF_H_

typedef class interface;

#define TAG_BALL 3
#define TAG_BLOCK 10

#define BLOCK_SIZE 128

#define GETTER(varType,varName) 	\
	public : virtual varType get##varName(){return varName;}

#define SETTER(varType,varName)		\
	public : virtual void set##varName(varType var){varName = var;}

#include <cocos2d.h>
#include <Box2d/Box2D.h>
#include <ryAndroidLib/Cobo2d/Facade/Box2dFacade.h>
#include <ryAndroidLib/Cobo2d/Facade/cbFacade.h>
#include <ryAndroidLib/Cobo2d/Facade/Cocos2dFacade.h>

#endif /* PUZZLEBALLDEF_H_ */
