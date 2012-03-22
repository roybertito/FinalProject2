#include "Explode.hpp"

Explode::Explode(Vec2f pos, int pts, Texture text, int tween){
	this->pos = pos;
	points = pts;
	explo = text;
	this->tween = 0;
	t=0;
	isAlive = true;
}

void  Explode::update(){
	t += 1/ci::app::AppBasic::get()->getFrameRate();
	if(t > 2*1/ci::app::AppBasic::get()->getFrameRate()){
		tween++;
		t = 0;
	}
	if(tween == 35)
		isAlive = false;
}


void  Explode::draw(){
	if(tween < 6)
		gl::draw( explo, Area(Vec2f(100*tween, 0), Vec2f(100*tween + 100, 100)), Rectf(pos - Vec2f(50,0), pos + Vec2f(50,100)));
	else if(tween < 12)
		gl::draw( explo, Area(Vec2f(100*tween, 100), Vec2f(100*tween + 100, 200)), Rectf(pos - Vec2f(50,0), pos + Vec2f(50,100)));
	else if(tween < 18)
		gl::draw( explo, Area(Vec2f(100*tween, 200), Vec2f(100*tween + 100, 300)), Rectf(pos - Vec2f(50,0), pos + Vec2f(50,100)));
	else if(tween < 24)
		gl::draw( explo, Area(Vec2f(100*tween, 300), Vec2f(100*tween + 100, 400)), Rectf(pos - Vec2f(50,0), pos + Vec2f(50,100)));
	else if(tween < 30)
		gl::draw( explo, Area(Vec2f(100*tween, 400), Vec2f(100*tween + 100, 500)), Rectf(pos - Vec2f(50,0), pos + Vec2f(50,100)));
	else if(tween < 36)
		gl::draw( explo, Area(Vec2f(100*tween, 500), Vec2f(100*tween + 100, 600)), Rectf(pos - Vec2f(50,0), pos + Vec2f(50,100)));
}