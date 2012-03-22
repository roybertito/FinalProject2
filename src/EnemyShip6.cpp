#include "EnemyShip6.hpp"

EnemyShip6::EnemyShip6(float xpos, float ypos, PlayerShip* p,Texture text) : EnemyShip(0,400,0,xpos,ypos,50,50,23.5,97,p)
{
	rec = Rectf( Vec2f(pos.x-width/2,pos.y-height/2), Vec2f(pos.x+width/2,pos.y+height/2));
	shipTexture = text;
	initVel = 50;
	explo = Texture( loadImage( loadResource( RES_EXPLODE ) ) );
	tween = 0;
}

void  EnemyShip6::update(){
	tween++;
	if(tween > 16)
		tween = 0;
	float dis = pos.distance(p->mMouseLoc);
	float speed = pos.distance(vel);
	t += 1/ci::app::AppBasic::get()->getFrameRate();
	pos += Vec2f(((p->mMouseLoc.x - pos.x) / dis) * (speed/90), ((p->mMouseLoc.y - pos.y) / dis) * (speed/90));
	rec = Rectf( Vec2f(pos.x-width/2.0,pos.y-height/2.0), Vec2f(pos.x+width/2.0,pos.y+height/2.0));
	for(int i=0;i<ex.size();i++){
		if(ex[i]->isAlive)
			ex[i]->update();
		else{
			delete ex[i];
			ex.erase(ex.begin()+i);
		}
	}
}

void EnemyShip6::collide(){
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
			ex.push_back(new Explode(pos,5,explo,0));
			return;
	}
	for(int i=0;i<p->pg->bullets.size();i++){
		Vec2f closestPoint,diff;
		switch(p->pg->bullets[i]->type){
		case PlayerBullet::Bullet:
			closestPoint = p->pg->bullets[i]->pos;
			if( p->pg->bullets[i]->pos.x > rec.getX2() ) closestPoint.x = rec.getX2();
			else if( p->pg->bullets[i]->pos.x < rec.getX1() ) closestPoint.x = rec.getX1();
			if( p->pg->bullets[i]->pos.y > rec.getY2() ) closestPoint.y = rec.getY2();
			else if( p->pg->bullets[i]->pos.y < rec.getY1() ) closestPoint.y = rec.getY1();
    
			diff = closestPoint -  p->pg->bullets[i]->pos;
			if( diff.x * diff.x + diff.y * diff.y > p->pg->bullets[i]->radius * p->pg->bullets[i]->radius){}
			else{
				hp -= p->pg->bullets[i]->dmg;
				p->pg->bullets[i]->isAlive = false;
				delete p->pg->bullets[i];
				p->pg->bullets.erase(p->pg->bullets.begin()+i);
				if(hp <= 0){
					p->score += 100;
					ex.push_back(new Explode(pos,5,explo,0));
					firing = false;
					return;
				}
			}
			break;
		case PlayerBullet::Laser:
			bool col = false;
			if( (p->mMouseLoc.x - 70.5 <= rec.getX2() && p->mMouseLoc.x - 70.5 >= rec.getX1() )|| (p->mMouseLoc.x + 70.5 >= rec.getX1() && p->mMouseLoc.x + 70.5 <= rec.getX2())){
				if( p->mMouseLoc.y >= rec.getY2() ){
					col = true;
				} 
			}
			if( (rec.getX1() <= p->mMouseLoc.x + 70.5 && rec.getX1() >= p->mMouseLoc.x - 70.5 )|| (rec.getX2() >= p->mMouseLoc.x - 70.5 && rec.getX2() <= p->mMouseLoc.x + 70.5)){
				if( p->mMouseLoc.y >= rec.getY2() ){
					col = true;
				} 
			}
			if(col){
				p->pg->bullets[0]->height = rec.getY2();
				hp -= 50;
				if(hp <= 0){
					p->score += 100;
					ex.push_back(new Explode(pos,5,explo,0));
				}
			}
			break;
		}
	}
}

void  EnemyShip6::draw(){
	if(hp>0)
		gl::draw( shipTexture, Area(Vec2f(23.5*tween, 0), Vec2f(23.5*tween + 23.5, 97)), Rectf(pos - Vec2f(11.75,0), pos + Vec2f(11.75,97)));
	for(int j=0;j<ex.size();j++)
		ex[j]->draw();
}




