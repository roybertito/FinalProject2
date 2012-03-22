#ifndef FinalProject_PlayerShip_h
#define FinalProject_PlayerShip_h

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Explode.hpp"
#include "PlayerGun1.hpp"
#include "Resources.h"
#include "cinder/app/KeyEvent.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class PlayerShip
{
public:
    PlayerShip();
    void update();
    void draw();
    void init();
    void onKeyDown(KeyEvent &e);
    void onKeyUp(KeyEvent &e);
    Vec2f mMouseLoc;
    Vec2f loc;
    int width, height;
	Rectf bar,rec;
    Texture shipTexture, lifeBar, lifeCover, explo;
	vector<Explode*> ex;
    PlayerGun* pg;
	float remainingLife, initLife;
	int score;
	int state;
private:
    float tween;
};

#endif
