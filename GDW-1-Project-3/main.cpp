#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>

#include"FunctionProto.h"
#include"SpriteSheets.h"
#include"Entity.h"
#include"CoreClasses.h"
#include "Sword.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE drawBuff = CreateConsoleScreenBuffer(
	GENERIC_READ | GENERIC_WRITE,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	CONSOLE_TEXTMODE_BUFFER,
	NULL);
HANDLE inputH;

//Instantiate stuff HERE.
Player player(0, 0);


bool Play = true;

/***************************
*			Main
***************************/
int main() {

	Sprites.LoadPlayer();

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
					//MouseHandler(inputR[c].Event.MouseEvent);
					break;
				default:
					break;
				}
			}
		}

		Draw();
	}

	return 0;
}


void GoToXY(HANDLE h, int x, int y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;

	SetConsoleCursorPosition(h, xy);
}

void DrawChars() {
	COORD size;
	size.X = 120;
	size.Y = 258;

	SetConsoleScreenBufferSize(console, size);

	for (int i = 0; i < 256; i++) {
		std::cout << i << ": " << (char)i << std::endl;
	}
}

void SwapBuffer() {
	CHAR_INFO *outBuff = new CHAR_INFO[120 * 30];

	//Area to read/write
	SMALL_RECT screen;
	screen.Top = 0;
	screen.Left = 0;
	screen.Right = 119;
	screen.Bottom = 29;

	//Top Left COORD
	COORD start;
	start.X = 0;
	start.Y = 0;

	//Buffer Size
	COORD size;
	size.X = 120;
	size.Y = 30;

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
			player.move(0, -1);
			break;
		case VK_DOWN:
			player.move(0, 1);
			break;
		case VK_LEFT:
			player.move(-2, 0);
			break;
		case VK_RIGHT:
			player.move(2, 0);
			break;
		case VK_TAB:
			
			break;
		case VK_SPACE:
			
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

	player.draw(drawBuff);

	SwapBuffer();
}