#include "GamePlayerBall.h"

GamePlayerBall::GamePlayerBall(char* fileName,float width,float height)
{

}

GamePlayerBall* GamePlayerBall::Create(char* fileName,float width,float height)
{
	return new GamePlayerBall(fileName,width,height);
}
