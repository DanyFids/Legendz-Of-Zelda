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
		//draw Green

		SetConsoleTextAttribute(playerSprites, 10 * 16);
		DWORD output;
		for (int i = 0; i < 16; i++) {
			GoToXY(playerSprites, 0, i);
			WriteConsole(playerSprites, &"                             ", 30, &output, NULL);
		}
		SetConsoleTextAttribute(playerSprites, 7);
		
		GoToXY(playerSprites, 5, 3);
		WriteConsole(playerSprites, &"        ", 8, &output, NULL);

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

};

SpriteSheets Sprites;