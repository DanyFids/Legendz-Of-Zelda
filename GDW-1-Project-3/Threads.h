#pragma once
DWORD WINAPI DrawThread(LPVOID lpParameter)
{
	while (true) {
		Draw();
	}
	return 0;
}

const int TO_LOAD = 16;
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
	if (Sprites.LoadCharacterMenu()) {
		LOADED++;
	}
	if (Sprites.LoadHeart()) {
		LOADED++;
	}
	if (Sprites.LoadGenericMenu()) {
		LOADED++;
	}

	// load player saves
	int savesSize = sizeof(Player_Info) * 3;
	char * bytes = new char[savesSize];
	std::fstream check; // Used to check if a given file exists
	check.open("profiles.sav", std::ios_base::in | std::ios_base::out);
	std::fstream saves("profiles.sav", std::ios::out | std::ios::in | std::ios::app | std::ios::binary);
	if (!check.is_open()) {
		memcpy(bytes, PLAYER_FILES, savesSize);
		saves.write(bytes, savesSize);
		saves.close();
		LOADED++;
	}
	else {
		saves.read(bytes, savesSize);
		memcpy(PLAYER_FILES, bytes, savesSize);
		saves.close();
		LOADED++;
	}
	if (Sprites.LoadBomb()) {
		LOADED++;
	}

	 //Sounds below!!


	
	return 0;
}