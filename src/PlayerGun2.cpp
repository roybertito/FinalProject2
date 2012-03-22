#include <iostream>
#include "PlayerGun2.hpp"

#define BPS 10
#define SPEED 15
#define DMG 75
#define pi 3.14159

void PlayerGun2::update(Vec2f mMouseLoc)
{
    t += 1/ci::app::AppBasic::get()->getFrameRate(); 
    if(firing)
    {
        if( t > 1.0/BPS)
        {
            bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/3), sin(pi/3))));
            bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/6), sin(pi/6))));
            bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/4), sin(pi/4))));
            bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/2), sin(pi/2))));
            bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(3*pi/4), sin(3*pi/4))));
            bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(5*pi/6), sin(5*pi/6))));
            bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(2*pi/3), sin(2*pi/3))));
            t = 0;
        }
    }
    
    for( int i=0;i<bullets.size();i++){
        bullets[i]->update();
        if( !bullets[i]->isAlive )
        {
			delete bullets[i];
			bullets.erase(bullets.begin()+i);
        }
    }
}

void PlayerGun2::init()
{
    bulletTexture = Texture(loadImage(loadResource(RES_BULLET)));
}

