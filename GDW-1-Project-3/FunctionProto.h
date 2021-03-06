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
void MouseHandler(MOUSE_EVENT_RECORD e);
void ButtonHandler(BtnAction action, int extra);
void Save();

//State Functions
void ToCharacterSelect();
void ToEliminationMode();
void ToRegisterName();

//GLOBAL VARS
COORD SCREEN_SIZE;