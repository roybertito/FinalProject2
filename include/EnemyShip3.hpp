#ifndef FinalProject_EnemyShip3_h
#define FinalProject_EnemyShip3_h

#include "EnemyShip.hpp"
#include "EnemyShip7.hpp"
#include "PlayerBullet.hpp"

class EnemyShip3: public EnemyShip{
public:
	vector<EnemyShip7*> minions;
	Texture missle;
	EnemyShip3(int arrivalTime, float hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p);
	void draw();
	void update();
	void collide();
	void init();
};
#endif