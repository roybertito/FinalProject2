#include "EnemyShip2.hpp"

EnemyShip2::EnemyShip2(int arrivalTime, float hp, float atkspd, float xpos, float ypos, float xvel, float yvel, PlayerShip* p) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,60,74,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	eg.push_back(new EnemyGun(atkspd,p));

}

void EnemyShip2::update(){
	float dis = pos.distance(Vec2f(p->mMouseLoc.x,p->mMouseLoc.y-400));
	float speed = pos.distance(vel);
	t += 1/ci::app::AppBasic::get()->getFrameRate();
	pos += Vec2f(((p->mMouseLoc.x - pos.x) / dis) * (speed/120), ((p->mMouseLoc.y-400 - pos.y) / dis) * (speed/120));
	if(pos.y - height < 0)
		pos.y = height;
	rec = Rectf( Vec2f(pos.x-width/2.0,pos.y-height/2.0), Vec2f(pos.x+width/2.0,pos.y+height/2.0));
	if(pos.x-width-200 < p->mMouseLoc.x && pos.x+width+200 > p->mMouseLoc.x && hp > 0){
		if(pos.y < p->mMouseLoc.y)
			firing=true;
	}
	else
		firing=false;
	for(int i=0;i<eg.size();i++)
		eg[i]->firing = firing;
	eg[0]->update(Vec2f(pos.x-width/3,pos.y-height/2),Vec2f(0,8));
	eg[1]->update(Vec2f(pos.x+width/3,pos.y-height/2),Vec2f(0,8));
	for(int i=0;i<ex.size();i++){
		if(ex[i]->isAlive)
			ex[i]->update();
		else{
			delete ex[i];
			ex.erase(ex.begin()+i);
		}
	}
}

void EnemyShip2::init(){
	shipTexture = Texture(loadImage(loadResource(RES_ENEMY2)));
	EnemyShip::init();
}

void EnemyShip2::collide(){
	EnemyShip::collide();
}

void  EnemyShip2::draw(){
	if(hp>0)
		gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	EnemyShip::draw();
}