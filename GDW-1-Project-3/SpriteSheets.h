#pragma once

class SpriteSheets {
public:
	HANDLE playerSprites = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);

	bool LoadPlayer() {
		//anim 1 frame 1
		//draw Green
		SetConsoleTextAttribute(playerSprites, 10);
		GoToXY(playerSprites, 10, 0);
		std::string line = { (char)219,(char)219 ,(char)219 ,(char)219 ,(char)219 ,(char)219 ,(char)219 ,(char)219, (char)219 ,(char)219 ,(char)219 ,(char)219 };
		WriteConsole(playerSprites, &line, 12, NULL, NULL);
		GoToXY(playerSprites, 8, 1);
		line = { (char)219,(char)219 ,(char)219 ,(char)219 ,(char)219 ,(char)219 ,(char)219 ,(char)219, (char)219 ,(char)219 ,(char)219 ,(char)219, (char)219 ,(char)219 ,(char)219 ,(char)219 };
		WriteConsole(playerSprites, &line, 16, NULL, NULL);
		GoToXY(playerSprites, 8, 2);
		line = { (char)219,(char)219 };
		WriteConsole(playerSprites, &line, 2, NULL, NULL);
		GoToXY(playerSprites, 22, 2);
		WriteConsole(playerSprites, &line, 2, NULL, NULL);
		GoToXY(playerSprites, 12, 4);
		WriteConsole(playerSprites, &line, 2, NULL, NULL);
		GoToXY(playerSprites, 12, 4);
		WriteConsole(playerSprites, &line, 2, NULL, NULL);


		SetConsoleTextAttribute(playerSprites, 10 * 16);
		DWORD output;
		for (int i = 0; i < 16; i++) {
			GoToXY(playerSprites, 0, i);
			WriteConsole(playerSprites, &"                             ", 30, &output, NULL);
		}

		return true;
	}
};

SpriteSheets Sprites;