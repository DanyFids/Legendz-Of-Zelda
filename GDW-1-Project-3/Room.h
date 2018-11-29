#pragma once
class Trigger {
public:
	virtual bool Check() = 0;
};

class NULL_TRIGGER: public Trigger {
public:
	bool Check() {
		return false;
	}
};

class KillTrigger: public Trigger {
private:
	std::vector<Enemy *> *HitList;
public:
	KillTrigger(std::vector<Enemy *> * h) {
		HitList = h;
	}

	bool Check() {
		if (HitList->size() <= 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Result {
public:
	virtual void Effect() = 0;
};

class NULL_RESULT : public Result{
public:
	void Effect() {};
};

class Open : public Result {
private:
	std::vector<Door> doors;
public:
	Open(std::vector<Door> d) {
		doors = d;
	}

	void Effect() {
		for (int c = 0; c < doors.size(); c++) {
			doors[c].setOpen(true);
		}
	}
};

class Puzzle {
private:
	bool solved;
	Trigger * trigger;
	std::vector<Result *> results;
public:
	Puzzle() {
		trigger = new NULL_TRIGGER;
		results = { new NULL_RESULT };
	}

	Puzzle(Trigger * t, std::vector<Result *> r) {
		trigger = t;
		results = r;
	}
	

};

class Room {
private:
	std::vector<Enemy *> SpawnList;
	Puzzle puzzle;
	HANDLE sprite_sheet;
	bool NullRoom = false;
	RoomType type;
public:
	std::vector<Enemy *> EnemyList;
	std::vector<Terrain *> TerrainList = {
		// Top Wall
		new Wall(64, 80, 176, 16),
		new Wall(272, 80, 176, 16),
		// Bottom Wall
		new Wall(64, 208, 176, 16),
		new Wall(272, 208, 176, 16),
		// Left Wall
		new Wall(32, 96, 32, 48),
		new Wall(32, 160, 32, 48),
		// Right Wall
		new Wall(448, 96, 32, 48),
		new Wall(448, 160, 32, 48)
	};

	Room() {
		NullRoom = true;
	}

	Room(std::vector<Terrain *> tl, std::vector<Enemy *> sl, Puzzle * p, RoomType t = RT_DEFAULT) {
		for (int t = 0; t < tl.size(); t++) {
			TerrainList.push_back(tl[t]);
		}
		SpawnList = sl;
		puzzle = *p;
		type = t;

		sprite_sheet = Sprites.roomSprites;
	}

	void Respawn() {
		if (EnemyList.size() <= 0) {
			for (int c = 0; c < SpawnList.size(); c++) {
				EnemyList.push_back(SpawnList[c]->Clone());
			}
		}
	}

	void Draw(HANDLE out) {
		Sprites.DrawSprite(sprite_sheet, (514 * type), 0, 512, 176, out, 0, 64);
	}

	bool IsNull() {
		return NullRoom;
	}
};

const COORD ROOM_TOP_WALL = {240, 80};
const COORD ROOM_RIGHT_WALL = {448, 144};
const COORD ROOM_BOTTOM_WALL = {240, 208};
const COORD ROOM_LEFT_WALL = { 32, 144 };