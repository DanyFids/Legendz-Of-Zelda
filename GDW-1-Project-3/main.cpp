#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<Windows.h>
#include<ctime>
#include<random>
#include<thread>

#include"Enums.h"
#include"FunctionProto.h"
#include"SpriteSheets.h"
#include"Entity.h"
#include"CoreClasses.h"
#include"Terrains.h"
#include"Enemies.h"
#include"Menus.h"
#include "PowerUp.h"
#include"Room.h"
#include"Dungeon.h"

//SFX/BGM Managers
//#include "bgMusicManager.h"
//#include "sfxManager.h"
#include"Threads.h"

//Projectiles
#include "Projectiles.h"

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

Dungeon LEVEL2;

Room * curRoom = LEVEL2.GetStartRoom();

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
	//hide cursor
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(console, &cursor);
	cursor.bVisible = false;
	SetConsoleCursorInfo(console, &cursor);

	//LoZTitleScreenBGM();	 //Legacy Player
	Load();
	//sounds.PlayTitleTheme();
	//PlayDungeonTheme();

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
				else if(isalnum(e.uChar.AsciiChar) || e.uChar.AsciiChar == ' '){
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
				
				//LoZDungeonThemeBGM();		   //Legacy Player

				break;
			case PLAY:
				state = INVENTORY;
				//LoZTitleScreenBGM();		  //Legacy Player
				break;
			case INVENTORY:
				state = PLAY;
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
			case 'C':
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
			case 'C':
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

		for (int t = 0; t < curRoom->TerrainList.size(); t++) {
			curRoom->TerrainList[t]->draw(drawBuff);
		}

		for (int p = 0; p < projectiles.size(); p++) {
			projectiles[p]->draw(drawBuff);
		}

		for (int u = 0; u < powerups.size(); u++) {
			powerups[u]->draw(drawBuff);
		}

		player.draw(drawBuff);

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
				player.SwingSword();
			}
		}

		for (int e = 0; e < curRoom->EnemyList.size(); e++) {
			curRoom->EnemyList[e]->AI(player);
			if (curRoom->EnemyList[e]->HitDetect(&player)) {
				curRoom->EnemyList[e]->Hit(player);
			}
			for (int f = 0; f < curRoom->EnemyList.size(); f++) {
				if (e != f) {
					curRoom->EnemyList[e]->HitDetect(curRoom->EnemyList[f]);
				}
			}
			for (int p = 0; p < projectiles.size(); p++) {
				if (projectiles[p]->HitDetect(curRoom->EnemyList[e])) {
					projectiles[p]->Hit(curRoom->EnemyList[e]);
					if (projectiles[p]->getEnum() == PT_ARROW) {
						std::vector<Projectile*>::iterator it = projectiles.begin();
						projectiles.erase(it + p);
						delete projectiles[p];
					}
				}
			}
		}
		
		for (int t = 0; t < curRoom->TerrainList.size(); t++) {
			curRoom->TerrainList[t]->HitDetect(&player);
			for (int e = 0; e < curRoom->EnemyList.size(); e++) {
				curRoom->TerrainList[t]->HitDetect(curRoom->EnemyList[e]);
			}
			for (int p = 0; p < projectiles.size(); p++) {
				if (projectiles[p]->getEnum() == PT_EXPLOSION) {
					curRoom->TerrainList[t]->HitDetect(projectiles[p]);
				}
			}
		}
		for (int u = 0; u < powerups.size(); u++) {
			
			if (powerups[u]->HitDetect(&player)) {
				powerups[u]->Effect(player_file);
				delete powerups[u];
				std::vector<PowerUp *>::iterator it = powerups.begin();
				powerups.erase(it + u);
			}
		}

		player.Update(dt);
		for (int e = 0; e < curRoom->EnemyList.size(); e++) {
			if (curRoom->EnemyList[e]->GetHP() <= 0) {
				curRoom->EnemyList.erase(curRoom->EnemyList.begin() + e);
			}
			else {
				if (!stop_watch)
				{
					curRoom->EnemyList[e]->Update(dt);
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
	//player_file->CurLife = player.GetHp();

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

void SetupRoom(Room * r, Direction d) {
	while (drawingFrame) {

	}
	curRoom = r;
	player.SetDir(d);
	switch (d) {
	case Up:
		player.MoveTo(ROOM_BOTTOM_WALL);
		break;
	case Down:
		player.MoveTo(ROOM_TOP_WALL);
		break;
	case Right:
		player.MoveTo(ROOM_LEFT_WALL);
		break;
	case Left:
		player.MoveTo(ROOM_RIGHT_WALL);
		break;
	}
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