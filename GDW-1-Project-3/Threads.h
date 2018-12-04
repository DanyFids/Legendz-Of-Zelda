#pragma once
int DrawThread()
{
	while (true) {
		Draw();
	}
	return 0;
}

const int TO_LOAD = 40;
int LoadThread(int & LOADED)
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
if (Sprites.LoadRooms()) {
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
if (Sprites.LoadUI()) {
	LOADED++;
}
if (Sprites.LoadInventoryScrn()) {
	LOADED++;
}
if (Sprites.LoadBomb()) {
	LOADED++;
}
if (Sprites.LoadArrow()) {
	LOADED++;
}
if (Sprites.LoadFireball()) {
	LOADED++;
}
if (Sprites.LoadBoomerang()) {
	LOADED++;
}
if (Sprites.LoadStatue()) {
	LOADED++;
}
if (Sprites.LoadFairy()) {
	LOADED++;
}
if (Sprites.LoadCompass()) {
	LOADED++;
}
if (Sprites.LoadKey()) {
	LOADED++;
}
if (Sprites.LoadMap()) {
	LOADED++;
}
if (Sprites.LoadBow()) {
	LOADED++;
}
if (Sprites.LoadExplosion()) {
	LOADED++;
}
if (Sprites.LoadSmoke()) {
	LOADED++;
}
if (Sprites.LoadBlip()) {
	LOADED++;
}
if (Sprites.LoadMoldorm()) {
	LOADED++;
}
if (Sprites.LoadGoriya()) {
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

// Sounds below!!
if (sounds.LoadSwing()) {
	LOADED++;
}
if (sounds.LoadBeamSword()) {
	LOADED++;
}
if (sounds.LoadTitleTheme()) {
	LOADED++;
}
if (sounds.LoadDungeonTheme()) {
	LOADED++;
}
if (sounds.LoadFileSelect()) {
	LOADED++;
}
if (sounds.LoadLinkDie()) {
	LOADED++;
}
if (sounds.LoadWasted()) {
	LOADED++;
}
if (sounds.LoadDarkSouls()) {
	LOADED++;
}
	

LEVEL2.GenerateRoomWalls();
LOADED++;
	

return 0;
}