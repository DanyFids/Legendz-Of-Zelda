#pragma once

void GoToXY(HANDLE h, int x, int y);
void SwapBuffer();
void KeyHandler(KEY_EVENT_RECORD e);
void clear();
void Draw();
void DrawScreen(HANDLE scrn);
void Update();
void ResizeWindow();
float GetTimeInSeconds();
void Load();

//GLOBAL VARS
COORD SCREEN_SIZE;