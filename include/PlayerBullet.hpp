#ifndef FinalProject_PlayerBullet_hpp
#define FinalProject_PlayerBullet_hpp

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class PlayerBullet
{
public:
    PlayerBullet();
	enum Type{Bullet, Laser, Missle} type;
    PlayerBullet(Vec2f pos, float dmg, float radius, Vec2f vel,Type type,Texture bullet);
	void draw();
	void update(Vec2f loc);
	float dmg, radius,width,height;
	Texture bullet;
	Vec2f pos, vel;
	int tween;
	bool isAlive;
};

#endif