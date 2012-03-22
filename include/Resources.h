#pragma once

#ifdef RC_INVOKED
	#define QUOTE_PATH(x) #x
	#define CINDER_RESOURCE( LOCALPREFIX, PATH, ID, TYPE ) \
		ID		TYPE 	QUOTE_PATH( LOCALPREFIX##PATH )
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
	#define CINDER_RESOURCE( LOCALPREFIX, PATH, ID, TYPE ) \
		ID,#TYPE
#else // MAC RESOURCE
	#define CINDER_RESOURCE( LOCALPREFIX, PATH, ID, TYPE ) #PATH
#endif

#define RES_ENEMY1			CINDER_RESOURCE( ../resources/, Enemy1.png, 130, ENEMY1 )
#define RES_ENEMY2			CINDER_RESOURCE( ../resources/, Enemy2.png, 131, ENEMY2 )
#define RES_ENEMY3			CINDER_RESOURCE( ../resources/, Enemy3.png, 132, ENEMY3 )
#define RES_ENEMY4			CINDER_RESOURCE( ../resources/, Enemy4.png, 133, ENEMY4 )
#define RES_ENEMY5			CINDER_RESOURCE( ../resources/, Enemy5.png, 134, ENEMY5 )
#define RES_ENEMY6			CINDER_RESOURCE( ../resources/, Enemy6.png, 135, ENEMY6 )
#define RES_ENEMY7			CINDER_RESOURCE( ../resources/, Enemy7.png, 136, ENEMY7 )
#define RES_ENEMY8			CINDER_RESOURCE( ../resources/, Enemy8.png, 137, ENEMY8 )
#define RES_ENEMY9			CINDER_RESOURCE( ../resources/, Enemy9.png, 138, ENEMY9 )
#define RES_ENEMY10			CINDER_RESOURCE( ../resources/, Enemy10.png, 139, ENEMY10 )
#define RES_BULLET			CINDER_RESOURCE( ../resources/, Bullet1.png, 141, BULLET )
#define RES_EBULLET1		CINDER_RESOURCE( ../resources/, Bullet2.png, 142, EBULLET1 )
#define RES_EBULLET2		CINDER_RESOURCE( ../resources/, Bullet3.png, 143, EBULLET2)
#define RES_SHIPMAP			CINDER_RESOURCE( ../resources/, ShipMap.png, 121, SHIPMAP )
#define RES_MYHP			CINDER_RESOURCE( ../resources/, HP.png, 122, MYHP )
#define RES_ENEMYHP			CINDER_RESOURCE( ../resources/, EnemyHP.png, 123, ENEMYHP )
#define RES_EXPLODE			CINDER_RESOURCE( ../resources/, Explode.png, 124, EXPLODE )
#define RES_BG				CINDER_RESOURCE( ../resources/, bg.png, 125, BG)
#define RES_LIFEBAR			CINDER_RESOURCE( ../resources/, lifebar.png, 126, LIFEBAR)
#define RES_LIFEBARLIGHT	CINDER_RESOURCE( ../resources/, lifebarlight.png, 127, LIFEBARLIGHT)
#define RES_LIFEBARCOVER	CINDER_RESOURCE( ../resources/, lifecover.png, 128, LIFEBARCOVER)
#define RES_PAUSE			CINDER_RESOURCE( ../resources/, pause.png, 129, PAUSE)
#define RES_PLANE			CINDER_RESOURCE( ../resources/, planes.png, 151, PLANE)
#define RES_PLAYGLOW		CINDER_RESOURCE( ../resources/, playglow.png, 152, PLAYGLOW)
#define RES_POINTER			CINDER_RESOURCE( ../resources/, pointer.png, 153, POINTER)
#define RES_QUITGLOW		CINDER_RESOURCE( ../resources/, quitglow.png, 154, QUITGLOW)
#define RES_HIGHGLOW		CINDER_RESOURCE( ../resources/, highglow.png, 155, HIGHGLOW)
#define RES_AGENCYR			CINDER_RESOURCE( ../resources/, AGENCYR.ttf, 156, AGENCYR)
#define RES_HELVETICA		CINDER_RESOURCE( ../resources/, HelveticaNeue.dfont, 157, HELVETICA)
#define RES_INFINITY		CINDER_RESOURCE( ../resources/, beyondinfinity.png, 158, INFINITY)
#define RES_BACK			CINDER_RESOURCE( ../resources/, back.png, 159, BACK)
#define RES_CONTINUE		CINDER_RESOURCE( ../resources/, continue.png, 160, CONTINUE)
#define RES_CONTINUEGLOW	CINDER_RESOURCE( ../resources/, continueglow.png, 161, CONTINUEGLOW)
#define RES_PLAYGAME		CINDER_RESOURCE( ../resources/, playgame.png, 162, PLAYGAME)
#define RES_HIGHSCORE		CINDER_RESOURCE( ../resources/, highscores.png, 163, HIGHSCORE)
#define RES_QUIT			CINDER_RESOURCE( ../resources/, quit.png, 164, QUIT)
#define RES_QUITGAME		CINDER_RESOURCE( ../resources/, quitgame.png, 165, QUITGAME)
#define RES_RESUME			CINDER_RESOURCE( ../resources/, resume.png, 166, RESUME)
#define RES_LASER			CINDER_RESOURCE( ../resources/, laser.png, 167, LASER)


