#include "EnemyShip4.hpp"

EnemyShip4::EnemyShip4(int arrivalTime, float hp, float xpos, float ypos, float xvel, float yvel,PlayerShip* p) : EnemyShip(arrivalTime,hp,0,xpos,ypos,xvel,yvel,82,94,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
}

void  EnemyShip4::update(){
	if(pos.x < width/2.0 + 20 && vel.x < 0)
		vel.x *= -1;
	if(pos.x > 780 - width/2.0 && vel.x > 0)
		vel.x *= -1;
	EnemyShip::update();
	if( t > 2 && hp > 0){
        minions.push_back(new EnemyShip6(pos.x,pos.y, p,missle));
        t = 0;
    }
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

void EnemyShip4::init(){
	shipTexture = Texture(loadImage(loadResource(RES_ENEMY4)));
	missle = Texture(loadImage(loadResource(RES_ENEMY6)));
	//missle = Texture(loadImage(loadResource(RES_EBULLET2)));
	explo = Texture( loadImage( loadResource( RES_EXPLODE ) ) );
}

void EnemyShip4::collide(){
	EnemyShip::collide();
}

void  EnemyShip4::draw(){
	if(hp>0)
		gl::draw(shipTexture,Vec2f(pos.x-width/2.0,pos.y-height/2.0));
	for(int i=0;i<minions.size();i++){
		minions[i]->draw();
	}
	for(int i=0;i<ex.size();i++){
		ex[i]->draw();
	}
}



