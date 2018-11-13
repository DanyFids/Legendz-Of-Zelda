#pragma once

class SpriteSheets {
public:
	HANDLE playerSprites = CreateConsoleScreenBuffer(
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

	bool LoadPlayer() {
		//anim 1 frame 1

		DWORD output;

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

		SetConsoleTextAttribute(floorSprites, 1 * 16); // Blue

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

		SetConsoleTextAttribute(floorSprites, 3 * 16); // Aqua

		// First Row
		GoToXY(floorSprites, 2, 0);
		WriteConsole(floorSprites, &"                            ", 28, &output, NULL);

		for (int i = 1; i < 15; i++) {
			GoToXY(floorSprites, 0, i);
			WriteConsole(floorSprites, &"  ", 2, &output, NULL);
		}

		return true;
	}

	bool LoadWall() {

		DWORD output;

		SetConsoleScreenBufferSize(wallSprites, SCREEN_SIZE);

		//FillConsoleOutputAttribute();

		SetConsoleTextAttribute(wallSprites, 1 * 16); // Blue
		for (int i = 0, j = 46; i < 24; i++, j -= 2) {
			GoToXY(wallSprites, j, i);
			WriteConsole(wallSprites, &"  ", 2, &output, NULL);
		}

		// Second Row
		GoToXY(wallSprites, 74, 1);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Third Row
		GoToXY(wallSprites, 72, 2);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Fourth Row
		GoToXY(wallSprites, 72, 3);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

		// Fifth Row
		GoToXY(wallSprites, 38, 4);
		WriteConsole(wallSprites, &"", 450, &output, NULL);

		// Thirteenth Row
		GoToXY(wallSprites, 22, 12);
		WriteConsole(wallSprites, &"                                    ", 36, &output, NULL);

		// Fourteenth Row
		GoToXY(wallSprites, 56, 13);
		WriteConsole(wallSprites, &"  ", 2, &output, NULL);

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

};

SpriteSheets Sprites;