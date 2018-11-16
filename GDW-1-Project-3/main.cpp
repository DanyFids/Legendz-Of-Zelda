#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
#include<ctime>
#include<random>

#include"Enums.h"
#include"FunctionProto.h"
#include"SpriteSheets.h"
#include"Entity.h"
#include"CoreClasses.h"
#include"Terrains.h"
#include"Enemies.h"


#include"Threads.h"


#include "bgMusicManager.h"

//Projectiles
#include "Projectiles.h"

const int PLAYER_SPEED = 2;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE drawBuff = CreateConsoleScreenBuffer(
	GENERIC_READ | GENERIC_WRITE,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	CONSOLE_TEXTMODE_BUFFER,
	NULL);
HANDLE inputH;


GameState state = TITLE;

bool Play = true;

// Play Objects
Player player(0, 0);
std::vector<Enemy*> enemies = {new Rope(80, 10),new SpikeTrap(400, 3),new SpikeTrap(400, 200),new Gel(50, 50), new Keese(100, 100) };
std::vector<Projectile*> projectiles = {};
std::vector<Terrain*> roomTer = {new Wall(20,100), new Wall(52, 100), new Wall(84, 100)};

/***************************
*			Main
***************************/
int main() {
	SCREEN_SIZE.X = 512;
	SCREEN_SIZE.Y = 224;

	Load();

	LoZTitleScreenBGM();

	//Start DrawThread
	DWORD drawThreadID;
	HANDLE drawThreadH = CreateThread(0, 0, DrawThread, NULL, 0, &drawThreadID);

	const int inputR_SIZE = 128;
	DWORD iNumRead, consoleModeSave, consoleMode;
	INPUT_RECORD inputR[inputR_SIZE];

	//hide cursor
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(console, &cursor);
	cursor.bVisible = false;
	SetConsoleCursorInfo(console, &cursor);

	ResizeWindow();


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
					//MouseHandler(inputR[c].Event.MouseEvent);
					break;
				default:
					break;
				}
			}
		}
		Update();

		Sleep(40);
	}

	CloseHandle(drawThreadH);

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
}


/************************
	   KeyHandler
*************************
	Handles keyboard input.
*/
void KeyHandler(KEY_EVENT_RECORD e) {
	if (e.bKeyDown) {
		switch (e.wVirtualKeyCode) {
		case VK_ESCAPE:
			Play = false;
			break;
		case VK_UP:
			player_input.keyUp = true;
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
			player_input.keySpace = true;
			break;
		}
	}
	else {
		switch (e.wVirtualKeyCode) {
		case VK_RETURN:
			switch (state) {
			case TITLE:
				state = PLAY;
				break;
			case PLAY:
				state = MENU;
				break;
			case MENU:
				state = PLAY;
				break;
			}
			
		case VK_UP:
			player_input.keyUp = false;
			break;
		case VK_DOWN:
			player_input.keyDown = false;
			break;
		case VK_LEFT:
			player_input.keyLeft = false;
			break;
		case VK_RIGHT:
			player_input.keyRight = false;
			break;
		case VK_SPACE:
			player_input.keySpace = false;
			break;
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
	clear();

	switch (state) {
	case TITLE:
		DrawScreen(Sprites.titleScreen);
		
		break;
	case PLAY:
		player.draw(drawBuff);

		for (int e = 0; e < enemies.size(); e++) {
			enemies[e]->draw(drawBuff);
		}

		for (int p = 0; p < projectiles.size(); p++) {
			projectiles[p]->draw(drawBuff);
		}

		for (int t = 0; t < roomTer.size(); t++) {
			roomTer[t]->draw(drawBuff);
		}

		break;
	case MENU:

		break;
	}

	SwapBuffer();
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

	if (state == PLAY) {
		bool changeDir = true;

		switch (player.GetDir()) {
		case Up:
			if (player_input.keyUp) {
				changeDir = false;
			}
			break;
		case Down:
			if (player_input.keyDown) {
				changeDir = false;
			}
			break;
		case Left:
			if (player_input.keyLeft) {
				changeDir = false;
			}			break;
		case Right:
			if (player_input.keyRight) {
				changeDir = false;
			}
			break;
		}

		if (player_input.keyUp && !player_input.keyDown) {
			player.ySpd = -PLAYER_SPEED;
			if (changeDir) {
				player.SetDir(Up);
			}
		}

		if (!player_input.keyUp && player_input.keyDown) {
			player.ySpd = PLAYER_SPEED;
			if (changeDir) {
				player.SetDir(Down);
			}
		}

		if (player_input.keyRight && !player_input.keyLeft) {
			player.xSpd = PLAYER_SPEED * 2;
			if (changeDir) {
				player.SetDir(Right);
			}
		}

		if (!player_input.keyRight && player_input.keyLeft) {
			player.xSpd = -PLAYER_SPEED * 2;
			if (changeDir) {
				player.SetDir(Left);
			}
		}

		if (player_input.keySpace)
		{
			if (player.CanAtk()) {
				Direction d = player.GetDir();
				switch (d) {
				case Up:
					projectiles.push_back(new Sword(player.GetX(), player.GetY() - 16, d));
					break;
				case Down:
					projectiles.push_back(new Sword(player.GetX(), player.GetY() + player.GetHeight(), d));
					break;
				case Left:
					projectiles.push_back(new Sword(player.GetX() - 32, player.GetY(), d));
					break;
				case Right:
					projectiles.push_back(new Sword(player.GetX() + player.GetWidth(), player.GetY(), d));
					break;
				}
			}
		}

		for (int e = 0; e < enemies.size(); e++) {
			enemies[e]->AI(player);
			if (enemies[e]->HitDetect(&player)) {
				enemies[e]->Hit(player);
			}
			for (int f = 0; f < enemies.size(); f++) {
				if (e != f) {
					enemies[e]->HitDetect(enemies[f]);
				}
			}
			for (int p = 0; p < projectiles.size(); p++) {
				if (projectiles[p]->HitDetect(enemies[e])) {
					projectiles[p]->Hit(*enemies[e]);
				}
			}
		}
		
		for (int t = 0; t < roomTer.size(); t++) {
			roomTer[t]->HitDetect(&player);
			for (int e = 0; e < enemies.size(); e++) {
				roomTer[t]->HitDetect(enemies[e]);
			}
			
		}

		player.Update(dt);
		for (int e = 0; e < enemies.size(); e++) {
			if (enemies[e]->GetHP() <= 0) {
				enemies.erase(enemies.begin() + e);
			}
			else {
				enemies[e]->Update(dt);
			}
		}
		for (int p = 0; p < projectiles.size(); p++) {
			if (projectiles[p]->getTime() > 0) {
				projectiles[p]->Update(dt);
			}
			else {
				std::vector<Projectile*>::iterator it = projectiles.begin();
				projectiles.erase(it + p);
			}
		}

	}
}

void ResizeWindow() {
	//resize window
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                 
	cfi.dwFontSize.Y = 4;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	_SMALL_RECT screenDimm;
	screenDimm.Top = 0;
	screenDimm.Left = 0;
	screenDimm.Right = SCREEN_SIZE.X - 1;
	screenDimm.Bottom = SCREEN_SIZE.Y - 1;

	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), SCREEN_SIZE);
	SetConsoleScreenBufferSize(drawBuff, SCREEN_SIZE);
	if (!SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &screenDimm)) {
		DWORD err = GetLastError();
	}
}

float GetTimeInSeconds() {
	static float timePassed = (float) clock();
	float ret = ((float)clock() - timePassed) / CLOCKS_PER_SEC;
	timePassed = (float)clock();
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
	HANDLE loadThreadH = CreateThread(0, 0, LoadThread, NULL, 0, &loadThreadID);
	int loadPerc = 0;

	SetConsoleTextAttribute(drawBuff, 10 * 16);
	while (SPRITES_LOADED != SPRITES_TO_LOAD) {
		int perc = (SPRITES_LOADED * 100) / SPRITES_TO_LOAD;
		if (perc > loadPerc) {
			loadPerc = perc;
			for (int i = 0; i < 20; i++) {
				GoToXY(drawBuff, 64, 32 + i);
				for (int j = 0; j < (loadPerc * 2); j++) {
					WriteConsole(drawBuff, "  ", 2, NULL, NULL);
				}
			}

			SwapBuffer();
		}
	}
}