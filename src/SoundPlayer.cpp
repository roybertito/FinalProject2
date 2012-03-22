#include "SoundPlayer.hpp"



SoundPlayer::SoundPlayer() {
	engine = createIrrKlangDevice();
	if (!engine)
	{
		printf("Could not startup engine\n");
	}
}
void SoundPlayer::playBGM(int track)
{

	switch (track) {
	case 0:
		snd=engine->play2D(tracka, true, false, true);
		break;
	case 1:
		snd=engine->play2D(tracka, true, false, true);
		break;
	default:
		break;
	}
	
	/*do
	{
		printf("Press any key to play some sound, press 'q' to quit.\n");

		engine->play2D("../../media/bell.wav");
	}
	while(getch() != 'q');*/

	
}
void SoundPlayer::playSFX(int strack) {
	switch (strack) {
	case 0:
		snd2=engine->play2D(stracka, false, false, false);
		break;
	case 1:
		snd2=engine->play2D(strackb, false, false, false);
		break;
	case 2:
		snd2=engine->play2D(strackc, false, false, false);
		break;
	case 3:
		snd2=engine->play2D(strackd, false, false, false);
		break;
	case 4:
		snd2=engine->play2D(strackf, false, false, false);
		break;
	case 5:
		snd2=engine->play2D(strackg, false, false, false);
		break;
	case 6:
		snd2=engine->play2D(strackh, false, false, false);
		break;
	case 7:
		snd2=engine->play2D(stracki, false, false, false);
		break;
	case 8:
		snd2=engine->play2D(strackj, false, false, false);
		break;
	default:
		break;
	}
}

void SoundPlayer::playVoice(int vtrack) {
	switch (vtrack) {
	case 0:
		engine->play2D(vtracka, false, false, false);
		break;
	case 1:
		engine->play2D(vtrackb, false, false, false);
		break;
	case 2:
		engine->play2D(vtrackc, false, false, false);
		break;
	case 3:
		engine->play2D(vtracka, false, false, false);
		break;
	default:
		break;
	}
}

//void pauseSounds() {
//	engine->pauseAllSounds();
//}

void SoundPlayer::setBGMVolume(float v) {
	if (snd)
		snd->setVolume(v);
}

void SoundPlayer::stopBGM() {
	if (snd)
		snd->stop();
}



void SoundPlayer::dropEngine() {
	engine->drop(); // delete engine
}