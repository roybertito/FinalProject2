#ifndef FinalProject_PlayerGun2_hpp
#define FinalProject_PlayerGun2_hpp

#include "PlayerGun.hpp"

class PlayerGun2 : public PlayerGun
{
public:
	PlayerGun2():PlayerGun(){}
    void update(Vec2f mMouseLoc);
    void init();
};

#endif