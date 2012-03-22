#ifndef FinalProject_EnemyShip6_h
#define FinalProject_EnemyShip6_h

#include "EnemyShip.hpp"
#include "PlayerBullet.hpp"

class EnemyShip6: public EnemyShip{
public:
	EnemyShip6(float xpos, float ypos,PlayerShip* p,Texture text);
	void draw();
	void update();
	void collide();
	void init(){};
	float initVel;
	int tween;
};
#endif