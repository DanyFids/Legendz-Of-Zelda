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

	HANDLE titleScreen = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

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

	bool LoadPlayer() {
		//anim 1 frame 1

		DWORD output;
		for (int i = 0; i < 16; i++) {
			GoToXY(playerSprites, 0, i);
			WriteConsole(playerSprites, &"                             ", 30, &output, NULL);
		}
		SetConsoleTextAttribute(playerSprites, 7);
		
		GoToXY(playerSprites, 5, 3);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Facing forward, shield
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

		SetConsoleTextAttribute(playerSprites, 4 * 16); // Red (dark brown)

		// Third Row
		GoToXY(playerSprites, 10, 2);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 18, 2);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourth Row
		GoToXY(playerSprites, 8, 3);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 16, 3);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Fifth Row
		GoToXY(playerSprites, 8, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 22, 4);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Sixth Row
		GoToXY(playerSprites, 8, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 12, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 18, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 22, 5);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Seventh Row
		GoToXY(playerSprites, 26, 6);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Eighth Row
		GoToXY(playerSprites, 14, 7);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 26, 7);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Ninth Row
		GoToXY(playerSprites, 2, 8);
		WriteConsole(playerSprites, &"          ", 10, &output, NULL);
		GoToXY(playerSprites, 24, 8);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(playerSprites, 0, 9);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 6, 9);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);
		GoToXY(playerSprites, 26, 9);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Eleventh Row
		GoToXY(playerSprites, 0, 10);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 8, 10);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 14, 10);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 28, 10);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);

		// Twelfth Row
		GoToXY(playerSprites, 0, 11);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 6, 11);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 16, 11);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

		// Thirteenth Row
		GoToXY(playerSprites, 0, 12);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);
		GoToXY(playerSprites, 6, 12);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);
		GoToXY(playerSprites, 14, 12);
		WriteConsole(playerSprites, &"    ", 4, &output, NULL);

		// Fourteenth Row
		GoToXY(playerSprites, 0, 13);
		WriteConsole(playerSprites, &"            ", 12, &output, NULL);

		// Fifteenth Row
		GoToXY(playerSprites, 12, 14);
		WriteConsole(playerSprites, &"  ", 2, &output, NULL);
		GoToXY(playerSprites, 18, 14);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

		// Sixteenth Row
		GoToXY(playerSprites, 8, 15);
		WriteConsole(playerSprites, &"      ", 6, &output, NULL);

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
		return true;
	}

	bool LoadKeese() {
		//anim 1 frame 1

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

		return true;
	}

	bool LoadRope() {

		DWORD output;


		// Facing left, tail extended
		SetConsoleTextAttribute(ropeSprites, 6 * 16); // Yellow (orange (why doesn't this exist?))

		// First Row
		GoToXY(ropeSprites, 6, 0);
		WriteConsole(ropeSprites, &"        ", 8, &output, NULL);

		// Second Row
		GoToXY(ropeSprites, 4, 1);
		WriteConsole(ropeSprites, &"  ", 2, &output, NULL);
		GoToXY(ropeSprites, 10, 1);
		WriteConsole(ropeSprites, &"      ", 6, &output, NULL);

		// Third Row
		GoToXY(ropeSprites, 10, 2);
		WriteConsole(ropeSprites, &"      ", 6, &output, NULL);

		// Fourth Row
		GoToXY(ropeSprites, 8, 3);
		WriteConsole(ropeSprites, &"          ", 10, &output, NULL);

		// Fifth Row
		GoToXY(ropeSprites, 0, 4);
		WriteConsole(ropeSprites, &"                    ", 20, &output, NULL);

		// Sixth Row
		GoToXY(ropeSprites, 8, 5);
		WriteConsole(ropeSprites, &"            ", 12, &output, NULL);

		// Seventh Row
		GoToXY(ropeSprites, 10, 6);
		WriteConsole(ropeSprites, &"          ", 10, &output, NULL);

		// Eighth Row
		GoToXY(ropeSprites, 2, 7);
		WriteConsole(ropeSprites, &"                ", 16, &output, NULL);

		// Ninth Row
		GoToXY(ropeSprites, 6, 8);
		WriteConsole(ropeSprites, &"        ", 8, &output, NULL);

		// Tenth Row
		GoToXY(ropeSprites, 10, 9);
		WriteConsole(ropeSprites, &"  ", 2, &output, NULL);

		// Eleventh Row
		GoToXY(ropeSprites, 6, 10);
		WriteConsole(ropeSprites, &"      ", 6, &output, NULL);
		GoToXY(ropeSprites, 16, 10);
		WriteConsole(ropeSprites, &"      ", 6, &output, NULL);

		// Twelfth Row
		GoToXY(ropeSprites, 6, 11);
		WriteConsole(ropeSprites, &"                  ", 18, &output, NULL);

		// Thirteenth Row
		GoToXY(ropeSprites, 4, 12);
		WriteConsole(ropeSprites, &"              ", 14, &output, NULL);
		GoToXY(ropeSprites, 22, 12);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);
		GoToXY(ropeSprites, 28, 12);
		WriteConsole(ropeSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(ropeSprites, 6, 13);
		WriteConsole(ropeSprites, &"        ", 8, &output, NULL);
		GoToXY(ropeSprites, 24, 13);
		WriteConsole(ropeSprites, &"    ", 4, &output, NULL);

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

		DWORD output;

		SetConsoleTextAttribute(swordSprites, 8 * 16); // Grey

		// First Row
		GoToXY(swordSprites, 6, 0);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		// Second Row
		GoToXY(swordSprites, 4, 1);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Third Row
		GoToXY(swordSprites, 4, 2);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fourth Row
		GoToXY(swordSprites, 4, 3);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fifth Row
		GoToXY(swordSprites, 4, 4);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Sixth Row
		GoToXY(swordSprites, 4, 5);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Seventh Row
		GoToXY(swordSprites, 4, 6);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Eighth Row
		GoToXY(swordSprites, 4, 7);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Ninth Row
		GoToXY(swordSprites, 4, 8);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Tenth Row
		GoToXY(swordSprites, 4, 9);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Eleventh Row
		GoToXY(swordSprites, 4, 10);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 10 * 16); // Green

		// Twelfth Row
		GoToXY(swordSprites, 0, 11);
		WriteConsole(swordSprites, &"              ", 14, &output, NULL);

		// Thirteenth Row
		GoToXY(swordSprites, 0, 12);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);
		GoToXY(swordSprites, 12, 12);
		WriteConsole(swordSprites, &"  ", 2, &output, NULL);

		// Fourteenth Row
		GoToXY(swordSprites, 4, 13);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Sixteenth Row
		GoToXY(swordSprites, 4, 15);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		SetConsoleTextAttribute(swordSprites, 14 * 16); // Light Yellow

		// Thirteenth Row
		GoToXY(swordSprites, 4, 12);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		// Fifteenth Row
		GoToXY(swordSprites, 4, 14);
		WriteConsole(swordSprites, &"      ", 6, &output, NULL);

		return true;
	}

	bool LoadHole() {

		DWORD output;

		SetConsoleTextAttribute(holeSprites, 0 * 16); // Black

		for (int i = 0; i < 16; i++) {
			GoToXY(holeSprites, 0, i);
			WriteConsole(holeSprites, &"                                ", 32, &output, NULL);
		}
		return true;
	}

	bool LoadFloor() {

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

		GoToXY(floorSprites, 46, 0);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 40, 1);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 36, 3);
		WriteConsole(floorSprites, &"  ", 2, &output, NULL);

		GoToXY(floorSprites, 42, 4);
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