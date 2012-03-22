#ifndef FinalProject_MainScene_hpp
#define FinalProject_MainScene_hpp

#include "SoundPlayer.hpp"
#include "PauseScene.hpp"
#include "SceneManager.hpp"
#include "PlayerShip.hpp"
#include "EnemyShip.hpp"
#include "EnemyShip1.hpp"
#include "EnemyShip2.hpp"
#include "EnemyShip3.hpp"
#include "EnemyShip4.hpp"
#include "EnemyShip5.hpp"
#include "EnemyShip6.hpp"
#include "cinder/Rect.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


#define FPS 60.0f

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace gl;

class MainScene : public SceneManager::Scene {
    virtual void onDeactivate(SceneManager &sm) {
		//delete this;
	}
    
    virtual void onActivate(){
        ps.state = 0;
        ps.pg->firing = false;
    }
    PauseScene pause;
public:
	MainScene() : pause(this) {};
	virtual void draw();
	virtual void update();
	void onKeyUp(KeyEvent &e);
    void onKeyDown(KeyEvent &e);
    void setup();
    void mouseDown( MouseEvent &event );
    void mouseUp( MouseEvent &event );
    void mouseMove( MouseEvent &event );    
    void mouseDrag( MouseEvent &event );
    virtual void onLoad();
    void createLevel();
    Vec2f mMouseLoc;
    PlayerShip ps;
	float time;
	float dt;
	vector<EnemyShip*> enemy;
};




#endif


