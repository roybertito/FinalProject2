#ifndef FinalProject_EnemyGun1_hpp
#define FinalProject_EnemyGun1_hpp

#include "EnemyGun.hpp"

class EnemyGun1 : public EnemyGun{
public:
    EnemyGun1(float atkspeed);
	void update(Vec2f pos);
    void draw();
};


#endif