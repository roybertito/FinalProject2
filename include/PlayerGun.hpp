#ifndef FinalProject_PlayerGun_hpp
#define FinalProject_PlayerGun_hpp

#include "PlayerBullet.hpp"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <vector>
#include "Resources.h"
#include "SoundPlayer.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class PlayerGun
{
public:
	SoundPlayer sp2;
	bool firing;
	float t;
	int level;
	Texture bulletTexture;
	vector<Texture> texts;
    vector<PlayerBullet*> bullets;
	PlayerGun() : firing(false), t(0), level(1){}
	virtual void update(Vec2f mMouseLoc){}
    virtual void draw(){
		for( int i=0;i<bullets.size();i++ )
			bullets[i]->draw();
	}
	virtual void init(){}
   
   
};

#endif