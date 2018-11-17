#pragma once
DWORD WINAPI DrawThread(LPVOID lpParameter)
{
	while (true) {
		Draw();
	}
	return 0;
}

const int TO_LOAD = 13;
int LOADED = 0;
DWORD WINAPI LoadThread(LPVOID lpParameter)
{
	if (Sprites.LoadPlayer()) {
		LOADED++;
	}
	if (Sprites.LoadFloor()) {
		LOADED++;
	}
	if (Sprites.LoadTitle()) {
		LOADED++;
	}
	if (Sprites.LoadWall()) {
		LOADED++;
	}
	if (Sprites.LoadBlock()) {
		LOADED++;
	}
	if (Sprites.LoadDoor()) {
		LOADED++;
	}
	if (Sprites.LoadSword()) {
		LOADED++;
	}
	if (Sprites.LoadKeese()) {
		LOADED++;
	}
	if (Sprites.LoadRope()) {
		LOADED++;
	}
	if (Sprites.LoadSpikeTrap()) {
		LOADED++;
	}
	if (Sprites.LoadGel()) {
		LOADED++;
	}
	if (sounds.LoadSwing()) {//12
		LOADED++;
	}
	if (sounds.LoadBeamSword()) {
		LOADED++;
	}

	
	return 0;
}