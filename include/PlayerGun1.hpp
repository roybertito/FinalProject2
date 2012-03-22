#ifndef FinalProject_PlayerGun1_hpp
#define FinalProject_PlayerGun1_hpp

#include "PlayerGun.hpp"

class PlayerGun1 : public PlayerGun
{
public:
	PlayerGun1():PlayerGun(){}
    void update(Vec2f mMouseLoc);
    void init();
};

#endif