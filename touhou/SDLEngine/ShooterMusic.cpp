#include "ShooterMusic.h"

ShooterMusic :: ShooterMusic()
{
	iMyChannel = 0;
}

ShooterMusic :: ~ShooterMusic()
{
	StopMusic();
	CloseMusic();
}

bool ShooterMusic :: LoadMusic(std::string IN_Path)
{

	//급하게 만드느라 예외처리 안됨.
	//차후 수정바람.

	printf ("Loading Music %s ... ", IN_Path.c_str());
	if (GetLoaded() == true)
	{
		printf ("Failed\n");
		return false;
	}

	SMPEG * mpeg;
	SMPEG_Info info;
	SDL_AudioSpec audiofmt;
	Uint16 format;
	int freq, channels;

	/* mpeg 파일을 열어 SMPEG 오브젝트 생성. 마지막 인자는 0이어야 함.
	* 마지막 인자가 1이라면 SMPEG_new() 안에서 SDL_audio를 초기화함.
	*/

	mpeg = SMPEG_new(IN_Path.c_str(), &info, 0);

	/* 오디오 재생 기능의 사용 여부. 일단 0을 입력해 사용 안함으로 한다. */
	SMPEG_enableaudio(mpeg, 0);
	/* SMPEG에게 오디오 포맷에 대해 알려준다. */
	Mix_QuerySpec(&freq, &format, &channels);
	audiofmt.format = format;
	audiofmt.freq = freq;
	audiofmt.channels = channels;
	SMPEG_actualSpec(mpeg, &audiofmt);
	/* MPEG 믹서를 후킹(Hooking)한다. */
	Mix_HookMusic(SMPEG_playAudioSDL, mpeg);
	/* 오디오 재생 기능을 활성화시키고 재생 시작 */
	SMPEG_enableaudio(mpeg, 1);
	SetObject(mpeg);
	SetLoaded(true);

	printf ("OK\n");

	return true;
}

bool ShooterMusic :: PlayMusic()
{
	if (GetLoaded() == true)
	{
		SMPEG_play( (SMPEG*)GetObject());
		return true;
	}

	return false;
}

bool ShooterMusic :: StopMusic()
{
	if (GetLoaded() == true)
	{
		SMPEG_stop((SMPEG*)GetObject());
		return true;
	}

	return false;

}

bool ShooterMusic :: CloseMusic()
{
	if (GetLoaded() == true)
	{
		SMPEG_enableaudio((SMPEG*)GetObject(), 0);
		Mix_HookMusic(NULL, NULL);
		return true;
	}

	return false;

}