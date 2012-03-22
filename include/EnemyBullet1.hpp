#ifndef FinalProject_EnemyBullet1_h
#define FinalProject_EnemyBullet1_h

#include "EnemyBullet.hpp"

class EnemyBullet1: public EnemyBullet{
public:
    EnemyBullet1(Vec2f pos);
	void collide(PlayerShip* p);
    void draw(Texture bullet);
	void update();
    float radius;
};

#endif
