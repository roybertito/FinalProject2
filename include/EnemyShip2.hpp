#ifndef FinalProject_EnemyShip2_h
#define FinalProject_EnemyShip2_h

#include "EnemyShip.hpp"
#include "PlayerBullet.hpp"

class EnemyShip2: public EnemyShip{
public:
	EnemyShip2(int arrivalTime, float hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p);
	void draw();
	void update();
	void collide();
	void init();
};
#endif