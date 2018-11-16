#pragma once
DWORD WINAPI DrawThread(LPVOID lpParameter)
{
	while (true) {
		Draw();
	}
	return 0;
}

const int SPRITES_TO_LOAD = 11;
int SPRITES_LOADED = 0;
DWORD WINAPI LoadThread(LPVOID lpParameter)
{
	if (Sprites.LoadPlayer()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadFloor()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadTitle()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadWall()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadBlock()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadDoor()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadSword()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadKeese()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadRope()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadSpikeTrap()) {
		SPRITES_LOADED++;
	}
	if (Sprites.LoadGel()) {
		SPRITES_LOADED++;
	}
	
	return 0;
}