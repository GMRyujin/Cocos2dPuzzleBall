/*
 * PlayerBall.h
 *
 *  Created on: 2012. 11. 2.
 *      Author: 류진영
 */

#ifndef PLAYERBALL_H_
#define PLAYERBALL_H_

#include "cocos2d.h"
#include "PuzzleBallDef.h"
#include <ryAndroidLib/Math/LMathLibrary.h>
#include <ryAndroidLib/Cobo2d/Physics/cbBox.h>

using namespace cocos2d;
using namespace LMathLibrary;

//TODO PlayerBall을 구현해야한다. 이 클래스는 플레이어 볼이며, 중력의 영향을 받고, 위치를 지정할수있으며 , 충돌이 가능하다. 이 클래스는 LMathLibrary 헤더파일을 포함한다.
//노드의 멤버인 schedule메소드는 함수가 등록되자마자 바로 실행이 된다. 이 메소드는 노드이 Layer 등록여부에 관계없이 등록이 되는 즉시 메소드가 호출된다.
//따라서 노드 자체에 스케쥴을하지않고, 해당레이어의 업데이트 구문에서 이 업데이트 메소드를 호출한다.
/**
 * @brief PlayerBall이다. 이 클래스는 플르에어 Sprite를 상속받는다.
 *
 * 이 객체는 스스로 자신을 업데이트 할수있다.
 * */
class PlayerBall{
public:
	PlayerBall(CCLayer* layer){
		this->Init(layer,0,0);
		LMathLibrary::LVector3D vec(1,1,1);
		LMathLibrary::LVector3D vec1(1,1,1);
		cbBox box;
		box.Update(10);
	}

	PlayerBall(CCLayer* layer,float x,float y){
		this->Init(layer,x,y);
	}

	void Init(CCLayer* layer,float x,float y)
	{
		this->power = 0;
		this->bApply = 0;
		ball = CCSprite::create("small_auq_ball.png");
		ball->setTag(TAG_BALL);
		ball->setPosition(ccp(x,y));
		this->layer = layer;
		this->gravity = 0;
	}

	/**
	 * @brief 볼을 등록한다.
	 * */
	void AddChild(){
		//노드의 등록과 함계 스케쥴 함수를 등록한다.
		layer->addChild(ball);
		//TODO bug : bApply를 초기화를 했으나, 계속 2로 출력된다. 따라서 이렇게 사용하지 않는다.
		//이것의 해결방법은 직접 스케쥴을 여기서 설정하지 않고, 레이어의  Update문에 직접 이 오브젝트를 Update 함수를 호출해준다.
		//ball->schedule(schedule_selector(PlayerBall::Update));
	}

	/**
	 *  @brief 이 볼의 위치를 지정한다.
	 * */
	void SetPosition(float x,float y){
		ball->setPosition(ccp(x,y));
	}

	/**
	 * @brief 이 볼의 힘을 지정한다.
	 * */
	void SetForce(float rad,float power){
		//TODO 아직 미구현됨. 각도에 따라 벡터를 조정할수있는 것이 필요함.
		//this->rad = rad;
		this->power = power;
	}

	void SetForce(float dx,float dy,float power){
		//dir.Normalize();
		this->power = power;

	}
	/**
	 * @brief 이 볼이 설정한 힘을 적용받는지에 대한 플레그이다.
	 * */
	void SetForceFlag(bool bApply){
		this->bApply = bApply;
	}
public:
	void Update(float dt){
		if(bApply){
			CCLOG("ball Address : %x, bApply : %d",ball,bApply);
			CCLOG("dt : %lf, ball->getPositionX() : %lf , this->power : %lf ",dt,ball->getPositionX(),this->power);

			 //ball->setPositionX(ball->getPositionX() + dir.GetX() * this->power * dt);
			 //ball->setPositionY(ball->getPositionY() + dir.GetY() * this->power * dt - gravity);
			 //gravity += 0.98f * dt;

			 //TODO PuzzleBallWorld를 통해서 블록들과 블록들의 크기를 가져와서 블록들과 충돌처리를 한다. 어디서 상속을 하냐하면.. CCLayer에 PuzzleBallWorld를 다중상속시킬까 생각중이다. ㅋㅋㅋ
		}
	}
private:
	//LMathLibrary::LVector2D dir;

	float gravity;
	float power;
	bool bApply;
	CCSprite* ball;
	CCLayer* layer;
};

#endif /* PLAYERBALL_H_ */
