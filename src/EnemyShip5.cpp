#include "EnemyShip5.hpp"

EnemyShip5::EnemyShip5(int arrivalTime, float hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,444,200,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	eg.push_back(new EnemyGun(atkspd,p));
	eg.push_back(new EnemyGun(atkspd,p));
	angle = 0;
	initHP = hp;
}

void  EnemyShip5::update(){
	if(pos.y  >= 150)
		vel.y = 0;
	if(pos.x < width/2.0 + 20 && vel.x < 0)
		vel.x *= -1;
	if(pos.x > 780 - width/2.0 && vel.x > 0)
		vel.x *= -1;
	EnemyShip::update();
	if(pos.x-width-100 < p->mMouseLoc.x && pos.x+width+100 > p->mMouseLoc.x && hp > 0){
		if(pos.y < p->mMouseLoc.y)
			firing=true;
	}
	else
		firing=false;
	eg[0]->firing=firing;
	eg[0]->update(Vec2f(pos.x,pos.y+height/2),Vec2f(0,5));
	eg[1]->firing=firing;
	eg[1]->update(Vec2f(pos.x+width/2.0,pos.y-height/2),Vec2f(-1*angle,5));
	eg[2]->firing=firing;
	eg[2]->update(Vec2f(pos.x-width/2.0,pos.y-height/2),Vec2f(1*angle,5));
	if(firing){
		if((int)(t*ci::app::AppBasic::get()->getFrameRate())%(int)(ci::app::AppBasic::get()->getFrameRate()/2) == 0)
			angle += 1;
		if(t>5){
			t=0;
			angle=0;
		}
	}
	for(int i=0;i<ex.size();i++){
		if(ex[i]->isAlive)
			ex[i]->update();
		else{
			delete ex[i];
			ex.erase(ex.begin()+i);
		}
	}
}

void EnemyShip5::init(){
	shipTexture = Texture(loadImage(loadResource(RES_ENEMY5)));
	bar = Texture(loadImage(loadResource(RES_ENEMYHP)));
	EnemyShip::init();
}

void EnemyShip5::collide(){
	EnemyShip::collide();
}

void  EnemyShip5::draw(){
	if(hp>0){
		gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
		gl::draw(bar,Vec2f(15,15));
		Vec2f hpbar = Vec2f(20,30);
		float percent = hp/initHP;
		if(percent <= 0)
			percent = 0;
		Vec2f life = Vec2f(hpbar.x+475*percent,40);
		Rectf rec = Rectf(hpbar,life);
		gl::color(1,0,0);
		gl::drawSolidRect(rec);
		gl::color(1,1,1);
		
	}
	EnemyShip::draw();
}



