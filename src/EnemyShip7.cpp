#include "EnemyShip7.hpp"

EnemyShip7::EnemyShip7(float xpos, float ypos, PlayerShip* p,Texture text) : EnemyShip(0,400,0,xpos,ypos,0,75,35,225,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	shipTexture = text;
	initVel = 75;
	tween = 11;
}

void  EnemyShip7::update(){
	tween++;
	if(tween > 11)
		tween = 0;
	EnemyShip::update();
}

void EnemyShip7::collide(){
	bool col = false;
	if( (p->rec.getX1() <= rec.getX2() && p->rec.getX1() >= rec.getX1() )|| (p->rec.getX2() >= rec.getX1() && p->rec.getX2() <= rec.getX2())){
		if( (p->rec.getY1() <= rec.getY2() && p->rec.getY1() >= rec.getY1() )|| (p->rec.getY2() >= rec.getY1() && p->rec.getY2() <= rec.getY2())){
			col = true;
		} 
	}
	if( (rec.getX1() <= p->rec.getX2() && rec.getX1() >= p->rec.getX1() )|| (rec.getX2() >= p->rec.getX1() && rec.getX2() <= p->rec.getX2())){
		if( (rec.getY1() <= p->rec.getY2() && rec.getY1() >= p->rec.getY1() )|| (rec.getY2() >= p->rec.getY1() && rec.getY2() <= p->rec.getY2())){
			col = true;
		} 
	}
	if(col){
		int temp = p->remainingLife;
			if (hp > temp){
				p->remainingLife = 0;
				hp -= temp;
			}
			else{
				p->remainingLife -= hp;
				hp = 0;
			}
			for(int j=0;j<eg.size();j++)
				eg[j]->firing = false;
			firing = false;
			return;
	}
}

void  EnemyShip7::draw(){
	if(hp>0)
		gl::draw( shipTexture, Area(Vec2f(35*tween, 0), Vec2f(35*tween + 35, 225)), Rectf(pos - Vec2f(17.5,0), pos + Vec2f(17.5,225)));
	for(int j=0;j<ex.size();j++)
		ex[j]->draw();
}




