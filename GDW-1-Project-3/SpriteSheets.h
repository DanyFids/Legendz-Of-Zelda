#pragma once

class SpriteSheets {
public:

	void DrawSprite(HANDLE sheet, int sX, int sY, int w, int h, HANDLE dest, int dx, int dy, bool trans = false) {
		int drX = 0;
		if (dx < 0) {
			drX = -dx;
		}

		int drY = 0;
		if (dy < 0) {
			drY = -dy;
		}

		CHAR_INFO *outBuff = new CHAR_INFO[w * h];
		CHAR_INFO *transBuff = new CHAR_INFO[w * h];

		//Area to read/write
		SMALL_RECT screen;
		screen.Top = sY + drY;
		screen.Left = sX + drX;
		screen.Right = sX + w - 1;
		screen.Bottom = sY + h - 1;

		//Top Left COORD
		COORD start;
		start.X = 0;
		start.Y = 0;

		//Position
		COORD pos;
		pos.X = 0;
		pos.Y = 0;

		//Buffer Size
		COORD size;
		size.X = w - drX;
		size.Y = h - drY;

		//Speed up by doing memcpy instead of ReadConsole:
		//
		ReadConsoleOutput(sheet, outBuff, size, start, &screen);

		screen.Top = dy + drY;
		screen.Left = dx + drX;
		screen.Right = w + dx - 1;
		screen.Bottom = h + dy - 1;

		if (trans) {
		ReadConsoleOutput(dest, transBuff, size, pos, &screen);
			for (int p = 0; p < (w * h); p++) {
				if (outBuff[p].Attributes == 7) {
					outBuff[p] = transBuff[p];
				}
			}
		}

		WriteConsoleOutput(dest, outBuff, size, pos, &screen);

		delete[] outBuff;
		delete[] transBuff;
	}

	HANDLE dodongoSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE playerSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE brickSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE blockSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE wallSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);
	HANDLE roomSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE keeseSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE spiketrapSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE gelSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE ropeSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE swordSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE bombSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE holeSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE doorSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE floorSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);


	HANDLE heartSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE stopwatchSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE titleScreen = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);
	HANDLE CharacterScreen = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);
	HANDLE GenericScreen = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);
	HANDLE InventoryScreen = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);
	HANDLE UIPanel = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	bool LoadDodongo() {
		SetConsoleScreenBufferSize(dodongoSprites, SCREEN_SIZE);
		DWORD output;
		for (int i = 0; i < 16; i++) {
			GoToXY(playerSprites, 0, i);
			WriteConsole(playerSprites, &"                             ", 30, &output, NULL);
		}
		SetConsoleTextAttribute(playerSprites, 7);
		
		GoToXY(playerSprites, 5, 3);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		char mGrad = { (char)177 };

		// Normal Facing Left First Foot Up
		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 14); // Yellow with red

		// First Row
		GoToXY(dodongoSprites, 18, 0);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);;
		}

		// Second Row
		GoToXY(dodongoSprites, 14, 1);
		for (int c = 0; c < 12; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(dodongoSprites, 12, 2);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 30, 2);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(dodongoSprites, 10, 3);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 16, 3);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 28, 3);
		for (int c = 0; c < 12; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(dodongoSprites, 8, 4);
		for (int c = 0; c < 16; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 28, 4);
		for (int c = 0; c < 16; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(dodongoSprites, 8, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 16, 5);
		for (int c = 0; c < 10; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 28, 5);
		for (int c = 0; c < 18; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(dodongoSprites, 4, 6);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 16, 6);
		for (int c = 0; c < 10; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 28, 6);
		for (int c = 0; c < 20; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(dodongoSprites, 2, 7);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 14, 7);
		for (int c = 0; c < 12; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 30, 7);
		for (int c = 0; c < 20; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(dodongoSprites, 0, 8);
		for (int c = 0; c < 16; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 18, 8);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 26, 8);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 32, 8);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 42, 8);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(dodongoSprites, 4, 9);
		for (int c = 0; c < 10; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 16, 9);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 24, 9);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 32, 9);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 40, 9);
		for (int c = 0; c < 12; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(dodongoSprites, 10, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 16, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 22, 10);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 32, 10);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 40, 10);
		for (int c = 0; c < 12; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(dodongoSprites, 6, 11);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 22, 11);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 32, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 40, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 48, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(dodongoSprites, 2, 12);
		for (int c = 0; c < 16; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 20, 12);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 34, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 40, 12);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 48, 12);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(dodongoSprites, 6, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 20, 13);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 40, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 50, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(dodongoSprites, 40, 14);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 54, 14);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(dodongoSprites, 15 * 16); // White

		// Third Row
		GoToXY(dodongoSprites, 8, 2);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(dodongoSprites, 0, 3);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);

		GoToXY(dodongoSprites, 8, 3);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(dodongoSprites, 0, 4);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(dodongoSprites, 2, 5);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);

		GoToXY(dodongoSprites, 14, 5);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(dodongoSprites, 2, 6);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);

		GoToXY(dodongoSprites, 12, 6);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);

		// Eighth Row
		GoToXY(dodongoSprites, 10, 7);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 6);

		// Third Row
		GoToXY(dodongoSprites, 26, 2);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(dodongoSprites, 12, 3);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 24, 3);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(dodongoSprites, 24, 4);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(dodongoSprites, 10, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 26, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(dodongoSprites, 10, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 26, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(dodongoSprites, 8, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 26, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(dodongoSprites, 16, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 24, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 30, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 40, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(dodongoSprites, 2, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 14, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 22, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 30, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 38, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(dodongoSprites, 4, 10);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 14, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 20, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 30, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 38, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(dodongoSprites, 4, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 20, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 30, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 38, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 46, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(dodongoSprites, 18, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 28, 12);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 38, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 46, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(dodongoSprites, 14, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 30, 13);
		for (int c = 0; c < 10; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 46, 13);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(dodongoSprites, 14, 14);
		for (int c = 0; c < 10; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 38, 14);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		GoToXY(dodongoSprites, 48, 14);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		return true;
	}

	bool LoadPlayer() {
		//anim 1 frame 1
		SetConsoleScreenBufferSize(playerSprites, SCREEN_SIZE);

		DWORD output;

		char mGrad = { (char)177 };

		// Facing forward, shield, Left Foot
		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 10, 0);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 14, 0);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 8, 1);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 16, 1);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 8, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 22, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 12, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 18, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 6, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 22, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 20, 8);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 14, 9);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 22, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 18, 10);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 14, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 18, 12);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 14, 13);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 22, 13);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red with dark yellow

		// Third Row
		GoToXY(playerSprites, 10, 2);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 8, 3);
		for (int c = 0; c < 16; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 8, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 22, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 8, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 12, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 18, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 22, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 26, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 14, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 26, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 2, 8);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 24, 8);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 0, 9);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 6, 9);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 26, 9);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 0, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 8, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 14, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 28, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 0, 11);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 6, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 16, 11);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 0, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 6, 12);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 14, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 0, 13);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 12, 14);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 18, 14);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 8, 15);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow (Light brown)

		// Third Row
		GoToXY(playerSprites, 4, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 26, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 4, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 26, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 4, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 10, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 14, 4);
		WriteConsole(playerSprites, &"     ", 4, &output, NULL);
		GoToXY(playerSprites, 20, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 24, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 4, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 10, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 14, 5);
		WriteConsole(playerSprites, &"     ", 4, &output, NULL);
		GoToXY(playerSprites, 20, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 24, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 6, 6);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 10, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 18, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 12, 8);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 4, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 24, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 2, 10);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 12, 10);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 22, 10);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 4, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 12, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 24, 11);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 4, 12);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 12, 12);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 26, 12);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 12, 13);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifteenth Row
		GoToXY(playerSprites, 2, 14);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Facing Right, Shield, Standing
		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 44, 0);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 40, 1);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 36, 2);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 44, 2);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 34, 3);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 34, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 38, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 54, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 38, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 42, 7);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 40, 8);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 42, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 50, 9);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 50, 10);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 48, 11);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 38, 12);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 44, 12);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 36, 13);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow

		// Third Row
		GoToXY(playerSprites, 42, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 42, 3);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 42, 4);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 50, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 56, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 44, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 50, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 56, 5);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 46, 6);
		WriteConsole(playerSprites, &"            ", 12, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 50, 7);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 60, 8);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 44, 9);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 60, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 44, 10);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 44, 11);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red with yellow

		// Second Row
		GoToXY(playerSprites, 50, 1);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 48, 2);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 46, 3);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 48, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 62, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 40, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 48, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 54, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 62, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 40, 6);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 62, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 62, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 38, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 54, 8);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 62, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 36, 9);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 56, 9);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 62, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 36, 10);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 56, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 62, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 36, 11);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 54, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 62, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 40, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 48, 12);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 62, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 42, 14);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 42, 15);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Facing Left, Shield, Standing

		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 80, 0);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 82, 1);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 90, 2);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 84, 2);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 90, 3);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 96, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 90, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 76, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 92, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 82, 7);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 78, 8);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 88, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 76, 9);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 76, 10);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 78, 11);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 92, 12);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 84, 12);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 76, 13);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow

		// Third Row
		GoToXY(playerSprites, 88, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 86, 3);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 84, 4);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 78, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 74, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 84, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 78, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 70, 5);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 74, 6);
		WriteConsole(playerSprites, &"            ", 12, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 74, 7);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 70, 8);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 82, 9);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 70, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 82, 10);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 84, 11);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red with yellow

		// Second Row
		GoToXY(playerSprites, 74, 1);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 72, 2);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 74, 3);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 82, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 88, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 82, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 76, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 86, 6);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 68, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 92, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 72, 8);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 90, 9);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 72, 9);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 88, 10);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 72, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 88, 11);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 76, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 88, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 76, 12);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 82, 14);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 80, 15);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Facing Back, Shield, Left Foot Back

		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 108, 0);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 106, 1);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 106, 2);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 104, 3);
		WriteConsole(playerSprites, &"                        ", 24, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 106, 4);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 112, 5);
		WriteConsole(playerSprites, &"         ", 8, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 114, 6);
		WriteConsole(playerSprites, &"     ", 4, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 106, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 124, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 106, 8);
		WriteConsole(playerSprites, &"                  ", 18, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 106, 9);
		WriteConsole(playerSprites, &"                  ", 18, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 108, 10);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 104, 11);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 124, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 104, 12);
		WriteConsole(playerSprites, &"                        ", 24, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 110, 13);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow

		// Third Row
		GoToXY(playerSprites, 102, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 128, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 102, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 128, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 102, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 128, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 102, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 126, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 104, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 126, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 128, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 128, 10);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 126, 11);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6);

		// Fifth Row
		GoToXY(playerSprites, 104, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 126, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 106, 5);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 120, 5);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 106, 6);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 118, 6);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 104, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 108, 7);
		for (int c = 0; c < 16; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 126, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 102, 8);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 124, 8);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 102, 9);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 124, 9);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 104, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 124, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 108, 11);
		for (int c = 0; c < 16; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 104, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 124, 13);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 104, 14);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 120, 14);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 106, 15);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Facing Back, Shield, Right Foot Back

		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 140, 0);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 138, 1);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 138, 2);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 136, 3);
		WriteConsole(playerSprites, &"                        ", 24, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 138, 4);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 144, 5);
		WriteConsole(playerSprites, &"         ", 8, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 146, 6);
		WriteConsole(playerSprites, &"     ", 4, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 138, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 156, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 140, 8);
		WriteConsole(playerSprites, &"                  ", 18, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 140, 9);
		WriteConsole(playerSprites, &"                  ", 18, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 140, 10);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 138, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 156, 11);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 136, 12);
		WriteConsole(playerSprites, &"                        ", 24, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 140, 13);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow

		// Third Row
		GoToXY(playerSprites, 134, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 160, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 134, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 160, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 134, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 160, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 134, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 158, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 136, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 158, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 134, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 134, 10);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 134, 11);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6);

		// Fifth Row
		GoToXY(playerSprites, 136, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 158, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 138, 5);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 152, 5);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 138, 6);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 150, 6);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 136, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 140, 7);
		for (int c = 0; c < 16; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 158, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 136, 8);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 158, 8);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 136, 9);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 158, 9);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 136, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 156, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 140, 11);
		for (int c = 0; c < 16; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 138, 13);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 154, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 140, 14);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 152, 14);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 154, 15);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Facing forward, shield, Right Foot
		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 176, 0);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 180, 0);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 174, 1);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 182, 1);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 174, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 188, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 178, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 184, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 172, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 188, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 186, 8);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 180, 9);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 188, 9);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 186, 10);
		WriteConsole(playerSprites, &"      ", 4, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 182, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 190, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 184, 12);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 180, 13);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 188, 13);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red with dark yellow

		// Third Row
		GoToXY(playerSprites, 176, 2);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 174, 3);
		for (int c = 0; c < 16; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 174, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 188, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 174, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 178, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 184, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 188, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 192, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 180, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 190, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 170, 8);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 168, 9);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 174, 9);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 168, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 176, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 182, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 190, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 168, 11);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 174, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 184, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 168, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 174, 12);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 182, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 168, 13);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 188, 13);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 184, 14);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 184, 15);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow (Light brown)

		// Third Row
		GoToXY(playerSprites, 170, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 192, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 170, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 192, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 170, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 176, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 180, 4);
		WriteConsole(playerSprites, &"     ", 4, &output, NULL);
		GoToXY(playerSprites, 186, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 190, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 170, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 176, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 180, 5);
		WriteConsole(playerSprites, &"     ", 4, &output, NULL);
		GoToXY(playerSprites, 186, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 190, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 172, 6);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 184, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 176, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 180, 8);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 192, 8);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 172, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 192, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 170, 10);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 180, 10);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 172, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 180, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 172, 12);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 180, 12);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 180, 13);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifteenth Row
		GoToXY(playerSprites, 170, 14);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Facing Right, Shield, Walking

		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 44, 17);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 40, 18);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 36, 19);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 44, 19);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 34, 20);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 34, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 38, 21);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 54, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 38, 22);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 42, 24);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 38, 25);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 42, 26);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 50, 26);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 36, 27);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 50, 27);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 36, 28);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 48, 28);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 34, 29);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);
		GoToXY(playerSprites, 56, 29);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 36, 30);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow

		// Third Row
		GoToXY(playerSprites, 42, 19);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 42, 20);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 42, 21);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 50, 21);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 56, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 44, 22);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 50, 22);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 56, 22);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 46, 23);
		WriteConsole(playerSprites, &"            ", 12, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 50, 24);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 48, 25);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 58, 25);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 48, 26);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 58, 26);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 48, 27);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red with yellow

		// Second Row
		GoToXY(playerSprites, 50, 18);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 48, 19);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 46, 20);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 48, 21);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 40, 22);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 48, 22);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 54, 22);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 40, 23);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 60, 23);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 60, 24);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 40, 25);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 54, 25);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 60, 25);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 38, 26);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 56, 26);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 60, 26);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 38, 27);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 56, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 60, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 40, 28);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 54, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 60, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 48, 29);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 60, 29);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 34, 29);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 34, 30);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 56, 30);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 36, 31);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 52, 31);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Facing Left, Shield, Walking

		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 10, 17);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 12, 18);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 20, 19);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 14, 19);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 20, 20);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 26, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 20, 21);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 6, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 22, 22);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 12, 24);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 10, 25);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 6, 26);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 12, 26);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 6, 27);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 20, 27);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 22, 28);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 8, 28);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 10, 29);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);
		GoToXY(playerSprites, 4, 29);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 2, 30);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow

		// Third Row
		GoToXY(playerSprites, 18, 19);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 16, 20);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 14, 21);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 8, 21);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 4, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 8, 22);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 14, 22);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 0, 22);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 4, 23);
		WriteConsole(playerSprites, &"            ", 12, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 4, 24);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 8, 25);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 2, 25);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 8, 26);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 2, 26);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 10, 27);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red with yellow

		// Second Row
		GoToXY(playerSprites, 4, 18);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 2, 19);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 4, 20);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 12, 21);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 18, 22);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 12, 22);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 6, 22);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 16, 23);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 0, 23);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 0, 24);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 4, 25);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 18, 25);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 0, 25);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 14, 26);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 4, 26);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 0, 26);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 14, 27);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 4, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 0, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 14, 28);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 6, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 0, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 6, 29);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 0, 29);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 24, 29);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 22, 30);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 2, 30);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 4, 31);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 20, 31);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		return true;
	}

	bool LoadKeese() {
		SetConsoleScreenBufferSize(keeseSprites, SCREEN_SIZE);

		DWORD output;

		// Wings Spread
		SetConsoleTextAttribute(keeseSprites, 1 * 16); // Blue

		// First Row
		GoToXY(keeseSprites, 8, 0);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 12, 0);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 18, 0);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 22, 0);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);

		// Second Row
		GoToXY(keeseSprites, 6, 1);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);
		GoToXY(keeseSprites, 22, 1);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);
		GoToXY(keeseSprites, 14, 1);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);

		// Third Row
		GoToXY(keeseSprites, 14, 2);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);
		GoToXY(keeseSprites, 4, 2);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);
		GoToXY(keeseSprites, 20, 2);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);

		// Fourth Row
		GoToXY(keeseSprites, 4, 3);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);
		GoToXY(keeseSprites, 12, 3);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);
		GoToXY(keeseSprites, 20, 3);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);

		// Fifth Row
		GoToXY(keeseSprites, 2, 4);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);
		GoToXY(keeseSprites, 10, 4);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);
		GoToXY(keeseSprites, 18, 4);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);
		GoToXY(keeseSprites, 26, 4);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(keeseSprites, 2, 5);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);
		GoToXY(keeseSprites, 10, 5);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);
		GoToXY(keeseSprites, 18, 5);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);
		GoToXY(keeseSprites, 26, 5);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);

		// Seventh Row
		GoToXY(keeseSprites, 0, 6);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);
		GoToXY(keeseSprites, 6, 6);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 10, 6);
		WriteConsole(keeseSprites, &"        ", 8, &output, NULL);
		GoToXY(keeseSprites, 18, 6);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);
		GoToXY(keeseSprites, 24, 6);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 28, 6);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);

		// Eighth Row
		GoToXY(keeseSprites, 0, 7);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 12, 7);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 18, 7);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 30, 7);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(keeseSprites, 9 * 16); // Light Blue
		GoToXY(keeseSprites, 12, 2);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 18, 2);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 12, 1);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 18, 1);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);

		// Wings in
		SetConsoleTextAttribute(keeseSprites, 1 * 16); // Blue

		// First Row
		GoToXY(keeseSprites, 38, 0);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);
		GoToXY(keeseSprites, 46, 0);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);

		// Second Row
		GoToXY(keeseSprites, 38, 1);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 42, 1);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);
		GoToXY(keeseSprites, 48, 1);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(keeseSprites, 36, 2);
		WriteConsole(keeseSprites, &"                ", 16, &output, NULL);

		// Fourth Row
		GoToXY(keeseSprites, 36, 3);
		WriteConsole(keeseSprites, &"                ", 16, &output, NULL);

		// Fifth Row
		GoToXY(keeseSprites, 34, 4);
		WriteConsole(keeseSprites, &"                    ", 20, &output, NULL);

		// Sixth Row
		GoToXY(keeseSprites, 34, 5);
		WriteConsole(keeseSprites, &"                    ", 20, &output, NULL);

		// Seventh Row
		GoToXY(keeseSprites, 34, 6);
		WriteConsole(keeseSprites, &"                    ", 20, &output, NULL);

		// Eighth Row
		GoToXY(keeseSprites, 36, 7);
		WriteConsole(keeseSprites, &"      ", 6, &output, NULL);
		GoToXY(keeseSprites, 46, 7);
		WriteConsole(keeseSprites, &"      ", 6, &output, NULL);

		// Ninth Row
		GoToXY(keeseSprites, 36, 8);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);
		GoToXY(keeseSprites, 48, 8);
		WriteConsole(keeseSprites, &"    ", 4, &output, NULL);

		//Tenth Row
		GoToXY(keeseSprites, 38, 9);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 48, 9);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(keeseSprites, 9 * 16); // Light Blue

		GoToXY(keeseSprites, 40, 2);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 46, 2);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 40, 1);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		GoToXY(keeseSprites, 46, 1);
		WriteConsole(keeseSprites, &"  ", 2, &output, NULL);
		return true;
	}

	bool LoadRope() {

		SetConsoleScreenBufferSize(ropeSprites, SCREEN_SIZE);

		DWORD output;

		char mGrad = { (char)177 };

		// Facing left, tail extended
		SetConsoleTextAttribute(ropeSprites, 4 * 16 + 14); // Yellow with red

		// First Row
		GoToXY(ropeSprites, 6, 0);
		for (int c = 0; c < 8; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Second Row
		GoToXY(ropeSprites, 4, 1);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 10, 1);
		for (int c = 0; c < 6; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(ropeSprites, 10, 2);
		for (int c = 0; c < 6; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(ropeSprites, 8, 3);
		for (int c = 0; c < 10; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(ropeSprites, 0, 4);
		for (int c = 0; c < 20; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(ropeSprites, 8, 5);
		for (int c = 0; c < 12; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(ropeSprites, 10, 6);
		for (int c = 0; c < 10; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(ropeSprites, 2, 7);
		for (int c = 0; c < 16; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(ropeSprites, 6, 8);
		for (int c = 0; c < 8; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(ropeSprites, 10, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(ropeSprites, 6, 10);
		for (int c = 0; c < 6; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 16, 10);
		for (int c = 0; c < 6; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(ropeSprites, 6, 11);
		for (int c = 0; c < 18; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(ropeSprites, 4, 12);
		for (int c = 0; c < 14; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 22, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 28, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(ropeSprites, 6, 13);
		for (int c = 0; c < 8; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 24, 13);
		for (int c = 0; c < 4; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(ropeSprites, 4 * 16); // Red

		// Second Row
		GoToXY(ropeSprites, 6, 1);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);

		// Third Row
		GoToXY(ropeSprites, 4, 2);
		WriteConsole(ropeSprites, &"      ", 6, &output, NULL);

		// Fourth Row
		GoToXY(ropeSprites, 2, 3);
		WriteConsole(ropeSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(ropeSprites, 6, 9);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);

		// Twelfth Row
		GoToXY(ropeSprites, 0, 11);
		WriteConsole(ropeSprites, &"      ", 6, &output, NULL);

		// Fourteenth Row
		GoToXY(ropeSprites, 2, 13);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(ropeSprites, 15 * 16); // White

		// Sixth Row
		GoToXY(ropeSprites, 2, 5);
		WriteConsole(ropeSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(ropeSprites, 2, 10);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);

		// Thirteenth Row
		GoToXY(ropeSprites, 0, 12);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);

		return true;

	}

	bool LoadSpikeTrap() {

		SetConsoleScreenBufferSize(spiketrapSprites, SCREEN_SIZE);

		DWORD output;

		// The spike trap doesn't change for anyone. RESPEC 
		SetConsoleTextAttribute(spiketrapSprites, 8 * 16); // Grey

		// First Row
		GoToXY(spiketrapSprites, 12, 0);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 18, 0);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Second Row
		GoToXY(spiketrapSprites, 12, 1);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 18, 1);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(spiketrapSprites, 12, 2);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 18, 2);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(spiketrapSprites, 12, 3);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 18, 3);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(spiketrapSprites, 0, 6);
		WriteConsole(spiketrapSprites, &"        ", 8, &output, NULL);
		GoToXY(spiketrapSprites, 24, 6);
		WriteConsole(spiketrapSprites, &"        ", 8, &output, NULL);

		// Tenth Row
		GoToXY(spiketrapSprites, 0, 9);
		WriteConsole(spiketrapSprites, &"        ", 8, &output, NULL);
		GoToXY(spiketrapSprites, 24, 9);
		WriteConsole(spiketrapSprites, &"        ", 8, &output, NULL);

		// Thirteenth Row
		GoToXY(spiketrapSprites, 12, 12);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 18, 12);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(spiketrapSprites, 12, 13);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 18, 13);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Fifteenth Row
		GoToXY(spiketrapSprites, 12, 14);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 18, 14);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Sixteenth Row
		GoToXY(spiketrapSprites, 12, 15);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 18, 15);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(spiketrapSprites, 1 * 16); // blue

		// Fifth Row
		GoToXY(spiketrapSprites, 10, 4);
		WriteConsole(spiketrapSprites, &"            ", 12, &output, NULL);

		// Sixth Row
		GoToXY(spiketrapSprites, 8, 5);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 12, 5);
		WriteConsole(spiketrapSprites, &"        ", 8, &output, NULL);
		GoToXY(spiketrapSprites, 22, 5);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(spiketrapSprites, 8, 6);
		WriteConsole(spiketrapSprites, &"    ", 4, &output, NULL);
		GoToXY(spiketrapSprites, 20, 6);
		WriteConsole(spiketrapSprites, &"    ", 4, &output, NULL);

		// Eighth Row
		GoToXY(spiketrapSprites, 8, 7);
		WriteConsole(spiketrapSprites, &"    ", 4, &output, NULL);
		GoToXY(spiketrapSprites, 20, 7);
		WriteConsole(spiketrapSprites, &"    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(spiketrapSprites, 8, 8);
		WriteConsole(spiketrapSprites, &"    ", 4, &output, NULL);
		GoToXY(spiketrapSprites, 20, 8);
		WriteConsole(spiketrapSprites, &"    ", 4, &output, NULL);

		// Tenth Row
		GoToXY(spiketrapSprites, 8, 9);
		WriteConsole(spiketrapSprites, &"    ", 4, &output, NULL);
		GoToXY(spiketrapSprites, 20, 9);
		WriteConsole(spiketrapSprites, &"    ", 4, &output, NULL);

		// Eleventh Row
		GoToXY(spiketrapSprites, 8, 10);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 12, 10);
		WriteConsole(spiketrapSprites, &"        ", 8, &output, NULL);
		GoToXY(spiketrapSprites, 22, 10);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(spiketrapSprites, 10, 11);
		WriteConsole(spiketrapSprites, &"            ", 12, &output, NULL);

		SetConsoleTextAttribute(spiketrapSprites, 9 * 16);

		// Fifth Row
		GoToXY(spiketrapSprites, 8, 4);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 22, 4);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(spiketrapSprites, 10, 5);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 20, 5);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(spiketrapSprites, 12, 6);
		WriteConsole(spiketrapSprites, &"        ", 8, &output, NULL);

		// Eighth Row
		GoToXY(spiketrapSprites, 12, 7);
		WriteConsole(spiketrapSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(spiketrapSprites, 12, 8);
		WriteConsole(spiketrapSprites, &"        ", 8, &output, NULL);

		// Tenth Row
		GoToXY(spiketrapSprites, 12, 9);
		WriteConsole(spiketrapSprites, &"        ", 8, &output, NULL);

		// Eleventh Row
		GoToXY(spiketrapSprites, 10, 10);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 20, 10);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(spiketrapSprites, 8, 11);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);
		GoToXY(spiketrapSprites, 22, 11);
		WriteConsole(spiketrapSprites, &"  ", 2, &output, NULL);

		return true;
	}

	bool LoadGel() {
		SetConsoleScreenBufferSize(gelSprites, SCREEN_SIZE);

		DWORD output;

		SetConsoleTextAttribute(gelSprites, 1 * 16); // Blue

		// First Row
		GoToXY(gelSprites, 4, 0);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		// Second Row
		GoToXY(gelSprites, 2, 1);
		WriteConsole(gelSprites, &"    ", 4, &output, NULL);

		// Third Row
		GoToXY(gelSprites, 2, 2);
		WriteConsole(gelSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(gelSprites, 0, 3);
		WriteConsole(gelSprites, &"        ", 8, &output, NULL);
		GoToXY(gelSprites, 10, 3);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(gelSprites, 0, 4);
		WriteConsole(gelSprites, &"            ", 12, &output, NULL);

		// Sixth Row
		GoToXY(gelSprites, 0, 5);
		WriteConsole(gelSprites, &"            ", 12, &output, NULL);

		// Seventh Row
		GoToXY(gelSprites, 0, 6);
		WriteConsole(gelSprites, &"            ", 12, &output, NULL);

		// Eighth Row
		GoToXY(gelSprites, 2, 7);
		WriteConsole(gelSprites, &"        ", 8, &output, NULL);


		SetConsoleTextAttribute(gelSprites, 3 * 16); // Aqua

		// Second Row
		GoToXY(gelSprites, 6, 1);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(gelSprites, 6, 2);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(gelSprites, 8, 3);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		return true;
	}

	bool LoadBlock() {
		SetConsoleScreenBufferSize(blockSprites, SCREEN_SIZE);

		DWORD output;

		SetConsoleTextAttribute(blockSprites, 1 * 16); // Blue

		// First Row
		GoToXY(blockSprites, 30, 0);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Second Row
		GoToXY(blockSprites, 28, 1);
		WriteConsole(blockSprites, &"    ", 4, &output, NULL);

		// Third Row
		GoToXY(blockSprites, 26, 2);
		WriteConsole(blockSprites, &"      ", 6, &output, NULL);

		// Fourth Row
		GoToXY(blockSprites, 24, 3);
		WriteConsole(blockSprites, &"        ", 8, &output, NULL);

		// Fifth Row
		GoToXY(blockSprites, 22, 4);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Sixth Row
		GoToXY(blockSprites, 22, 5);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Seventh Row
		GoToXY(blockSprites, 22, 6);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Eighth Row
		GoToXY(blockSprites, 22, 7);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Ninth Row
		GoToXY(blockSprites, 22, 8);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Tenth Row
		GoToXY(blockSprites, 22, 9);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Eleventh Row
		GoToXY(blockSprites, 22, 10);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Twelfth Row
		GoToXY(blockSprites, 10, 11);
		WriteConsole(blockSprites, &"            ", 12, &output, NULL);
		GoToXY(blockSprites, 24, 11);
		WriteConsole(blockSprites, &"        ", 8, &output, NULL);

		// Thirteenth Row
		GoToXY(blockSprites, 8, 12);
		WriteConsole(blockSprites, &"                ", 16, &output, NULL);
		GoToXY(blockSprites, 26, 12);
		WriteConsole(blockSprites, &"      ", 6, &output, NULL);

		// Fourteenth Row
		GoToXY(blockSprites, 6, 13);
		WriteConsole(blockSprites, &"                    ", 20, &output, NULL);
		GoToXY(blockSprites, 28, 13);
		WriteConsole(blockSprites, &"    ", 4, &output, NULL);

		// Fifteenth Row
		GoToXY(blockSprites, 4, 14);
		WriteConsole(blockSprites, &"                        ", 24, &output, NULL);
		GoToXY(blockSprites, 30, 14);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Sixteenth Row
		GoToXY(blockSprites, 2, 15);
		WriteConsole(blockSprites, &"                            ", 28, &output, NULL);

		SetConsoleTextAttribute(blockSprites, 3 * 16); // Aqua

		// First Row
		GoToXY(blockSprites, 0, 0);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Second Row
		GoToXY(blockSprites, 2, 1);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(blockSprites, 4, 2);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(blockSprites, 6, 3);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(blockSprites, 8, 4);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(blockSprites, 10, 5);
		WriteConsole(blockSprites, &"            ", 12, &output, NULL);

		// Seventh Row
		GoToXY(blockSprites, 10, 6);
		WriteConsole(blockSprites, &"            ", 12, &output, NULL);

		// Eighth Row
		GoToXY(blockSprites, 10, 7);
		WriteConsole(blockSprites, &"            ", 12, &output, NULL);

		// Ninth Row
		GoToXY(blockSprites, 10, 8);
		WriteConsole(blockSprites, &"            ", 12, &output, NULL);

		// Tenth Row
		GoToXY(blockSprites, 10, 9);
		WriteConsole(blockSprites, &"            ", 12, &output, NULL);

		// Eleventh Row
		GoToXY(blockSprites, 10, 10);
		WriteConsole(blockSprites, &"            ", 12, &output, NULL);

		// Twelfth Row
		GoToXY(blockSprites, 22, 11);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(blockSprites, 24, 12);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(blockSprites, 26, 13);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Fifteenth Row
		GoToXY(blockSprites, 28, 14);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		// Sixteenth Row
		GoToXY(blockSprites, 30, 15);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(blockSprites, 11 * 16); // Light Aqua

		// First Row
		GoToXY(blockSprites, 2, 0);
		WriteConsole(blockSprites, &"                            ", 28, &output, NULL);

		// Second Row
		GoToXY(blockSprites, 0, 1);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);
		GoToXY(blockSprites, 4, 1);
		WriteConsole(blockSprites, &"                        ", 24, &output, NULL);

		// Third Row
		GoToXY(blockSprites, 0, 2);
		WriteConsole(blockSprites, &"    ", 4, &output, NULL);
		GoToXY(blockSprites, 6, 2);
		WriteConsole(blockSprites, &"                      ", 20, &output, NULL);

		// Fourth Row
		GoToXY(blockSprites, 0, 3);
		WriteConsole(blockSprites, &"      ", 6, &output, NULL);
		GoToXY(blockSprites, 8, 3);
		WriteConsole(blockSprites, &"                  ", 16, &output, NULL);

		// Fifth Row
		GoToXY(blockSprites, 0, 4);
		WriteConsole(blockSprites, &"        ", 8, &output, NULL);
		GoToXY(blockSprites, 10, 4);
		WriteConsole(blockSprites, &"              ", 12, &output, NULL);

		// Sixth Row
		GoToXY(blockSprites, 0, 5);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Seventh Row
		GoToXY(blockSprites, 0, 6);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Eighth Row
		GoToXY(blockSprites, 0, 7);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Ninth Row
		GoToXY(blockSprites, 0, 8);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Tenth Row
		GoToXY(blockSprites, 0, 9);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Eleventh Row
		GoToXY(blockSprites, 0, 10);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Twelfth Row
		GoToXY(blockSprites, 0, 11);
		WriteConsole(blockSprites, &"          ", 10, &output, NULL);

		// Thirteenth Row
		GoToXY(blockSprites, 0, 12);
		WriteConsole(blockSprites, &"        ", 8, &output, NULL);

		// Fourteenth Row
		GoToXY(blockSprites, 0, 13);
		WriteConsole(blockSprites, &"      ", 6, &output, NULL);

		// Fifteenth Row
		GoToXY(blockSprites, 0, 14);
		WriteConsole(blockSprites, &"    ", 4, &output, NULL);

		// Sixteenth Row
		GoToXY(blockSprites, 0, 15);
		WriteConsole(blockSprites, &"  ", 2, &output, NULL);

		return true;
	}

	bool LoadSword() {

		SetConsoleScreenBufferSize(swordSprites, SCREEN_SIZE);

		DWORD output;

		// Upright
		SetConsoleTextAttribute(swordSprites, 8 * 16); // Grey

		// First Row
		GoToXY(swordSprites, 14, 0);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		// Second Row
		GoToXY(swordSprites, 12, 1);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Third Row
		GoToXY(swordSprites, 12, 2);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fourth Row
		GoToXY(swordSprites, 12, 3);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fifth Row
		GoToXY(swordSprites, 12, 4);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Sixth Row
		GoToXY(swordSprites, 12, 5);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(swordSprites, 12, 6);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Eighth Row
		GoToXY(swordSprites, 12, 7);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Ninth Row
		GoToXY(swordSprites, 12, 8);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(swordSprites, 12, 9);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(swordSprites, 12, 10);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 10 * 16); // Green

		// Twelfth Row
		GoToXY(swordSprites, 8, 11);
		WriteConsole(swordSprites, &"              ", 14, &output, NULL);

		// Thirteenth Row
		GoToXY(swordSprites, 8, 12);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		GoToXY(swordSprites, 20, 12);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(swordSprites, 12, 13);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Sixteenth Row
		GoToXY(swordSprites, 12, 15);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 14 * 16); // Light Yellow

		// Thirteenth Row
		GoToXY(swordSprites, 12, 12);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fifteenth Row
		GoToXY(swordSprites, 12, 14);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Down
		SetConsoleTextAttribute(swordSprites, 8 * 16); // Grey

		// First Row
		GoToXY(swordSprites, 50, 15);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		// Second Row
		GoToXY(swordSprites, 48, 14);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Third Row
		GoToXY(swordSprites, 48, 13);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fourth Row
		GoToXY(swordSprites, 48, 12);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fifth Row
		GoToXY(swordSprites, 48, 11);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Sixth Row
		GoToXY(swordSprites, 48, 10);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(swordSprites, 48, 9);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Eighth Row
		GoToXY(swordSprites, 48, 8);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Ninth Row
		GoToXY(swordSprites, 48, 7);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(swordSprites, 48, 6);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(swordSprites, 48, 5);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 10 * 16); // Green

		// Twelfth Row
		GoToXY(swordSprites, 44, 4);
		WriteConsole(swordSprites, &"              ", 14, &output, NULL);

		// Thirteenth Row
		GoToXY(swordSprites, 44, 3);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		GoToXY(swordSprites, 56, 3);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(swordSprites, 48, 2);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Sixteenth Row
		GoToXY(swordSprites, 48, 0);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 14 * 16); // Light Yellow

		// Thirteenth Row
		GoToXY(swordSprites, 48, 3);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fifteenth Row
		GoToXY(swordSprites, 48, 1);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Right
		SetConsoleTextAttribute(swordSprites, 8 * 16); // Grey

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 78, i);
			WriteConsole(swordSprites, &"                    ", 20, &output, NULL);
		}

		GoToXY(swordSprites, 98, 7);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 10 * 16); // Green

		GoToXY(swordSprites, 74, 4);
		WriteConsole(swordSprites, &"    ", 4, &output, NULL);

		GoToXY(swordSprites, 76, 5);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 68, i);
			WriteConsole(swordSprites, &"          ", 10, &output, NULL);
		}

		GoToXY(swordSprites, 76, 9);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		GoToXY(swordSprites, 74, 10);
		WriteConsole(swordSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 14 * 16); // Light Yellow

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 70, i);
			WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 74, i);
			WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		}

		// Left
		SetConsoleTextAttribute(swordSprites, 8 * 16); // Grey

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 104, i);
			WriteConsole(swordSprites, &"                    ", 20, &output, NULL);
		}

		GoToXY(swordSprites, 102, 7);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 10 * 16); // Green

		GoToXY(swordSprites, 124, 4);
		WriteConsole(swordSprites, &"    ", 4, &output, NULL);

		GoToXY(swordSprites, 124, 5);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 124, i);
			WriteConsole(swordSprites, &"          ", 10, &output, NULL);
		}

		GoToXY(swordSprites, 124, 9);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		GoToXY(swordSprites, 124, 10);
		WriteConsole(swordSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 14 * 16); // Light Yellow

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 126, i);
			WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 130, i);
			WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		}
		return true;
	}

	bool LoadHole() {
		SetConsoleScreenBufferSize(holeSprites, SCREEN_SIZE);

		DWORD output;

		SetConsoleTextAttribute(holeSprites, 0 * 16); // Black

		for (int i = 0; i < 16; i++) {
			GoToXY(holeSprites, 0, i);
			WriteConsole(holeSprites, &"                                ", 32, &output, NULL);
		}
		return true;
	}

	bool LoadFloor() {

		SetConsoleScreenBufferSize(floorSprites, SCREEN_SIZE);

		DWORD output;

		// Normal Floor Tile

		SetConsoleTextAttribute(floorSprites, 9 * 16); // Light Blue

		for (int i = 0; i < 16; i++) {
			GoToXY(floorSprites, 0, i);
			WriteConsole(floorSprites, &"                               ", 32, &output, NULL);
		}

		SetConsoleTextAttribute(floorSprites, 0 * 16); // Black

		for (int i = 1; i < 15; i++) {
			GoToXY(floorSprites, 30, i);
			WriteConsole(floorSprites, &"  ", 2, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(floorSprites, 2, 15);
		WriteConsole(floorSprites, &"                            ", 28, &output, NULL);

		SetConsoleTextAttribute(floorSprites, 11 * 16); // Aqua

		// First Row
		GoToXY(floorSprites, 2, 0);
		WriteConsole(floorSprites, &"                            ", 28, &output, NULL);

		for (int i = 1; i < 15; i++) {
			GoToXY(floorSprites, 0, i);
			WriteConsole(floorSprites, &"  ", 2, &output, NULL);
		}

		// Blue Sand Tile
		SetConsoleTextAttribute(floorSprites, 9 * 16);

		for (int i = 0; i < 8; i++) {
			GoToXY(floorSprites, 34, i);
			WriteConsole(floorSprites, &"                ", 16, &output, NULL);
		}

		SetConsoleTextAttribute(floorSprites, 1 * 16);

		GoToXY(floorSprites, 48, 0);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 40, 1);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 36, 3);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 42, 4);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 46, 5);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 38, 6);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(floorSprites, 11 * 16);

		GoToXY(floorSprites, 34, 1);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 46, 3);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 44, 7);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		return true;
	}

	bool LoadWall() {

		DWORD output;
		HANDLE out = ::GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleScreenBufferSize(wallSprites, SCREEN_SIZE);

		SetConsoleTextAttribute(wallSprites, 9 * 16); // Light Blue
		for (int i = 57; i < 240; i++) {
			GoToXY(wallSprites, 0, i);
			WriteConsole(wallSprites, &"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ", 512, &output, NULL);
		}

		SetConsoleTextAttribute(wallSprites, 11 * 16); // Aqua

		for (int i = 76; i < 220; i++) {
			GoToXY(wallSprites, 40, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 84; i < 212; i++) {
			GoToXY(wallSprites, 56, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 76; i < 220; i++) {
			GoToXY(wallSprites, 470, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 84; i < 212; i++) {
			GoToXY(wallSprites, 454, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		// Fourth Row
		GoToXY(wallSprites, 42, 76);
		WriteConsole(wallSprites, &"                                                                                                                                                                                                                                                                                                                 ", 428, &output, NULL);

		// Twelfth Row
		GoToXY(wallSprites, 56, 84);
		WriteConsole(wallSprites, &"                                                                                                                                                                                                                                                                ", 402, &output, NULL);

		// Fourth Row
		GoToXY(wallSprites, 42, 219);
		WriteConsole(wallSprites, &"                                                                                                                                                                                                                                                                                                                 ", 428, &output, NULL);

		// Twelfth Row
		GoToXY(wallSprites, 56, 211);
		WriteConsole(wallSprites, &"                                                                                                                                                                                                                                                                ", 402, &output, NULL);

		GoToXY(wallSprites, 390, 82);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 390, 81);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 392, 80);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 392, 79);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 394, 78);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 394, 77);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 394, 76);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 320, 82);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 320, 81);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 322, 80);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 322, 79);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 324, 78);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 324, 77);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 324, 76);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 124, 82);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 124, 81);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 122, 80);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 122, 79);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 120, 78);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 120, 77);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 120, 76);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 194, 82);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 194, 81);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 192, 80);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 192, 79);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 190, 78);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 190, 77);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 190, 76);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 194, 213);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 194, 214);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 192, 215);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 192, 216);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 190, 217);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 190, 218);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 190, 219);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 124, 213);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 124, 214);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 122, 215);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 122, 216);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 120, 217);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 120, 218);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 120, 219);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 320, 213);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 320, 214);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 322, 215);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 322, 216);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 324, 217);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 324, 218);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 324, 219);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 390, 213);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 390, 214);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 392, 215);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 392, 216);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 394, 217);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 394, 218);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 394, 219);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 96, 208);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 94, 209);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 94, 210);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 164, 208);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 162, 209);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 162, 210);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 352, 208);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 354, 209);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 354, 210);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 416, 208);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 418, 209);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 418, 210);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 96, 87);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 94, 86);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 94, 85);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 164, 87);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 162, 86);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 162, 85);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 352, 87);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 354, 86);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 354, 85);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 416, 87);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 418, 86);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 418, 85);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 422, 74);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 422, 73);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 424, 72);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 424, 71);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 426, 70);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 426, 69);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 428, 68);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 428, 67);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 430, 66);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 430, 65);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 430, 64);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 360, 74);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 360, 73);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 362, 72);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 362, 71);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 364, 70);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 364, 69);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 366, 68);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 366, 67);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 368, 66);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 368, 65);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 368, 64);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 88, 74);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 88, 73);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 86, 72);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 86, 71);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 84, 70);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 84, 69);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 82, 68);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 82, 67);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 80, 66);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 80, 65);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 80, 64);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 154, 74);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 154, 73);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 152, 72);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 152, 71);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 150, 70);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 150, 69);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 148, 68);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 148, 67);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 146, 66);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 146, 65);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 146, 64);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Inverted

		GoToXY(wallSprites, 422, 221);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 422, 222);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 424, 223);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 424, 224);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 426, 225);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 426, 226);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 428, 227);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 428, 228);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 430, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 430, 230);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 430, 231);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 360, 221);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 360, 222);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 362, 223);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 362, 224);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 364, 225);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 364, 226);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 366, 227);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 366, 228);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 368, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 368, 230);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 368, 231);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 88, 221);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 88, 222);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 86, 223);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 86, 224);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 84, 225);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 84, 226);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 82, 227);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 82, 228);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 80, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 80, 230);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 80, 231);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 154, 221);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 154, 222);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 152, 223);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 152, 224);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 150, 225);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 150, 226);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 148, 227);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 148, 228);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 146, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 146, 230);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 146, 231);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Side

		GoToXY(wallSprites, 34, 109);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 30, 108);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 26, 107);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 22, 106);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 16, 105);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 474, 109);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 478, 108);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 482, 107);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 486, 106);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 490, 105);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		//Inverted

		GoToXY(wallSprites, 34, 188);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 30, 189);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 26, 190);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 22, 191);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 16, 192);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 474, 188);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 478, 189);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 482, 190);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 486, 191);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 490, 192);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		// Side Middle

		GoToXY(wallSprites, 50, 100);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 46, 99);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 40, 98);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 458, 100);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 462, 99);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 466, 98);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 50, 196);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 46, 197);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 40, 198);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 458, 196);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 462, 197);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 466, 198);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);



		GoToXY(wallSprites, 50, 125);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 46, 124);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 40, 123);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 458, 125);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 462, 124);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 466, 123);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 50, 171);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 46, 172);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 40, 173);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 458, 171);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 462, 172);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 466, 173);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 450, 116);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		GoToXY(wallSprites, 448, 117);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 450, 184);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		GoToXY(wallSprites, 448, 183);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Inverted

		GoToXY(wallSprites, 56, 116);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		GoToXY(wallSprites, 62, 117);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 56, 184);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		GoToXY(wallSprites, 62, 183);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		SetConsoleTextAttribute(wallSprites, 1 * 16); // Blue

		for (int i = 64, j = 16; i < 88; i++, j += 2) {
			GoToXY(wallSprites, j, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 64, j = 494; i < 88; i++, j -= 2) {
			GoToXY(wallSprites, j, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 232, j = 496; i > 207; i--, j -= 2) {
			GoToXY(wallSprites, j, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 232, j = 14; i > 207; i--, j += 2) {
			GoToXY(wallSprites, j, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 76; i < 220; i++) {
			GoToXY(wallSprites, 38, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 84; i < 212; i++) {
			GoToXY(wallSprites, 54, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 76; i < 220; i++) {
			GoToXY(wallSprites, 472, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 84; i < 212; i++) {
			GoToXY(wallSprites, 456, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		// Fourth Row
		GoToXY(wallSprites, 40, 75);
		WriteConsole(wallSprites, &"                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ", 432, &output, NULL);

		// Twelfth Row
		GoToXY(wallSprites, 56, 83);
		WriteConsole(wallSprites, &"                                                                                                                                                                                                                                                                                                                                                                                                         ", 402, &output, NULL);

		// Fourth Row
		GoToXY(wallSprites, 40, 220);
		WriteConsole(wallSprites, &"                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ", 432, &output, NULL);

		// Twelfth Row
		GoToXY(wallSprites, 56, 212);
		WriteConsole(wallSprites, &"                                                                                                                                                                                                                                                                                                                                                                                                         ", 402, &output, NULL);


		// Side Inner

		GoToXY(wallSprites, 450, 115);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		GoToXY(wallSprites, 448, 116);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 450, 183);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		GoToXY(wallSprites, 448, 182);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Inverted

		GoToXY(wallSprites, 56, 115);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		GoToXY(wallSprites, 62, 116);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 56, 183);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		GoToXY(wallSprites, 62, 182);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Side Middle

		GoToXY(wallSprites, 50, 99);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 46, 98);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 40, 97);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 458, 99);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 462, 98);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 466, 97);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 50, 170);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 46, 171);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 40, 172);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 458, 170);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 462, 171);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 466, 172);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);



		GoToXY(wallSprites, 50, 124);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 46, 123);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 40, 122);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 458, 124);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 462, 123);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 466, 122);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 50, 195);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 46, 196);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 40, 197);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 458, 195);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 462, 196);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 466, 197);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		// Side Outer

		GoToXY(wallSprites, 34, 108);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 30, 107);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 26, 106);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 22, 105);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 16, 104);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 474, 108);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 478, 107);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 482, 106);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 486, 105);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 490, 104);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		//Inverted

		GoToXY(wallSprites, 34, 187);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 30, 188);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 26, 189);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 22, 190);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 16, 191);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);


		GoToXY(wallSprites, 474, 187);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 478, 188);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 482, 189);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 486, 190);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		GoToXY(wallSprites, 490, 191);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		// Top and Bottom

		GoToXY(wallSprites, 420, 221);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 420, 222);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 422, 223);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 422, 224);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 424, 225);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 424, 226);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 426, 227);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 426, 228);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 428, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 428, 230);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 428, 231);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 358, 221);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 358, 222);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 360, 223);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 360, 224);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 362, 225);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 362, 226);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 364, 227);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 364, 228);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 366, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 366, 230);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 366, 231);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 86, 221);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 86, 222);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 84, 223);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 84, 224);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 82, 225);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 82, 226);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 80, 227);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 80, 228);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 78, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 78, 230);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 78, 231);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 152, 221);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 152, 222);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 150, 223);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 150, 224);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 148, 225);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 148, 226);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 146, 227);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 146, 228);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 144, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 144, 230);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 144, 231);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Inverted

		GoToXY(wallSprites, 420, 74);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 420, 73);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 422, 72);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 422, 71);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 424, 70);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 424, 69);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 426, 68);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 426, 67);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 428, 66);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 428, 65);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 428, 64);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 358, 74);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 358, 73);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 360, 72);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 360, 71);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 362, 70);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 362, 69);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 364, 68);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 364, 67);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 366, 66);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 366, 65);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 366, 64);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 86, 74);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 86, 73);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 84, 72);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 84, 71);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 82, 70);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 82, 69);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 80, 68);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 80, 67);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 78, 66);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 78, 65);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 78, 64);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 152, 74);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 152, 73);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 150, 72);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 150, 71);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 148, 70);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 148, 69);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 146, 68);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 146, 67);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 144, 66);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 144, 65);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 144, 64);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 94, 208);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 92, 209);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 92, 210);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 92, 211);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 162, 208);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 160, 209);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 160, 210);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 160, 211);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 350, 208);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 352, 209);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 352, 210);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 352, 211);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 414, 208);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 416, 209);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 416, 210);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 416, 211);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 94, 87);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 92, 86);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 92, 85);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 92, 84);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 162, 87);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 160, 86);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 160, 85);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 160, 84);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 414, 87);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 416, 86);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 416, 85);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 416, 84);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		// Second Row
		GoToXY(wallSprites, 350, 87);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 352, 86);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// One Hundred and Eighty Eighth Row
		GoToXY(wallSprites, 352, 85);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 352, 84);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 388, 82);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 388, 81);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 390, 80);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 390, 79);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 392, 78);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 392, 77);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 392, 76);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 318, 82);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 318, 81);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 320, 80);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 320, 79);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 322, 78);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 322, 77);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 322, 76);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 122, 82);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 122, 81);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 120, 80);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 120, 79);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 118, 78);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 118, 77);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 118, 76);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 192, 82);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 192, 81);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 190, 80);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 190, 79);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 188, 78);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 188, 77);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 188, 76);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 192, 213);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 192, 214);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 190, 215);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 190, 216);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 188, 217);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 188, 218);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 188, 219);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 122, 213);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 122, 214);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 120, 215);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 120, 216);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 118, 217);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 118, 218);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 118, 219);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 318, 213);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 318, 214);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 320, 215);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 320, 216);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 322, 217);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 322, 218);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 322, 219);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);


		GoToXY(wallSprites, 388, 213);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 388, 214);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 390, 215);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 390, 216);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 392, 217);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 392, 218);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		GoToXY(wallSprites, 392, 219);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		for (int i = 0; i < 23; i++) {
			if (i == 0 || i == 22) {
				for (int j = 0; j < 32; j++) {
					DrawSprite(brickSprites, 0, 0, 16, 8, wallSprites, (j * 16), 56 + (i * 8));
				}
			}
			else {
				DrawSprite(brickSprites, 0, 0, 16, 8, wallSprites, 0, 56 + (i * 8));
				DrawSprite(brickSprites, 0, 0, 16, 8, wallSprites, 496, 56 + (i * 8));
			}
		}

		return true;
	}

	bool LoadDoor() {

		SetConsoleScreenBufferSize(doorSprites, SCREEN_SIZE);

		DWORD output;

		// Door Open Bottom Screen (64 across)
		SetConsoleTextAttribute(doorSprites, 1 * 16); // Blue

		// First Row
		GoToXY(doorSprites, 52, 0);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Second Row
		GoToXY(doorSprites, 52, 1);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 16, 1);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 46, 1);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(doorSprites, 52, 2);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 16, 2);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 46, 2);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(doorSprites, 54, 3);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 14, 3);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 46, 3);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(doorSprites, 54, 4);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 14, 4);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 46, 4);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(doorSprites, 54, 5);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 14, 5);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 46, 5);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(doorSprites, 56, 6);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 14, 6);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 46, 6);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		// Eighth Row
		GoToXY(doorSprites, 56, 7);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 12, 7);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 46, 7);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		// Ninth Row
		GoToXY(doorSprites, 56, 8);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 12, 8);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 46, 8);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(doorSprites, 58, 9);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 12, 9);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 46, 9);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(doorSprites, 58, 10);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 10, 10);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		GoToXY(doorSprites, 46, 10);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		// Twelfth Row
		GoToXY(doorSprites, 58, 11);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 10, 11);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		GoToXY(doorSprites, 46, 11);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		// Thirteenth Row
		GoToXY(doorSprites, 60, 12);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 10, 12);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		GoToXY(doorSprites, 46, 12);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		// Fourteenth Row
		GoToXY(doorSprites, 60, 13);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 8, 13);
		WriteConsole(doorSprites, &"          ", 10, &output, NULL);
		GoToXY(doorSprites, 46, 13);
		WriteConsole(doorSprites, &"          ", 10, &output, NULL);

		// Fifteenth Row
		GoToXY(doorSprites, 60, 14);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 8, 14);
		WriteConsole(doorSprites, &"          ", 10, &output, NULL);
		GoToXY(doorSprites, 46, 14);
		WriteConsole(doorSprites, &"          ", 10, &output, NULL);

		// Sixteenth Row
		GoToXY(doorSprites, 60, 15);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Seventeenth Row
		GoToXY(doorSprites, 0, 16);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 62, 16);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);


		// Eighteenth Row
		GoToXY(doorSprites, 0, 17);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 62, 17);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Ninteenth Row
		GoToXY(doorSprites, 0, 18);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 62, 18);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Twentieth Row
		GoToXY(doorSprites, 0, 19);
		WriteConsole(doorSprites, &"                                                                ", 64, &output, NULL);

		SetConsoleTextAttribute(doorSprites, 3 * 16); // Aqua

		// First Row
		GoToXY(doorSprites, 10, 0);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 18, 0);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 34, 0);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);

		// Second Row
		GoToXY(doorSprites, 10, 1);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 32, 1);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(doorSprites, 10, 2);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 32, 2);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(doorSprites, 8, 3);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 32, 3);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(doorSprites, 8, 4);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 32, 4);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(doorSprites, 8, 5);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 32, 5);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(doorSprites, 6, 6);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 32, 6);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(doorSprites, 6, 7);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(doorSprites, 6, 8);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(doorSprites, 4, 9);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(doorSprites, 4, 10);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(doorSprites, 4, 11);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(doorSprites, 2, 12);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(doorSprites, 2, 13);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Fifteenth Row
		GoToXY(doorSprites, 2, 14);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Sixteenth Row
		GoToXY(doorSprites, 2, 15);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		// Ninteenth Row
		GoToXY(doorSprites, 2, 18);
		WriteConsole(doorSprites, &"                                                            ", 60, &output, NULL);

		SetConsoleTextAttribute(doorSprites, 9 * 16); // Light Blue

		// First Row
		GoToXY(doorSprites, 12, 0);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 48, 0);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Second Row
		GoToXY(doorSprites, 12, 1);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 18, 1);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 34, 1);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 48, 1);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Third Row
		GoToXY(doorSprites, 12, 2);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 18, 2);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 34, 2);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 48, 2);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(doorSprites, 10, 3);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 18, 3);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 34, 3);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 48, 3);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		// Fifth Row
		GoToXY(doorSprites, 10, 4);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 18, 4);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 34, 4);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 50, 4);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(doorSprites, 10, 5);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 18, 5);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 34, 5);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 50, 5);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Seventh Row
		GoToXY(doorSprites, 8, 6);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 18, 6);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 34, 6);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 50, 6);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		// Eighth Row
		GoToXY(doorSprites, 8, 7);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 52, 7);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(doorSprites, 8, 8);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 52, 8);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Tenth Row
		GoToXY(doorSprites, 6, 9);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 52, 9);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(doorSprites, 6, 10);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 54, 10);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Twelfth Row
		GoToXY(doorSprites, 6, 11);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 54, 11);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Thirteenth Row
		GoToXY(doorSprites, 4, 12);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 54, 12);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		// Fourteenth Row
		GoToXY(doorSprites, 4, 13);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 56, 13);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Fifteenth Row
		GoToXY(doorSprites, 4, 14);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 56, 14);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Seventeenth Row
		GoToXY(doorSprites, 2, 16);
		WriteConsole(doorSprites, &"                                                            ", 60, &output, NULL);

		// Eighteenth Row
		GoToXY(doorSprites, 2, 17);
		WriteConsole(doorSprites, &"                                                            ", 60, &output, NULL);

		SetConsoleTextAttribute(doorSprites, 0); // black
		for (int c = 0; c < 7;c++) {
			GoToXY(doorSprites, 16, 8 + c);
			for (int d = 0; d < 16; d++) {
				WriteConsole(doorSprites, &"  ", 2, &output, NULL);
			}
		}

		return true;
	}

	bool LoadBrick() {

		SetConsoleScreenBufferSize(brickSprites, SCREEN_SIZE);

		DWORD output;

		SetConsoleTextAttribute(brickSprites, 9 * 16);

		for (int i = 0; i < 8; i++) {
			GoToXY(brickSprites, 0, i);
			WriteConsole(brickSprites, &"                ", 16, &output, NULL);
		}

		SetConsoleTextAttribute(brickSprites, 1 * 16);

		GoToXY(brickSprites, 0, 3);
		WriteConsole(brickSprites, &"                ", 16, &output, NULL);

		for (int i = 0; i < 3; i++) {
			GoToXY(brickSprites, 2, i);
			WriteConsole(brickSprites, "  ", 2, &output, NULL);
		}

		for (int i = 4; i < 8; i++) {
			GoToXY(brickSprites, 10, i);
			WriteConsole(brickSprites, "  ", 2, &output, NULL);
		}

		GoToXY(brickSprites, 0, 7);
		WriteConsole(brickSprites, "                ", 16, &output, NULL);

		SetConsoleTextAttribute(brickSprites, 11 * 16);

		GoToXY(brickSprites, 4, 0);
		WriteConsole(brickSprites, "  ", 2, &output, NULL);

		GoToXY(brickSprites, 12, 4);
		WriteConsole(brickSprites, "  ", 2, &output, NULL);

		return true;
	}

	bool LoadHeart() {

		SetConsoleScreenBufferSize(heartSprites, SCREEN_SIZE);

		DWORD output;

		// Full Heart
		SetConsoleTextAttribute(heartSprites, 4 * 16 + 15); // Red with white

		// First Row
		GoToXY(heartSprites, 2, 0);
		WriteConsole(heartSprites, "    ", 4, &output, NULL);

		GoToXY(heartSprites, 8, 0);
		WriteConsole(heartSprites, "    ", 4, &output, NULL);

		for (int i = 1; i < 5; i++) {
			GoToXY(heartSprites, 0, i);
			WriteConsole(heartSprites, "              ", 14, &output, NULL);
		}

		// Sixth Row
		GoToXY(heartSprites, 2, 5);
		WriteConsole(heartSprites, "          ", 10, &output, NULL);

		// Seventh Row
		GoToXY(heartSprites, 4, 6);
		WriteConsole(heartSprites, "      ", 6, &output, NULL);

		// Eighth Row
		GoToXY(heartSprites, 6, 7);
		WriteConsole(heartSprites, "  ", 2, &output, NULL);

		// Half Heart
		char mGrad = { (char)177 };

		// First Row
		GoToXY(heartSprites, 18, 0);
		WriteConsole(heartSprites, "    ", 4, &output, NULL);

		GoToXY(heartSprites, 24, 0);
		for (int c = 0; c < 4; c++) {
			WriteConsole(heartSprites, &mGrad, 1, &output, NULL);
		}

		for (int i = 1; i < 5; i++) {
			GoToXY(heartSprites, 16, i);
			WriteConsole(heartSprites, "              ", 14, &output, NULL);
		}

		// Second Row
		GoToXY(heartSprites, 24, 1);
		for (int c = 0; c < 6; c++) {
			WriteConsole(heartSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(heartSprites, 22, 2);
		for (int c = 0; c < 8; c++) {
			WriteConsole(heartSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(heartSprites, 24, 3);
		for (int c = 0; c < 6; c++) {
			WriteConsole(heartSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(heartSprites, 22, 4);
		for (int c = 0; c < 8; c++) {
			WriteConsole(heartSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(heartSprites, 18, 5);
		WriteConsole(heartSprites, "          ", 10, &output, NULL);

		GoToXY(heartSprites, 24, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(heartSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(heartSprites, 20, 6);
		WriteConsole(heartSprites, "      ", 6, &output, NULL);

		GoToXY(heartSprites, 22, 6);
		for (int c = 0; c < 4; c++) {
			WriteConsole(heartSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(heartSprites, 22, 7);
		WriteConsole(heartSprites, "  ", 2, &output, NULL);

		// Empty Heart
		SetConsoleTextAttribute(heartSprites, 4 * 16 + 15); // Red with white

		// First Row
		GoToXY(heartSprites, 34, 0);
		WriteConsole(heartSprites, &mGrad, 4, &output, NULL);

		GoToXY(heartSprites, 40, 0);
		WriteConsole(heartSprites, &mGrad, 4, &output, NULL);

		for (int i = 1; i < 5; i++) {
			GoToXY(heartSprites, 32, i);
			WriteConsole(heartSprites, &mGrad, 14, &output, NULL);
		}

		// Sixth Row
		GoToXY(heartSprites, 34, 5);
		WriteConsole(heartSprites, &mGrad, 10, &output, NULL);

		// Seventh Row
		GoToXY(heartSprites, 36, 6);
		WriteConsole(heartSprites, &mGrad, 6, &output, NULL);

		// Eighth Row
		GoToXY(heartSprites, 38, 7);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		return true;
	}

	bool LoadStopwatch() {

		SetConsoleScreenBufferSize(stopwatchSprites, SCREEN_SIZE);

		DWORD output;

		SetConsoleTextAttribute(stopwatchSprites, 15 * 16); // White

		GoToXY(stopwatchSprites, 10, 2);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);

		GoToXY(stopwatchSprites, 8, 4);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 12, 4);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);

		GoToXY(stopwatchSprites, 6, 5);
		WriteConsole(stopwatchSprites, "          ", 10, &output, NULL);

		GoToXY(stopwatchSprites, 2, 8);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 18, 8);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);

		GoToXY(stopwatchSprites, 2, 10);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 18, 10);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);

		GoToXY(stopwatchSprites, 6, 13);
		WriteConsole(stopwatchSprites, "          ", 10, &output, NULL);

		GoToXY(stopwatchSprites, 8, 14);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 12, 14);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);

		for (int i = 6; i < 13; i++) {
			GoToXY(stopwatchSprites, 4, i);
			WriteConsole(stopwatchSprites, "              ", 14, &output, NULL);
		}

		SetConsoleTextAttribute(stopwatchSprites, 4 * 16); // Red
		for (int i = 0; i < 2; i++) {
			GoToXY(stopwatchSprites, 6, i);
			WriteConsole(stopwatchSprites, "          ", 10, &output, NULL);
		}

		GoToXY(stopwatchSprites, 6, 3);
		WriteConsole(stopwatchSprites, "          ", 10, &output, NULL);

		GoToXY(stopwatchSprites, 4, 4);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);
		GoToXY(stopwatchSprites, 10, 4);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 14, 4);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);

		GoToXY(stopwatchSprites, 2, 5);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);
		GoToXY(stopwatchSprites, 16, 5);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);

		GoToXY(stopwatchSprites, 2, 6);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 18, 6);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);

		GoToXY(stopwatchSprites, 0, 7);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);
		GoToXY(stopwatchSprites, 6, 7);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 14, 7);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 18, 7);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);

		GoToXY(stopwatchSprites, 0, 8);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 8, 8);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 12, 8);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 20, 8);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);

		GoToXY(stopwatchSprites, 0, 9);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);
		GoToXY(stopwatchSprites, 10, 9);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 18, 9);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);

		GoToXY(stopwatchSprites, 0, 10);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 20, 10);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);

		GoToXY(stopwatchSprites, 0, 11);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);
		GoToXY(stopwatchSprites, 18, 11);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);

		GoToXY(stopwatchSprites, 2, 12);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 18, 12);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);

		GoToXY(stopwatchSprites, 2, 13);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);
		GoToXY(stopwatchSprites, 16, 13);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);

		GoToXY(stopwatchSprites, 4, 14);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);
		GoToXY(stopwatchSprites, 10, 14);
		WriteConsole(stopwatchSprites, "  ", 2, &output, NULL);
		GoToXY(stopwatchSprites, 14, 14);
		WriteConsole(stopwatchSprites, "    ", 4, &output, NULL);

		GoToXY(stopwatchSprites, 6, 15);
		WriteConsole(stopwatchSprites, "          ", 10, &output, NULL);

		return true;
	}

	bool LoadTitle() {
		// Set screen size
		SetConsoleScreenBufferSize(titleScreen, SCREEN_SIZE);

		// Set background color
		COORD origin = { 0, 0 }; // top left corner of screen
		CONSOLE_SCREEN_BUFFER_INFO scrn;
		DWORD buff;

		char lGrad = (char) 176;

		GetConsoleScreenBufferInfo(titleScreen, &scrn);

		//Fills Console with 
		FillConsoleOutputCharacterA(
			titleScreen, lGrad, scrn.dwSize.X * scrn.dwSize.Y, origin, &buff
		);

		//Returns text colors to default
		FillConsoleOutputAttribute(
			titleScreen, 14 + (12*16),
			scrn.dwSize.X * scrn.dwSize.Y, origin, &buff
		);

		//Draw Triforce
		DWORD output;
		SetConsoleTextAttribute(titleScreen, (14 * 16) + 6);

		GoToXY(titleScreen, 186, 56);
		for (int c = 0; c < 136; c++) {
			WriteConsole(titleScreen, &lGrad, 1, &output, NULL);
		}

		GoToXY(titleScreen, 184, 57);
		for (int c = 0; c < 140; c++) {
			WriteConsole(titleScreen, &lGrad, 1, &output, NULL);
		}

		GoToXY(titleScreen, 186, 58);
		for (int c = 0; c < 136; c++) {
			WriteConsole(titleScreen, &lGrad, 1, &output, NULL);
		}

		for (int c = 0; c < 33; c++) {
			GoToXY(titleScreen, 188 + (c * 2), 59 + (c*2));
			for (int d = 0; d < (132 - (c * 4)); d++) {
				WriteConsole(titleScreen, &lGrad, 1, &output, NULL);
			}
			GoToXY(titleScreen, 188 + (c * 2), 59 + (c*2)+1);
			for (int d = 0; d < (132 - (c * 4)); d++) {
				WriteConsole(titleScreen, &lGrad, 1, &output, NULL);
			}
		}

		// Triforce shadow
		SetConsoleTextAttribute(titleScreen, 0);
		GoToXY(titleScreen, 322, 58);
		for (int d = 0; d < 2; d++) {
			WriteConsole(titleScreen, &lGrad, 1, &output, NULL);
		}

		for (int c = 0; c < 33; c++) {
			GoToXY(titleScreen, 320 - (c * 2), 59 + (c * 2));
			for (int d = 0; d < 4; d++) {
				WriteConsole(titleScreen, &lGrad, 1, &output, NULL);
			}
			GoToXY(titleScreen, 320 - (c * 2), 59 + (c * 2) + 1);
			for (int d = 0; d < 2; d++) {
				WriteConsole(titleScreen, &lGrad, 1, &output, NULL);
			}
		}

		GoToXY(titleScreen, 322 - (34 * 2), 125);
		for (int d = 0; d < 4; d++) {
			WriteConsole(titleScreen, &lGrad, 1, &output, NULL);
		}




		// Draw Rocks
		SetConsoleTextAttribute(titleScreen, 8 * 16);
		for (int c = 0; c < 207; c++) {
			GoToXY(titleScreen, 0, 17 + c);
			for (int d = 0; d < 22; d++) {
				WriteConsole(titleScreen, &" ", 1, &output, NULL);
			}

			if (c > 47) {
				for (int d = 0; d < 16; d++) {
					WriteConsole(titleScreen, &" ", 1, &output, NULL);
				}
				if (c > 111) {
					for (int d = 0; d < 16; d++) {
						WriteConsole(titleScreen, &" ", 1, &output, NULL);
					}
					
					if (c > 143) {
						for (int d = 0; d < 32; d++) {
							WriteConsole(titleScreen, &" ", 1, &output, NULL);
						}

						if (c > 151) {
							for (int d = 0; d < 16; d++) {
								WriteConsole(titleScreen, &" ", 1, &output, NULL);
							}

							if (c > 159) {
								for (int d = 0; d < 58; d++) {
									WriteConsole(titleScreen, &" ", 1, &output, NULL);
								}

								GoToXY(titleScreen, 224, 17 + c);

								for (int d = 0; d < 60; d++) {
									WriteConsole(titleScreen, &" ", 1, &output, NULL);
								}
								if (c > 167) {
									for (int d = 0; d < 204; d++) {
										WriteConsole(titleScreen, &" ", 1, &output, NULL);
									}
								}
							}
						}
					}
				}
			}

			GoToXY(titleScreen, 488, 17 + c);
			for (int d = 0; d < 24; d++) {
				WriteConsole(titleScreen, &" ", 1, &output, NULL);
			}
			if (c > 53) {
				GoToXY(titleScreen, 464, 17 + c);
				for (int d = 0; d < 24; d++) {
					WriteConsole(titleScreen, &" ", 1, &output, NULL);
				}
				if (c > 109) {
					GoToXY(titleScreen, 440, 17 + c);
					for (int d = 0; d < 24; d++) {
						WriteConsole(titleScreen, &" ", 1, &output, NULL);
					}
				}
			}
		}

		//Draw waterfall
		SetConsoleTextAttribute(titleScreen, (9 * 16)+11);
		for (int c = 0; c < 41; c++) {
			GoToXY(titleScreen, 160, (183 + c));
			for (int d = 0; d < 64; d++) {
				WriteConsole(titleScreen, &" ", 1, &output, NULL);
			}
		}

		DrawTextSprites(titleScreen, "Push Enter Button", 128, 159, 0);
		return true;
	}

	bool LoadCharacterMenu() {
		SetConsoleScreenBufferSize(CharacterScreen, SCREEN_SIZE);
		DrawTextSprites(CharacterScreen, "- S E L E C T -", 128, 40);
		DrawTextSprites(CharacterScreen, "Name", 176, 64);
		DrawTextSprites(CharacterScreen, "Life", 322, 64);


		SetConsoleTextAttribute(CharacterScreen, 1*16);
		//top line
		GoToXY(CharacterScreen, 56, 67);
		for (int c = 0; c < 104; c++) {
			WriteConsole(CharacterScreen, &" ", 1, NULL, NULL);
		}
		GoToXY(CharacterScreen, 56, 68);
		for (int c = 0; c < 104; c++) {
			WriteConsole(CharacterScreen, &" ", 1, NULL, NULL);
		}

		GoToXY(CharacterScreen, 256, 67);
		for (int c = 0; c < 48; c++) {
			WriteConsole(CharacterScreen, &" ", 1, NULL, NULL);
		}
		GoToXY(CharacterScreen, 256, 68);
		for (int c = 0; c < 48; c++) {
			WriteConsole(CharacterScreen, &" ", 1, NULL, NULL);
		}

		GoToXY(CharacterScreen, 400, 67);
		for (int c = 0; c < 56; c++) {
			WriteConsole(CharacterScreen, &" ", 1, NULL, NULL);
		}
		GoToXY(CharacterScreen, 400, 68);
		for (int c = 0; c < 56; c++) {
			WriteConsole(CharacterScreen, &" ", 1, NULL, NULL);
		}

		//left line
		for (int c = 0; c < 136; c++) {
			GoToXY(CharacterScreen, 54, 68+c);
			WriteConsole(CharacterScreen, &"    ", 4, NULL, NULL);
		}

		//right line
		for (int c = 0; c < 136; c++) {
			GoToXY(CharacterScreen, 454, 68 + c);
			WriteConsole(CharacterScreen, &"    ", 4, NULL, NULL);
		}

		//bottom line
		GoToXY(CharacterScreen, 56, 203);
		for (int c = 0; c < 200; c++) {
			WriteConsole(CharacterScreen, &"  ", 2, NULL, NULL);
		}
		GoToXY(CharacterScreen, 56, 204);
		for (int c = 0; c < 200; c++) {
			WriteConsole(CharacterScreen, &"  ", 2, NULL, NULL);
		}

		return true;
	}

	void DrawChar(HANDLE out, char ch, int x, int y) {
		DWORD output;

		switch (ch) {
		case 'a':
		case 'A':
			//line 1
			GoToXY(out, x + 4, y);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 2
			GoToXY(out, x + 2, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);

			break;
		case 'b':
		case 'B':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y+3);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"            ", 12, &output, NULL);
			break;
		case 'c':
		case 'C':
			//line 1
			GoToXY(out, x+4, y);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 2
			GoToXY(out, x+2, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x+2, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x+4, y + 6);
			WriteConsole(out, &"        ", 8, &output, NULL);
			break;
		case 'd':
		case 'D':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"          ", 10, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"          ", 10, &output, NULL);
			break;
		case 'e':
		case 'E':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"              ", 14, &output, NULL);
			break;
		case 'f':
		case 'F':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case 'g':
		case 'G':
			//line 1
			GoToXY(out, x + 4, y);
			WriteConsole(out, &"          ", 10, &output, NULL);
			//line 2
			GoToXY(out, x + 2, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 3);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x + 2, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 4, y + 6);
			WriteConsole(out, &"          ", 10, &output, NULL);
			break;
		case 'h':
		case 'H':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case 'i':
		case 'I':
			//line 1
			GoToXY(out, x+2, y);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 2
			GoToXY(out, x + 4, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x + 4, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x + 4, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x + 4, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x + 4, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x+2, y + 6);
			WriteConsole(out, &"        ", 8, &output, NULL);
			break;
		case 'j':
		case 'J':
			//line 1
			GoToXY(out, x+6, y);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 2
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x + 10, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x+4, y + 6);
			WriteConsole(out, &"        ", 8, &output, NULL);
			break;
		case 'k':
		case 'K':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 6, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 4, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 6, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case 'l':
		case 'L':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"              ", 14, &output, NULL);
			break;
		case 'm':
		case 'M':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"      ", 6, &output, NULL);
			GoToXY(out, x + 8, y + 1);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 6, y + 4);
			WriteConsole(out, &"  ", 2, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case 'n':
		case 'N':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"      ", 6, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"        ", 8, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 6, y + 4);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 5);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case 'o':
		case 'O':
			//line 1
			GoToXY(out, x+2, y);
			WriteConsole(out, &"          ", 10, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x+2, y + 6);
			WriteConsole(out, &"          ", 10, &output, NULL);
			break;
		case 'p':
		case 'P':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case 'q':
		case 'Q':
			//line 1
			GoToXY(out, x + 2, y);
			WriteConsole(out, &"          ", 10, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 6, y + 4);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 2, y + 6);
			WriteConsole(out, &"        ", 8, &output, NULL);
			GoToXY(out, x + 12, y + 6);
			WriteConsole(out, &"  ", 2, &output, NULL);
			break;
		case 'r':
		case 'R':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x+6, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x+8, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x+10, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case 's':
		case 'S':
			//line 1
			GoToXY(out, x+2, y);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x+2, y + 3);
			WriteConsole(out, &"          ", 10, &output, NULL);
			//line 5
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x+2, y + 6);
			WriteConsole(out, &"          ", 10, &output, NULL);
			break;
		case 't':
		case 'T':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 2
			GoToXY(out, x + 4, y + 1);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 3
			GoToXY(out, x + 4, y + 2);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 4
			GoToXY(out, x + 4, y + 3);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 5
			GoToXY(out, x + 4, y + 4);
			WriteConsole(out, &"    ", 6, &output, NULL);
			//line 6
			GoToXY(out, x + 4, y + 5);
			WriteConsole(out, &"    ", 6, &output, NULL);
			//line 7
			GoToXY(out, x + 4, y + 6);
			WriteConsole(out, &"    ", 6, &output, NULL);
			break;
		case 'u':
		case 'U':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y);
			WriteConsole(out, &"    ", 4, &output, NULL);;
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 2, y + 6);
			WriteConsole(out, &"          ", 10, &output, NULL);
			break;
		case 'v':
		case 'V':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y);
			WriteConsole(out, &"    ", 4, &output, NULL);;
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"      ", 6, &output, NULL);
			GoToXY(out, x + 8, y + 3);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 5
			GoToXY(out, x+2, y + 4);
			WriteConsole(out, &"          ", 10, &output, NULL);
			//line 6
			GoToXY(out, x+4, y + 5);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 7
			GoToXY(out, x + 6, y + 6);
			WriteConsole(out, &"  ", 2, &output, NULL);
			break;
		case 'w':
		case 'W':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 6, y + 2);
			WriteConsole(out, &"  ", 2, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"      ", 6, &output, NULL);
			GoToXY(out, x + 8, y + 5);
			WriteConsole(out, &"      ", 6, &output, NULL);;
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case 'x':
		case 'X':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"      ", 6, &output, NULL);
			GoToXY(out, x + 8, y + 1);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 3
			GoToXY(out, x+2, y + 2);
			WriteConsole(out, &"          ", 10, &output, NULL);
			//line 4
			GoToXY(out, x+4, y + 3);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 5
			GoToXY(out, x+2, y + 4);
			WriteConsole(out, &"          ", 10, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"      ", 6, &output, NULL);
			GoToXY(out, x + 8, y + 5);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case 'y':
		case 'Y':
			//line 1
			GoToXY(out, x+2, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 2
			GoToXY(out, x+2, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x+2, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x+4, y + 3);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 5
			GoToXY(out, x+6, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x+6, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x+6, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case 'z':
		case 'Z':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 2
			GoToXY(out, x + 8, y + 1);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 3
			GoToXY(out, x + 6, y + 2);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 4
			GoToXY(out, x + 4, y + 3);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 5
			GoToXY(out, x + 2, y + 4);
			WriteConsole(out, &"    ", 6, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 6, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"              ", 14, &output, NULL);
			break;
		case '0':
			//line 1
			GoToXY(out, x + 4, y);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 2
			GoToXY(out, x+2, y + 1);
			WriteConsole(out, &"  ", 2, &output, NULL);
			GoToXY(out, x + 8, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x+2, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"  ", 2, &output, NULL);
			//line 7
			GoToXY(out, x + 4, y + 6);
			WriteConsole(out, &"      ", 6, &output, NULL);
			break;
		case '1':
			//line 1
			GoToXY(out, x+4, y);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 2
			GoToXY(out, x + 2, y + 1);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 3
			GoToXY(out, x + 4, y + 2);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 4
			GoToXY(out, x + 4, y + 3);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 5
			GoToXY(out, x + 4, y + 4);
			WriteConsole(out, &"    ", 6, &output, NULL);
			//line 6
			GoToXY(out, x + 4, y + 5);
			WriteConsole(out, &"    ", 6, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"              ", 14, &output, NULL);
			break;
		case '2':
			//line 1
			GoToXY(out, x+2, y);
			WriteConsole(out, &"          ", 10, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x + 8, y + 2);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 4
			GoToXY(out, x + 4, y + 3);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 5
			GoToXY(out, x + 2, y + 4);
			WriteConsole(out, &"      ", 8, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 6, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"              ", 14, &output, NULL);
			break;
		case '3':
			//line 1
			GoToXY(out, x + 2, y);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 2
			GoToXY(out, x+8, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x+6, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x + 4, y + 3);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 5
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 2, y + 6);
			WriteConsole(out, &"          ", 10, &output, NULL);
			break;
		case '4':
			//line 1
			GoToXY(out, x + 6, y);
			WriteConsole(out, &"      ", 6, &output, NULL);
			//line 2
			GoToXY(out, x + 4, y + 1);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 3
			GoToXY(out, x + 2, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x+8, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 6
			GoToXY(out, x + 8, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x+8, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case '5':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 4
			GoToXY(out, x + 10, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 2, y + 6);
			WriteConsole(out, &"          ", 10, &output, NULL);
			break;
		case '6':
			//line 1
			GoToXY(out, x + 4, y);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 2
			GoToXY(out, x+2, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 2, y + 6);
			WriteConsole(out, &"          ", 10, &output, NULL);
			break;
		case '7':
			//line 1
			GoToXY(out, x, y);
			WriteConsole(out, &"              ", 14, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x + 8, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x + 6, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x + 4, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x + 4, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 4, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case '8':
			//line 1
			GoToXY(out, x + 2, y);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"  ", 2, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"      ", 6, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"  ", 2, &output, NULL);
			//line 4
			GoToXY(out, x+2, y + 3);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"  ", 2, &output, NULL);
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"  ", 2, &output, NULL);
			GoToXY(out, x + 10, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 2, y + 6);
			WriteConsole(out, &"          ", 10, &output, NULL);
			break;
		case '9':
			//line 1
			GoToXY(out, x + 2, y);
			WriteConsole(out, &"          ", 10, &output, NULL);
			//line 2
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 3
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 10, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 4
			GoToXY(out, x + 2, y + 3);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 5
			GoToXY(out, x + 10, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x + 8, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x+2, y + 6);
			WriteConsole(out, &"        ", 8, &output, NULL);
			break;
		case '.':
			//line 6
			GoToXY(out, x + 4, y + 5);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 4, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case ',':
			//line 5
			GoToXY(out, x + 4, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x + 6, y + 5);
			WriteConsole(out, &"  ", 2, &output, NULL);
			//line 7
			GoToXY(out, x + 4, y + 6);
			WriteConsole(out, &"  ", 2, &output, NULL);
			break;
		case '?':
			//line 1
			GoToXY(out, x + 2, y);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 5
			GoToXY(out, x, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 8, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 6, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x + 4, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6

			//line 7
			GoToXY(out, x + 4, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case '!':
			//line 1
			GoToXY(out, x + 4, y);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x + 4, y + 1);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			GoToXY(out, x + 4, y + 2);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 7
			GoToXY(out, x + 4, y + 3);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 5
			GoToXY(out, x + 4, y + 4);
			WriteConsole(out, &"    ", 4, &output, NULL);
			//line 6
			
			//line 7
			GoToXY(out, x + 4, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			break;
		case '-':
			//line 1
			//line 2
			//line 3
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"            ", 12, &output, NULL);
			//line 5
			//line 6

			//line 7
			break;
		case '$':
			//line 1
			GoToXY(out, x + 6, y);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 2
			GoToXY(out, x + 4, y+1);
			WriteConsole(out, &"      ", 6, &output, NULL);
			GoToXY(out, x + 12, y+1);
			WriteConsole(out, &"  ", 2, &output, NULL);
			//line 3
			GoToXY(out, x + 2, y + 2);
			WriteConsole(out, &"        ", 8, &output, NULL);
			GoToXY(out, x + 12, y + 2);
			WriteConsole(out, &"  ", 2, &output, NULL);
			//line 4
			GoToXY(out, x, y + 3);
			WriteConsole(out, &"          ", 10, &output, NULL);
			GoToXY(out, x + 12, y + 3);
			WriteConsole(out, &"  ", 2, &output, NULL);
			//line 5
			GoToXY(out, x, y + 4);
			WriteConsole(out, &"        ", 8, &output, NULL);
			//line 6
			GoToXY(out, x, y + 5);
			WriteConsole(out, &"  ", 2, &output, NULL);
			GoToXY(out, x + 8, y + 5);
			WriteConsole(out, &"  ", 2, &output, NULL);
			//line 7
			GoToXY(out, x, y + 6);
			WriteConsole(out, &"    ", 4, &output, NULL);
			GoToXY(out, x + 6, y + 6);
			WriteConsole(out, &"  ", 2, &output, NULL);
			break;
		default:

			break;
		}
	}

	void DrawTextSprites(HANDLE out, std::string text, int x, int y, int attr = 15*16) {
		SetConsoleTextAttribute(out, attr);
		for (int c = 0; c < text.length(); c++) {
			DrawChar(out, text[c], x + (16 * c), y);
		}
	}

	bool LoadGenericMenu() {
		SetConsoleScreenBufferSize(GenericScreen, SCREEN_SIZE);

		SetConsoleTextAttribute(GenericScreen, 1 * 16);
		//top line
		GoToXY(GenericScreen, 56, 67);
		for (int c = 0; c < 200; c++) {
			WriteConsole(GenericScreen, &"  ", 2, NULL, NULL);
		}
		GoToXY(GenericScreen, 56, 68);
		for (int c = 0; c < 200; c++) {
			WriteConsole(GenericScreen, &"  ", 2, NULL, NULL);
		}

		//left line
		for (int c = 0; c < 136; c++) {
			GoToXY(GenericScreen, 54, 68 + c);
			WriteConsole(GenericScreen, &"    ", 4, NULL, NULL);
		}

		//right line
		for (int c = 0; c < 136; c++) {
			GoToXY(GenericScreen, 454, 68 + c);
			WriteConsole(GenericScreen, &"    ", 4, NULL, NULL);
		}

		//bottom line
		GoToXY(GenericScreen, 56, 203);
		for (int c = 0; c < 200; c++) {
			WriteConsole(GenericScreen, &"  ", 2, NULL, NULL);
		}
		GoToXY(GenericScreen, 56, 204);
		for (int c = 0; c < 200; c++) {
			WriteConsole(GenericScreen, &"  ", 2, NULL, NULL);
		}
		return true;
	}
	bool LoadBomb() { // Anthony's Attempt

		DWORD output;

		SetConsoleTextAttribute(bombSprites, 1 * 16); // Colour

		for (int i = 0; i < 8; i++) {// Draws Row (i = y size)
			GoToXY(bombSprites, 0, i);	 //Position of pixel
			for (int c = 0; c < 8; c++) { // Draws Col (c = x size)
				WriteConsole(bombSprites, &"  ", 2, &output, NULL); // Drawing the sprites?
			}
		}
		return true;
	}

	bool LoadRooms() {
		LoadBrick();
		LoadWall();

		SetConsoleScreenBufferSize(roomSprites, { SCREEN_SIZE.X * 5 + 8, SCREEN_SIZE.Y });
		DrawSprite(wallSprites, 0, 64, 512, 176, roomSprites, 0, 0);
		DrawSprite(wallSprites, 0, 64, 512, 88, roomSprites, 0, 8);
		for (int b = 0; b < 32; b++) {
			DrawSprite(brickSprites, 0, 0, 16, 8, roomSprites, 16 + (16 * b), 0);
		}
		for (int c = 0; c < 7; c++) {
			for (int d = 0; d < 12;d++) {
				DrawSprite(floorSprites, 0, 0, 32, 16, roomSprites, 64 + (d * 32), 32 + (c * 16));
			}
		}

		DrawSprite(roomSprites, 0, 0, 512, 176, roomSprites, SCREEN_SIZE.X + 2, 0);
		for (int c = 0; c < 4; c++) {
			DrawSprite(floorSprites, 34, 0, 16, 8, roomSprites, (SCREEN_SIZE.X + 2) + 224 + (16 * c), 96);
			DrawSprite(floorSprites, 34, 0, 16, 8, roomSprites, (SCREEN_SIZE.X + 2) + 224 + (16 * c), 104);
		}
		for (int c = 0; c < 12; c++) {
			DrawSprite(floorSprites, 34, 0, 16, 8, roomSprites, (SCREEN_SIZE.X + 2) + 160 + (16 * c), 112);
			DrawSprite(floorSprites, 34, 0, 16, 8, roomSprites, (SCREEN_SIZE.X + 2) + 160 + (16 * c), 120);
			DrawSprite(floorSprites, 34, 0, 16, 8, roomSprites, (SCREEN_SIZE.X + 2) + 160 + (16 * c), 128);
			DrawSprite(floorSprites, 34, 0, 16, 8, roomSprites, (SCREEN_SIZE.X + 2) + 160 + (16 * c), 136);
		}

		return true;
	}

	bool LoadUI() {
		SetConsoleScreenBufferSize(UIPanel, SCREEN_SIZE);

		DrawTextSprites(UIPanel, "LEVEL-2", 34, 16);
		DrawTextSprites(UIPanel, "-LIFE-", 368, 24, 4 * 16);

		SetConsoleTextAttribute(UIPanel, 1 * 16);
		// 'B' Top Line
		GoToXY(UIPanel, 248, 27);
		WriteConsole(UIPanel, "        ", 8, NULL, NULL);
		GoToXY(UIPanel, 248, 28);
		WriteConsole(UIPanel, "        ", 8, NULL, NULL);
		GoToXY(UIPanel, 272, 27);
		WriteConsole(UIPanel, "        ", 8, NULL, NULL);
		GoToXY(UIPanel, 272, 28);
		WriteConsole(UIPanel, "        ", 8, NULL, NULL);
		// 'B' sides
		for (int c = 0; c < 24; c++) {
			GoToXY(UIPanel, 246, 28 + c);
			WriteConsole(UIPanel, "    ", 4, NULL, NULL);
			GoToXY(UIPanel, 278, 28 + c);
			WriteConsole(UIPanel, "    ", 4, NULL, NULL);
		}
		//'B' Bottom
		GoToXY(UIPanel, 248, 51);
		WriteConsole(UIPanel, "                                ", 32, NULL, NULL);
		GoToXY(UIPanel, 248, 52);
		WriteConsole(UIPanel, "                                ", 32, NULL, NULL);

		DrawTextSprites(UIPanel, "x", 256, 24);

		SetConsoleTextAttribute(UIPanel, 1 * 16);
		// 'A' Top Line
		GoToXY(UIPanel, 296, 27);
		WriteConsole(UIPanel, "        ", 8, NULL, NULL);
		GoToXY(UIPanel, 296, 28);
		WriteConsole(UIPanel, "        ", 8, NULL, NULL);
		GoToXY(UIPanel, 320, 27);
		WriteConsole(UIPanel, "        ", 8, NULL, NULL);
		GoToXY(UIPanel, 320, 28);
		WriteConsole(UIPanel, "        ", 8, NULL, NULL);
		// 'A' sides
		for (int c = 0; c < 24; c++) {
			GoToXY(UIPanel, 294, 28 + c);
			WriteConsole(UIPanel, "    ", 4, NULL, NULL);
			GoToXY(UIPanel, 326, 28 + c);
			WriteConsole(UIPanel, "    ", 4, NULL, NULL);
		}
		//'A' Bottom
		GoToXY(UIPanel, 296, 51);
		WriteConsole(UIPanel, "                                ", 32, NULL, NULL);
		GoToXY(UIPanel, 296, 52);
		WriteConsole(UIPanel, "                                ", 32, NULL, NULL);

		DrawTextSprites(UIPanel, "c", 304, 24);

		DrawSprite(swordSprites, 0, 0, 32, 16, UIPanel, 296, 32, true);

		// Rupees
		// red
		SetConsoleTextAttribute(UIPanel, 12 * 16);
		for (int c = 0; c < 8; c++) {
			int dX = 176;

			if (c <= 2) {
				dX = 182 - (2 * c);
			}

			GoToXY(UIPanel, dX, 24 + c);

			if (c == 0 || c == 7) {
				WriteConsole(UIPanel, "          ", 10, NULL, NULL);
			}
			else if (c == 1 || c == 6) {
				WriteConsole(UIPanel, "            ", 12, NULL, NULL);
			}
			else if(c == 2 || c == 5){
				WriteConsole(UIPanel, "              ", 14, NULL, NULL);
			}
			else {
				WriteConsole(UIPanel, "                ", 16, NULL, NULL);
			}
		}
		//white
		SetConsoleTextAttribute(UIPanel, 15 * 16);
		GoToXY(UIPanel, 184, 24);
		WriteConsole(UIPanel, "      ", 6, NULL, NULL);
		GoToXY(UIPanel, 180, 25);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 178, 26);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 176, 28);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 176, 29);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 176, 30);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		//Black
		SetConsoleTextAttribute(UIPanel, 0);
		for (int c = 0; c < 3; c++) {
			GoToXY(UIPanel, 188, 25 + c);
			WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		}
		GoToXY(UIPanel, 186, 28);
		WriteConsole(UIPanel, "      ", 6, NULL, NULL);
		GoToXY(UIPanel, 184, 29);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 178, 30);
		WriteConsole(UIPanel, "      ", 6, NULL, NULL);
		GoToXY(UIPanel, 182, 31);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);

		// Keys
		SetConsoleTextAttribute(UIPanel, 6 * 16);
		//line 1
		GoToXY(UIPanel, 184, 40);
		WriteConsole(UIPanel, "      ", 6, NULL, NULL);
		//line 2
		GoToXY(UIPanel, 182, 41);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 188, 41);
		WriteConsole(UIPanel, "    ", 4, NULL, NULL);
		//line 3
		GoToXY(UIPanel, 182, 42);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 190, 42);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		//line 4
		GoToXY(UIPanel, 184, 43);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 190, 43);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		//line 5
		GoToXY(UIPanel, 182, 44);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 186, 44);
		WriteConsole(UIPanel, "    ", 4, NULL, NULL);
		//line 6
		GoToXY(UIPanel, 180, 45);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		//line 7
		GoToXY(UIPanel, 178, 46);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 182, 46);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		// line 8
		GoToXY(UIPanel, 176, 47);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 180, 47);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);

		// Bomb
		//blue
		SetConsoleTextAttribute(UIPanel, 1 * 16);
		for (int c = 0; c < 7; c++) {
			int dX;
			if (c == 0 || c == 6) {
				dX = 180;
			}
			else if (c == 1 || c == 5) {
				dX = 178;
			}
			else {
				dX = 176;
			}
			GoToXY(UIPanel, dX, 49 + c);
			if (c == 0 || c == 6) {
				WriteConsole(UIPanel, "        ", 8, NULL, NULL);
			}
			else if (c == 1 || c == 5) {
				WriteConsole(UIPanel, "            ", 12, NULL, NULL);
			}
			else {
				WriteConsole(UIPanel, "                ", 16, NULL, NULL);
			}

		}
		//Grey
		SetConsoleTextAttribute(UIPanel, 8 * 16);
		GoToXY(UIPanel, 180, 49);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 178, 50);
		WriteConsole(UIPanel, "      ", 6, NULL, NULL);
		GoToXY(UIPanel, 176, 51);
		WriteConsole(UIPanel, "      ", 6, NULL, NULL);
		GoToXY(UIPanel, 176, 52);
		WriteConsole(UIPanel, "      ", 6, NULL, NULL);
		GoToXY(UIPanel, 178, 53);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		//white
		SetConsoleTextAttribute(UIPanel, 15 * 16);
		GoToXY(UIPanel, 190, 48);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 190, 49);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 180, 50);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 178, 51);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);
		GoToXY(UIPanel, 178, 52);
		WriteConsole(UIPanel, "  ", 2, NULL, NULL);

		return true;
	}

	bool LoadInventoryScrn() {
		SetConsoleScreenBufferSize(InventoryScreen, SCREEN_SIZE);

		DrawTextSprites(InventoryScreen, "Inventory", 68, 31, 4 * 16);
		DrawTextSprites(InventoryScreen, "MAP", 80, 103, 4 * 16);
		DrawTextSprites(InventoryScreen, "COMPASS", 48, 143, 4 * 16);
		DrawTextSprites(InventoryScreen, "USE x BUTTON", 32, 79);
		DrawTextSprites(InventoryScreen, "For This", 64, 87);

		//Selected Item Box
		SetConsoleTextAttribute(InventoryScreen, 1 * 16);
		//top
		for (int c = 0; c < 24; c++) {
			GoToXY(InventoryScreen, 120+(c*2), 50);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
			GoToXY(InventoryScreen, 120 + (c * 2), 51);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		//sides
		for (int c = 0; c < 24; c++) {
			GoToXY(InventoryScreen, 118, 51+c);
			WriteConsole(InventoryScreen, "    ", 4, NULL, NULL);
			GoToXY(InventoryScreen, 166, 51+c);
			WriteConsole(InventoryScreen, "    ", 4, NULL, NULL);
		}
		//bottom
		for (int c = 0; c < 24; c++) {
			GoToXY(InventoryScreen, 120 + (c * 2), 74);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
			GoToXY(InventoryScreen, 120 + (c * 2), 75);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}

		// Inventory Box
		//top
		for (int c = 0; c < 96; c++) {
			GoToXY(InventoryScreen, 248 + (c * 2), 50);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
			GoToXY(InventoryScreen, 248 + (c * 2), 51);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		//sides
		for (int c = 0; c < 40; c++) {
			GoToXY(InventoryScreen, 246, 51 + c);
			WriteConsole(InventoryScreen, "    ", 4, NULL, NULL);
			GoToXY(InventoryScreen, 438, 51 + c);
			WriteConsole(InventoryScreen, "    ", 4, NULL, NULL);
		}
		//bottom
		for (int c = 0; c < 96; c++) {
			GoToXY(InventoryScreen, 248 + (c * 2), 90);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
			GoToXY(InventoryScreen, 248 + (c * 2), 91);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}

		//Map
		// base
		SetConsoleTextAttribute(InventoryScreen, 6 * 16);
		for (int h = 0; h < 80; h++) {
			GoToXY(InventoryScreen, 192, 95 + h);
			for (int w = 0; w < 128; w++) {
				WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
			}
		}
		// template rip (top)
		SetConsoleTextAttribute(InventoryScreen, 0);
		for (int c = 0; c < 2; c++) {
			GoToXY(InventoryScreen, 224, 95 + c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 6; c++) {
			GoToXY(InventoryScreen, 226, 95 + c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 4; c++) {
			GoToXY(InventoryScreen, 228, 95 + c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 1; c++) {
			GoToXY(InventoryScreen, 230, 95 + c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 2; c++) {
			GoToXY(InventoryScreen, 232, 95 + c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 1; c++) {
			GoToXY(InventoryScreen, 236, 95 + c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 3; c++) {
			GoToXY(InventoryScreen, 238, 95 + c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		// ctl-c ctl-v top rip
		DrawSprite(InventoryScreen, 224, 95, 16, 8, InventoryScreen, 272, 95);
		DrawSprite(InventoryScreen, 224, 95, 16, 8, InventoryScreen, 320, 95);
		DrawSprite(InventoryScreen, 224, 95, 16, 8, InventoryScreen, 384, 95);

		// template rip (bottom)
		SetConsoleTextAttribute(InventoryScreen, 0);
		for (int c = 0; c < 2; c++) {
			GoToXY(InventoryScreen, 208, 174 - c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 6; c++) {
			GoToXY(InventoryScreen, 210, 174 - c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 3; c++) {
			GoToXY(InventoryScreen, 212, 174 - c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 1; c++) {
			GoToXY(InventoryScreen, 214, 174 - c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 2; c++) {
			GoToXY(InventoryScreen, 218, 174 - c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 3; c++) {
			GoToXY(InventoryScreen, 220, 174 - c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		for (int c = 0; c < 1; c++) {
			GoToXY(InventoryScreen, 222, 174 - c);
			WriteConsole(InventoryScreen, "  ", 2, NULL, NULL);
		}
		// ctl-c ctl-v top rip
		DrawSprite(InventoryScreen, 208, 167, 16, 8, InventoryScreen, 272, 167);
		DrawSprite(InventoryScreen, 208, 167, 16, 8, InventoryScreen, 352, 167);
		DrawSprite(InventoryScreen, 208, 167, 16, 8, InventoryScreen, 416, 167);

		return true;
	}
};

SpriteSheets Sprites;