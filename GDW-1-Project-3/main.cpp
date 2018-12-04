#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<Windows.h>
#include<ctime>
#include<random>
#include<cmath>
#include<thread>

#include"Enums.h"
#include"FunctionProto.h"
#include"SpriteSheets.h"
#include"Entity.h"
#include"CoreClasses.h"
#include"Terrains.h"
#include "Projectiles.h"
#include"Enemies.h"

#include"Menus.h"
#include "PowerUp.h"
#include "VisualFX.h"
#include"Room.h"
#include"Dungeon.h"

//SFX/BGM Managers
//#include "bgMusicManager.h"
#include "sfxManager.h"
#include"Threads.h"

void SetupRoom(Room * r, Direction d);


const int PLAYER_SPEED = 2;
const int WaitInterval = 50;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE drawBuff = CreateConsoleScreenBuffer(
	GENERIC_READ | GENERIC_WRITE,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	CONSOLE_TEXTMODE_BUFFER,
	NULL);
HANDLE inputH;

COORD mouseLoc;

GameState state = TITLE;

bool Play = true;

bool drawingFrame = true;

// Play Objects
// Player
Player player(240, 192);
// Non-Player entities
//std::vector<Enemy*> * enemies;
std::vector<Projectile*> projectiles = {};
//std::vector<Terrain*> * roomTer;
std::vector<VisualFX*> fx = {new Smoke(60,40), new Blip(100,40)};

Room * curRoom = LEVEL2.GetStartRoom();

const float deathTimer = 2.45f;
float deathSpinTime = deathTimer;
bool hasSpun = false;

//std::vector<PowerUp *> powerups = {};

// Menus
Menu CharSelMenu({
	new CharacterButton(94, 86, &PLAYER_FILES[0], 0),
	new CharacterButton(94, 109, &PLAYER_FILES[1], 1),
	new CharacterButton(94, 132, &PLAYER_FILES[2], 2),
	new TextButton(94, 164, "Register Your Name", REGISTER), 
	new TextButton(94, 180, "Elimination Mode  ", ERASE)
});
Menu ElimMenu({
	new CharacterButton(94, 86, &PLAYER_FILES[0], 0, false),
	new CharacterButton(94, 109, &PLAYER_FILES[1], 1, false),
	new CharacterButton(94, 132, &PLAYER_FILES[2], 2, false),
	new TextButton(94, 180, "Elimination End   ", END)
});
Menu RegisterMenu({
	new CharacterButton(94, 86, &PLAYER_FILES[0], 0, false),
	new CharacterButton(94, 109, &PLAYER_FILES[1], 1, false),
	new CharacterButton(94, 132, &PLAYER_FILES[2], 2, false),
	new TextButton(94, 180, "Register Name End ", END)
});
Menu GameOverMenu({
	new TextButton((512/2),30, "Continue", CONTINUE),
	new TextButton((512 / 2),70, "SAVE", SAVE),
	new TextButton((512 / 2),110, "Retry", RETRY)
	});
int editId = 0;
int editChar = 0;
int EDIT_TIME = 10;
int editTimer = EDIT_TIME;

/***************************
*			Main
***************************/
int main() {
	SCREEN_SIZE.X = 512;
	SCREEN_SIZE.Y = 240;

	ResizeWindow();
	//hide cursor
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(console, &cursor);
	cursor.bVisible = false;
	SetConsoleCursorInfo(console, &cursor);

	//LoZTitleScreenBGM();	 //Legacy Player
	Load();
	sounds.PlayTitleTheme();
	

	//Start DrawThread
	DWORD drawThreadID;
	std::thread drawThreadH(DrawThread);
	drawThreadH.detach();

	const int inputR_SIZE = 128;
	DWORD iNumRead, consoleModeSave, consoleMode;
	INPUT_RECORD inputR[inputR_SIZE];

	inputH = GetStdHandle(STD_INPUT_HANDLE);

	if (inputH == INVALID_HANDLE_VALUE) {
		return 101;
	}

	if (!GetConsoleMode(inputH, &consoleModeSave)) {
		return 102;
	}

	/*DWORD fdwMode;

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(inputH, fdwMode))
		return 103;*/

	consoleMode = ENABLE_EXTENDED_FLAGS;
	if (!SetConsoleMode(inputH, consoleMode))
		return 103;

	consoleMode = ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(inputH, consoleMode)) {
		return 103;
	}

	curRoom->Respawn();

	while (Play) {
		DWORD unreadInputs;

		if (!GetNumberOfConsoleInputEvents(
			inputH,
			&unreadInputs
		)) {
			return 201;
		}

		if (unreadInputs > 0) {
			if (!ReadConsoleInput(
				inputH,
				inputR,
				inputR_SIZE,
				&iNumRead
			)) {
				return 202;
			}

			for (DWORD c = 0; c < iNumRead; c++) {
				switch (inputR[c].EventType) {
				case KEY_EVENT:
					KeyHandler(inputR[c].Event.KeyEvent);
					break;
				case MOUSE_EVENT:
					MouseHandler(inputR[c].Event.MouseEvent);
					break;
				default:
					break;
				}
			}
		}
		Update();

		int ut = GetUpdateTime();
		if (ut < WaitInterval) {
			Sleep(WaitInterval - ut);
		}
		GetUpdateTime(); // reset timer
	}

	return 0;
}


void GoToXY(HANDLE h, int x, int y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;

	SetConsoleCursorPosition(h, xy);
}

/*void DrawChars() {
	COORD size;
	size.X = 120;
	size.Y = 258;

	SetConsoleScreenBufferSize(console, size);

	for (int i = 0; i < 256; i++) {
		std::cout << i << ": " << (char)i << std::endl;
	}
}*/

void SwapBuffer() {
	/*
	static CHAR_INFO *outBuff = new CHAR_INFO[SCREEN_SIZE.X * SCREEN_SIZE.Y];

	//Area to read/write
	SMALL_RECT screen;
	screen.Top = 0;
	screen.Left = 0;
	screen.Right = SCREEN_SIZE.X - 1;
	screen.Bottom = SCREEN_SIZE.Y - 1;

	//Top Left COORD
	COORD start;
	start.X = 0;
	start.Y = 0;

	//Buffer Size
	COORD size;
	size.X = SCREEN_SIZE.X;
	size.Y = SCREEN_SIZE.Y;

	ReadConsoleOutput(drawBuff, outBuff, size, start, &screen);
	
	WriteConsoleOutput(console, outBuff, size, start, &screen);
	*/
	HANDLE temp = console;
	console = drawBuff;
	drawBuff = temp;

	SetConsoleActiveScreenBuffer(console);
	ResizeWindow();
}


/************************
	   KeyHandler
*************************
	Handles keyboard input.
*/
bool isMoving = false;

void KeyHandler(KEY_EVENT_RECORD e) {
	if (state == CHARACTER_ADD) {
		if (e.bKeyDown) {
			if (RegisterMenu.GetSelected() < 3) {
				if (e.wVirtualKeyCode == VK_BACK) {
					editChar--;
					if (editChar < 0) {
						editChar = 7;
					}
					PLAYER_FILES[editId].Name[editChar] = ' ';
				}
				else if (isalnum(e.uChar.AsciiChar) || e.uChar.AsciiChar == ' ') {
					PLAYER_FILES[editId].Name[editChar] = e.uChar.AsciiChar;
					editChar++;
					if (editChar >= 8) {
						editChar = 0;
					}
					if (!PLAYER_FILES[editId].file_exists) {
						PLAYER_FILES[editId].file_exists = true;
					}
				}
			}
		}
	}
	else {
		if (e.bKeyDown) {
			switch (e.wVirtualKeyCode) {
			case VK_ESCAPE:
				Play = false;
				break;
			case VK_UP:
				player_input.keyUp = true;
				break;
			case VK_RETURN:
				switch (state) {
				case TITLE:
					ToCharacterSelect();
					//LoZDungeonThemeBGM();           //Legacy Player
					break;
				case PLAY:
					state = INVENTORY;
					//LoZTitleScreenBGM();          //Legacy Player
					break;
				case INVENTORY:
					state = PLAY;
					break;
				case CREDITS:
					Save();
					state = TITLE;
					sounds.PlayTitleTheme();
					break;
				}
			break;
			case VK_DOWN:
				player_input.keyDown = true;
				break;
			case VK_LEFT:
				player_input.keyLeft = true;
				break;
			case VK_RIGHT:
				player_input.keyRight = true;
				break;
			case VK_SPACE:
				if (state == INVENTORY) {
					state = PAUSE;
				}
				break;
			case 'C':
				player_input.keySpace = true;
				break;
			}
		}
		else {
			switch (e.wVirtualKeyCode) {
			case VK_UP:
				player_input.keyUp = false;
				isMoving = false;
				break;
			case VK_DOWN:
				player_input.keyDown = false;
				isMoving = false;
				break;
			case VK_LEFT:
				player_input.keyLeft = false;
				isMoving = false;
				break;
			case VK_RIGHT:
				player_input.keyRight = false;
				isMoving = false;
				break;
			case 'C':
				player_input.keySpace = false;
				isMoving = false;
				break;
			}

		}
	}																												
}




void clear() {
	COORD origin = { 0, 0 }; // top left corner of screen
	CONSOLE_SCREEN_BUFFER_INFO scrn;
	DWORD buff;

	GetConsoleScreenBufferInfo(drawBuff, &scrn);

	//Fills Console with Whitespace
	FillConsoleOutputCharacterA(
		drawBuff, ' ', scrn.dwSize.X * scrn.dwSize.Y, origin, &buff
	);

	//Returns text colors to default
	FillConsoleOutputAttribute(
		drawBuff, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		scrn.dwSize.X * scrn.dwSize.Y, origin, &buff
	);

	//return to 0,0
	SetConsoleCursorPosition(drawBuff, origin);
}

void Draw() {
	//clear();
	drawingFrame = true;
	switch (state) {
	case TITLE:
		DrawScreen(Sprites.titleScreen);
		
		break;
	case CHARACTER_SEL:
		DrawScreen(Sprites.CharacterScreen);
		CharSelMenu.Draw(drawBuff);
		break;
	case PLAY:
		curRoom->Draw(drawBuff);

		for (int e = 0; e < curRoom->EnemyList.size(); e++) {
			if (curRoom->EnemyList[e]->GetType() == ET_MOLDORM) {
				Moldorm * enem = (Moldorm *) curRoom->EnemyList[e];
				enem->draw(drawBuff);
			}
			else {
				curRoom->EnemyList[e]->draw(drawBuff);
			}
		}

		for (int h = 0; h < curRoom->hazards.size(); h++) {
			curRoom->hazards[h]->draw(drawBuff);
		}

		for (int t = 0; t < curRoom->TerrainList.size(); t++) {
			curRoom->TerrainList[t]->draw(drawBuff);
		}

		for (int p = 0; p < projectiles.size(); p++) {
			projectiles[p]->draw(drawBuff);
		}

		for (int u = 0; u < curRoom->powerups.size(); u++) {
			curRoom->powerups[u]->draw(drawBuff);
		}

		for (int f = 0; f < fx.size(); f++)
		{
			fx[f]->draw(drawBuff);
		}

		player.draw(drawBuff);

		curRoom->DrawWalls(drawBuff);

		DrawUI();
		break;
	case INVENTORY:
		DrawScreen(Sprites.InventoryScreen);
		DrawUI(176);
		break;
	case CHARACTER_ADD:
		DrawScreen(Sprites.GenericScreen);
		Sprites.DrawTextSprites(drawBuff, "- Register Name -", 112, 40);

		// Draw cursor
		if (editTimer > (EDIT_TIME / 2)) {
			for (int c = 0; c < 9; c++) {
				GoToXY(drawBuff, 144 + (editChar * 16), 87 + (editId * 23) + c);
				SetConsoleTextAttribute(drawBuff, 4*16);
				WriteConsole(drawBuff, &"                  ", 18, NULL, NULL);
			}
		}
		editTimer--;
		if (editTimer <= 0) {
			editTimer = EDIT_TIME;
		}

		RegisterMenu.Draw(drawBuff);
		break;
	case CHARACTER_RMV:
		DrawScreen(Sprites.GenericScreen);
		Sprites.DrawTextSprites(drawBuff, "- Elimination Mode -", 80, 40);
		ElimMenu.Draw(drawBuff);
		break;
	case GAME_OVER:
		clear();
		
		switch ((rand() % 2 + 1)) {
		case 2:
			sounds.PlayDarkSouls();	   // OOOOF
			break;
		case 1:
			sounds.PlayWasted();
			break;
		}

		if (deathSpinTime > 0) {
			player.draw(drawBuff);
		}
		else {
			GameOverMenu.Draw(drawBuff);
		}
		break;
	case PAUSE:
		clear();
		GameOverMenu.Draw(drawBuff);
		break;
	case CREDITS:
		clear();
		DrawScreen(Sprites.victoryScreen);
		break;
	}

	SwapBuffer();
	//int dt = GetDrawTime();
	//if (dt < WaitInterval) {
	//	Sleep(WaitInterval - dt);
	//}
	//GetDrawTime(); // reset timer
	drawingFrame = false;
}

void DrawScreen(HANDLE scrn) {
	static CHAR_INFO *outBuff = new CHAR_INFO[SCREEN_SIZE.X * SCREEN_SIZE.Y];

	//Area to read/write
	SMALL_RECT screen;
	screen.Top = 0;
	screen.Left = 0;
	screen.Right = SCREEN_SIZE.X - 1;
	screen.Bottom = SCREEN_SIZE.Y - 1;

	//Top Left COORD
	COORD start;
	start.X = 0;
	start.Y = 0;

	//Buffer Size
	COORD size;
	size.X = SCREEN_SIZE.X;
	size.Y = SCREEN_SIZE.Y;

	ReadConsoleOutput(scrn, outBuff, size, start, &screen);

	WriteConsoleOutput(drawBuff, outBuff, size, start, &screen);
}

void Update() {
	float dt = GetTimeInSeconds();

	if (state == GAME_OVER) {
		if (deathSpinTime > 0.5f)
		{
			switch (player.GetCurAnim()) {
			case 0:
				player.SetCurAnim(1);
				break;
			case 1:
				player.SetCurAnim(3);
				break;
			case 2:
				player.SetCurAnim(0);
				break;
			case 3:
				player.SetCurAnim(2);
				break;

			}
			
			deathSpinTime -= dt;
		}

		else if(deathSpinTime > 0){
			player.SetCurAnim(9);
			deathSpinTime -= dt;
		}

	}

	if (state == PLAY) {

		bool changeDir = true;
		
		if (player_file->CurLife <= 0) {
			GameOver();
		}
		
		switch (player.GetDir()) {
		case Up:
			if (player_input.keyUp) {
				changeDir = false;
				if (player.CanAtk())
				{
					player.nextFrame();
				}
				isMoving = true;
			}
			break;
		case Down:
			if (player_input.keyDown) {
				changeDir = false;
				if (player.CanAtk())
				{
					player.nextFrame();
				}
				isMoving = true;
			}
			break;
		case Left:
			if (player_input.keyLeft) {
				changeDir = false;
				if (player.CanAtk())
				{
					player.nextFrame();
				}
				isMoving = true;
			}			break;
		case Right:
			if (player_input.keyRight) {
				changeDir = false;
				if (player.CanAtk())
				{
					player.nextFrame();
				}
				isMoving = true;
			}
			break;
		}

		if (!isMoving && (player.CanAtk()))
		{
			player.SetCurFrame(0);
		}
		
		

		if (player.CanAtk()) {
			if (player_input.keyUp && !player_input.keyDown) {
				player.ySpd = -PLAYER_SPEED;
				if (changeDir) {
					player.SetDir(Up);
					player.SetCurAnim(3);
				}
			}

			if (!player_input.keyUp && player_input.keyDown) {
				player.ySpd = PLAYER_SPEED;
				if (changeDir) {
					player.SetDir(Down);
					player.SetCurAnim(0);
				}
			}

			if (player_input.keyRight && !player_input.keyLeft) {
				player.xSpd = PLAYER_SPEED * 2;
				if (changeDir) {
					player.SetDir(Right);
					player.SetCurAnim(1);
				}
			}

			if (!player_input.keyRight && player_input.keyLeft) {
				player.xSpd = -PLAYER_SPEED * 2;
				if (changeDir) {
					player.SetDir(Left);
					player.SetCurAnim(2);
				}
			}
		}

		if (!player.CanAtk()) {
			switch (player.GetDir()) {
			case Down:
				player.SetCurAnim(4);
				break;
			case Right:
				player.SetCurAnim(5);
				break;
			case Left:
				player.SetCurAnim(6);
				break;
			case Up:
				player.SetCurAnim(7);
				break;
			}
		}

		if (player.CanAtk()) {
			switch (player.GetDir()) {
			case Down:
				player.SetCurAnim(0);
				break;
			case Right:
				player.SetCurAnim(1);
				break;
			case Left:
				player.SetCurAnim(2);
				break;
			case Up:
				player.SetCurAnim(3);
				break;
			}
		}
		

		if (player_input.keySpace)
		{
			if (player_file->CurLife == player_file->MaxLife) {
				sounds.PlaySwordBeam();
			}
			else
			{
				sounds.PlaySwing();
			}
			
			if (player.CanAtk()) {
				Direction d = player.GetDir();
				switch (d) {
				case Up:
					projectiles.push_back(new Sword(player.GetX(), player.GetY() - 16, d));
					if (player_file->CurLife == player_file->MaxLife) {
						projectiles.push_back(new BeamSword(player.GetX(), player.GetY() - 16, 0, -4, d));
						

					}
					break;
				case Down:
					projectiles.push_back(new Sword(player.GetX(), player.GetY() + player.GetHeight(), d));
					if (player_file->CurLife == player_file->MaxLife) {
						projectiles.push_back(new BeamSword(player.GetX(), player.GetY() + player.GetHeight(), 0, 4, d));
						

					}
					break;
				case Left:
					projectiles.push_back(new Sword(player.GetX() - 32, player.GetY(), d));
					if (player_file->CurLife == player_file->MaxLife) {
						projectiles.push_back(new BeamSword(player.GetX() - 32, player.GetY(), -8, 0, d));
						

					}
					break;
				case Right:
					projectiles.push_back(new Sword(player.GetX() + player.GetWidth(), player.GetY(), d));
					if (player_file->CurLife == player_file->MaxLife) {
						projectiles.push_back(new BeamSword(player.GetX() + player.GetWidth(), player.GetY(), 8, 0, d));
						
					}
					break;
				}
				player.SwingSword();
			}
		}

		for (int e = 0; e < curRoom->EnemyList.size(); e++) {
			if (curRoom->EnemyList[e]->getStunTime() <= 0.0f) {
				curRoom->EnemyList[e]->AI(player);
			}
			else
			{
				curRoom->EnemyList[e]->setStunTime(curRoom->EnemyList[e]->getStunTime() - dt);
			}
			if (curRoom->EnemyList[e]->HitDetect(&player)) {
				curRoom->EnemyList[e]->Hit(player);
			}
			for (int p = 0; p < projectiles.size(); p++) {
				bool check;
				if (curRoom->EnemyList[e]->GetType() == ET_MOLDORM)
					check = curRoom->EnemyList[e]->HitDetect(projectiles[p]);
				else
					check = projectiles[p]->HitDetect(curRoom->EnemyList[e]);
				if (check) {
					if (projectiles[p]->getEnum() == PT_BOMB) {
						if (curRoom->EnemyList[e]->getBoss()) {
							Dodongo * boss = (Dodongo *)curRoom->EnemyList[e];
							boss->BombHurt();
							projectiles[p]->setTime(0.0f);
						}
					}
					if (projectiles[p]->getEnum() == PT_BOOMERANG && curRoom->EnemyList[e]->GetType() != ET_GEL && curRoom->EnemyList[e]->GetType() != ET_KEESE) {
						curRoom->EnemyList[e]->stun();
					}
					else
					{
						projectiles[p]->Hit(curRoom->EnemyList[e]);
					}



					if (projectiles[p]->getEnum() == PT_ARROW || projectiles[p]->getEnum() == PT_BEAMSWORD) { //Removing Projectiles When they strike an Entity
						std::vector<Projectile*>::iterator it = projectiles.begin();
						delete projectiles[p];
						projectiles.erase(it + p);

					}

				}
			}

		}

		for (int h = 0; h < curRoom->hazards.size(); h++) {
			curRoom->hazards[h]->AI(player);

			if (curRoom->hazards[h]->HitDetect(&player)) {
				curRoom->hazards[h]->Hit(player);
			}
			for (int f = 0; f < curRoom->hazards.size(); f++) {
				if (h != f) {
					curRoom->hazards[h]->HitDetect(curRoom->hazards[f]);
				}
			}
		}

		for (int t = 0; t < curRoom->TerrainList.size(); t++) {
			curRoom->TerrainList[t]->HitDetect(&player);
			for (int e = 0; e < curRoom->EnemyList.size(); e++) {
				curRoom->TerrainList[t]->HitDetect(curRoom->EnemyList[e]);
			}
			for (int e = 0; e < curRoom->EnemyList.size(); e++) {
				if (curRoom->TerrainList[t]->HitDetect(curRoom->EnemyList[e])) {
					curRoom->EnemyList[e]->hitTerrain();
				}
				for (int ep = 0; ep < curRoom->EnemyList[e]->projectiles.size(); ep++) {
					if (curRoom->TerrainList[t]->HitDetect(curRoom->EnemyList[e]->projectiles[ep])) {
						curRoom->EnemyList[e]->projectiles[ep]->setTime(0.0f);
					}
				}
				for (int h = 0; h < curRoom->hazards.size(); h++) {
					curRoom->TerrainList[t]->HitDetect(curRoom->hazards[h]);
				}
				for (int p = 0; p < projectiles.size(); p++) {
					if (projectiles[p]->getEnum() == PT_EXPLOSION) {
						curRoom->TerrainList[t]->HitDetect(projectiles[p]);
					}
				}
			}
		}
		for (int u = 0; u < curRoom->powerups.size(); u++) {

			if (curRoom->powerups[u]->HitDetect(&player)) {
				curRoom->powerups[u]->Effect(player_file);
				delete curRoom->powerups[u];
				std::vector<PowerUp *>::iterator it = curRoom->powerups.begin();
				curRoom->powerups.erase(it + u);
			}
		}

		player.Update(dt);
		for (int e = 0; e < curRoom->EnemyList.size(); e++) {
			if (curRoom->EnemyList[e]->GetHP() <= 0) {
				fx.push_back(new Blip(curRoom->EnemyList[e]->GetX(), curRoom->EnemyList[e]->GetY() ));
				curRoom->EnemyList[e]->Drop(&curRoom->powerups);
				delete curRoom->EnemyList[e];
				curRoom->EnemyList.erase(curRoom->EnemyList.begin() + e);
			}
			else {
				if (!stop_watch)
				{
					curRoom->EnemyList[e]->Update(dt);
				}
			}
		}
		for (int h = 0; h < curRoom->hazards.size(); h++) {
			if (!stop_watch) {
				curRoom->hazards[h]->Update(dt);
			}
		}
		for (int p = 0; p < projectiles.size(); p++) {
			projectiles[p]->Update(dt);
			if (projectiles[p]->getTime() <= 0) {
				std::vector<Projectile*>::iterator it = projectiles.begin();
				if (projectiles[p]->getEnum() == PT_BOMB)
				{
					projectiles.push_back(new Explosion(projectiles[p]->GetX(), projectiles[p]->GetY()));

					fx.push_back(new Smoke(projectiles[p]->GetX(), projectiles[p]->GetY()));//Smoke puffs @location
					fx.push_back(new Smoke(projectiles[p]->GetX() + 28, projectiles[p]->GetY()));	//@Right
					fx.push_back(new Smoke(projectiles[p]->GetX(), projectiles[p]->GetY() - 14)); //@Up
					fx.push_back(new Smoke(projectiles[p]->GetX() - 28, projectiles[p]->GetY() - 7));//@Left&Up
					fx.push_back(new Smoke(projectiles[p]->GetX(), projectiles[p]->GetY() + 14));//@Down
					fx.push_back(new Smoke(projectiles[p]->GetX() - 28, projectiles[p]->GetY()));//Left
					fx.push_back(new Smoke(projectiles[p]->GetX() + 28, projectiles[p]->GetY() + 7));//Down&Right
				}
				delete projectiles[p];
				projectiles.erase(it + p);

			}
		}

		for (int f = 0; f < fx.size(); f++)
		{
			fx[f]->Update(dt);
			if (fx[f]->getTime() <= 0)
			{
				std::vector<VisualFX*>::iterator it = fx.begin();

				delete fx[f];
				fx.erase(it + f);
			}
		}
		if (player.GetX() <= 0 || player.GetX() + player.GetWidth() >= SCREEN_SIZE.X - 1 || player.GetY() <= 64 || player.GetY() + player.GetHeight() >= SCREEN_SIZE.Y - 1) {
			Room * nextRoom = NULL;
			Direction d;

			if (player.GetX() <= 0) {
				nextRoom = LEVEL2.GetNextRoom(curRoom, Left);
				d = Left;
			}
			else if (player.GetX() + player.GetWidth() >= SCREEN_SIZE.X) {
				nextRoom = LEVEL2.GetNextRoom(curRoom, Right);
				d = Right;
			}
			else if (player.GetY() <= 64) {
				nextRoom = LEVEL2.GetNextRoom(curRoom, Up);
				d = Up;
			}
			else if (player.GetY() <= 64 || player.GetY() + player.GetHeight() >= SCREEN_SIZE.Y - 1) {
				nextRoom = LEVEL2.GetNextRoom(curRoom, Down);
				d = Down;
			}

			if (nextRoom != NULL) {
				SetupRoom(nextRoom, d);
			}
		}

		LEVEL2.CheckPuzzles();
	}
}

void ResizeWindow() {
	//resize window
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                 
	cfi.dwFontSize.Y = 4;
	SetCurrentConsoleFontEx(console, FALSE, &cfi);
	SetCurrentConsoleFontEx(drawBuff, FALSE, &cfi);

	_SMALL_RECT screenDimm;
	screenDimm.Top = 0;
	screenDimm.Left = 0;
	screenDimm.Right = SCREEN_SIZE.X - 1;
	screenDimm.Bottom = SCREEN_SIZE.Y - 1;

	SetConsoleScreenBufferSize(console, SCREEN_SIZE);
	SetConsoleScreenBufferSize(drawBuff, SCREEN_SIZE);
	if (!SetConsoleWindowInfo(console, TRUE, &screenDimm)) {
		DWORD err = GetLastError();
	}
	if (!SetConsoleWindowInfo(drawBuff, TRUE, &screenDimm)) {
		DWORD err = GetLastError();
	}
}

float GetTimeInSeconds() {
	static float timePassed = (float) clock();
	float ret = ((float)clock() - timePassed) / CLOCKS_PER_SEC;
	timePassed = (float)clock();
	return ret;
}

int GetUpdateTime() {
	static int timePassed = clock();
	int ret = (clock() - timePassed);
	timePassed = clock();
	return ret;
}

int GetDrawTime() {
	static int timePassed = clock();
	int ret = (clock() - timePassed);
	timePassed = clock();
	return ret;
}

void Load() {
	SetConsoleTextAttribute(drawBuff, 15 * 16);
	//Draw Loading Bar
	Sprites.DrawTextSprites(drawBuff, "Loading Game...", 80,20);

	GoToXY(drawBuff, 60, 30);
	for (int i = 0; i < 204; i++) {
		WriteConsole(drawBuff, "  ", 2, NULL, NULL);
	}
	for (int i = 0; i < 22; i++) {
		GoToXY(drawBuff, 60, 31 + i);
		WriteConsole(drawBuff, "  ", 2, NULL, NULL);
		GoToXY(drawBuff, 466, 31 + i);
		WriteConsole(drawBuff, "  ", 2, NULL, NULL);
	}
	GoToXY(drawBuff, 60, 53);
	for (int i = 0; i < 204; i++) {
		WriteConsole(drawBuff, "  ", 2, NULL, NULL);
	}
	SwapBuffer();

	//Load Stuff
	DWORD loadThreadID;
	int LOADED = 0;
	std::thread loadThreadH(LoadThread, std::ref(LOADED));
	loadThreadH.detach();
	int loadPerc = 0;

	SetConsoleTextAttribute(console, 10 * 16);
	while (LOADED != TO_LOAD) {
		int perc = (LOADED * 100) / TO_LOAD;
		if (perc > loadPerc) {
			loadPerc = perc;
			for (int i = 0; i < 20; i++) {
				GoToXY(console, 64, 32 + i);
				for (int j = 0; j < (loadPerc * 2); j++) {
					WriteConsole(console, "  ", 2, NULL, NULL);
				}
			}
		}
	}
}

void MouseHandler(MOUSE_EVENT_RECORD e) {
	Menu* scrn;

	switch (state) {
	case TITLE:
		if (e.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			ToCharacterSelect();
		}
		return;
	case CHARACTER_SEL:
		scrn = &CharSelMenu;
		break;
	case CHARACTER_ADD:
		scrn = &RegisterMenu;
		break;
	case CHARACTER_RMV:
		scrn = &ElimMenu;
		break;
	case GAME_OVER:
		if (deathSpinTime <= 0) {
			scrn = &GameOverMenu;
			break;
		}
		else {
			return;
		}
	case PAUSE:
		scrn = &GameOverMenu;
		break;
	default:
		//state = CHARACTER_SEL;
		return;
	}

	if (e.dwEventFlags == MOUSE_MOVED) {
		mouseLoc = e.dwMousePosition;
	}

	scrn->isOverBtn(e.dwMousePosition);

	if (e.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
		if (scrn->isOverBtn(e.dwMousePosition) && e.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			ButtonHandler(scrn->GetSelAction(), scrn->GetSelExtra());
		}
	}
}

/************************
	  ButtonHandler
*************************
	Handles Action from Button
*/

void ButtonHandler(BtnAction action, int extra) {
	switch (action) {
	case SELECT_FILE:
		if (state == CHARACTER_SEL) {
			if (PLAYER_FILES[extra].file_exists) {
				player_file = &PLAYER_FILES[extra];
				LEVEL2.SetupDungeon();
				state = PLAY;
				//Dungeon Theme here
				sounds.PlayDungeonTheme();
			}
		}
		else if(state == CHARACTER_RMV) {
			Player_Info temp;
			PLAYER_FILES[extra] = temp;
			Save();
		}
		else if (state == CHARACTER_ADD) {
			if (editId != extra) {
				editChar = 0;
				editTimer = EDIT_TIME;
			}
			editId = extra;
		}
		break;
	case REGISTER:
		ToRegisterName();
		break;
	case ERASE:
		ToEliminationMode();
		break;
	case END:
		switch (state) {
		case CHARACTER_ADD:
			ToCharacterSelect();
			break;
		case CHARACTER_RMV:
			ToRegisterName();
			break;
		}
		break;
	case CONTINUE:
		state = PLAY;
		sounds.LoadDungeonTheme();
		break;
	case SAVE:
		Save();
		ToCharacterSelect();
		sounds.LoadFileSelect();
		break;
	case RETRY:
		LoadFiles();
		ToCharacterSelect();
		sounds.LoadFileSelect();
		break;
	default:
		break;
	}
}

void Save() {

	int savesSize = sizeof(Player_Info) * 3;
	char * bytes = new char[savesSize];
	std::fstream saves("profiles.sav", std::ios::out | std::ios::in | std::ios::trunc | std::ios::binary);
	memcpy(bytes, PLAYER_FILES, savesSize);
	saves.write(bytes, savesSize);
	saves.close();
}

void LoadFiles() {
	int savesSize = sizeof(Player_Info) * 3;
	char * bytes = new char[savesSize];
	std::fstream check; // Used to check if a given file exists
	check.open("profiles.sav", std::ios_base::in | std::ios_base::out);
	std::fstream saves("profiles.sav", std::ios::out | std::ios::in | std::ios::app | std::ios::binary);
	if (!check.is_open()) {
		memcpy(bytes, PLAYER_FILES, savesSize);
		saves.write(bytes, savesSize);
		saves.close();
	}
	else {
		saves.read(bytes, savesSize);
		memcpy(PLAYER_FILES, bytes, savesSize);
		saves.close();
	}
}

void ToCharacterSelect() {
	if (state == CHARACTER_ADD) {
		for (int f = 0; f < 3; f++) {
			if (!PLAYER_FILES[f].file_exists && PLAYER_FILES[f].Name.compare("        ") == 0) {
				PLAYER_FILES[f].file_exists = false;
			}
		}

		Save();
	}

	bool setSelected = false;
	state = CHARACTER_SEL;
	std::vector<int> disableIds;
	std::vector<int> enableIds;
	for (int f = 0; f < 3; f++) {
		if (PLAYER_FILES[f].file_exists) {
			enableIds.push_back(f);
			if (!setSelected) {
				CharSelMenu.SetSelected(f);
				setSelected = true;
			}
		}
		else {
			disableIds.push_back(f);
		}
	}

	CharSelMenu.DisableButtons(disableIds);
	CharSelMenu.EnableButtons(enableIds);

	if (!setSelected) {
		CharSelMenu.SetSelected(3);
	}

	//Put Music here
	sounds.PlayFileSelect();
}

void ToRegisterName() {
	bool setSelected = false;
	state = CHARACTER_ADD;
	std::vector<int> disableIds;
	std::vector<int> enableIds;
	for (int f = 0; f < 3; f++) {
		if (!(PLAYER_FILES[f].file_exists)) {
			enableIds.push_back(f);
			if (!setSelected) {
				RegisterMenu.SetSelected(f);
				setSelected = true;
			}
		}
		else {
			disableIds.push_back(f);
		}
	}

	RegisterMenu.DisableButtons(disableIds);
	RegisterMenu.EnableButtons(enableIds);

	if (!setSelected) {
		RegisterMenu.SetSelected(3);
	}

	editId = 0;
}

void ToEliminationMode() {
	bool setSelected = false;
	state = CHARACTER_RMV;
	std::vector<int> disableIds;
	std::vector<int> enableIds;
	for (int f = 0; f < 3; f++) {
		if (PLAYER_FILES[f].file_exists) {
			enableIds.push_back(f);
			if (!setSelected) {
				ElimMenu.SetSelected(f);
				setSelected = true;
			}
		}
		else {
			disableIds.push_back(f);
		}
	}

	ElimMenu.DisableButtons(disableIds);
	ElimMenu.EnableButtons(enableIds);

	if (!setSelected) {
		ElimMenu.SetSelected(3);
	}
}

void SetupRoom(Room * r, Direction d) {
	while (drawingFrame) {

	}
	curRoom = r;
	stop_watch = false;
	player.SetDir(d);
	switch (d) {
	case Up:
		player.MoveTo({ ROOM_BOTTOM_WALL.X, ROOM_BOTTOM_WALL.Y - 16 });
		break;
	case Down:
		player.MoveTo({ ROOM_TOP_WALL.X, ROOM_TOP_WALL.Y + 16 });
		break;
	case Right:
		player.MoveTo({ ROOM_LEFT_WALL.X + 32, ROOM_LEFT_WALL.Y });
		break;
	case Left:
		player.MoveTo({ ROOM_RIGHT_WALL.X - 32, ROOM_RIGHT_WALL.Y });
		break;
	}

	curRoom->Respawn();
}

void DrawUI(int y) {
	Sprites.DrawSprite(Sprites.UIPanel, 0, 0, 512, 64, drawBuff, 0, y);

	int numHearts = player_file->MaxLife / 2;
	int numFullHearts = player_file->CurLife / 2;
	bool halfHeart = (player_file->CurLife % 2) == 1;
	for (int c = 0; c < numHearts; c++) {
		int HeartType = 0;
		if (c >= numFullHearts) {
			if (c == numFullHearts && halfHeart) {
				HeartType = 1;
			}
			else {
				HeartType = 2;
			}
		}

		if (c < 8) {
			Sprites.DrawSprite(Sprites.heartSprites, (16 * HeartType), 0, 14, 8, drawBuff, 352 + (c * 16), y + 48);
		}
		else {
			Sprites.DrawSprite(Sprites.heartSprites, (16 * HeartType), 0, 14, 8, drawBuff, 352 + ((c - 8) * 16), y + 39);
		}
	}
	
	if (player_file->Rupees < 100) {
		Sprites.DrawTextSprites(drawBuff, "x" + std::to_string(player_file->Rupees), 192, y + 24);
	}
	else {
		Sprites.DrawTextSprites(drawBuff, std::to_string(player_file->Rupees), 192, y + 24);
	}

	Sprites.DrawTextSprites(drawBuff, "x" + std::to_string(player_file->Keys), 192, y + 40);

	if (player_file->Bombs <= 0) {
		Sprites.DrawTextSprites(drawBuff, "x$", 192, y + 48);
	}
	else {
		Sprites.DrawTextSprites(drawBuff, "x" + std::to_string(player_file->Bombs), 192, y + 48);
	}

	LEVEL2.DrawMap(drawBuff, y, curRoom);
}

void Victory() {
	state = CREDITS;

}

void GameOver() {

	state = GAME_OVER;
	sounds.StopMusic();
	sounds.PlayLinkDeath();

	//clear screen except Link
	
	deathSpinTime = deathTimer;
	//play death sound byte byte
	

	//Spin link for as long as it takes.

	//Remove Link
	//put a blip on link
	
	//Play Oof?

	player_file->CurLife = 6;
	//LEVEL2.getStartRoom();
}

// CLASS FUNCTIONS
void Projectile::Hit(Enemy * e) {
	if (e->GetType() == ET_MOLDORM) {
		Moldorm * enem = (Moldorm *)e;
		enem->Hurt(dmg);
	}
	else {
		e->Hurt(dmg);
	}
}

void LockedDoor::OpenDoor() {
	bond->OpenDoors();
}

void BombableWall::OpenWall() {
	bond->OpenWalls();
}


// Enemy Functions please god forgive my spaghetti
void Enemy::draw(HANDLE out) {
	Entity::draw(out);

	for (int c = 0; c < projectiles.size(); c++) {
		projectiles[c]->draw(out);
	}
}

void Enemy::move() {
	Entity::move();

	for (int c = 0; c < projectiles.size(); c++) {
		projectiles[c]->move();
	}
}

void Enemy::Drop(std::vector<PowerUp *> * pl) {
	std::random_device gen;
	std::uniform_int_distribution<> range(1, 5);
	int per;
	per = range(gen);
	if (per == 1) {
		std::random_device gen;
		std::uniform_int_distribution<> range(1, 100);
		int per;
		per = range(gen);
		if (per >= 1 && per <= 25) {
			pl->push_back(new HeartPickup(GetX(), GetY()));
		} 
		else if (per >= 26 && per <= 50) {
			pl->push_back(new RupeesPickup(GetX(), GetY()));
		}
		else if (per >= 51 && per <= 70) {
			pl->push_back(new BombPickup(GetX(), GetY()));
		}
		else if (per >= 71 && per <= 80) {
			pl->push_back(new FairiesPickup(GetX(), GetY()));
		}
		else if (per >= 81 && per <= 90) {
			pl->push_back(new StopwatchPickup(GetX(), GetY()));
		}
		else {
			pl->push_back(new BlueRupeesPickup(GetX(), GetY()));
		}
	}
	else {
	}
}