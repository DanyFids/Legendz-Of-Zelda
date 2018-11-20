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
	Bow,
	Bomb,
	Boomerang
};

enum BtnAction {
	SELECT_FILE,
	REGISTER,
	ERASE,
	END
};