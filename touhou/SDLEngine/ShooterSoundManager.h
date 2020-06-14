#pragma once
#include "../MemoryLeakChecker.h"
#include "ShooterObject.h"
#include "ShooterSound.h"
#include <fmod.hpp>
#include <vector>

class ShooterSound;

typedef void (*SoundPlayer)(ShooterSound *, bool, double);

typedef enum PlayStatus
{
	PLAYSTATUS_STOP = 0,
	PLAYSTATUS_PLAYING,
	PLAYSTATUS_PAUSED,
};

typedef struct SoundStruct
{
	SoundStruct();
	SoundStruct(ShooterSound * IN_pSound, bool IN_Playing);
	ShooterSound * pSound;
	PlayStatus iPlayStatus;
	double fVolume;
} SoundStruct;

class ShooterSoundManager : public ShooterObject
{
friend ShooterSound;
private:

protected:
	std::vector <SoundStruct *> vChannels;
	int iMaxChannel;
	bool SoundLoader (SoundPlayer IN_SoundPlayer, ShooterSound * IN_pSound, int * OUT_pChannel, bool IN_Loop = false, double IN_Volume = 1.0, bool IN_AllowDuplicate = false);

	FMOD::Channel * g_pLastChannel;

	FMOD::System * GetSoundSystem();

public:
	ShooterSoundManager();
	~ShooterSoundManager();
	bool OpenAudio(int IN_Channels = 2);
	bool Update();
	bool Stop(int IN_Channel);
	bool Pause(int IN_Channel);
	bool Resume(int IN_Channel);
	bool SetVolume(int IN_Channel, double IN_Volume);
	void CloseAudio();
};

