#pragma once

class SpriteSheets {
public:
	HANDLE playerSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	HANDLE enemySprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	bool LoadPlayer() {
		//anim 1 frame 1
		//draw Green

		SetConsoleTextAttribute(playerSprites, 10 * 16);
		DWORD output;
		for (int i = 0; i < 16; i++) {
			GoToXY(playerSprites, 0, i);
			WriteConsole(playerSprites, &"                             ", 30, &output, NULL);
		}

		return true;
	}

	bool LoadEnemy() {
		//anim 1 frame 1
		//draw Green

		SetConsoleTextAttribute(enemySprites, 4 * 16);
		DWORD output;
		for (int i = 0; i < 16; i++) {
			GoToXY(enemySprites, 0, i);
			WriteConsole(enemySprites, &"                             ", 30, &output, NULL);
		}

		return true;
	}
};

SpriteSheets Sprites;