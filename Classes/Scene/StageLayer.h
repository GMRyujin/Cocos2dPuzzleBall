/*
 * StageLayer.h
 *
 *  Created on: 2012. 11. 9.
 *      Author: Ryu jin-young
 *      Email : GMRyuj@Gmail.com
 */

#ifndef STAGELAYER_H_
#define STAGELAYER_H_

#include <cocos2d.h>
#include <Box2D/Box2d.h>

using namespace cocos2d;

#define PHYSICS_BLOCK_NUM 20

class StageLayer {
	//배경화면을 설정한다.
	void SetBackground();
	//World를 설정한다.
	void SetWorld();
	//플레이어 설정한다.
	void SetPlayerBall(float x, float y);
	//블록 설정한다.
	void SetBlocks();
	//목표지점 추가
	void SetGoal(float x, float y);
	//공이 목표지점에 닿았는지 확인한다.
	bool CheckGoal();

private:
	bool bTouchDown;
	float power;
	b2World* world;
	b2Body* playerBall;
	b2Body* ground;

	b2Body* blocks[PHYSICS_BLOCK_NUM];
};

#endif /* STAGELAYER_H_ */
