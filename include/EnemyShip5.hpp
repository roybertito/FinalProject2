#ifndef FinalProject_EnemyShip5_h
#define FinalProject_EnemyShip5_h

#include "EnemyShip.hpp"
#include "PlayerBullet.hpp"

class EnemyShip5: public EnemyShip{
public:
	EnemyShip5(int arrivalTime, float hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p);
	void draw();
	void update();
	void collide();
	void init();
	Texture bar;
	float angle,initHP;
};
#endif