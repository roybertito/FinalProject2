#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <iostream>

#include "PlayerShip.hpp"


#define DT .5f
#define THING 1/2.f
#define FRAMENO 1
#define SIZE 64
#define H_SPEED 10
#define V_SPEED 10
#define PLAYER_HP 10000
#define BAR_HEIGHT 30
#define BAR_WIDTH 400
#define COVER_WIDTH ( BAR_WIDTH - 21 )
#define COVER_HEIGHT ( BAR_HEIGHT - 21 )

float t = 0;

PlayerShip::PlayerShip()
{
	remainingLife = PLAYER_HP;
    mMouseLoc = Vec2f(600,400);
    tween = 0;
	state = 0;
	width = 64;
	height = 64;
	score = 0;
	pg = new PlayerGun1();
	rec = Rectf( Vec2f(mMouseLoc.x-width/2,mMouseLoc.y), Vec2f(mMouseLoc.x+width/2,mMouseLoc.y+height));
	initLife = PLAYER_HP;
	bar = Rectf( Vec2f(30, 720), Vec2f(30 + BAR_WIDTH, 720 + BAR_HEIGHT) );
}

void PlayerShip::init()
{
    shipTexture = Texture( loadImage( loadResource( RES_SHIPMAP ) ) );
	lifeBar = Texture(loadImage(loadResource(RES_LIFEBARLIGHT)));
    lifeCover = Texture(loadImage(loadResource(RES_LIFEBARCOVER)));
	explo = Texture( loadImage( loadResource( RES_EXPLODE ) ) );
    pg->init();
}

void PlayerShip::update()
{
    t += 1/ci::app::AppBasic::get()->getFrameRate(); 
	if(score > 1500)
		pg->level = 4;
	else if(score > 1000)
		pg->level = 3;
	else if (score > 500)
		pg->level = 2;
	rec = Rectf( Vec2f(mMouseLoc.x-width/2,mMouseLoc.y), Vec2f(mMouseLoc.x+width/2,mMouseLoc.y+height));
    if( state&1 )
    {
        mMouseLoc += Vec2f(H_SPEED, 0);
        tween = 1;
    }
    if( state&2 )
    {
        mMouseLoc -= Vec2f(H_SPEED, 0);
        tween = -1;
    }
    
    if( state&4 )
    {
        mMouseLoc += Vec2f(0, V_SPEED);
    }
    if( state&8 )
    {
        mMouseLoc -= Vec2f(0, V_SPEED);
    }
    
    if( (state&3) == 0 ){
        tween = 0;
    }
    pg->update(mMouseLoc-Vec2f(7,0));
}

void PlayerShip::draw()
{
	cinder::gl::draw( shipTexture, Area(Vec2f(SIZE*(floor(tween)+FRAMENO), 0), Vec2f(SIZE*(floor(tween)+FRAMENO) + SIZE, SIZE)), Rectf(mMouseLoc - Vec2f(SIZE/2,0), mMouseLoc + Vec2f(SIZE/2,SIZE)) );
	Vec2f hpbar = Vec2f(41, 731);
	float percent = remainingLife/initLife;
	if(percent < 0)
		percent = 0;
	Vec2f life = Vec2f(40 + COVER_WIDTH * percent, 731 + COVER_HEIGHT);
	Rectf cover = Rectf(hpbar,life);
	cinder::gl::draw( lifeBar, bar );
    gl::color(44/255.0f,230/255.0f,131/255.0f,0.5f);
    drawSolidRect(cover);
    pg->draw();
}

void PlayerShip::onKeyDown(KeyEvent &e)
{
    if ( e.getCode() == KeyEvent::KEY_RIGHT ) {
        state |= 1;
    }
    
    if( e.getCode() == KeyEvent::KEY_LEFT ){
        state |= 2;
    }
    
    if( e.getCode() == KeyEvent::KEY_UP ){
        state |= 8;
    }
    
    if( e.getCode() == KeyEvent::KEY_DOWN ){
        state |= 4;
    }
    
    if( e.getCode() == KeyEvent::KEY_SPACE ){
        pg->firing = true;
    }
}

void PlayerShip::onKeyUp(KeyEvent &e)
{
    if ( e.getCode() == KeyEvent::KEY_RIGHT ) {
        state &= 14;    
    }
    
    if( e.getCode() == KeyEvent::KEY_LEFT ){
        state &= 13;
    }
    
    if( e.getCode() == KeyEvent::KEY_UP ){
        state &= 7;
    }
    
    if( e.getCode() == KeyEvent::KEY_DOWN ){
        state &= 11;
    }
    
    if( e.getCode() == KeyEvent::KEY_SPACE ){
        pg->firing = false;
    }
}