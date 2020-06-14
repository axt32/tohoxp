#pragma once
#include "../MemoryLeakChecker.h"
#include "ShooterObject.h"
#include "ShooterSoundManager.h"

class ShooterSoundManager;
class ShooterMusic : public ShooterObject
{
friend ShooterSoundManager;
private:
	ShooterSoundManager * pSoundManager;
	int iMyChannel;

public:
	ShooterMusic();
	~ShooterMusic();
	bool LoadMusic(std::string IN_Path);
	bool CloseSound();
	bool PlayMusic();
	bool StopMusic();
	bool CloseMusic();
};