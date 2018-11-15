
#include "bgMusicManager.h"



void LoZTitleScreen()
{
	PlaySound(TEXT("BGM\\TitleThemeLoZ.wav"), NULL, SND_LOOP | SND_SYNC | SND_ASYNC);
}

void LoZDungeonTheme()
{
	PlaySound(TEXT("BGM\\DungeonThemeLoZ.wav"), NULL, SND_LOOP | SND_SYNC | SND_ASYNC);
}

void stopSound()
{
	PlaySound(NULL, NULL, SND_ASYNC);
}


