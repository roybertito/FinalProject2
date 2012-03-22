#ifndef FinalProject_EnemyShip_h
#define FinalProject_EnemyShip_h

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <iostream>
#include "Resources.h"
#include "EnemyGun.hpp"
#include "PlayerShip.hpp"
#include "Explode.hpp"
#include "SoundPlayer.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class EnemyShip
{
public:
	//SoundPlayer sp3;
    EnemyShip(int arrivalTime, float hp, float atkspd, float xpos, float ypos, float xvel, float yvel, float width, float height,PlayerShip* p);
    vector<EnemyGun*> eg;
	vector<Explode*> ex;
    virtual void draw();
	virtual void update();
	virtual void collide();
	virtual void init();
	/*void boom() {
		for(int i=0;i<ex.size();i++){
			if(ex[i]->isAlive){
				sp3.playSFX(6);
			}
		}
	}*/
	int arrivalTime,bulletType;
	float hp, width, height;
	Vec2f pos, vel;
	Rectf rec;
	Texture shipTexture,explo;
	PlayerShip* p;
	float atkspd;
	bool firing;
	float t;
};

#endif
