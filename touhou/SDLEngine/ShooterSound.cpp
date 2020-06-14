#include "ShooterSound.h"
#include "FilePacker/FilePacker.h"

ShooterSound :: ShooterSound()
{
	m_SoundSource_Stream = NULL;
	iMyChannel = -1;
}
ShooterSound :: ~ShooterSound()
{
	FreeSound();
}

bool ShooterSound :: LoadSound(std::string IN_Path, ShooterSoundManager * IN_SoundManager)
{
	//printf ("Loading Sound : %s ... ", IN_Path.c_str());
	
	if (GetLoaded() == true)
	{
		printf ("Failed\n");
		return false;
	}

	pSoundManager = IN_SoundManager;

	FMOD::Sound * g_pSound;

	std::string Extension = (IN_Path.substr(IN_Path.length() - 3, 3));
	std::transform(Extension.begin(), Extension.end(), Extension.begin(), std::tolower);

	if (Extension == "mp3")
	{
		IN_SoundManager->GetSoundSystem()->createStream(IN_Path.c_str(), FMOD_HARDWARE | FMOD_LOOP_NORMAL, 0, &g_pSound);
	}
	else
	{
		IN_SoundManager->GetSoundSystem()->createSound(IN_Path.c_str(), FMOD_HARDWARE, 0, &g_pSound);
	}

	SetObject (g_pSound);

	SetLoaded(true);

	//printf ("OK\n");
	return true;
}

bool ShooterSound::LoadSound(std::string IN_PackFilePath, std::string IN_Path, ShooterSoundManager * IN_SoundManager)
{
	//printf ("Loading Sound : %s ... ", IN_Path.c_str());

	if (GetLoaded() == true)
	{
		printf ("Failed\n");
		return false;
	}

	pSoundManager = IN_SoundManager;

	FMOD::Sound * g_pSound;

 	std::string Extension = (IN_Path.substr(IN_Path.length() - 3, 3));
 	std::transform(Extension.begin(), Extension.end(), Extension.begin(), std::tolower);

	FilePacker filepacker;
	char * pData;
	int iFileSize;
	filepacker.GetFilePtr(IN_PackFilePath, IN_Path, &pData, &iFileSize);
	FMOD_CREATESOUNDEXINFO exinfo;
	memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
	exinfo.cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
	exinfo.length = iFileSize;
 	if (std::strcmp (Extension.c_str(), "ogg") == 0)
  	{
 		m_SoundSource_Stream = pData;
  		if (IN_SoundManager->GetSoundSystem()->createStream(m_SoundSource_Stream, FMOD_CREATESTREAM | FMOD_OPENMEMORY | FMOD_HARDWARE | FMOD_LOOP_NORMAL, &exinfo, &g_pSound) != FMOD_OK)
 		{
 			printf ("Failed : %s\n", IN_Path.c_str());
			return false;
 		}
  	}
  	else
  	{
		if ( IN_SoundManager->GetSoundSystem()->createSound(pData, FMOD_OPENMEMORY | FMOD_HARDWARE, &exinfo, &g_pSound) != FMOD_OK)
		{
			printf ("Failed : %s\n", IN_Path.c_str());
			return false;
		}
		filepacker.DeleteFilePtr();
	}


	SetObject (g_pSound);

	SetLoaded(true);

	//printf ("OK\n");
	return true;
}

bool ShooterSound :: FreeSound()
{
	if (GetLoaded() == true)
	{
		((FMOD::Sound *)GetObject())->release();
		if (m_SoundSource_Stream != NULL)
		{
			delete[] m_SoundSource_Stream;
			m_SoundSource_Stream = NULL;
		}
		SetLoaded(false);
		return true;
	}

	return false;
}

FMOD::Sound * ShooterSound :: GetSound()
{
	if (GetLoaded() == true)
	{
		return ((FMOD::Sound*)GetObject());
	}

	return NULL;
}

bool ShooterSound :: Play(bool IN_Loop, int * OUT_Channel, double IN_Volume, bool IN_AllowDuplicate)
{
	if (GetLoaded() == true)
	{
		bool bResult = pSoundManager->SoundLoader( (SoundPlayer)&_Play, this, &iMyChannel, IN_Loop, IN_Volume, IN_AllowDuplicate);	 
		if (bResult == true)
		{
			if (OUT_Channel != NULL)
			{
				*OUT_Channel = iMyChannel;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

void ShooterSound :: _Play(ShooterSound * IN_pSound, bool IN_Loop, double IN_Volume)
{
	//Loop => 입력만 받고, 처리하는부분은 아직 없음.
	//현재는 음악을 로드할 때에 mp3파일이면 Loop 재생하고, 그 외에는 Loop 없음.
	int iLoop;
	if (IN_Loop == true)
	{
		iLoop = 1;
	}
	else
	{
		iLoop = 0;
	}


	IN_pSound->pSoundManager->GetSoundSystem()->playSound( (FMOD_CHANNELINDEX)(IN_pSound->iMyChannel), (FMOD::Sound*)(IN_pSound->GetObject()), true, &(IN_pSound->pSoundManager->g_pLastChannel));
	IN_pSound->SetVolume(IN_Volume);
	IN_pSound->pSoundManager->vChannels[IN_pSound->iMyChannel]->iPlayStatus = PLAYSTATUS_PAUSED;
	IN_pSound->Resume();
}

bool ShooterSound :: Stop()
{
	if (GetLoaded() == false)
	{
		return false;
	}

	return pSoundManager->Stop(iMyChannel);

}

bool ShooterSound :: Pause()
{
	if (GetLoaded() == false)
	{
		return false;
	}

	return pSoundManager->Pause(iMyChannel);
}

bool ShooterSound :: Resume()
{
	if (GetLoaded() == false)
	{
		return false;
	}

	return pSoundManager->Resume(iMyChannel);
}

bool ShooterSound :: SetVolume(double IN_Volume)
{
	if (GetLoaded() == false)
	{
		return false;
	}
	return pSoundManager->SetVolume(iMyChannel, IN_Volume);
}