#include "MainScene.hpp"
#define FPS 60.0f
#define BAR_HEIGHT 30
#define BAR_WIDTH 400
#define COVER_WIDTH ( BAR_WIDTH - 21 )
#define COVER_HEIGHT ( BAR_HEIGHT - 21 )
Vec2f stars[500];

Vec2f offset(0,1);


void MainScene::onLoad()
{
	createLevel();
    ps.init();
	pause.init();
	getManager()->playSPVoice(1);
    for( int i = 0; i < 500; i++ )
    {
        stars[i] = Vec2f(Rand::randFloat(ci::app::AppBasic::get()->getWindowWidth()), Rand::randFloat(ci::app::AppBasic::get()->getWindowWidth()));
    }
	for(int i=0;i<enemy.size();i++)
		enemy[i]->init();
	time = 0;
	dt = 1.0/FPS;
	getManager()->playSPBGM(0);
	getManager()->playSPVoice(0);
}

void MainScene::mouseDown( MouseEvent &event ) {}

void MainScene::mouseUp( MouseEvent &event ){}

void MainScene::mouseMove( MouseEvent &event ) {}

void MainScene::mouseDrag( MouseEvent &event ) {}

void MainScene::update()
{
	//offset += 2;
	if(ps.remainingLife > 0){
		time += dt;
		for ( size_t i = 0; i < enemy.size(); ++i ) {
			if(time >= enemy[i]->arrivalTime){
				enemy[i]->update();
				if(enemy[i]->hp > 0)
					enemy[i]->collide();
				if(enemy[i]->hp <= 0 || enemy[i]->pos.y > 650){
					bool del = true;
					for(int j = 0; j < enemy[i]->eg.size(); j++){
						if(enemy[i]->eg[0]->bullets.size() > 0){
							del = false;
							break;
						}
					}
					for(int j = 0; j < enemy[i]->ex.size(); j++){
						if(enemy[i]->ex[0]->isAlive){
							//getManager()->playSPSFX(6);
							del = false;
							break;
						}
					}
					if(dynamic_cast<EnemyShip5*>(enemy[i]) != NULL && enemy.size() > 1)
						del = false;
					if(del){
						delete enemy[i];
						enemy.erase(enemy.begin()+i);
					}
					else{
						enemy[i]->firing = false;
					}
				}
			}
		}
		if ( ps.mMouseLoc.x - ps.width/2 < 0 )
			ps.mMouseLoc.x = ps.width/2;
		else if (ps.mMouseLoc.x + ps.width/2 > getWindowWidth() )
			ps.mMouseLoc.x = getWindowWidth() - ps.width/2;
		if ( ps.mMouseLoc.y + ps.height > getWindowHeight() )
			ps.mMouseLoc.y = getWindowHeight() - ps.height;
		else if ( ps.mMouseLoc.y < 0 )
			 ps.mMouseLoc.y = 0;
		ps.update();
	}
}

void MainScene::draw()
{
	
	gl::color(1.f,1.f,1.f);
    for( int i = 0; i < 500; i++ )
    {
		stars[i] += offset;
		stars[i].y = int(stars[i].y)%800;
        drawSolidCircle( stars[i], Rand::randFloat( 1.3f ));
    }
	for(size_t i=0;i<enemy.size();++i){
		if(time >= enemy[i]->arrivalTime){
			enemy[i]->draw();
		}
	}
	if(enemy.size()==0)
		gl::drawString("YOU WIN!",Vec2f(350,300));
	if(ps.remainingLife > 0)
		ps.draw();
	else
		gl::drawString("GAME OVER",Vec2f(350,300));
}

void MainScene::onKeyUp(KeyEvent &e){
    if ( e.getCode() == KeyEvent::KEY_ESCAPE ) {
        getManager()->push(&pause);
    }
    else{
        ps.onKeyUp(e);
    }
}

void MainScene::onKeyDown(KeyEvent &e){
    ps.onKeyDown(e);
}


void MainScene::createLevel()
{
	ofstream logfile;
	logfile.open ("log.txt");
	if (logfile.is_open()) {
		ifstream infile("Stage1.lvl");
		if (infile.is_open()){
			int num;
			infile >> num;
			for(int i=0;i<num;i++){
				int type;
				int arrivalTime, hp;
				float atkspd, xpos, ypos, xvel, yvel;
				infile >> type;
				switch(type){
				case 1:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip1(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps));
					logfile << "Added Ship 1" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 2:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip2(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps));
					logfile << "Added Ship 2" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 3:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip3(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps));
					logfile << "Added Ship 3" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 4:
					infile >> arrivalTime >> hp >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip4(arrivalTime,hp,xpos,ypos,xvel,yvel,&ps));
					logfile << "Added Ship 4" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				case 5:
					infile >> arrivalTime >> hp >> atkspd >> xpos >> ypos >> xvel >> yvel;
					enemy.push_back(new EnemyShip5(arrivalTime,hp,atkspd,xpos,ypos,xvel,yvel,&ps));
					logfile << "Added Ship 5" << endl;
					logfile << "Time: " << arrivalTime << " HP: " << hp << " Attack Speed: " << atkspd << endl;
					logfile << "X: " << xpos << " Y: " << ypos << " XVel: " << xvel << " YVel: " << yvel << endl;
					break;
				default:
					break;
				}
			}
		}
		infile.close();
	}
	logfile.close();
}
