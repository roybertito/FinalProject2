#include <iostream>
#include "PlayerBullet.hpp"
#include "PlayerShip.hpp"
#include "MainScene.hpp"
#define SPEED 15

PlayerBullet::PlayerBullet(Vec2f mMouseLoc, float dmg, float radius, Vec2f vel, Type type,Texture bullet)
{
    pos = mMouseLoc;
	this->vel = vel;
	isAlive = true;
    this->dmg = dmg;
	this->radius = radius;
	this->type = type;
	height = -50;
	tween = 0;
	this->bullet = bullet;
}

void PlayerBullet::update(Vec2f loc)
{
	height = -50;
	switch(type){
	case Bullet:
		pos -= vel*SPEED;
		if(pos.y < 0)
		{
			isAlive = false;
		}
		break;
	case Laser:
		pos = loc;
		tween++;
		if(tween > 4)
			tween = 0;
		break;
	}
}

void PlayerBullet::draw()
{
	color(128,255,255);
	switch(type){
	case Bullet:
		cinder::gl::draw( bullet, Vec2f(pos.x-radius/2.0,pos.y-radius/2.0));
		break;
	case Laser:
		cinder::gl::draw( bullet, Area(Vec2f(140*tween,0),Vec2f(140*tween + 140,238)),Rectf(Vec2f(pos.x -70.5,height), Vec2f(pos.x + 70.5,pos.y)));
		break;
	}
}