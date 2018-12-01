#pragma once
enum Direction {
	Down,
	Right,
	Left,
	Up
};

enum GameState {
	TITLE,
	CHARACTER_SEL,
	CHARACTER_ADD,
	CHARACTER_RMV,
	PLAY,
	INVENTORY,
	CREDITS
};

enum Weapon {
	W_BOW,
	W_BOMB,
	W_BOOM
};

enum BtnAction {
	SELECT_FILE,
	REGISTER,
	ERASE,
	END
};

enum RoomType {
	RT_DEFAULT,
	RT_START,
	RT_BOSS,
	RT_MINI_BOSS,
	RT_SECRET
};

enum EnemyType {
	ET_DEFAULT,
	ET_MOLDORM
};