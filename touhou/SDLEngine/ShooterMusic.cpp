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

	//���ϰ� ������� ����ó�� �ȵ�.
	//���� �����ٶ�.

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

	/* mpeg ������ ���� SMPEG ������Ʈ ����. ������ ���ڴ� 0�̾�� ��.
	* ������ ���ڰ� 1�̶�� SMPEG_new() �ȿ��� SDL_audio�� �ʱ�ȭ��.
	*/

	mpeg = SMPEG_new(IN_Path.c_str(), &info, 0);

	/* ����� ��� ����� ��� ����. �ϴ� 0�� �Է��� ��� �������� �Ѵ�. */
	SMPEG_enableaudio(mpeg, 0);
	/* SMPEG���� ����� ���˿� ���� �˷��ش�. */
	Mix_QuerySpec(&freq, &format, &channels);
	audiofmt.format = format;
	audiofmt.freq = freq;
	audiofmt.channels = channels;
	SMPEG_actualSpec(mpeg, &audiofmt);
	/* MPEG �ͼ��� ��ŷ(Hooking)�Ѵ�. */
	Mix_HookMusic(SMPEG_playAudioSDL, mpeg);
	/* ����� ��� ����� Ȱ��ȭ��Ű�� ��� ���� */
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