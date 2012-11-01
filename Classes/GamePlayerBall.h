#ifndef __GAMEPLAYERBALL_H__
#define __GAMEPLAYERBALL_H__

#include "cocos2d.h"
using namespace cocos2d;

class GamePlayerBall : public CCSprite{
private:
	float width,height;
	char* fileName;
public:
	GamePlayerBall(char* fileName,float width,float height);
	GamePlayerBall* Create(char* fileName,float width,float height);
	void GetPos(float x,float y);
	void SetPos(float x,float y);
};







#endif
