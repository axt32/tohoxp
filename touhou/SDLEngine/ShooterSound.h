#pragma once
#include "../MemoryLeakChecker.h"
#include "ShooterObject.h"
#include "ShooterSoundManager.h"
#include <fmod.hpp>
#include <algorithm>
#include <cctype>

class ShooterSoundManager;
class ShooterSound : public ShooterObject
{

friend ShooterSoundManager;
private:
	
	ShooterSoundManager * pSoundManager;
	int iMyChannel;
	char * m_SoundSource_Stream;		//MP3 포맷일때만 쓰임. Streaming의 소스를 담고있음.
	static void _Play(ShooterSound * IN_pSound, bool IN_Loop, double IN_Volume);
	
public:
	ShooterSound();
	~ShooterSound();
	bool LoadSound(std::string IN_Path, ShooterSoundManager * IN_SoundManager);
	bool LoadSound(std::string IN_PackFilePath, std::string IN_Path, ShooterSoundManager * IN_SoundManager);
	bool FreeSound();
	FMOD::Sound * GetSound();
	bool Play(bool IN_Loop = false, int * OUT_Channel = NULL, double IN_Volume = 1.0, bool IN_AllowDuplicate = false);
	bool Stop();
	bool Pause();
	bool Resume();
	bool SetVolume(double IN_Volume);
};