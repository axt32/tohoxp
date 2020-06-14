#include "ShooterSoundManager.h"

SoundStruct :: SoundStruct()
{
	pSound = NULL;
	iPlayStatus = PLAYSTATUS_STOP;
	fVolume = 1.0;
}
SoundStruct :: SoundStruct(ShooterSound * IN_pSound, bool IN_Playing)
{
	pSound = IN_pSound;
	iPlayStatus = PLAYSTATUS_STOP;
	fVolume = 1.0;
}

ShooterSoundManager :: ShooterSoundManager()
{

}

ShooterSoundManager :: ~ShooterSoundManager()
{
	CloseAudio();
}

bool ShooterSoundManager :: SoundLoader (SoundPlayer IN_SoundPlayer, ShooterSound * IN_pSound, int * OUT_pChannel, bool IN_Loop, double IN_Volume, bool IN_AllowDuplicate)
{
	if (GetLoaded() == false)
	{
		return false;
	}

	//중복 재생 방지
	if (IN_AllowDuplicate == false)
	{
		for (int i = 0; i < iMaxChannel; i++)
		{
			if (vChannels[i]->iPlayStatus != PLAYSTATUS_STOP && vChannels[i]->pSound == IN_pSound)
			{
				GetSoundSystem()->getChannel(i, &g_pLastChannel);
				
				unsigned int iLength = 0;
				IN_pSound->GetSound()->getLength(&iLength, FMOD_TIMEUNIT_MS);

				unsigned int iPos = 0;
				g_pLastChannel->getPosition(&iPos, FMOD_TIMEUNIT_MS);

				if ( (double)iPos / (double)iLength <= 0.05 )
				{
					return false;
				}

				//return false;
			}
		}
	}

	for (int i = 0; i < iMaxChannel; i++)
	{
		if (vChannels[i]->iPlayStatus == PLAYSTATUS_STOP)
		{
			*OUT_pChannel = i;
			vChannels[i]->pSound = IN_pSound;
			(*IN_SoundPlayer)(IN_pSound, IN_Loop, IN_Volume);
			return true;
		}

	}

	return false;
	
}



FMOD::System * ShooterSoundManager :: GetSoundSystem()
{
	if (GetLoaded() == true)
	{
		return ((FMOD::System *)GetObject());
	}

	return NULL;
}


bool ShooterSoundManager :: OpenAudio(int IN_Channels)
{
	printf ("Initalizing Audio System ... ");

	if (GetLoaded() == true)
	{
		printf ("Failed\n");
		return false;
	}

	iMaxChannel = IN_Channels;
	vChannels.reserve(iMaxChannel);
	for (int i = 0; i < iMaxChannel; i++)
	{
		vChannels.push_back(new SoundStruct(NULL, false));
	}

	//FMOD
	FMOD::System * g_pSystem;
	System_Create(&g_pSystem);
	g_pSystem->init(iMaxChannel, FMOD_INIT_NORMAL, 0);
	SetObject(g_pSystem);
	//FMOD END

	SetLoaded(true);

	printf ("OK\n");
	return true;
}

bool ShooterSoundManager :: Update()
{
	if (GetLoaded() == false)
	{
		return false;
	}

	GetSoundSystem()->update();

	if (vChannels.size() > 0)
	{
		int iCount = 0;
		for ( std::vector<SoundStruct*>::iterator Iter = vChannels.begin(); Iter != vChannels.end(); Iter++)
		{
			if ( (*Iter)->iPlayStatus == PLAYSTATUS_PLAYING)
			{
				bool bPlaying;

				GetSoundSystem()->getChannel(iCount, &g_pLastChannel);
				g_pLastChannel->isPlaying(&bPlaying);
				if ( bPlaying == false)
				{
					(*Iter)->pSound->iMyChannel = -1;
					(*Iter)->pSound = NULL;
					(*Iter)->iPlayStatus = PLAYSTATUS_STOP;
				}
			}
			iCount++;
		}
	}

	return true;
}

bool ShooterSoundManager :: Stop(int IN_Channel)
{
	if (IN_Channel == -1)
	{
		return false;
	}

	if (vChannels[IN_Channel]->iPlayStatus == PLAYSTATUS_STOP)
	{
		return false;
	}

	GetSoundSystem()->getChannel(IN_Channel, &g_pLastChannel);
	g_pLastChannel->stop();
	vChannels[IN_Channel]->iPlayStatus = PLAYSTATUS_STOP;
	vChannels[IN_Channel]->pSound->iMyChannel = -1;
	vChannels[IN_Channel]->pSound = NULL;

	return true;
}

bool ShooterSoundManager :: Pause(int IN_Channel)
{
	if (IN_Channel == -1)
	{
		return false;
	}

	if (vChannels[IN_Channel]->iPlayStatus == PLAYSTATUS_PLAYING)
	{
		GetSoundSystem()->getChannel(IN_Channel, &g_pLastChannel);
		g_pLastChannel->setPaused(true);
		vChannels[IN_Channel]->iPlayStatus = PLAYSTATUS_PAUSED;
		
		return true;
	}

	return false;
}

bool ShooterSoundManager :: Resume(int IN_Channel)
{
	if (IN_Channel == -1)
	{
		return false;
	}

	if (vChannels[IN_Channel]->iPlayStatus == PLAYSTATUS_PAUSED)
	{
		GetSoundSystem()->getChannel(IN_Channel, &g_pLastChannel);
		g_pLastChannel->setPaused(false);
		vChannels[IN_Channel]->iPlayStatus = PLAYSTATUS_PLAYING;
		return true;
	}

	return false;
}

bool ShooterSoundManager :: SetVolume(int IN_Channel, double IN_Volume)
{
	if (IN_Channel == -1)
	{
		return false;
	}

	GetSoundSystem()->getChannel(IN_Channel, &g_pLastChannel);
	g_pLastChannel->setVolume(IN_Volume);
	vChannels[IN_Channel]->fVolume = IN_Volume;

	return true;
}

void ShooterSoundManager :: CloseAudio()
{

	if (vChannels.size() > 0)
	{
		for ( std::vector<SoundStruct *>::iterator Iter = vChannels.begin(); Iter != vChannels.end(); Iter++)
		{
			delete (*Iter);
		}
	}
	vChannels.clear();

	GetSoundSystem()->release();
	GetSoundSystem()->close();
}