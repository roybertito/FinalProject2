#ifndef FinalProject_EnemyShip1_h
#define FinalProject_EnemyShip1_h

#include "EnemyShip.hpp"
#include "PlayerBullet.hpp"

class EnemyShip1: public EnemyShip{
public:
	EnemyShip1(int arrivalTime, float hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p);
	void draw();
	void update();
	void collide();
	void init();
};
#endif
