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
	PT_EBOOMERANG,
	PT_BOOMERANG
};

enum EnemyType {
	ET_DEFAULT,
	ET_MOLDORM,
	ET_KEESE,
	ET_GEL
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


enum ROOM_LAYOUT {
	RL_U,
	RL_L,
	RL_D,
	RL_R,
	RL_UL,
	RL_UD,
	RL_UR,
	RL_LD,
	RL_LR,
	RL_DR,
	RL_ULD,
	RL_ULR,
	RL_UDR,
	RL_LDR,
	RL_ULDR
};