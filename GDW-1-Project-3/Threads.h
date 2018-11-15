#pragma once
DWORD WINAPI DrawThread(LPVOID lpParameter)
{
	while (true) {
		Draw();
	}
	return 0;
}

const int SPRITES_TO_LOAD = 3;
int SPRITES_LOADED = 0;
DWORD WINAPI LoadThread(LPVOID lpParameter)
{
	if (Sprites.LoadPlayer()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadEnemy()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadTitle()) {
		SPRITES_LOADED++;
	}
	
	return 0;
}