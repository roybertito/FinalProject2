#ifndef FinalProject_Header_h
#define FinalProject_Header_h

#include "SceneManager.hpp"
#include "Resources.h"

#define PAUSESCENE_TRANSITION_DURATION 0.3f
#define XPOS 875
#define PAD (10 + pointer.getWidth())

class PauseScene : public SceneManager::Scene {
	SceneManager::Scene *base;
	float trans;
	enum State { In, Active, Out } state;
    enum Selected {Resume, Back, Quit} selected;
    Texture pauseTexture;
    Texture pointer;
    Texture resume, back, quit;
    Font k;
    Selected prev;
    float thingy;
public:
	PauseScene(SceneManager::Scene *base) : base(base), trans(0), state(In), selected(Resume), thingy(0) {}
    
    void init()
    {
        pauseTexture = Texture(loadImage(loadResource(RES_PAUSE)));
        pointer = Texture(loadImage(loadResource(RES_POINTER)));
        resume = Texture(loadImage(loadResource(RES_RESUME)));
        back = Texture(loadImage(loadResource(RES_BACK)));
        quit = Texture(loadImage(loadResource(RES_QUIT)));
    }
    
    void onActivate()
    {
        selected = Resume;
		getManager()->setSPBGMVolume(0.5f);
    }
	
	virtual void draw() {
		if ( base ){
			base->draw();
        }
		
		ci::app::AppBasic *a = ci::app::AppBasic::get();
		
		const float t = trans/PAUSESCENE_TRANSITION_DURATION;
		const float x = t*t*(3 - 2 * t);
		
        ColorA c(213/255.f, 213/255.f, 213/255.f, 1.f * x);
		ci::gl::color(0.0f,0.0f,0.0f, 0.75f * x);
		ci::gl::drawSolidRect(ci::Rectf(0,0,a->getWindowWidth(), a->getWindowHeight()));
        
		ci::gl::color(1.0f,1.0f,1.0f, 1.0f * x);
        ci::gl::draw(pauseTexture, Vec2f(0,0));
        
        ci::gl::draw(resume, ci::Vec2f(XPOS - resume.getWidth(), 320));
        ci::gl::draw(back, ci::Vec2f(XPOS - back.getWidth(), 420));
        ci::gl::draw(quit, ci::Vec2f(XPOS - quit.getWidth(), 520));
        
        switch (selected) {
            case Resume:
                ci::gl::draw(pointer, Vec2f(XPOS - resume.getWidth() - PAD,323));
                break;
            case Back:
                ci::gl::draw(pointer, Vec2f(XPOS - back.getWidth() - PAD,433));
                break;
            case Quit:
                ci::gl::draw(pointer, Vec2f(XPOS - quit.getWidth() - PAD,533));
                break;
        }
	}
	
	virtual void update() {
		switch ( state ) {
			case In:
				if ( trans < PAUSESCENE_TRANSITION_DURATION )
					trans += 1/ci::app::AppBasic::get()->getFrameRate();
				else {
					trans = PAUSESCENE_TRANSITION_DURATION;
					state = Active;
				}
				break;
			case Active:
				break;
			case Out:
				if ( trans > 0 )
					trans -= 1/ci::app::AppBasic::get()->getFrameRate();
				else {
					trans = 1/ci::app::AppBasic::get()->getFrameRate();
					state = In;
					getManager()->pop();
				}
				break;
		}
		
	}
	virtual void onKeyUp(ci::app::KeyEvent &e) {
        switch( selected )
        {
            case Resume:
                if ( ( e.getCode() == ci::app::KeyEvent::KEY_KP_ENTER || e.getCode() == ci::app::KeyEvent::KEY_RETURN ) && state != In ) {  
					getManager()->playSPSFX(8);
                    state = Out;
					getManager()->setSPBGMVolume(1.0f);
                }
                break;
            case Back:
                if ( ( e.getCode() == ci::app::KeyEvent::KEY_KP_ENTER || e.getCode() == ci::app::KeyEvent::KEY_RETURN ) ) {
					getManager()->playSPSFX(8);
					getManager()->bot()->onActivate();
                    getManager()->m_scenes.erase(getManager()->m_scenes.end() - 2, getManager()->m_scenes.end());
					getManager()->stopSPBGM();
                }
                break;
            case Quit:
                if ( ( e.getCode() == ci::app::KeyEvent::KEY_KP_ENTER || e.getCode() == ci::app::KeyEvent::KEY_RETURN ) ) { 
					getManager()->playSPSFX(8);
                    ci::app::AppBasic::get()->quit();
                }
                break;
        }
    }
    
    void onKeyDown(ci::app::KeyEvent &e)
    {
        switch( selected )
        {
            case Resume:
                if( e.getCode() == ci::app::KeyEvent::KEY_DOWN ){
                    prev = Resume;
                    selected = Back;
					getManager()->playSPSFX(7);
                }
                else if( e.getCode() == ci::app::KeyEvent::KEY_UP ){
                    prev = Resume;
                    selected = Quit;
					getManager()->playSPSFX(7);
                }
                break;
            case Back:
                if( e.getCode() == ci::app::KeyEvent::KEY_DOWN ){
                    prev = Back;
                    selected = Quit;
					getManager()->playSPSFX(7);
                }
                else if( e.getCode() == ci::app::KeyEvent::KEY_UP ){
                    prev = Back;
                    selected = Resume;
					getManager()->playSPSFX(7);
                }
                break;
            case Quit:
                if( e.getCode() == ci::app::KeyEvent::KEY_UP ){
                    prev = Quit;
                    selected = Back;
					getManager()->playSPSFX(7);
                }
                else if( e.getCode() == ci::app::KeyEvent::KEY_DOWN ){
                    prev = Quit;
                    selected = Resume;
					getManager()->playSPSFX(7);
                }
                break;
        }
    }
};

#endif
