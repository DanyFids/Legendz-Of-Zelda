#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<Windows.h>
#include<ctime>
#include<random>
#include<cmath>

#include"Enums.h"
#include"FunctionProto.h"
#include"SpriteSheets.h"
#include"Entity.h"
#include"CoreClasses.h"
#include"Terrains.h"
#include "Projectiles.h"
#include"Enemies.h"

#include"Menus.h"
#include "sfxManager.h"
#include "PowerUp.h"

//SFX/BGM Managers
//#include "bgMusicManager.h"

#include"Threads.h"

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

COORD mouseLoc;

GameState state = TITLE;

bool Play = true;

// Play Objects
// Player
Player player(0, 0);
// Non-Player entities
std::vector<Enemy*> enemies = {new Dodongo(400, 100), new Statue(100, 200, false)};
std::vector<Projectile*> projectiles = {new Bomb(400, 100)};
std::vector<Terrain*> roomTer = {new Wall(20,100), new Wall(52, 100), new Wall(84, 100)};
std::vector<PowerUp *> powerups = {};

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

	ResizeWindow();
	//LoZTitleScreenBGM();	 //Legacy Player
	Load();
	//sounds.PlayTitleTheme();

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
					MouseHandler(inputR[c].Event.MouseEvent);
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
				player_input.keySpace = true;
				break;
			}
		}
		else {
			switch (e.wVirtualKeyCode) {
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
	case CHARACTER_SEL:
		DrawScreen(Sprites.CharacterScreen);
		CharSelMenu.Draw(drawBuff);
		break;
	case PLAY:
		for (int e = 0; e < enemies.size(); e++) {
			enemies[e]->draw(drawBuff);
		}

		for (int t = 0; t < roomTer.size(); t++) {
			roomTer[t]->draw(drawBuff);
		}

 		for (int p = 0; p < projectiles.size(); p++) {
			projectiles[p]->draw(drawBuff);
		}

		player.draw(drawBuff);
		break;
	case INVENTORY:

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

		if (player_input.keySpace)
		{
			//sounds.PlaySwing();
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
					if (projectiles[p]->getEnum() == PT_BOMB){
						if (enemies[e]->getBoss()) {
							Dodongo * boss = (Dodongo *)enemies[e];
							boss->BombHurt();
							projectiles[p]->setTime(0.0f);
						}
					}
					else {
						projectiles[p]->Hit(*enemies[e]);
						if (projectiles[p]->getEnum() == PT_ARROW) {
							delete projectiles[p];
							std::vector<Projectile*>::iterator it = projectiles.begin();
							projectiles.erase(it + p);
						}
					}
				}
			}

		}

		for (int p = 0; p < projectiles.size(); p++) {
			if (projectiles[p]->getEnum() == PT_FIREBALL) {
				if (projectiles[p]->HitDetect(&player)) {
					projectiles[p]->Hit(player);
				}
			}
		}
		
		for (int t = 0; t < roomTer.size(); t++) {
			if ((roomTer[t]->HitDetect(&player) && roomTer[t]->CanMove()) || roomTer[t]->isMoving()) {
				roomTer[t]->Update(dt);
			}
			for (int e = 0; e < enemies.size(); e++) {
				roomTer[t]->HitDetect(enemies[e]);
				for (int ep = 0; ep < enemies[e]->projectiles.size(); ep++) {
					if (roomTer[t]->HitDetect(enemies[e]->projectiles[ep])) {
						enemies[e]->projectiles[ep]->setTime(0.0f);
					}
				}
			}
		}

		player.Update(dt);
		for (int e = 0; e < enemies.size(); e++) {
			if (enemies[e]->GetHP() <= 0) {
				enemies.erase(enemies.begin() + e);
			}
			else {
				if (!stop_watch)
				{
					enemies[e]->Update(dt);
				}
			}
		}
		for (int p = 0; p < projectiles.size(); p++) {
			projectiles[p]->Update(dt);
			if (projectiles[p]->getTime() <= 0){
				std::vector<Projectile*>::iterator it = projectiles.begin();
				projectiles.erase(it + p);
			}
		}

		for (int c = 0; c < powerups.size(); c++) {
			if (powerups[c]->HitDetect(&player)) {
				powerups[c]->Effect(*player_file);
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
	while (LOADED != TO_LOAD) {
		int perc = (LOADED * 100) / TO_LOAD;
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
				state = PLAY;
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