#include "EnemyShip3.hpp"

EnemyShip3::EnemyShip3(int arrivalTime, float hp, float atkspd, float xpos, float ypos, float xvel, float yvel,PlayerShip* p) : EnemyShip(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,40,54,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
}

void  EnemyShip3::update(){
	float dis = pos.distance(p->mMouseLoc);
	float speed = pos.distance(vel);
	t += 1/ci::app::AppBasic::get()->getFrameRate();
	pos += Vec2f(((p->mMouseLoc.x - pos.x) / dis) * (speed/180), ((p->mMouseLoc.y - pos.y) / dis) * (speed/180));
	rec = Rectf( Vec2f(pos.x-width/2.0,pos.y-height/2.0), Vec2f(pos.x+width/2.0,pos.y+height/2.0));
	for(int i=0;i<minions.size();i++){
		minions[i]->update();
		if(minions[i]->hp > 0)
			minions[i]->collide();
		else{
			if(minions[i]->ex.size() <= 0){
				delete minions[i];
				minions.erase(minions.begin()+i);
			}
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

void EnemyShip3::init(){
	shipTexture = Texture(loadImage(loadResource(RES_ENEMY3)));
	missle = Texture(loadImage(loadResource(RES_EBULLET2)));
	explo = Texture( loadImage( loadResource( RES_EXPLODE ) ) );
}

void EnemyShip3::collide(){
	EnemyShip::collide();
}

void  EnemyShip3::draw(){
	if(hp>0)
		gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	for(int i=0;i<minions.size();i++){
		minions[i]->draw();
	}
	for(int i=0;i<ex.size();i++){
		ex[i]->draw();
	}
}