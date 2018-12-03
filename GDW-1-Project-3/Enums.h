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
	W_BOOMERANG
};

enum ProjType {
	PT_NULL, // Base projectile
	PT_SWORD,
	PT_BEAMSWORD,
	PT_ARROW,
	PT_BOMB,
	PT_EXPLOSION,
	PT_FIREBALL,
	PT_BOOMERANG

};

enum BtnAction {
	SELECT_FILE,
	REGISTER,
	ERASE,
	END,
	CONTINUE,
	SAVE,
	RETRY
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