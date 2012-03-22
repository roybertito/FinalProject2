#pragma once

#include <iostream>
#include <stdio.h>
#include <irrKlang.h>

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

#define tracka "../media/233-drive-into-the-dark.mp3"
#define trackb "../media/233-drive-into-the-dark.mp3"
#define stracka "../media/laserzap.mp3"
#define strackb "../media/laser4.mp3"
#define strackc "../media/laser2.mp3"
#define strackd "../media/laser1.mp3"
#define stracke "../media/highpower laser.mp3"
#define strackf "../media/confirm.mp3"
#define strackg "../media/dig2.mp3"
#define strackh "../media/explosion.wav"
#define stracki "../media/digital3.mp3"
#define strackj "../media/bleep.mp3"
#define vtracka "../media/all systems operational.mp3"
#define vtrackb "../media/loading.mp3"
#define vtrackc "../media/system activated.mp3"


using namespace irrklang;

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

class SoundPlayer {
	ISoundEngine* engine;
	ISound* snd;
	ISound* snd2;
public:
	SoundPlayer();
	void playBGM(int track);
	void playSFX(int strack);
	void playVoice(int vtrack);
	void dropEngine();
	void setBGMVolume(float v);
	void stopBGM();
};


