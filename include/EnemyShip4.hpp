#ifndef FinalProject_EnemyShip4_h
#define FinalProject_EnemyShip4_h

#include "EnemyShip6.hpp"
#include "PlayerBullet.hpp"

class EnemyShip4: public EnemyShip{
public:
	EnemyShip4(int arrivalTime, float hp, float xpos, float ypos, float xvel, float yvel,PlayerShip* p);
	void draw();
	void update();
	void collide();
	void init();
	Texture missle;
	vector<EnemyShip6*> minions;
};
#endif