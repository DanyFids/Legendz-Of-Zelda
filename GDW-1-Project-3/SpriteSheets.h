#pragma once

class SpriteSheets {
public:

	void DrawSprite(HANDLE sheet, int sX, int sY, int w, int h, HANDLE dest, int dx, int dy) {
		CHAR_INFO *outBuff = new CHAR_INFO[w * h];
		CHAR_INFO *transBuff = new CHAR_INFO[w * h];

		//Area to read/write
		SMALL_RECT screen;
		screen.Top = sY;
		screen.Left = sX;
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
		size.X = w;
		size.Y = h;

		ReadConsoleOutput(sheet, outBuff, size, start, &screen);

		screen.Top = dy;
		screen.Left = dx;
		screen.Right = w + dx - 1;
		screen.Bottom = h + dy - 1;

		ReadConsoleOutput(dest, transBuff, size, pos, &screen);

		/*for (int p = 0; p < (w * h); p++) {
			if (outBuff[p].Attributes == 7) {
				outBuff[p] = transBuff[p];
			}
		}*/

		WriteConsoleOutput(dest, outBuff, size, pos, &screen);
	}

	HANDLE dodongoSprites = CreateConsoleScreenBuffer(
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

	HANDLE moldormSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE goriyaSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE oldmanSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE fireSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE bombablewallSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE triforceSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE mapdoorSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE doorlightSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	bool LoadDodongo() {
		SetConsoleScreenBufferSize(dodongoSprites, SCREEN_SIZE);

		DWORD output;

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

		// Dodongo Facing Right One Foot
		for (int c = 0; c < 29; c++)
			DrawSprite(dodongoSprites, 56 - (c * 2), 0, 2, 30, dodongoSprites, 64 + 56 + (c * 2), 0);

		// Dodongo Front Facing One Foot
		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 14);
		for (int i = 0; i < 15; i++) {
			GoToXY(dodongoSprites, 68, i);
			for (int c = 0; c < 10; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 1; i < 14; i++) {
			GoToXY(dodongoSprites, 64, i);
			for (int c = 0; c < 18; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 7; i < 14; i++) {
			GoToXY(dodongoSprites, 58, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 8; i < 16; i++) {
			GoToXY(dodongoSprites, 80, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 70, 15);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 2; i < 4; i++) {
			GoToXY(dodongoSprites, 62, i);
			for (int c = 0; c < 22; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 4; i < 8; i++) {
			GoToXY(dodongoSprites, 60, i);
			for (int c = 0; c < 26; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 7; i < 15; i++) {
			GoToXY(dodongoSprites, 86, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 6);
		GoToXY(dodongoSprites, 70, 0);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 74, 0);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 66, 2);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 76, 2);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 64, 3);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 70, 3);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 80, 3);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 4; i < 7; i++) {
			GoToXY(dodongoSprites, 62, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
			GoToXY(dodongoSprites, 82, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 7; i < 11; i++) {
			GoToXY(dodongoSprites, 60, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
			GoToXY(dodongoSprites, 84, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 66, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 78, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 68, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 76, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 68, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 76, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 68, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 76, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 62, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 82, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 64, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 80, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 70, 13);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 74, 13);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 80, 13);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 78, 14);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		SetConsoleTextAttribute(dodongoSprites, 15 * 16);
		GoToXY(dodongoSprites, 72, 6);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 72, 7);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 66, 8);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 66, 9);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 78, 8);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 78, 9);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 72, 9);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 72, 10);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 72, 11);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 60, 13);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 64, 13);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 78, 15);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 82, 15);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);

		// Dodongo Facing Front Other Foot
		for (int c = 0; c < 29; c++)
			DrawSprite(dodongoSprites, 112 - (c * 2), 0, 2, 16, dodongoSprites, 32 + (c * 2), 17);

		// Dodongo Facing Back One Foot
		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 14);

		for (int i = 3; i < 15; i++) {
			GoToXY(dodongoSprites, 100, i);
			for (int c = 0; c < 10; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 102, 15);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 4; i < 13; i++) {
			GoToXY(dodongoSprites, 96, i);
			for (int c = 0; c < 18; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 5; i < 12; i++) {
			GoToXY(dodongoSprites, 94, i);
			for (int c = 0; c < 22; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 7; i < 10; i++) {
			GoToXY(dodongoSprites, 92, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 7; i < 11; i++) {
			GoToXY(dodongoSprites, 116, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 98, 13);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 10; i < 15; i++) {
			GoToXY(dodongoSprites, 90, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 12; i < 16; i++) {
			GoToXY(dodongoSprites, 92, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 13; i < 16; i++) {
			GoToXY(dodongoSprites, 94, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 96, 14);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 96, 15);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 114, 13);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 116, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 118, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 6);

		GoToXY(dodongoSprites, 98, 0);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 108, 0);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 1; i < 3; i++) {
			GoToXY(dodongoSprites, 94, i);
			for (int c = 0; c < 22; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 92, 3);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 110, 3);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 92, 4);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 114, 4);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 90, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 116, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 90, 6);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 116, 6);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 90, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 118, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 118, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 118, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 116, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 114, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 112, 13);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 92, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 92, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 94, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 96, 13);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 98, 14);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		// Dodongo Facing Back Other Foot
		for (int c = 0; c < 16; c++)
			DrawSprite(dodongoSprites, 120 - (c * 2), 0, 2, 16, dodongoSprites, 88 + (c * 2), 17);

		// Dodongo Facing Left Other Foot

		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 14);

		for (int i = 17; i < 26; i++) {
			GoToXY(dodongoSprites, 18, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 19; i < 30; i++) {
			GoToXY(dodongoSprites, 12, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 20; i < 26; i++) {
			GoToXY(dodongoSprites, 28, i);
			for (int c = 0; c < 12; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 27; i < 33; i++) {
			GoToXY(dodongoSprites, 16, i);
			for (int c = 0; c < 8; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 24, 31);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 23; i < 29; i++) {
			GoToXY(dodongoSprites, 40, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 27; i < 31; i++) {
			GoToXY(dodongoSprites, 38, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
			GoToXY(dodongoSprites, 22, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 26; i < 29; i++) {
			GoToXY(dodongoSprites, 24, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 24; i < 29; i++) {
			GoToXY(dodongoSprites, 2, i);
			for (int c = 0; c < 18; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 25; i < 28; i++) {
			GoToXY(dodongoSprites, 0, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 24, 19);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 24, 24);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 14, 18);
		for (int c = 0; c < 12; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 10, 20);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 8, 21);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 8, 22);
		for (int c = 0; c < 18; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 4, 23);
		for (int c = 0; c < 22; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 4, 29);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 30, 19);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 30, 28);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 30, 27);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 30, 26);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 38, 21);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 40, 22);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 42, 23);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 42, 24);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 44, 25);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 46, 26);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 46, 27);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 46, 28);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 46, 29);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 48, 30);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 50, 31);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 26; i < 32; i++) {
			GoToXY(dodongoSprites, 36, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 20, 26);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 26, 25);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 6);

		GoToXY(dodongoSprites, 12, 20);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 10, 22);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 10, 23);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 8, 24);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 20, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 14, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 14, 26);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 16, 25);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 20, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 18, 29);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 12, 29);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 10, 30);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 10, 31);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 22, 26);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 24, 25);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 19; i < 25; i++) {
			GoToXY(dodongoSprites, 26, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 28, 19);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 24, 20);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 24, 21);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 26, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 28, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 28, 29);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 28; i < 33; i++) {
			GoToXY(dodongoSprites, 34, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 30, 31);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 30, 32);
		for (int c = 0; c < 10; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 36, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 36, 26);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 38, 25);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 46, 26);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 46, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 44, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 44, 29);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 44, 30);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 48, 31);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 2, 25);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 0, 27);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(dodongoSprites, 15 * 16);

		GoToXY(dodongoSprites, 8, 19);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 8, 20);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 0, 20);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 0, 21);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 2, 22);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 2, 23);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 14, 22);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 12, 23);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 10, 24);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 4, 26);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 4, 27);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 28, 30);
		WriteConsole(dodongoSprites, &"      ", 6, &output, NULL);

		// Dodongo Facing Right Other Foot
		for (int c = 0; c < 29; c++)
			DrawSprite(dodongoSprites, 56 - (c * 2), 17, 2, 30, dodongoSprites, 64 + 56 + (c * 2), 17);

		// Dodongo Facing Forward Bomb
		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 14);

		GoToXY(dodongoSprites, 256, 34 - 34);
		for (int c = 0; c < 12; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 35; i < 50; i++) {
			GoToXY(dodongoSprites, 252, i - 34);
			for (int c = 0; c < 20; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 36; i < 49; i++) {
			GoToXY(dodongoSprites, 248, i - 34);
			for (int c = 0; c < 28; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 39; i < 47; i++) {
			GoToXY(dodongoSprites, 246, i - 34);
			for (int c = 0; c < 32; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 250, 49 - 34);
		for (int c = 0; c < 24; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 6);

		GoToXY(dodongoSprites, 260, 38 - 34);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 258, 37 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 264, 37 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 252, 37 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 270, 37 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 254, 36 - 34);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 266, 36 - 34);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 45; i < 49; i++) {
			GoToXY(dodongoSprites, 258, i - 34);
			for (int c = 0; c < 8; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 38; i < 41; i++) {
			GoToXY(dodongoSprites, 250, i - 34);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
			GoToXY(dodongoSprites, 272, i - 34);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 41; i < 45; i++) {
			GoToXY(dodongoSprites, 248, i - 34);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
			GoToXY(dodongoSprites, 274, i - 34);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 250, 45 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 272, 45 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 252, 46 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 270, 46 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 252, 47 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 270, 47 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 254, 48 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 268, 48 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 258, 34 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 264, 34 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 256, 43 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 266, 43 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 254, 44 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 268, 44 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 254, 41 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 268, 41 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 252, 42 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 270, 42 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 252, 43 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 270, 43 - 34);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(dodongoSprites, 15 * 16);

		GoToXY(dodongoSprites, 260, 39 - 34);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 260, 40 - 34);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 68 + 188, 41 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 78 + 188, 41 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 66 + 188, 42 - 34);
		WriteConsole(dodongoSprites, &"      ", 6, &output, NULL);
		GoToXY(dodongoSprites, 76 + 188, 42 - 34);
		WriteConsole(dodongoSprites, &"      ", 6, &output, NULL);
		GoToXY(dodongoSprites, 66 + 188, 43 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 70 + 188, 43 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 76 + 188, 43 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 80 + 188, 43 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 68 + 188, 44 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 78 + 188, 44 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 72 + 188, 45 - 34);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 64 + 188, 49 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 68 + 188, 49 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 78 + 188, 49 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 82 + 188, 49 - 34);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);

		// Dodongo Facing Left, Bomb
		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 14);

		for (int i = 1; i < 12; i++) {
			GoToXY(dodongoSprites, 200, i);
			for (int c = 0; c < 30; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 204, 0);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 218, 0);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 3; i < 11; i++) {
			GoToXY(dodongoSprites, 196, i);
			for (int c = 0; c < 4; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 5; i < 12; i++) {
			GoToXY(dodongoSprites, 194, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 6; i < 12; i++) {
			GoToXY(dodongoSprites, 192, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 188, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 190, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 196, 11);
		for (int c = 0; c < 16; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 198, 12);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 202, 13);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 204, 14);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 218, 12);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 228, 8);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 228, 9);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 228, 10);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 230, 11);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 230, 12);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 228, 13);
		for (int c = 0; c < 16; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 220, 2);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 222, 3);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 224, 4);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 224, 5);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 226, 6);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 226, 7);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 230, 14);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 242, 14);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 6);

		GoToXY(dodongoSprites, 216, 0);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 214, 1);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 214, 2);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 212, 3);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 212, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 214, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 214, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 212, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 212, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 208, 9);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 204, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 212, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 212, 11);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 212, 12);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 214, 13);
		for (int c = 0; c < 14; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 226, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 224, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 224, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 224, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 226, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 228, 14);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 232, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 234, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 234, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 236, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 236, 13);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 238, 14);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 240, 15);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 190, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 190, 8);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 192, 9);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 204, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 202, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 200, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 196, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 198, 8);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 202, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 204, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 204, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 204, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 198, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 200, 2);
		for (int c = 0; c < 4; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(dodongoSprites, 15 * 16);

		GoToXY(dodongoSprites, 186, 1);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 194, 1);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 186, 2);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 194, 2);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 188, 3);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 188, 4);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 180, 7);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 180, 8);
		WriteConsole(dodongoSprites, &"      ", 6, &output, NULL);
		GoToXY(dodongoSprites, 180, 9);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 198, 4);
		WriteConsole(dodongoSprites, &"      ", 6, &output, NULL);
		GoToXY(dodongoSprites, 196, 5);
		WriteConsole(dodongoSprites, &"  ", 2, &output, NULL);
		GoToXY(dodongoSprites, 200, 5);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 196, 6);
		WriteConsole(dodongoSprites, &"        ", 8, &output, NULL);
		GoToXY(dodongoSprites, 198, 7);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 210, 13);
		WriteConsole(dodongoSprites, &"    ", 4, &output, NULL);
		GoToXY(dodongoSprites, 212, 14);
		WriteConsole(dodongoSprites, &"              ", 14, &output, NULL);
		GoToXY(dodongoSprites, 214, 15);
		WriteConsole(dodongoSprites, &"          ", 10, &output, NULL);

		// Dodongo Facing Back Bomb
		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 14);

		GoToXY(dodongoSprites, 256 + 34, 34 - 34);
		for (int c = 0; c < 12; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 35; i < 49; i++) {
			GoToXY(dodongoSprites, 252 + 34, i - 34);
			for (int c = 0; c < 20; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 36; i < 49; i++) {
			GoToXY(dodongoSprites, 248 + 34, i - 34);
			for (int c = 0; c < 28; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 39; i < 49; i++) {
			GoToXY(dodongoSprites, 246 + 34, i - 34);
			for (int c = 0; c < 32; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 248 + 34, 49 - 34);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 258 + 34, 49 - 34);
		for (int c = 0; c < 8; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 270 + 34, 49 - 34);
		for (int c = 0; c < 6; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(dodongoSprites, 4 * 16 + 6);

		for (int i = 10, j = 280; i < 16; j += 2, i++) {
			GoToXY(dodongoSprites, j, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 10, j = 310; i < 16; j -= 2, i++) {
			GoToXY(dodongoSprites, j, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(dodongoSprites, 310, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(dodongoSprites, 280, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(dodongoSprites, &mGrad, 1, &output, NULL);
		}

		// Dodongo Facing Right Bomb
		for (int c = 0; c < 34; c++)
			DrawSprite(dodongoSprites, 56 + 100 + 88 - (c * 2), 0, 2, 30, dodongoSprites, 64 + 56 + 100 + 92 + (c * 2), 0);
		return true;
	}

	bool LoadPlayer() {

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
		GoToXY(playerSprites, 108, 17);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 106, 18);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 106, 19);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 104, 20);
		WriteConsole(playerSprites, &"                        ", 24, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 106, 21);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 112, 22);
		WriteConsole(playerSprites, &"         ", 8, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 114, 23);
		WriteConsole(playerSprites, &"     ", 4, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 106, 24);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 124, 24);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 108, 25);
		WriteConsole(playerSprites, &"                  ", 18, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 108, 26);
		WriteConsole(playerSprites, &"                  ", 18, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 108, 27);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 106, 28);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 124, 28);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 104, 29);
		WriteConsole(playerSprites, &"                        ", 24, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 108, 30);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow

		// Third Row
		GoToXY(playerSprites, 102, 19);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 128, 19);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 102, 20);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 128, 20);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 102, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 128, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 102, 22);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 126, 22);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 104, 23);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 126, 23);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 102, 26);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 102, 27);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 102, 28);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6);

		// Fifth Row
		GoToXY(playerSprites, 104, 21);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 126, 21);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 106, 22);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 120, 22);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 106, 23);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 118, 23);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 104, 24);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 108, 24);
		for (int c = 0; c < 16; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 126, 24);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 104, 25);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 126, 25);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 104, 26);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 126, 26);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 104, 27);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 124, 27);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 108, 28);
		for (int c = 0; c < 16; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 106, 30);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 122, 30);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 108, 31);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 120, 31);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 122, 32);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Facing forward, shield, Right Foot
		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 10, 17);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 14, 17);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 8, 18);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 16, 18);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 8, 19);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 22, 19);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 12, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 18, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 6, 24);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 22, 24);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 20, 25);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 14, 26);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 22, 26);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 20, 27);
		WriteConsole(playerSprites, &"      ", 4, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 16, 28);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 24, 28);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 18, 29);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 14, 30);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 22, 30);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red with dark yellow

		// Third Row
		GoToXY(playerSprites, 10, 19);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 8, 20);
		for (int c = 0; c < 16; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 8, 21);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 22, 21);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 8, 22);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 12, 22);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 18, 22);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 22, 22);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 26, 23);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 14, 24);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 24, 24);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 4, 25);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 2, 26);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 8, 26);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 2, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 10, 27);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 16, 27);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 24, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 2, 28);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 8, 28);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 18, 28);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 2, 29);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 8, 29);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 16, 29);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 2, 30);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 22, 30);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 18, 31);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 18, 32);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow (Light brown)

		// Third Row
		GoToXY(playerSprites, 4, 19);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 26, 19);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 4, 20);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 26, 20);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 4, 21);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 10, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 14, 21);
		WriteConsole(playerSprites, &"     ", 4, &output, NULL);
		GoToXY(playerSprites, 20, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 24, 21);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 4, 22);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 10, 22);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 14, 22);
		WriteConsole(playerSprites, &"     ", 4, &output, NULL);
		GoToXY(playerSprites, 20, 22);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 24, 22);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 6, 23);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 18, 24);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 10, 24);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 14, 25);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 26, 25);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 6, 26);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 26, 26);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 4, 27);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 14, 27);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 6, 28);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 14, 28);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 6, 29);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 14, 29);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 14, 30);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifteenth Row
		GoToXY(playerSprites, 4, 31);
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
		GoToXY(playerSprites, 78, 17);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 80, 18);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 88, 19);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 82, 19);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 88, 20);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 94, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 88, 21);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 74, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 90, 22);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 80, 24);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 78, 25);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 74, 26);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 80, 26);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 74, 27);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 88, 27);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 90, 28);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 76, 28);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 78, 29);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);
		GoToXY(playerSprites, 72, 29);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 70, 30);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 14 * 16); // Light Yellow

		// Third Row
		GoToXY(playerSprites, 86, 19);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 84, 20);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 82, 21);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 76, 21);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 72, 21);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 76, 22);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 82, 22);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 68, 22);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 72, 23);
		WriteConsole(playerSprites, &"            ", 12, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 72, 24);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 76, 25);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 70, 25);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 76, 26);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 70, 26);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 78, 27);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red with yellow

		// Second Row
		GoToXY(playerSprites, 72, 18);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 70, 19);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 72, 20);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 80, 21);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 86, 22);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 80, 22);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 74, 22);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 84, 23);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 23);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 68, 24);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 72, 25);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 86, 25);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 25);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 82, 26);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 72, 26);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 26);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 82, 27);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 72, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 82, 28);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 74, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 74, 29);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 68, 29);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 92, 29);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 90, 30);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 70, 30);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 72, 31);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 88, 31);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sword, Forward
		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 146, 0);
		WriteConsole(playerSprites, "         ", 10, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 144, 1);
		WriteConsole(playerSprites, "             ", 14, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 142, 2);
		WriteConsole(playerSprites, "    ", 4, &output, NULL);
		GoToXY(playerSprites, 154, 2);
		WriteConsole(playerSprites, "      ", 6, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 142, 3);
		WriteConsole(playerSprites, "  ", 2, &output, NULL);
		GoToXY(playerSprites, 156, 3);
		WriteConsole(playerSprites, "    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 146, 4);
		WriteConsole(playerSprites, "  ", 2, &output, NULL);
		GoToXY(playerSprites, 152, 4);
		WriteConsole(playerSprites, "  ", 2, &output, NULL);
		GoToXY(playerSprites, 158, 4);
		WriteConsole(playerSprites, "  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 158, 5);
		WriteConsole(playerSprites, "  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 142, 6);
		WriteConsole(playerSprites, "  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 142, 7);
		WriteConsole(playerSprites, "    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 142, 8);
		WriteConsole(playerSprites, "      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 144, 9);
		WriteConsole(playerSprites, "            ", 12, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 142, 10);
		WriteConsole(playerSprites, "  ", 2, &output, NULL);
		GoToXY(playerSprites, 146, 10);
		WriteConsole(playerSprites, "  ", 2, &output, NULL);
		GoToXY(playerSprites, 160, 10);
		WriteConsole(playerSprites, "  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 142, 11);
		WriteConsole(playerSprites, "    ", 4, &output, NULL);
		GoToXY(playerSprites, 150, 11);
		WriteConsole(playerSprites, "  ", 2, &output, NULL);
		GoToXY(playerSprites, 158, 11);
		WriteConsole(playerSprites, "    ", 4, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 144, 12);
		WriteConsole(playerSprites, "    ", 4, &output, NULL);
		GoToXY(playerSprites, 158, 12);
		WriteConsole(playerSprites, "    ", 4, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 146, 13);
		WriteConsole(playerSprites, "    ", 4, &output, NULL);
		GoToXY(playerSprites, 156, 13);
		WriteConsole(playerSprites, "    ", 4, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red with Yellow

		// First Row
		GoToXY(playerSprites, 140, 0);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Second Row
		GoToXY(playerSprites, 138, 1);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 142, 1);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 136, 2);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 146, 2);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 134, 3);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 144, 3);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 134, 4);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 142, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 154, 4);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 134, 5);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 142, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 146, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 152, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 156, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 148, 6);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 136, 6);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 138, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 148, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 156, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 140, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 154, 8);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 154, 9);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 142, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 144, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 148, 10);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 146, 11);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 152, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 140, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 148, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 156, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 162, 12);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 138, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 160, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 158, 14);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(playerSprites, 14 * 16);

		// Second Row
		GoToXY(playerSprites, 140, 1);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 140, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 138, 3);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 162, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 138, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 144, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 148, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 160, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 140, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 144, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 148, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 154, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 160, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 144, 6);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 152, 6);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 146, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 152, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 148, 8);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 152, 12);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 150, 13);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Fifteenth Row
		GoToXY(playerSprites, 150, 14);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Sword, Right

		SetConsoleTextAttribute(playerSprites, 10 * 16);

		// First Row
		GoToXY(playerSprites, 182, 0);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 178, 1);
		WriteConsole(playerSprites, &"            ", 10, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 176, 2);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 182, 2);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 176, 3);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 174, 4);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 192, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 172, 5);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 172, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 178, 7);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 176, 8);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 176, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 174, 10);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 192, 10);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 172, 11);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 186, 11);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 174, 12);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 176, 13);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red and Yellow

		// Second Row
		GoToXY(playerSprites, 188, 1);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 186, 2);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 184, 3);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 186, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 178, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 186, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 192, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 178, 6);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 180, 8);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 178, 9);
		for (int c = 0; c < 14; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 178, 10);
		for (int c = 0; c < 14; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 180, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 192, 11);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 170, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 186, 12);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 170, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 194, 13);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 172, 14);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 192, 14);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(playerSprites, 14 * 16);

		// Third Row
		GoToXY(playerSprites, 180, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 180, 3);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 180, 4);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 188, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 194, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 182, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 188, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 194, 5);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 184, 6);
		WriteConsole(playerSprites, &"            ", 12, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 188, 7);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 192, 8);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 192, 9);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Sword, Left

		SetConsoleTextAttribute(playerSprites, 10 * 16);

		// First Row
		GoToXY(playerSprites, 216, 0);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 218, 1);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 220, 2);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 226, 2);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 226, 3);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 226, 4);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 212, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 228, 5);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 232, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 218, 7);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 226, 8);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 228, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 228, 10);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 212, 10);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 226, 11);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 214, 11);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 218, 12);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 210, 13);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red and Yellow

		// Second Row
		GoToXY(playerSprites, 210, 1);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 208, 2);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 210, 3);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 218, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 224, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 218, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 212, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 222, 6);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 214, 8);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 214, 9);
		for (int c = 0; c < 14; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 214, 10);
		for (int c = 0; c < 14; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 220, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 210, 11);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 232, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 210, 12);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 230, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 208, 13);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 228, 14);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 206, 14);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(playerSprites, 14 * 16);

		// Third Row
		GoToXY(playerSprites, 224, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 222, 3);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 220, 4);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 214, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 210, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 214, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 220, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 206, 5);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 210, 6);
		WriteConsole(playerSprites, &"            ", 12, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 208, 7);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 208, 8);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 210, 9);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Sword, Back
		SetConsoleTextAttribute(playerSprites, 10 * 16);

		// First Row
		GoToXY(playerSprites, 248, 0);
		WriteConsole(playerSprites, &"            ", 12, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 246, 1);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 246, 2);
		WriteConsole(playerSprites, &"                  ", 18, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 246, 3);
		WriteConsole(playerSprites, &"                  ", 18, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 248, 4);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 250, 5);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 246, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 252, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 262, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 246, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 260, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 246, 8);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 246, 9);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 244, 10);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 248, 10);
		WriteConsole(playerSprites, &"              ", 14, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 244, 11);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 244, 12);
		WriteConsole(playerSprites, &"                      ", 22, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 254, 13);
		WriteConsole(playerSprites, &"           ", 10, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red and Yellow

		// First Row
		GoToXY(playerSprites, 246, 0);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 244, 2);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 242, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 246, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 262, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 242, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 246, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 256, 5);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 242, 6);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 248, 6);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 254, 6);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 272, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 242, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 250, 7);
		for (int c = 0; c < 10; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 262, 7);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 270, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 244, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 262, 8);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 268, 8);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 244, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 262, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 266, 9);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 246, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 264, 10);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 242, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 248, 11);
		for (int c = 0; c < 16; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 266, 11);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 240, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 240, 13);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 264, 13);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 262, 14);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 262, 15);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(playerSprites, 14 * 16);

		// Second Row
		GoToXY(playerSprites, 242, 1);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 242, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 242, 3);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 266, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 244, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 264, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 244, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 264, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 272, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 264, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 270, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 268, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 266, 8);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 264, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 262, 10);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 264, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 266, 12);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Item Pickup
		SetConsoleTextAttribute(playerSprites, 10 * 16); // Green

		// First Row
		GoToXY(playerSprites, 288, 0);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 286, 1);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 292, 1);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 284, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 298, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 288, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 294, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 286, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 298, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 284, 8);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 296, 8);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 284, 9);
		WriteConsole(playerSprites, &"                  ", 18, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 282, 10);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 296, 10);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 290, 11);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 300, 11);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 282, 12);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 296, 12);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 282, 13);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red and Yellow

		// Second Row
		GoToXY(playerSprites, 288, 1);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 278, 2);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 286, 2);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 278, 3);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 284, 3);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 292, 3);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 278, 4);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 288, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 298, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 280, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 294, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 298, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 280, 6);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 290, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 302, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 280, 7);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 290, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 300, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 282, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 282, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 288, 10);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 300, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 282, 11);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 294, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 288, 12);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(playerSprites, 298, 13);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 284, 14);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 294, 14);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 284, 15);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 294, 15);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(playerSprites, 14 * 16);

		// First Row
		GoToXY(playerSprites, 278, 0);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 278, 1);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 302, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 282, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 286, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 290, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 302, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 282, 4);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 290, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 296, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 300, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 284, 5);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);
		GoToXY(playerSprites, 296, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 300, 5);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 286, 6);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 292, 6);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 288, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 294, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 292, 8);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 302, 8);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 302, 9);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Triforce
		SetConsoleTextAttribute(playerSprites, 10 * 16);

		// First Row
		GoToXY(playerSprites, 318, 0);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 316, 1);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 326, 1);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(playerSprites, 314, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 328, 2);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 318, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 324, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 316, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 326, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 314, 8);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 314, 9);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 312, 10);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 326, 10);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 320, 11);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 312, 12);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 326, 12);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 312, 13);
		WriteConsole(playerSprites, &"                    ", 20, &output, NULL);

		SetConsoleTextAttribute(playerSprites, 4 * 16 + 6); // Red and Yellow

		// Second Row
		GoToXY(playerSprites, 318, 1);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Third Row
		GoToXY(playerSprites, 308, 2);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 316, 2);
		for (int c = 0; c < 12; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 332, 2);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fourth Row
		GoToXY(playerSprites, 308, 3);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 314, 3);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 328, 3);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 332, 3);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(playerSprites, 308, 4);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 318, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 324, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 332, 4);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixth Row
		GoToXY(playerSprites, 310, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 330, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Seventh Row
		GoToXY(playerSprites, 310, 6);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 320, 6);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 328, 6);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(playerSprites, 310, 7);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 320, 7);
		for (int c = 0; c < 4; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 328, 7);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(playerSprites, 312, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 330, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(playerSprites, 312, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 330, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(playerSprites, 318, 10);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(playerSprites, 312, 11);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 324, 11);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(playerSprites, 318, 12);
		for (int c = 0; c < 8; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Fifteenth Row
		GoToXY(playerSprites, 314, 14);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 324, 14);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		// Sixteenth Row
		GoToXY(playerSprites, 314, 15);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(playerSprites, 324, 15);
		for (int c = 0; c < 6; c++) {
			WriteConsole(playerSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(playerSprites, 14 * 16);

		// First Row
		GoToXY(playerSprites, 308, 0);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 332, 0);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Second Row
		GoToXY(playerSprites, 308, 1);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 330, 1);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 312, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 316, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 320, 3);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 326, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 330, 3);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 312, 4);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 320, 4);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 326, 4);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 314, 5);
		WriteConsole(playerSprites, &"                ", 16, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 316, 6);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 324, 6);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 318, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 324, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

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

		// Facing Right, Tail Extended
		for (int c = 0; c < 16; c++)
			DrawSprite(ropeSprites, 30 - (c * 2), 0, 2, 16, ropeSprites, 32 + (c * 2), 0);

		// Facing Left, Tail Squished
		SetConsoleTextAttribute(ropeSprites, 4 * 16 + 14);

		GoToXY(ropeSprites, 8, 16);
		for (int c = 0; c < 8; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 6, 17);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 17; i < 24; i++) {
			GoToXY(ropeSprites, 12, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 19; i < 22; i++) {
			GoToXY(ropeSprites, 10, i);
			for (int c = 0; c < 10; c++) {
				WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(ropeSprites, 2, 20);
		for (int c = 0; c < 20; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 20, 21);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 18, 22);
		for (int c = 0; c < 4; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 4, 23);
		for (int c = 0; c < 16; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 8, 24);
		for (int c = 0; c < 8; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 25; i < 30; i++) {
			GoToXY(ropeSprites, 12, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 26; i < 30; i++) {
			GoToXY(ropeSprites, 6, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(ropeSprites, 8, 30);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 14, 30);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 14, 28);
		for (int c = 0; c < 4; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 14, 29);
		for (int c = 0; c < 4; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 16, 26);
		for (int c = 0; c < 6; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 16, 27);
		for (int c = 0; c < 6; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 18, 25);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 20, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 24, 28);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 22, 29);
		for (int c = 0; c < 4; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 26, 27);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(ropeSprites, 22, 30);
		for (int c = 0; c < 2; c++) {
			WriteConsole(ropeSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(ropeSprites, 4 * 16);

		GoToXY(ropeSprites, 8, 17);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);
		GoToXY(ropeSprites, 6, 18);
		WriteConsole(ropeSprites, &"      ", 6, &output, NULL);
		GoToXY(ropeSprites, 4, 19);
		WriteConsole(ropeSprites, &"      ", 6, &output, NULL);
		GoToXY(ropeSprites, 0, 22);
		WriteConsole(ropeSprites, &"        ", 8, &output, NULL);
		GoToXY(ropeSprites, 8, 25);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);
		GoToXY(ropeSprites, 8, 27);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);
		GoToXY(ropeSprites, 8, 29);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(ropeSprites, 15 * 16);

		GoToXY(ropeSprites, 4, 21);
		WriteConsole(ropeSprites, &"  ", 2, &output, NULL);
		GoToXY(ropeSprites, 8, 26);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);
		GoToXY(ropeSprites, 8, 28);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);
		GoToXY(ropeSprites, 10, 30);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);
		GoToXY(ropeSprites, 18, 28);
		WriteConsole(ropeSprites, &"  ", 2, &output, NULL);
		GoToXY(ropeSprites, 20, 29);
		WriteConsole(ropeSprites, &"  ", 2, &output, NULL);
		GoToXY(ropeSprites, 20, 30);
		WriteConsole(ropeSprites, &"  ", 2, &output, NULL);

		// Facing Left, Tail Extended
		for (int c = 0; c < 16; c++)
			DrawSprite(ropeSprites, 30 - (c * 2), 16, 2, 16, ropeSprites, 32 + (c * 2), 16);

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
		GoToXY(gelSprites, 0, 7);
		WriteConsole(gelSprites, &"            ", 12, &output, NULL);

		// Ninth Row
		GoToXY(gelSprites, 2, 8);
		WriteConsole(gelSprites, &"        ", 8, &output, NULL);


		SetConsoleTextAttribute(gelSprites, 11 * 16); // Aqua

		// Second Row
		GoToXY(gelSprites, 6, 1);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(gelSprites, 6, 2);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(gelSprites, 8, 3);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(gelSprites, 3 * 16);

		// Second Row
		GoToXY(gelSprites, 6, 0);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(gelSprites, 8, 1);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(gelSprites, 8, 2);
		WriteConsole(gelSprites, &"  ", 2, &output, NULL);

		// Jiggly Gel
		for (int c = 0; c < 6; c++)
			DrawSprite(gelSprites, 0, 0, 2 + (c * 2), 8, gelSprites, 16, 0);

		SetConsoleTextAttribute(gelSprites, 1 * 16);

		for (int i = 4; i < 7; i++) {
			GoToXY(gelSprites, 14, i);
			WriteConsole(gelSprites, &"                ", 16, &output, NULL);
		}

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
		GoToXY(swordSprites, 42, 15);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		// Second Row
		GoToXY(swordSprites, 40, 14);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Third Row
		GoToXY(swordSprites, 40, 13);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fourth Row
		GoToXY(swordSprites, 40, 12);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fifth Row
		GoToXY(swordSprites, 40, 11);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Sixth Row
		GoToXY(swordSprites, 40, 10);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(swordSprites, 40, 9);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Eighth Row
		GoToXY(swordSprites, 40, 8);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Ninth Row
		GoToXY(swordSprites, 40, 7);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(swordSprites, 40, 6);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(swordSprites, 40, 5);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 10 * 16); // Green

		// Twelfth Row
		GoToXY(swordSprites, 36, 4);
		WriteConsole(swordSprites, &"              ", 14, &output, NULL);

		// Thirteenth Row
		GoToXY(swordSprites, 36, 3);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		GoToXY(swordSprites, 48, 3);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(swordSprites, 40, 2);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Sixteenth Row
		GoToXY(swordSprites, 40, 0);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 14 * 16); // Light Yellow

		// Thirteenth Row
		GoToXY(swordSprites, 40, 3);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fifteenth Row
		GoToXY(swordSprites, 40, 1);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Right
		SetConsoleTextAttribute(swordSprites, 8 * 16); // Grey

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 70, i);
			WriteConsole(swordSprites, &"                      ", 22, &output, NULL);
		}

		GoToXY(swordSprites, 92, 7);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 10 * 16); // Green

		GoToXY(swordSprites, 66, 4);
		WriteConsole(swordSprites, &"    ", 4, &output, NULL);

		GoToXY(swordSprites, 68, 5);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 60, i);
			WriteConsole(swordSprites, &"          ", 10, &output, NULL);
		}

		GoToXY(swordSprites, 68, 9);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		GoToXY(swordSprites, 66, 10);
		WriteConsole(swordSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 14 * 16); // Light Yellow

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 62, i);
			WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 66, i);
			WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		}

		// Left
		SetConsoleTextAttribute(swordSprites, 8 * 16); // Grey

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 98, i);
			WriteConsole(swordSprites, &"                      ", 22, &output, NULL);
		}

		GoToXY(swordSprites, 96, 7);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 10 * 16); // Green

		GoToXY(swordSprites, 120, 4);
		WriteConsole(swordSprites, &"    ", 4, &output, NULL);

		GoToXY(swordSprites, 120, 5);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 120, i);
			WriteConsole(swordSprites, &"          ", 10, &output, NULL);
		}

		GoToXY(swordSprites, 120, 9);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		GoToXY(swordSprites, 120, 10);
		WriteConsole(swordSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 14 * 16); // Light Yellow

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 122, i);
			WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 6; i < 9; i++) {
			GoToXY(swordSprites, 126, i);
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

		// Yellow Sand Tile
		SetConsoleTextAttribute(floorSprites, 14 * 16 + 6);

		char mGrad = { (char)177 };

		for (int i = 0; i < 8; i++) {
			GoToXY(floorSprites, 52, i);
			for (int c = 0; c < 16; c++)
			{
				WriteConsole(floorSprites, &mGrad, 1, &output, NULL);
			}
		}

		SetConsoleTextAttribute(floorSprites, 6 * 16);

		GoToXY(floorSprites, 66, 0);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 58, 1);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 54, 3);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 60, 4);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 66, 5);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 56, 6);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(floorSprites, 14 * 16);

		GoToXY(floorSprites, 52, 1);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 64, 3);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 62, 7);
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

		//for (int i = 0; i < 32; i++) {
		//	DrawSprite(doorSprites, 0+i*2, 0, 2, 20, wallSprites, 224 + i*2, 208);
		//}

		// Wall Protrusions
		// Bottom
		SetConsoleTextAttribute(wallSprites, 11 * 16);

		GoToXY(wallSprites, 200 + 4 + 6, 226);
		WriteConsole(wallSprites, &"        ", 8, &output, NULL);
		GoToXY(wallSprites, 200 + 4 + 6, 227);
		WriteConsole(wallSprites, &"        ", 8, &output, NULL);
		GoToXY(wallSprites, 202 + 4 + 6, 228);
		WriteConsole(wallSprites, &"        ", 8, &output, NULL);
		GoToXY(wallSprites, 204 + 4 + 6, 229);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(wallSprites, 1 * 16);

		GoToXY(wallSprites, 214 + 4 + 6, 224);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		GoToXY(wallSprites, 210 + 4 + 6, 225);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);
		GoToXY(wallSprites, 208 + 4 + 6, 226);
		WriteConsole(wallSprites, &"        ", 8, &output, NULL);
		GoToXY(wallSprites, 208 + 4 + 6, 227);
		WriteConsole(wallSprites, &"        ", 8, &output, NULL);
		GoToXY(wallSprites, 210 + 4 + 6, 228);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);
		GoToXY(wallSprites, 210 + 4 + 6, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(wallSprites, 0 * 16);

		GoToXY(wallSprites, 206 + 4 + 6, 224);
		WriteConsole(wallSprites, &"        ", 8, &output, NULL);
		GoToXY(wallSprites, 200 + 4 + 6, 225);
		WriteConsole(wallSprites, &"          ", 10, &output, NULL);

		SetConsoleTextAttribute(wallSprites, 11 * 16);

		GoToXY(wallSprites, 288, 224);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		GoToXY(wallSprites, 288, 225);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);
		GoToXY(wallSprites, 288, 226);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);
		GoToXY(wallSprites, 296, 226);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);
		GoToXY(wallSprites, 288, 227);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);
		GoToXY(wallSprites, 296, 227);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);
		GoToXY(wallSprites, 290, 228);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		GoToXY(wallSprites, 294, 228);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);
		GoToXY(wallSprites, 290, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		GoToXY(wallSprites, 294, 229);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(wallSprites, 1 * 16);

		GoToXY(wallSprites, 294, 226);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		GoToXY(wallSprites, 294, 227);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		GoToXY(wallSprites, 292, 228);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		GoToXY(wallSprites, 292, 229);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(wallSprites, 0 * 16);

		GoToXY(wallSprites, 290, 224);
		WriteConsole(wallSprites, &"      ", 6, &output, NULL);
		GoToXY(wallSprites, 292, 225);
		WriteConsole(wallSprites, &"          ", 10, &output, NULL);

		// Top
		for (int i = 0; i < 6; i++) {
			DrawSprite(wallSprites, 210, 224 + (i), 92, 1, wallSprites, 210, 71 - (i));
		}

		SetConsoleTextAttribute(wallSprites, 11 * 16);

		for (int i = 125; i < 129; i++) {
			GoToXY(wallSprites, 484, i);
			WriteConsole(wallSprites, &"    ", 4, &output, NULL);
		}
		for (int i = 127; i < 130; i++) {
			GoToXY(wallSprites, 488, i);
			WriteConsole(wallSprites, &"    ", 4, &output, NULL);
		}
		GoToXY(wallSprites, 488, 126);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(wallSprites, 1 * 16);

		GoToXY(wallSprites, 484, 129);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);
		GoToXY(wallSprites, 482, 130);
		WriteConsole(wallSprites, &"          ", 10, &output, NULL);
		GoToXY(wallSprites, 482, 131);
		WriteConsole(wallSprites, &"        ", 8, &output, NULL);

		SetConsoleTextAttribute(wallSprites, 0 * 16);

		for (int i = 125; i < 130; i++) {
			GoToXY(wallSprites, 482, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}
		for (int i = 128; i < 132; i++) {
			GoToXY(wallSprites, 480, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		SetConsoleTextAttribute(wallSprites, 11 * 16);

		GoToXY(wallSprites, 482, 164);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		GoToXY(wallSprites, 482, 165);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		for (int i = 164; i < 170; i++) {
			GoToXY(wallSprites, 484, i);
			WriteConsole(wallSprites, &"      ", 6, &output, NULL);
		}
		GoToXY(wallSprites, 484, 170);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);
		for (int i = 165; i < 169; i++) {
			GoToXY(wallSprites, 490, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		SetConsoleTextAttribute(wallSprites, 1 * 16);

		GoToXY(wallSprites, 488, 166);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);
		GoToXY(wallSprites, 484, 167);
		WriteConsole(wallSprites, &"    ", 4, &output, NULL);

		SetConsoleTextAttribute(wallSprites, 0 * 16);

		for (int i = 164; i < 168; i++) {
			GoToXY(wallSprites, 480, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}
		for (int i = 166; i < 171; i++) {
			GoToXY(wallSprites, 482, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		// Left
		for (int i = 0; i < 6; i++) {
			DrawSprite(wallSprites, 480 + (i * 2), 125, 2, 54, wallSprites, 30 - (i * 2), 125);
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
		GoToXY(doorSprites, 30, 0);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

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
		GoToXY(doorSprites, 8, 15);
		WriteConsole(doorSprites, &"          ", 10, &output, NULL);
		GoToXY(doorSprites, 46, 15);
		WriteConsole(doorSprites, &"          ", 10, &output, NULL);

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

		SetConsoleTextAttribute(doorSprites, 11 * 16); // Aqua

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

		// Sixteenth Row
		GoToXY(doorSprites, 4, 15);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 56, 15);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		// Seventeenth Row
		GoToXY(doorSprites, 2, 16);
		WriteConsole(doorSprites, &"                                                            ", 60, &output, NULL);

		// Eighteenth Row
		GoToXY(doorSprites, 2, 17);
		WriteConsole(doorSprites, &"                                                            ", 60, &output, NULL);

		SetConsoleTextAttribute(doorSprites, 0 * 16);

		// First Row
		GoToXY(doorSprites, 16, 0);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 46, 0);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		for (int i = 1; i < 12; i++) {
			GoToXY(doorSprites, 30, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 7; i < 16; i++) {
			GoToXY(doorSprites, 18, i);
			WriteConsole(doorSprites, &"                            ", 28, &output, NULL);
		}

		GoToXY(doorSprites, 8, 15);
		WriteConsole(doorSprites, &"                                                      ", 48, &output, NULL);

		// Left Side Door Open

		SetConsoleTextAttribute(doorSprites, 1 * 16);

		for (int i = 0; i < 32; i++) {
			GoToXY(doorSprites, 132, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		GoToXY(doorSprites, 134, 0);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 134, 31);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 140, 30);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		GoToXY(doorSprites, 148, 29);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 154, 28);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 160, 27);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 166, 26);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		for (int i = 4; i < 9; i++) {
			GoToXY(doorSprites, 142, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		}

		for (int i = 23; i < 28; i++) {
			GoToXY(doorSprites, 142, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		}

		for (int i = 5; i < 9; i++) {
			GoToXY(doorSprites, 146, i);
			WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		}

		for (int i = 23; i < 27; i++) {
			GoToXY(doorSprites, 146, i);
			WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		}

		for (int i = 6; i < 9; i++) {
			GoToXY(doorSprites, 152, i);
			WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		}

		for (int i = 23; i < 26; i++) {
			GoToXY(doorSprites, 152, i);
			WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		}

		for (int i = 7; i < 9; i++) {
			GoToXY(doorSprites, 158, i);
			WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		}

		for (int i = 23; i < 25; i++) {
			GoToXY(doorSprites, 158, i);
			WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		}

		GoToXY(doorSprites, 164, 8);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 164, 23);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(doorSprites, 11 * 16);

		for (int i = 1; i < 31; i++) {
			GoToXY(doorSprites, 134, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		GoToXY(doorSprites, 140, 1);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		GoToXY(doorSprites, 148, 2);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 154, 3);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 160, 4);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 166, 5);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 158, 9);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);

		SetConsoleTextAttribute(doorSprites, 9 * 16);

		for (int i = 1; i < 31; i++) {
			GoToXY(doorSprites, 136, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		}

		for (int i = 2; i < 4; i++) {
			GoToXY(doorSprites, 140, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 28; i < 30; i++) {
			GoToXY(doorSprites, 140, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 3; i < 5; i++) {
			GoToXY(doorSprites, 146, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 27; i < 29; i++) {
			GoToXY(doorSprites, 146, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 4; i < 6; i++) {
			GoToXY(doorSprites, 152, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 26; i < 28; i++) {
			GoToXY(doorSprites, 152, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 5; i < 7; i++) {
			GoToXY(doorSprites, 158, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 25; i < 27; i++) {
			GoToXY(doorSprites, 158, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 6; i < 8; i++) {
			GoToXY(doorSprites, 164, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 24; i < 26; i++) {
			GoToXY(doorSprites, 164, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 10; i < 22; i++) {
			GoToXY(doorSprites, 158, i);
			WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		}

		SetConsoleTextAttribute(doorSprites, 0 * 16);

		for (int i = 4; i < 28; i++) {
			GoToXY(doorSprites, 140, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 9; i < 23; i++) {
			GoToXY(doorSprites, 142, i);
			WriteConsole(doorSprites, &"                ", 16, &output, NULL);
		}

		GoToXY(doorSprites, 158, 22);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);

		HANDLE temp = CreateConsoleScreenBuffer(
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL,
			CONSOLE_TEXTMODE_BUFFER,
			NULL);

		DrawSprite(doorSprites, 132, 0, 40, 32, temp, 0, 0);

		for (int c = 0; c < 32; c++) {
			GoToXY(doorSprites, 132, c);
			for (int d = 0; d < 32; d++) {
				WriteConsole(doorSprites, "  ", 2, NULL, NULL);
			}
		}

		DrawSprite(temp, 0, 0, 40, 32, doorSprites, 156, 0);

		// Right Side Door Open
		for (int c = 0; c < 32; c++)
			DrawSprite(doorSprites, 194 - (c * 2), 0, 2, 32, doorSprites, 198 + (c * 2), 0);

		SetConsoleTextAttribute(doorSprites, 11 * 16);
		for (int i = 10; i < 22; i++) {
			GoToXY(doorSprites, 198, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		// Top Door Open
		for (int c = 0; c < 32; c++)
			DrawSprite(doorSprites, 0, 0 + c, 64, 1, doorSprites, 66, 32 - (c + 1));

		SetConsoleTextAttribute(doorSprites, 0 * 16);

		GoToXY(doorSprites, 84, 32);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);
		GoToXY(doorSprites, 100, 32);
		WriteConsole(doorSprites, &"            ", 12, &output, NULL);

		// Bottom Door Closed

		SetConsoleTextAttribute(doorSprites, 1 * 16);

		for (int i = 46; i < 50; i++) {
			GoToXY(doorSprites, 60, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 43; i < 46; i++) {
			GoToXY(doorSprites, 58, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 40; i < 43; i++) {
			GoToXY(doorSprites, 56, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 37; i < 40; i++) {
			GoToXY(doorSprites, 54, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 34; i < 37; i++) {
			GoToXY(doorSprites, 52, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 35; i < 49; i++) {
			GoToXY(doorSprites, 16, i);
			WriteConsole(doorSprites, &"                                ", 32, &output, NULL);
		}

		for (int i = 38; i < 49; i++) {
			GoToXY(doorSprites, 14, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
			GoToXY(doorSprites, 48, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 41; i < 49; i++) {
			GoToXY(doorSprites, 12, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
			GoToXY(doorSprites, 50, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 44; i < 49; i++) {
			GoToXY(doorSprites, 10, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
			GoToXY(doorSprites, 52, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 47; i < 49; i++) {
			GoToXY(doorSprites, 8, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
			GoToXY(doorSprites, 54, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 50; i < 54; i++) {
			GoToXY(doorSprites, 0, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
			GoToXY(doorSprites, 62, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		GoToXY(doorSprites, 2, 53);
		WriteConsole(doorSprites, &"                                                            ", 60, &output, NULL);

		SetConsoleTextAttribute(doorSprites, 9 * 16);

		for (int i = 50; i < 52; i++) {
			GoToXY(doorSprites, 2, i);
			WriteConsole(doorSprites, &"                                                            ", 60, &output, NULL);
		}

		for (int i = 34; i < 38; i++) {
			GoToXY(doorSprites, 12, i);
			WriteConsole(doorSprites, "    ", 4, &output, NULL);
			GoToXY(doorSprites, 48, i);
			WriteConsole(doorSprites, "    ", 4, &output, NULL);
		}

		for (int i = 37; i < 41; i++) {
			GoToXY(doorSprites, 10, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
			GoToXY(doorSprites, 50, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		}

		for (int i = 40; i < 44; i++) {
			GoToXY(doorSprites, 8, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
			GoToXY(doorSprites, 52, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		}

		for (int i = 43; i < 47; i++) {
			GoToXY(doorSprites, 6, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
			GoToXY(doorSprites, 54, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		}

		for (int i = 46; i < 50; i++) {
			GoToXY(doorSprites, 4, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
			GoToXY(doorSprites, 56, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		}

		SetConsoleTextAttribute(doorSprites, 11 * 16);

		GoToXY(doorSprites, 28, 37);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		GoToXY(doorSprites, 28, 46);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		GoToXY(doorSprites, 26, 38);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 36, 38);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 24, 39);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 38, 39);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 22, 40);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 40, 40);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 20, 41);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 42, 41);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 20, 42);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 42, 42);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 22, 43);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 40, 43);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 24, 44);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 38, 44);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 26, 45);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		GoToXY(doorSprites, 36, 45);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		for (int i = 46; i < 50; i++) {
			GoToXY(doorSprites, 2, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 43; i < 46; i++) {
			GoToXY(doorSprites, 4, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 40; i < 43; i++) {
			GoToXY(doorSprites, 6, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 37; i < 40; i++) {
			GoToXY(doorSprites, 8, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 34; i < 37; i++) {
			GoToXY(doorSprites, 10, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		GoToXY(doorSprites, 2, 52);
		WriteConsole(doorSprites, &"                                                            ", 60, &output, NULL);

		SetConsoleTextAttribute(doorSprites, 0 * 16);

		GoToXY(doorSprites, 16, 34);
		WriteConsole(doorSprites, &"                                ", 32, &output, NULL);

		for (int i = 34; i < 36; i++) {
			GoToXY(doorSprites, 32, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 36; i < 38; i++) {
			GoToXY(doorSprites, 30, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 38; i < 40; i++) {
			GoToXY(doorSprites, 32, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 40; i < 42; i++) {
			GoToXY(doorSprites, 30, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 42; i < 44; i++) {
			GoToXY(doorSprites, 32, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 44; i < 46; i++) {
			GoToXY(doorSprites, 30, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 46; i < 48; i++) {
			GoToXY(doorSprites, 32, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		for (int i = 48; i < 50; i++) {
			GoToXY(doorSprites, 30, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		GoToXY(doorSprites, 8, 49);
		WriteConsole(doorSprites, &"                                                    ", 48, &output, NULL);

		// Top Door Closed
		for (int c = 0; c < 32; c++)
			DrawSprite(doorSprites, 0, 32 + c, 64, 1, doorSprites, 66, 66 - (c));

		// Left Door Closed
		SetConsoleTextAttribute(doorSprites, 1 * 16);
		for (int i = 34; i < 66; i++) {
			GoToXY(doorSprites, 156, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		GoToXY(doorSprites, 158, 34);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 158, 65);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 164, 64);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		GoToXY(doorSprites, 172, 63);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 178, 62);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 184, 61);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 190, 60);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		for (int i = 37; i < 62; i++) {
			GoToXY(doorSprites, 166, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		}

		for (int i = 38; i < 61; i++) {
			GoToXY(doorSprites, 170, i);
			WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		}

		for (int i = 39; i < 60; i++) {
			GoToXY(doorSprites, 176, i);
			WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		}

		for (int i = 40; i < 59; i++) {
			GoToXY(doorSprites, 182, i);
			WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		}

		for (int i = 41; i < 58; i++) {
			GoToXY(doorSprites, 188, i);
			WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		}

		SetConsoleTextAttribute(doorSprites, 11 * 16);

		for (int i = 35; i < 65; i++) {
			GoToXY(doorSprites, 158, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}
		GoToXY(doorSprites, 164, 35);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		GoToXY(doorSprites, 172, 36);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 178, 37);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 184, 38);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);
		GoToXY(doorSprites, 190, 39);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		for (int i = 48; i < 52; i++) {
			GoToXY(doorSprites, 170, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		GoToXY(doorSprites, 172, 47);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 172, 52);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 174, 46);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 174, 53);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 176, 45);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 176, 54);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 178, 44);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 178, 55);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 186, 47);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 186, 52);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 184, 46);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 184, 53);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 182, 45);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		GoToXY(doorSprites, 182, 54);
		WriteConsole(doorSprites, &"  ", 2, &output, NULL);

		for (int i = 48; i < 52; i++) {
			GoToXY(doorSprites, 188, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		SetConsoleTextAttribute(doorSprites, 9 * 16);

		for (int i = 35; i < 65; i++) {
			GoToXY(doorSprites, 160, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		}

		for (int i = 36; i < 38; i++) {
			GoToXY(doorSprites, 164, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 62; i < 64; i++) {
			GoToXY(doorSprites, 164, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 37; i < 39; i++) {
			GoToXY(doorSprites, 170, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 61; i < 63; i++) {
			GoToXY(doorSprites, 170, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 38; i < 40; i++) {
			GoToXY(doorSprites, 176, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 60; i < 62; i++) {
			GoToXY(doorSprites, 176, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 39; i < 41; i++) {
			GoToXY(doorSprites, 182, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 59; i < 61; i++) {
			GoToXY(doorSprites, 182, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 40; i < 42; i++) {
			GoToXY(doorSprites, 188, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		for (int i = 58; i < 60; i++) {
			GoToXY(doorSprites, 188, i);
			WriteConsole(doorSprites, &"        ", 8, &output, NULL);
		}

		SetConsoleTextAttribute(doorSprites, 0 * 16);

		for (int i = 38; i < 62; i++) {
			GoToXY(doorSprites, 164, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		GoToXY(doorSprites, 164, 49);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 168, 50);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		GoToXY(doorSprites, 172, 49);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 176, 50);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		GoToXY(doorSprites, 180, 49);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 184, 50);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		GoToXY(doorSprites, 188, 49);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		GoToXY(doorSprites, 192, 50);
		WriteConsole(doorSprites, &"    ", 4, &output, NULL);

		for (int i = 42; i < 58; i++) {
			GoToXY(doorSprites, 194, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		// Right Side Door Closed
		for (int c = 0; c < 32; c++)
			DrawSprite(doorSprites, 194 - (c * 2), 34, 2, 32, doorSprites, 198 + (c * 2), 34);

		// Bottom Door Locked
		DrawSprite(doorSprites, 0, 32, 64, 40, doorSprites, 0, 66);

		// Left Door Locked
		DrawSprite(doorSprites, 156, 34, 40, 32, doorSprites, 156, 68);

		SetConsoleTextAttribute(doorSprites, 1 * 16);

		for (int i = 76; i < 90; i++) {
			GoToXY(doorSprites, 166, i);
			WriteConsole(doorSprites, &"                            ", 28, &output, NULL);
		}

		SetConsoleTextAttribute(doorSprites, 0 * 16);

		for (int i = 83; i < 85; i++) {
			GoToXY(doorSprites, 176, i);
			WriteConsole(doorSprites, &"              ", 14, &output, NULL);
		}

		for (int i = 82; i < 86; i++) {
			GoToXY(doorSprites, 178, i);
			WriteConsole(doorSprites, &"    ", 4, &output, NULL);
		}

		SetConsoleTextAttribute(doorSprites, 11 * 16);

		for (int i = 77; i < 91; i++) {
			GoToXY(doorSprites, 170, i);
			WriteConsole(doorSprites, &"  ", 2, &output, NULL);
		}

		GoToXY(doorSprites, 172, 77);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 172, 90);
		WriteConsole(doorSprites, &"      ", 6, &output, NULL);

		GoToXY(doorSprites, 178, 78);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		GoToXY(doorSprites, 178, 89);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		GoToXY(doorSprites, 186, 79);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		GoToXY(doorSprites, 186, 88);
		WriteConsole(doorSprites, &"        ", 8, &output, NULL);

		// Right Door Locked
		for (int c = 0; c < 32; c++)
			DrawSprite(doorSprites, 194 - (c * 2), 66, 2, 34, doorSprites, 198 + (c * 2), 66);

		// Top Door Locked
		for (int c = 0; c < 32; c++)
			DrawSprite(doorSprites, 0, 32 + c, 64, 1, doorSprites, 66, 100 - (c));

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

		// Heart Container

		SetConsoleTextAttribute(heartSprites, 4 * 16);

		for (int i = 1; i < 8; i++) {
			GoToXY(heartSprites, 52, i);
			WriteConsole(heartSprites, &"      ", 6, &output, NULL);
			GoToXY(heartSprites, 64, i);
			WriteConsole(heartSprites, &"      ", 6, &output, NULL);
		}

		for (int i = 2; i < 6; i++) {
			GoToXY(heartSprites, 50, i);
			WriteConsole(heartSprites, &"          ", 10, &output, NULL);
			GoToXY(heartSprites, 62, i);
			WriteConsole(heartSprites, &"          ", 10, &output, NULL);
		}

		for (int i = 3; i < 10; i++) {
			GoToXY(heartSprites, 56, i);
			WriteConsole(heartSprites, &"          ", 10, &output, NULL);
		}

		GoToXY(heartSprites, 54, 8);
		WriteConsole(heartSprites, &"              ", 14, &output, NULL);

		GoToXY(heartSprites, 58, 10);
		WriteConsole(heartSprites, &"      ", 6, &output, NULL);

		GoToXY(heartSprites, 60, 11);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(heartSprites, 14 * 16 + 4);

		GoToXY(heartSprites, 48, 2);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 52, 0);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 56, 0);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 60, 2);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 64, 0);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 68, 0);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 72, 2);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 72, 4);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 70, 6);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 68, 8);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 64, 10);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 60, 12);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 56, 10);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 52, 8);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 50, 6);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		GoToXY(heartSprites, 48, 4);
		WriteConsole(heartSprites, &mGrad, 2, &output, NULL);

		SetConsoleTextAttribute(heartSprites, 14 * 16);

		GoToXY(heartSprites, 48, 5);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 48, 3);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 50, 1);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 72, 5);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 72, 3);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 70, 1);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 62, 1);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 58, 1);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 66, 0);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 54, 0);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 70, 7);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 50, 7);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 66, 9);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 54, 9);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 62, 11);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

		GoToXY(heartSprites, 58, 11);
		WriteConsole(heartSprites, &"  ", 2, &output, NULL);

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

	bool LoadMoldorm() {

		SetConsoleScreenBufferSize(moldormSprites, SCREEN_SIZE);

		DWORD output;

		char mGrad = { char(177) };

		SetConsoleTextAttribute(moldormSprites, 4 * 16); // Red

		for (int i = 0; i < 10; i++) {
			GoToXY(moldormSprites, 4, i);
			WriteConsole(moldormSprites, "        ", 8, &output, NULL);
		}
		for (int i = 3; i < 7; i++) {
			GoToXY(moldormSprites, 0, i);
			WriteConsole(moldormSprites, "                ", 16, &output, NULL);
		}

		// Second Row
		GoToXY(moldormSprites, 2, 1);
		WriteConsole(moldormSprites, "  ", 2, &output, NULL);
		GoToXY(moldormSprites, 12, 1);
		WriteConsole(moldormSprites, "  ", 2, &output, NULL);

		// Third Row
		GoToXY(moldormSprites, 2, 2);
		WriteConsole(moldormSprites, "  ", 2, &output, NULL);
		GoToXY(moldormSprites, 12, 2);
		WriteConsole(moldormSprites, "  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(moldormSprites, 2, 7);
		WriteConsole(moldormSprites, "  ", 2, &output, NULL);
		GoToXY(moldormSprites, 12, 7);
		WriteConsole(moldormSprites, "  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(moldormSprites, 2, 8);
		WriteConsole(moldormSprites, "  ", 2, &output, NULL);
		GoToXY(moldormSprites, 12, 8);
		WriteConsole(moldormSprites, "  ", 2, &output, NULL);

		SetConsoleTextAttribute(moldormSprites, 14 * 16 + 4);

		GoToXY(moldormSprites, 6, 2);
		WriteConsole(moldormSprites, &mGrad, 4, &output, NULL);

		for (int i = 3; i < 7; i++) {
			GoToXY(moldormSprites, 4, i);
			WriteConsole(moldormSprites, &mGrad, 8, &output, NULL);
		}

		GoToXY(moldormSprites, 6, 7);
		WriteConsole(moldormSprites, &mGrad, 4, &output, NULL);

		SetConsoleTextAttribute(moldormSprites, 15 * 16);

		for (int i = 4; i < 6; i++) {
			GoToXY(moldormSprites, 6, i);
			WriteConsole(moldormSprites, &"    ", 4, &output, NULL);
		}

		return true;
	}

	bool LoadGoriya() {

		SetConsoleScreenBufferSize(goriyaSprites, SCREEN_SIZE);

		DWORD output;

		// Blue Front Facing One Foot
		SetConsoleTextAttribute(goriyaSprites, 11 * 16);

		// First Row
		GoToXY(goriyaSprites, 0, 0);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 18, 0);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(goriyaSprites, 4, 1);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 18, 1);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Fifth Row
		GoToXY(goriyaSprites, 10, 4);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Eighth Row
		GoToXY(goriyaSprites, 6, 7);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 18, 7);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(goriyaSprites, 2, 8);
		WriteConsole(goriyaSprites, &"                  ", 18, &output, NULL);

		// Tenth Row
		GoToXY(goriyaSprites, 2, 9);
		WriteConsole(goriyaSprites, &"                ", 16, &output, NULL);

		// Eleventh Row
		GoToXY(goriyaSprites, 4, 10);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 16, 10);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(goriyaSprites, 2, 11);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(goriyaSprites, 2, 12);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 16, 12);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Fourteenth Row
		GoToXY(goriyaSprites, 4, 13);
		WriteConsole(goriyaSprites, &"                    ", 20, &output, NULL);

		SetConsoleTextAttribute(goriyaSprites, 1 * 16);

		// Second Row
		GoToXY(goriyaSprites, 8, 1);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);

		// Third Row
		GoToXY(goriyaSprites, 8, 2);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);

		// Fourth Row
		GoToXY(goriyaSprites, 6, 3);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 12, 3);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 18, 3);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(goriyaSprites, 4, 4);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 16, 4);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Sixth Row
		GoToXY(goriyaSprites, 2, 5);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 20, 5);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(goriyaSprites, 0, 6);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 22, 6);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(goriyaSprites, 0, 7);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 8, 7);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 22, 7);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(goriyaSprites, 0, 8);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 20, 8);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(goriyaSprites, 0, 9);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 22, 9);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Eleventh Row
		GoToXY(goriyaSprites, 2, 10);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 10, 10);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 24, 10);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(goriyaSprites, 4, 11);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 14, 11);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 24, 11);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(goriyaSprites, 10, 12);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Fifteenth Row
		GoToXY(goriyaSprites, 4, 14);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 16, 14);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Sixteenth Row
		GoToXY(goriyaSprites, 4, 15);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(goriyaSprites, 15 * 16);

		// Fourth Row
		GoToXY(goriyaSprites, 8, 3);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 14, 3);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(goriyaSprites, 6, 5);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);

		// Seventh Row
		GoToXY(goriyaSprites, 4, 6);
		WriteConsole(goriyaSprites, &"                  ", 18, &output, NULL);

		// Eighth Row
		GoToXY(goriyaSprites, 4, 7);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 20, 7);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(goriyaSprites, 18, 9);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Eleventh Row
		GoToXY(goriyaSprites, 18, 10);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(goriyaSprites, 12, 11);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 18, 11);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(goriyaSprites, 20, 12);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Blue Front Facing Other Foot
		for (int c = 0; c < 13; c++)
			DrawSprite(goriyaSprites, 24 - (c * 2), 0, 2, 16, goriyaSprites, 0 + (c * 2), 18);

		// Blue Facing Left Standing
		SetConsoleTextAttribute(goriyaSprites, 1 * 16);

		GoToXY(goriyaSprites, 36, 0);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 32, 1);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 30, 2);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);
		GoToXY(goriyaSprites, 32, 3);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);
		GoToXY(goriyaSprites, 38, 4);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 40, 5);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 30, 6);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 40, 6);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 34, 7);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 40, 8);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 30, 9);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 46, 9);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 30, 10);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 46, 10);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 30, 11);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 38, 14);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 36, 15);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);

		SetConsoleTextAttribute(goriyaSprites, 11 * 16);

		GoToXY(goriyaSprites, 42, 0);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 40, 1);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 28, 3);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 48, 5);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 44, 6);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 32, 7);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 40, 7);
		WriteConsole(goriyaSprites, &"            ", 12, &output, NULL);
		GoToXY(goriyaSprites, 32, 8);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 48, 8);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 32, 9);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 50, 9);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 50, 10);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 32, 11);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 46, 11);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 30, 12);
		WriteConsole(goriyaSprites, &"                      ", 22, &output, NULL);
		GoToXY(goriyaSprites, 32, 13);
		WriteConsole(goriyaSprites, &"                ", 16, &output, NULL);

		SetConsoleTextAttribute(goriyaSprites, 15 * 16);

		GoToXY(goriyaSprites, 32, 2);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 30, 4);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 30, 5);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 38, 6);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 40, 9);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		for (int i = 10; i < 12; i++) {
			GoToXY(goriyaSprites, 38, i);
			WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		}

		// Blue Facing Right Standing
		for (int c = 0; c < 13; c++)
			DrawSprite(goriyaSprites, 52 - (c * 2), 0, 2, 16, goriyaSprites, 56 + (c * 2), 0);

		// Blue Facing Back One Foot

		SetConsoleTextAttribute(goriyaSprites, 1 * 16);

		for (int i = 1; i < 5; i++) {
			GoToXY(goriyaSprites, 92, i);
			WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		}

		GoToXY(goriyaSprites, 90, 3);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);

		for (int i = 4; i < 6; i++) {
			GoToXY(goriyaSprites, 88, i);
			WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
			GoToXY(goriyaSprites, 102, i);
			WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		}

		GoToXY(goriyaSprites, 106, 6);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 106, 7);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 108, 8);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 108, 9);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 106, 10);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		for (int i = 7; i < 11; i++) {
			GoToXY(goriyaSprites, 88, i);
			WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		}
		for (int i = 8; i < 12; i++) {
			GoToXY(goriyaSprites, 86, i);
			WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		}
		GoToXY(goriyaSprites, 90, 11);
		WriteConsole(goriyaSprites, &"                ", 16, &output, NULL);
		GoToXY(goriyaSprites, 88, 14);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		for (int i = 14; i < 16; i++) {
			GoToXY(goriyaSprites, 100, i);
			WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		}

		SetConsoleTextAttribute(goriyaSprites, 11 * 16);

		GoToXY(goriyaSprites, 84, 0);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 88, 1);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 102, 0);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 102, 1);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		for (int i = 5; i < 11; i++) {
			GoToXY(goriyaSprites, 92, i);
			WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		}
		for (int i = 6; i < 11; i++) {
			GoToXY(goriyaSprites, 90, i);
			WriteConsole(goriyaSprites, &"                ", 16, &output, NULL);
		}
		for (int i = 8; i < 10; i++) {
			GoToXY(goriyaSprites, 106, i);
			WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		}
		GoToXY(goriyaSprites, 88, 11);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 106, 11);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 86, 12);
		WriteConsole(goriyaSprites, &"                      ", 22, &output, NULL);
		GoToXY(goriyaSprites, 88, 13);
		WriteConsole(goriyaSprites, &"                  ", 18, &output, NULL);

		SetConsoleTextAttribute(goriyaSprites, 15 * 16);

		GoToXY(goriyaSprites, 108, 6);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 106, 5);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Blue Facing Back Other Foot
		for (int c = 0; c < 13; c++)
			DrawSprite(goriyaSprites, 108 - (c * 2), 0, 2, 16, goriyaSprites, 84 + (c * 2), 18);

		// Blue Facing Left Walking

		SetConsoleTextAttribute(goriyaSprites, 1 * 16);

		GoToXY(goriyaSprites, 38, 18);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 34, 19);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 32, 20);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 38, 20);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 34, 21);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);
		GoToXY(goriyaSprites, 40, 22);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 42, 23);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 32, 24);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 42, 24);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 36, 25);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 34, 26);
		WriteConsole(goriyaSprites, &"            ", 12, &output, NULL);
		GoToXY(goriyaSprites, 34, 27);
		WriteConsole(goriyaSprites, &"            ", 12, &output, NULL);
		GoToXY(goriyaSprites, 38, 28);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 48, 29);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 30, 30);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 48, 30);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 28, 31);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 44, 31);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);

		SetConsoleTextAttribute(goriyaSprites, 11 * 16);

		GoToXY(goriyaSprites, 44, 18);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 42, 19);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 30, 21);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 50, 23);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 46, 24);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 34, 25);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 42, 25);
		WriteConsole(goriyaSprites, &"            ", 12, &output, NULL);
		for (int i = 26; i < 28; i++) {
			GoToXY(goriyaSprites, 46, i);
			WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		}
		GoToXY(goriyaSprites, 32, 28);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 44, 28);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 32, 29);
		WriteConsole(goriyaSprites, &"                ", 16, &output, NULL);
		GoToXY(goriyaSprites, 34, 30);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);

		SetConsoleTextAttribute(goriyaSprites, 15 * 16);

		GoToXY(goriyaSprites, 34, 20);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 30, 22);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 30, 23);
		WriteConsole(goriyaSprites, &"            ", 12, &output, NULL);
		GoToXY(goriyaSprites, 40, 24);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 28, 26);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 28, 27);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 30, 28);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Blue Facing Right Walking
		for (int c = 0; c < 13; c++)
			DrawSprite(goriyaSprites, 52 - (c * 2), 18, 2, 16, goriyaSprites, 56 + (c * 2), 18);

		// Red Front Facing One Foot
		SetConsoleTextAttribute(goriyaSprites, 14 * 16 + 4);

		char mGrad = { (char)177 };

		// First Row
		GoToXY(goriyaSprites, 0 + 114, 0);
		for (int c = 0; c < 8; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 18 + 114, 0);
		for (int c = 0; c < 8; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		// Second Row
		GoToXY(goriyaSprites, 4 + 114, 1);
		for (int c = 0; c < 4; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 18 + 114, 1);
		for (int c = 0; c < 4; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		// Fifth Row
		GoToXY(goriyaSprites, 10 + 114, 4);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		// Eighth Row
		GoToXY(goriyaSprites, 6 + 114, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 18 + 114, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		// Ninth Row
		GoToXY(goriyaSprites, 2 + 114, 8);
		for (int c = 0; c < 18; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		// Tenth Row
		GoToXY(goriyaSprites, 2 + 114, 9);
		for (int c = 0; c < 16; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		// Eleventh Row
		GoToXY(goriyaSprites, 4 + 114, 10);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 16 + 114, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		// Twelfth Row
		GoToXY(goriyaSprites, 2 + 114, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		// Thirteenth Row
		GoToXY(goriyaSprites, 2 + 114, 12);
		for (int c = 0; c < 8; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 16 + 114, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		// Fourteenth Row
		GoToXY(goriyaSprites, 4 + 114, 13);
		for (int c = 0; c < 20; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(goriyaSprites, 4 * 16);

		// Second Row
		GoToXY(goriyaSprites, 8 + 114, 1);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);

		// Third Row
		GoToXY(goriyaSprites, 8 + 114, 2);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);

		// Fourth Row
		GoToXY(goriyaSprites, 6 + 114, 3);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 12 + 114, 3);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 18 + 114, 3);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(goriyaSprites, 4 + 114, 4);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 16 + 114, 4);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Sixth Row
		GoToXY(goriyaSprites, 2 + 114, 5);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 20 + 114, 5);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(goriyaSprites, 0 + 114, 6);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 22 + 114, 6);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(goriyaSprites, 0 + 114, 7);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 8 + 114, 7);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 22 + 114, 7);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(goriyaSprites, 0 + 114, 8);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 20 + 114, 8);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(goriyaSprites, 0 + 114, 9);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 22 + 114, 9);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Eleventh Row
		GoToXY(goriyaSprites, 2 + 114, 10);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 10 + 114, 10);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 24 + 114, 10);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(goriyaSprites, 4 + 114, 11);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 14 + 114, 11);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 24 + 114, 11);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Thirteenth Row
		GoToXY(goriyaSprites, 10 + 114, 12);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Fifteenth Row
		GoToXY(goriyaSprites, 4 + 114, 14);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 16 + 114, 14);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Sixteenth Row
		GoToXY(goriyaSprites, 4 + 114, 15);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(goriyaSprites, 15 * 16);

		// Fourth Row
		GoToXY(goriyaSprites, 8 + 114, 3);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 14 + 114, 3);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Sixth Row
		GoToXY(goriyaSprites, 6 + 114, 5);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);

		// Seventh Row
		GoToXY(goriyaSprites, 4 + 114, 6);
		WriteConsole(goriyaSprites, &"                  ", 18, &output, NULL);

		// Eighth Row
		GoToXY(goriyaSprites, 4 + 114, 7);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 20 + 114, 7);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Tenth Row
		GoToXY(goriyaSprites, 18 + 114, 9);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Eleventh Row
		GoToXY(goriyaSprites, 18 + 114, 10);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(goriyaSprites, 12 + 114, 11);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 18 + 114, 11);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);

		// Thirteenth Row
		GoToXY(goriyaSprites, 20 + 114, 12);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Red Front Facing Other Foot
		for (int c = 0; c < 13; c++)
			DrawSprite(goriyaSprites, 24 + 114 - (c * 2), 0, 2, 16, goriyaSprites, 0 + 114 + (c * 2), 18);

		// Red Facing Left Standing
		SetConsoleTextAttribute(goriyaSprites, 4 * 16);

		GoToXY(goriyaSprites, 36 + 114, 0);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 32 + 114, 1);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 2);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);
		GoToXY(goriyaSprites, 32 + 114, 3);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);
		GoToXY(goriyaSprites, 38 + 114, 4);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 40 + 114, 5);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 6);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 40 + 114, 6);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 34 + 114, 7);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 40 + 114, 8);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 9);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 46 + 114, 9);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 10);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 46 + 114, 10);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 11);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 38 + 114, 14);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 36 + 114, 15);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);

		SetConsoleTextAttribute(goriyaSprites, 14 * 16 + 4);

		GoToXY(goriyaSprites, 42 + 114, 0);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 40 + 114, 1);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 28 + 114, 3);
		for (int c = 0; c < 4; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 48 + 114, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 44 + 114, 6);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 32 + 114, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 40 + 114, 7);
		for (int c = 0; c < 12; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 32 + 114, 8);
		for (int c = 0; c < 8; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 48 + 114, 8);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 32 + 114, 9);
		for (int c = 0; c < 8; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 50 + 114, 9);
		for (int c = 0; c < 4; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 50 + 114, 10);
		for (int c = 0; c < 4; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 32 + 114, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 46 + 114, 11);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 30 + 114, 12);
		for (int c = 0; c < 22; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 32 + 114, 13);
		for (int c = 0; c < 16; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(goriyaSprites, 15 * 16);

		GoToXY(goriyaSprites, 32 + 114, 2);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 4);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 5);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 38 + 114, 6);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 40 + 114, 9);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		for (int i = 10; i < 12; i++) {
			GoToXY(goriyaSprites, 38 + 114, i);
			WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		}

		// Red Facing Right Standing
		for (int c = 0; c < 13; c++)
			DrawSprite(goriyaSprites, 52 + 114 - (c * 2), 0, 2, 16, goriyaSprites, 56 + 114 + (c * 2), 0);

		// Red Facing Back One Foot

		SetConsoleTextAttribute(goriyaSprites, 4 * 16);

		for (int i = 1; i < 5; i++) {
			GoToXY(goriyaSprites, 92 + 114, i);
			WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		}

		GoToXY(goriyaSprites, 90 + 114, 3);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);

		for (int i = 4; i < 6; i++) {
			GoToXY(goriyaSprites, 88 + 114, i);
			WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
			GoToXY(goriyaSprites, 102 + 114, i);
			WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		}

		GoToXY(goriyaSprites, 106 + 114, 6);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 106 + 114, 7);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 108 + 114, 8);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 108 + 114, 9);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 106 + 114, 10);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		for (int i = 7; i < 11; i++) {
			GoToXY(goriyaSprites, 88 + 114, i);
			WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		}
		for (int i = 8; i < 12; i++) {
			GoToXY(goriyaSprites, 86 + 114, i);
			WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		}
		GoToXY(goriyaSprites, 90 + 114, 11);
		WriteConsole(goriyaSprites, &"                ", 16, &output, NULL);
		GoToXY(goriyaSprites, 88 + 114, 14);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		for (int i = 14; i < 16; i++) {
			GoToXY(goriyaSprites, 100 + 114, i);
			WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		}

		SetConsoleTextAttribute(goriyaSprites, 14 * 16 + 4);

		GoToXY(goriyaSprites, 84 + 114, 0);
		for (int c = 0; c < 8; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 88 + 114, 1);
		for (int c = 0; c < 4; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 102 + 114, 0);
		for (int c = 0; c < 8; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 102 + 114, 1);
		for (int c = 0; c < 4; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 5; i < 11; i++) {
			GoToXY(goriyaSprites, 92 + 114, i);
			for (int c = 0; c < 10; c++) {
				WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 6; i < 11; i++) {
			GoToXY(goriyaSprites, 90 + 114, i);
			for (int c = 0; c < 16; c++) {
				WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 8; i < 10; i++) {
			GoToXY(goriyaSprites, 106 + 114, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(goriyaSprites, 88 + 114, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 106 + 114, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 86 + 114, 12);
		for (int c = 0; c < 22; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 88 + 114, 13);
		for (int c = 0; c < 18; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(goriyaSprites, 15 * 16);

		GoToXY(goriyaSprites, 108 + 114, 6);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 106 + 114, 5);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);

		// Red Facing Back Other Foot
		for (int c = 0; c < 13; c++)
			DrawSprite(goriyaSprites, 108 + 114 - (c * 2), 0, 2, 16, goriyaSprites, 84 + 114 + (c * 2), 18);

		// Red Facing Left Walking

		SetConsoleTextAttribute(goriyaSprites, 4 * 16);

		GoToXY(goriyaSprites, 38 + 114, 18);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 34 + 114, 19);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 32 + 114, 20);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 38 + 114, 20);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 34 + 114, 21);
		WriteConsole(goriyaSprites, &"              ", 14, &output, NULL);
		GoToXY(goriyaSprites, 40 + 114, 22);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 42 + 114, 23);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 32 + 114, 24);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);
		GoToXY(goriyaSprites, 42 + 114, 24);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 36 + 114, 25);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 34 + 114, 26);
		WriteConsole(goriyaSprites, &"            ", 12, &output, NULL);
		GoToXY(goriyaSprites, 34 + 114, 27);
		WriteConsole(goriyaSprites, &"            ", 12, &output, NULL);
		GoToXY(goriyaSprites, 38 + 114, 28);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 48 + 114, 29);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 30);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 48 + 114, 30);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 28 + 114, 31);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 44 + 114, 31);
		WriteConsole(goriyaSprites, &"        ", 8, &output, NULL);

		SetConsoleTextAttribute(goriyaSprites, 14 * 16 + 4);

		GoToXY(goriyaSprites, 44 + 114, 18);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 42 + 114, 19);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 30 + 114, 21);
		for (int c = 0; c < 4; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 50 + 114, 23);
		for (int c = 0; c < 2; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 46 + 114, 24);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 34 + 114, 25);
		for (int c = 0; c < 2; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 42 + 114, 25);
		for (int c = 0; c < 12; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 26; i < 28; i++) {
			GoToXY(goriyaSprites, 46 + 114, i);
			for (int c = 0; c < 8; c++) {
				WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(goriyaSprites, 32 + 114, 28);
		for (int c = 0; c < 6; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 44 + 114, 28);
		for (int c = 0; c < 8; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 32 + 114, 29);
		for (int c = 0; c < 16; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(goriyaSprites, 34 + 114, 30);
		for (int c = 0; c < 14; c++) {
			WriteConsole(goriyaSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(goriyaSprites, 15 * 16);

		GoToXY(goriyaSprites, 34 + 114, 20);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 22);
		WriteConsole(goriyaSprites, &"          ", 10, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 23);
		WriteConsole(goriyaSprites, &"            ", 12, &output, NULL);
		GoToXY(goriyaSprites, 40 + 114, 24);
		WriteConsole(goriyaSprites, &"  ", 2, &output, NULL);
		GoToXY(goriyaSprites, 28 + 114, 26);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 28 + 114, 27);
		WriteConsole(goriyaSprites, &"      ", 6, &output, NULL);
		GoToXY(goriyaSprites, 30 + 114, 28);
		WriteConsole(goriyaSprites, &"    ", 4, &output, NULL);

		// Blue Facing Right Walking
		for (int c = 0; c < 13; c++)
			DrawSprite(goriyaSprites, 52 + 114 - (c * 2), 18, 2, 16, goriyaSprites, 56 + 114 + (c * 2), 18);

		return true;
	}

	bool LoadOldman() {

		SetConsoleScreenBufferSize(oldmanSprites, SCREEN_SIZE);

		DWORD output;

		SetConsoleTextAttribute(oldmanSprites, 4 * 16 + 14);

		char mGrad = { (char)177 };

		GoToXY(oldmanSprites, 10, 0);
		for (int c = 0; c < 12; c++) {
			WriteConsole(oldmanSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(oldmanSprites, 10, 1);
		for (int c = 0; c < 12; c++) {
			WriteConsole(oldmanSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(oldmanSprites, 8, 2);
		for (int c = 0; c < 16; c++) {
			WriteConsole(oldmanSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(oldmanSprites, 8, 3);
		for (int c = 0; c < 16; c++) {
			WriteConsole(oldmanSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(oldmanSprites, 12, 4);
		for (int c = 0; c < 8; c++) {
			WriteConsole(oldmanSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 8; i < 11; i++) {
			GoToXY(oldmanSprites, 0, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(oldmanSprites, &mGrad, 1, &output, NULL);
			}
			GoToXY(oldmanSprites, 30, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(oldmanSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(oldmanSprites, 10, 15);
		for (int c = 0; c < 4; c++) {
			WriteConsole(oldmanSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(oldmanSprites, 18, 15);
		for (int c = 0; c < 4; c++) {
			WriteConsole(oldmanSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(oldmanSprites, 4 * 16);

		GoToXY(oldmanSprites, 8, 4);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 22, 4);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 6, 5);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 24, 5);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 4, 6);
		WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
		GoToXY(oldmanSprites, 24, 6);
		WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
		for (int i = 7; i < 13; i++) {
			GoToXY(oldmanSprites, 2, i);
			WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
			GoToXY(oldmanSprites, 26, i);
			WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
		}
		for (int i = 9; i < 13; i++) {
			GoToXY(oldmanSprites, 6, i);
			WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
			GoToXY(oldmanSprites, 24, i);
			WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		}
		GoToXY(oldmanSprites, 10, 10);
		WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
		GoToXY(oldmanSprites, 18, 10);
		WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
		GoToXY(oldmanSprites, 10, 11);
		WriteConsole(oldmanSprites, &"            ", 12, &output, NULL);
		GoToXY(oldmanSprites, 10, 12);
		WriteConsole(oldmanSprites, &"            ", 12, &output, NULL);
		GoToXY(oldmanSprites, 4, 13);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 26, 13);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 8, 13);
		WriteConsole(oldmanSprites, &"                ", 16, &output, NULL);
		GoToXY(oldmanSprites, 8, 14);
		WriteConsole(oldmanSprites, &"                ", 16, &output, NULL);
		GoToXY(oldmanSprites, 6, 15);
		WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
		GoToXY(oldmanSprites, 14, 15);
		WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
		GoToXY(oldmanSprites, 22, 15);
		WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);

		for (int i = 7; i < 10; i++) {
			GoToXY(oldmanSprites, 10, i);
			WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
			GoToXY(oldmanSprites, 20, i);
			WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		}
		for (int i = 8; i < 10; i++) {
			GoToXY(oldmanSprites, 8, i);
			WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
			GoToXY(oldmanSprites, 22, i);
			WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		}

		SetConsoleTextAttribute(oldmanSprites, 15 * 16);

		GoToXY(oldmanSprites, 8, 1);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 12, 1);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 18, 1);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 22, 1);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 10, 4);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 20, 4);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		for (int i = 5; i < 7; i++) {
			GoToXY(oldmanSprites, 8, i);
			WriteConsole(oldmanSprites, &"                ", 16, &output, NULL);
		}
		for (int i = 7; i < 10; i++) {
			GoToXY(oldmanSprites, 12, i);
			WriteConsole(oldmanSprites, &"        ", 8, &output, NULL);
		}
		GoToXY(oldmanSprites, 14, 10);
		WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
		GoToXY(oldmanSprites, 22, 7);
		WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
		GoToXY(oldmanSprites, 6, 7);
		WriteConsole(oldmanSprites, &"    ", 4, &output, NULL);
		GoToXY(oldmanSprites, 6, 8);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		GoToXY(oldmanSprites, 24, 8);
		WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);

		SetConsoleTextAttribute(oldmanSprites, 0 * 16);

		for (int i = 2; i < 4; i++) {
			GoToXY(oldmanSprites, 12, i);
			WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
			GoToXY(oldmanSprites, 18, i);
			WriteConsole(oldmanSprites, &"  ", 2, &output, NULL);
		}

		GoToXY(oldmanSprites, 12, 6);
		WriteConsole(oldmanSprites, &"        ", 8, &output, NULL);
		return true;
	}

	bool LoadFire() {

		DWORD output;

		SetConsoleScreenBufferSize(fireSprites, SCREEN_SIZE);

		char mGrad = { (char)177 };

		SetConsoleTextAttribute(fireSprites, 4 * 16 + 6);
		GoToXY(fireSprites, 4, 0);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 12, 0);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 4, 1);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 1; i < 9; i++) {
			GoToXY(fireSprites, 14, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 2; i < 5; i++) {
			GoToXY(fireSprites, 10, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 3; i < 8; i++) {
			GoToXY(fireSprites, 12, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 6; i < 10; i++) {
			GoToXY(fireSprites, 4, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(fireSprites, 2, 6);
		for (int c = 0; c < 8; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 2, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 6, 5);
		for (int c = 0; c < 4; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 6, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 7; i < 11; i++) {
			GoToXY(fireSprites, 0, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 9; i < 13; i++) {
			GoToXY(fireSprites, 2, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 13; i < 15; i++) {
			GoToXY(fireSprites, 4, i);
			for (int c = 0; c < 4; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(fireSprites, 8, 14);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 8, 15);
		for (int c = 0; c < 14; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 10, 7);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 10, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 10; i < 13; i++) {
			GoToXY(fireSprites, 4, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(fireSprites, 6, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 20, 14);
		for (int c = 0; c < 8; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 2; i < 7; i++) {
			GoToXY(fireSprites, 16, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 3; i < 5; i++) {
			GoToXY(fireSprites, 18, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 6; i < 9; i++) {
			GoToXY(fireSprites, 18, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 12; i < 14; i++) {
			GoToXY(fireSprites, 24, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 10; i < 12; i++) {
			GoToXY(fireSprites, 26, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(fireSprites, 26, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 30, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 6; i < 9; i++) {
			GoToXY(fireSprites, 24, i);
			for (int c = 0; c < 6; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 2; i < 8; i++) {
			GoToXY(fireSprites, 22, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(fireSprites, 20, 4);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 20, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 26, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 26, 3);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 26, 2);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 20, 1);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 12, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 22, 10);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}

		SetConsoleTextAttribute(fireSprites, 4 * 16 + 14);

		GoToXY(fireSprites, 24, 1);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 4, 3);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 18, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 28, 5);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 10, 6);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 6; i < 11; i++) {
			GoToXY(fireSprites, 20, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		GoToXY(fireSprites, 12, 8);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 10, 14);
		for (int c = 0; c < 10; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 8, 13);
		for (int c = 0; c < 4; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 20, 13);
		for (int c = 0; c < 4; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 20, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 22, 11);
		for (int c = 0; c < 4; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 6, 11);
		for (int c = 0; c < 4; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 6, 12);
		for (int c = 0; c < 4; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 10, 11);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 8, 10);
		for (int c = 0; c < 8; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		GoToXY(fireSprites, 10, 9);
		for (int c = 0; c < 2; c++) {
			WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
		}
		for (int i = 9; i < 12; i++) {
			GoToXY(fireSprites, 14, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 7; i < 10; i++) {
			GoToXY(fireSprites, 16, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 9; i < 12; i++) {
			GoToXY(fireSprites, 18, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 8; i < 10; i++) {
			GoToXY(fireSprites, 22, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 9; i < 11; i++) {
			GoToXY(fireSprites, 24, i);
			for (int c = 0; c < 2; c++) {
				WriteConsole(fireSprites, &mGrad, 1, &output, NULL);
			}
		}

		SetConsoleTextAttribute(fireSprites, 15 * 16);

		GoToXY(fireSprites, 12, 11);
		WriteConsole(fireSprites, &"  ", 2, &output, NULL);
		GoToXY(fireSprites, 16, 10);
		WriteConsole(fireSprites, &"  ", 2, &output, NULL);
		GoToXY(fireSprites, 16, 11);
		WriteConsole(fireSprites, &"  ", 2, &output, NULL);
		GoToXY(fireSprites, 20, 11);
		WriteConsole(fireSprites, &"  ", 2, &output, NULL);
		GoToXY(fireSprites, 10, 12);
		WriteConsole(fireSprites, &"          ", 10, &output, NULL);
		GoToXY(fireSprites, 12, 13);
		WriteConsole(fireSprites, &"        ", 8, &output, NULL);

		return true;
	}

	bool LoadBombableWall() {

		DWORD output;

		SetConsoleScreenBufferSize(bombablewallSprites, SCREEN_SIZE);

		SetConsoleTextAttribute(bombablewallSprites, 9 * 16);
		for (int i = 0; i < 16; i++) {
			GoToXY(bombablewallSprites, 0, i);
			WriteConsole(bombablewallSprites, &"                                                                                                                                        ", 132, &output, NULL);
		}

		// Top
		SetConsoleTextAttribute(bombablewallSprites, 0 * 16);
		for (int i = 8; i < 16; i++) {
			GoToXY(bombablewallSprites, 0, i);
			WriteConsole(bombablewallSprites, &"                                ", 32, &output, NULL);
		}
		for (int i = 6; i < 8; i++) {
			GoToXY(bombablewallSprites, 2, i);
			WriteConsole(bombablewallSprites, &"                            ", 28, &output, NULL);
		}
		GoToXY(bombablewallSprites, 4, 5);
		WriteConsole(bombablewallSprites, &"                        ", 24, &output, NULL);
		GoToXY(bombablewallSprites, 6, 4);
		WriteConsole(bombablewallSprites, &"                    ", 20, &output, NULL);
		GoToXY(bombablewallSprites, 10, 3);
		WriteConsole(bombablewallSprites, &"            ", 12, &output, NULL);
		GoToXY(bombablewallSprites, 2, 0);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 6, 0);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 18, 0);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 4, 1);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 12, 1);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 16, 1);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 24, 1);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 30, 1);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 0, 2);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 6, 2);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 14, 2);
		WriteConsole(bombablewallSprites, &"    ", 4, &output, NULL);
		GoToXY(bombablewallSprites, 22, 2);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 30, 2);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 0, 3);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 6, 3);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 30, 3);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 2, 4);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 28, 4);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);

		// Bottom
		for (int c = 0; c < 16; c++)
			DrawSprite(bombablewallSprites, 0, 15 - c, 32, 1, bombablewallSprites, 34, 0 + c);

		// Left
		for (int i = 0; i < 16; i++) {
			GoToXY(bombablewallSprites, 68, i);
			WriteConsole(bombablewallSprites, &"                ", 16, &output, NULL);
		}
		for (int i = 1; i < 15; i++) {
			GoToXY(bombablewallSprites, 84, i);
			WriteConsole(bombablewallSprites, &"    ", 4, &output, NULL);
		}
		for (int i = 2; i < 14; i++) {
			GoToXY(bombablewallSprites, 88, i);
			WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		}
		for (int i = 3; i < 13; i++) {
			GoToXY(bombablewallSprites, 90, i);
			WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		}
		for (int i = 5; i < 11; i++) {
			GoToXY(bombablewallSprites, 92, i);
			WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		}
		GoToXY(bombablewallSprites, 88, 0);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 94, 0);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 92, 1);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 92, 2);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 98, 5);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 96, 6);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 96, 7);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 94, 8);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 94, 9);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 96, 10);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 92, 13);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 94, 14);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);
		GoToXY(bombablewallSprites, 96, 15);
		WriteConsole(bombablewallSprites, &"  ", 2, &output, NULL);

		// Right
		for (int c = 0; c < 16; c++)
			DrawSprite(bombablewallSprites, 66 + 34 - (c * 2), 0, 2, 16, bombablewallSprites, 68 + 32 + (c * 2), 0);

		return true;
	}

	bool LoadTriforce() {

		char mGrad = { (char)177 };

		DWORD output;

		SetConsoleScreenBufferSize(triforceSprites, SCREEN_SIZE);

		// Yellow Triforce
		SetConsoleTextAttribute(triforceSprites, 14 * 16 + 6);
		for (int i = 0; i < 2; i++) {
			GoToXY(triforceSprites, 8, i);
			for (int c = 0; c < 4; c++) {
				WriteConsole(triforceSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 2; i < 4; i++) {
			GoToXY(triforceSprites, 6, i);
			for (int c = 0; c < 8; c++) {
				WriteConsole(triforceSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 4; i < 6; i++) {
			GoToXY(triforceSprites, 4, i);
			for (int c = 0; c < 12; c++) {
				WriteConsole(triforceSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 6; i < 8; i++) {
			GoToXY(triforceSprites, 2, i);
			for (int c = 0; c < 16; c++) {
				WriteConsole(triforceSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 8; i < 10; i++) {
			GoToXY(triforceSprites, 0, i);
			for (int c = 0; c < 20; c++) {
				WriteConsole(triforceSprites, &mGrad, 1, &output, NULL);
			}
		}

		// Blue Triforce
		SetConsoleTextAttribute(triforceSprites, 9 * 16 + 1);
		for (int i = 0; i < 2; i++) {
			GoToXY(triforceSprites, 30, i);
			for (int c = 0; c < 4; c++) {
				WriteConsole(triforceSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 2; i < 4; i++) {
			GoToXY(triforceSprites, 28, i);
			for (int c = 0; c < 8; c++) {
				WriteConsole(triforceSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 4; i < 6; i++) {
			GoToXY(triforceSprites, 26, i);
			for (int c = 0; c < 12; c++) {
				WriteConsole(triforceSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 6; i < 8; i++) {
			GoToXY(triforceSprites, 24, i);
			for (int c = 0; c < 16; c++) {
				WriteConsole(triforceSprites, &mGrad, 1, &output, NULL);
			}
		}
		for (int i = 8; i < 10; i++) {
			GoToXY(triforceSprites, 22, i);
			for (int c = 0; c < 20; c++) {
				WriteConsole(triforceSprites, &mGrad, 1, &output, NULL);
			}
		}

		return true;
	}

	bool LoadMapDoor() {

		DWORD output;

		SetConsoleScreenBufferSize(mapdoorSprites, SCREEN_SIZE);

		SetConsoleTextAttribute(mapdoorSprites, 6 * 16);
		for (int i = 0; i < 40; i++) {
			GoToXY(mapdoorSprites, 0, i);
			WriteConsole(mapdoorSprites, &"                                                                                                   ", 110, &output, NULL);
		}

		SetConsoleTextAttribute(mapdoorSprites, 0 * 16);

		// 1 Door, Left
		for (int i = 1; i < 7; i++) {
			GoToXY(mapdoorSprites, 2, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 0, 3);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 0, 4);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);

		// 1 Door, Right
		for (int i = 1; i < 7; i++) {
			GoToXY(mapdoorSprites, 20, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 32, 3);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 32, 4);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);

		// 1 Door, Up
		for (int i = 1; i < 7; i++) {
			GoToXY(mapdoorSprites, 38, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 42, 0);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);

		// 1 Door, Down
		for (int i = 1; i < 7; i++) {
			GoToXY(mapdoorSprites, 56, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 60, 7);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);

		// 2 Doors, Left and Up
		for (int i = 10; i < 16; i++) {
			GoToXY(mapdoorSprites, 2, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 0, 12);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 0, 13);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 6, 9);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);

		// 2 Doors, Right and Up
		for (int i = 10; i < 16; i++) {
			GoToXY(mapdoorSprites, 20, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 32, 12);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 32, 13);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 24, 9);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);

		// 2 Doors, Right and Down
		for (int i = 10; i < 16; i++) {
			GoToXY(mapdoorSprites, 38, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 50, 12);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 50, 13);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 42, 16);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);

		// 2 Doors, Left and Down
		for (int i = 10; i < 16; i++) {
			GoToXY(mapdoorSprites, 56, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 54, 12);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 54, 13);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 60, 16);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);

		// 2 Doors, Right and Left
		for (int i = 10; i < 16; i++) {
			GoToXY(mapdoorSprites, 74, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 72, 12);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 72, 13);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 86, 12);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 86, 13);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);

		// 2 Doors, Up and Down
		for (int i = 10; i < 16; i++) {
			GoToXY(mapdoorSprites, 90, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 94, 9);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);
		GoToXY(mapdoorSprites, 94, 16);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);

		// 3 Doors, Left, Right and Up
		for (int i = 19; i < 25; i++) {
			GoToXY(mapdoorSprites, 2, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 0, 21);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 0, 22);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 6, 18);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);
		GoToXY(mapdoorSprites, 14, 21);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 14, 22);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);

		// 3 Doors, Right, Down and Up
		for (int i = 19; i < 25; i++) {
			GoToXY(mapdoorSprites, 20, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 32, 21);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 32, 22);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 24, 18);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);
		GoToXY(mapdoorSprites, 24, 25);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);

		// 3 Doors, Left, Right and Down
		for (int i = 19; i < 25; i++) {
			GoToXY(mapdoorSprites, 38, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 50, 21);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 50, 22);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 42, 25);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);
		GoToXY(mapdoorSprites, 36, 21);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 36, 22);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);

		// 3 Doors, Left, Up and Down
		for (int i = 19; i < 25; i++) {
			GoToXY(mapdoorSprites, 56, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 54, 21);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 54, 22);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 60, 25);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);
		GoToXY(mapdoorSprites, 60, 18);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);

		// 4 Doors, All Directions
		for (int i = 28; i < 34; i++) {
			GoToXY(mapdoorSprites, 2, i);
			WriteConsole(mapdoorSprites, &"            ", 12, &output, NULL);
		}
		GoToXY(mapdoorSprites, 0, 30);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 0, 31);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 6, 27);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);
		GoToXY(mapdoorSprites, 14, 30);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 14, 31);
		WriteConsole(mapdoorSprites, &"  ", 2, &output, NULL);
		GoToXY(mapdoorSprites, 6, 34);
		WriteConsole(mapdoorSprites, &"    ", 4, &output, NULL);

		return true;
	}

	bool LoadTitle() {
		// Set screen size
		SetConsoleScreenBufferSize(titleScreen, SCREEN_SIZE);

		// Set background color
		COORD origin = { 0, 0 }; // top left corner of screen
		CONSOLE_SCREEN_BUFFER_INFO scrn;
		DWORD buff;

		GetConsoleScreenBufferInfo(titleScreen, &scrn);

		//Fills Console with 
		FillConsoleOutputCharacterA(
			titleScreen, (char) 176, scrn.dwSize.X * scrn.dwSize.Y, origin, &buff
		);

		//Returns text colors to default
		FillConsoleOutputAttribute(
			titleScreen, 14 + (12*16),
			scrn.dwSize.X * scrn.dwSize.Y, origin, &buff
		);

		//Draw Triforce
		DWORD output;
		SetConsoleTextAttribute(titleScreen, (14 * 16) + 6);

		std::string lGrad = { (char)176 };
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

	bool LoadBrick() {

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

};

SpriteSheets Sprites;