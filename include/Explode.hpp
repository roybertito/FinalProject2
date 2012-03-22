#ifndef FinalProject_Explode_h
#define FinalProject_Explode_h

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <iostream>
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class Explode
{
public:
    Explode(Vec2f pos, int pts, Texture text,int tween);
    virtual void draw();
	virtual void update();
	Vec2f pos;
	Texture explo;
	int points,tween;
	float t;
	bool isAlive;
};

#endif