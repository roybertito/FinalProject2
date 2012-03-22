#ifndef FinalProject_EnemyShip7_h
#define FinalProject_EnemyShip7_h

#include "EnemyShip.hpp"
#include "PlayerBullet.hpp"

class EnemyShip7: public EnemyShip{
public:
	EnemyShip7(float xpos, float ypos,PlayerShip* p,Texture text);
	void draw();
	void update();
	void collide();
	void init(){};
	float initVel;
	int tween;
};
#endif