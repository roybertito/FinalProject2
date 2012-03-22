#include <iostream>
#include "PlayerGun1.hpp"

#define BPS 10
#define SPEED 15
#define DMG 75
#define pi 3.14159


void PlayerGun1::update(Vec2f mMouseLoc)
{
    t += 1/ci::app::AppBasic::get()->getFrameRate(); 
    if(firing)
    {
        if( t > 1.0/BPS)
        {
			switch(level){
			case 1:
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/2), sin(pi/2)),PlayerBullet::Bullet,texts[0]));
				sp2.playSFX(0);
				break;
			case 2:
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/3), sin(pi/3)),PlayerBullet::Bullet,texts[0]));
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/2), sin(pi/2)),PlayerBullet::Bullet,texts[0]));
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(2*pi/3), sin(2*pi/3)),PlayerBullet::Bullet,texts[0]));
				sp2.playSFX(1);
				break;
			case 3:
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/3), sin(pi/3)),PlayerBullet::Bullet,texts[0]));
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/6), sin(pi/6)),PlayerBullet::Bullet,texts[0]));
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/4), sin(pi/4)),PlayerBullet::Bullet,texts[0]));
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(pi/2), sin(pi/2)),PlayerBullet::Bullet,texts[0]));
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(3*pi/4), sin(3*pi/4)),PlayerBullet::Bullet,texts[0]));
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(5*pi/6), sin(5*pi/6)),PlayerBullet::Bullet,texts[0]));
				bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(2*pi/3), sin(2*pi/3)),PlayerBullet::Bullet,texts[0]));
				sp2.playSFX(2);
				break;
			case 4:
				bulletTexture = texts[1];
				int count=0;
				for(int i=0;i<bullets.size();i++){
					if(bullets[i]->type == PlayerBullet::Laser)
						count++;
				}
				if(count == 0)
					bullets.push_back(new PlayerBullet(mMouseLoc,50,15,Vec2f(cos(2*pi/2), sin(2*pi/2)),PlayerBullet::Laser,texts[1]));
				sp2.playSFX(3);
				break;
			}
            t = 0;
        }
    }
	else{
		if(level == 4){
			for(int i=0;i<bullets.size();i++){
				delete bullets[i];
				bullets.erase(bullets.begin()+i);
			}
		}
	}
    
    for( int i=0;i<bullets.size();i++){
        bullets[i]->update(mMouseLoc);
        if( !bullets[i]->isAlive )
        {
			delete bullets[i];
			bullets.erase(bullets.begin()+i);
        }
    }
}

void PlayerGun1::init()
{
	texts.push_back(Texture(loadImage(loadResource(RES_BULLET))));
	texts.push_back(Texture(loadImage(loadResource(RES_LASER))));
}

