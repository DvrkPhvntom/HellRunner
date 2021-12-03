#include "Const.h"
extern int music;

void Music()
{
	int cont = 0;
	while (1)
	{
		if (music != cont)
		{
			mciSendString(TEXT("close mp3"), NULL, 0, NULL);
			switch (music)
			{
			case 0:
				break;
			case 1:
				mciSendString(TEXT("open \"SWARM - Take Me to Hell (cut).mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
				mciSendString(TEXT("play mp3"), NULL, 0, NULL);
				break;
			}
			Sleep(100);
			cont = music;
		}
	}
}