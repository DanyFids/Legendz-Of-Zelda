#pragma once
class Room {
private:
	std::vector<Enemy *> SpawnList;
	HANDLE sprite_sheet;
	bool NullRoom = false;
	RoomType type;
	CHAR_INFO * topWall;
	CHAR_INFO * bottomWall;
	CHAR_INFO * rightWall;
	CHAR_INFO * leftWall;
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
	std::vector<PowerUp *> powerups;
	std::vector<Enemy *> hazards;

	Room() {
		NullRoom = true;
	}

	Room(std::vector<Terrain *> tl, std::vector<Enemy *> sl, std::vector<Enemy *> hl, std::vector<PowerUp *> pl, RoomType t = RT_DEFAULT) {
		for (int t = 0; t < tl.size(); t++) {
			TerrainList.push_back(tl[t]);
		}
		SpawnList = sl;
		type = t;
		hazards = hl;
		powerups = pl;

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
		
		/*//Area to read/write
		int w = 512;
		int h = 176;

		SMALL_RECT screen;
		screen.Top = 64;
		screen.Left = 0;
		screen.Right = 0 + w - 1;
		screen.Bottom = 64 + h - 1;

		//Top Left COORD
		COORD start;
		start.X = 0;
		start.Y = 0;

		//Buffer Size
		COORD size;
		size.X = w;
		size.Y = h;
		WriteConsoleOutput(out, Sprites.roomsByType[type], size, start, &screen);*/
	}

	void GenerateWalls() {
		HANDLE tempRoom = CreateConsoleScreenBuffer(
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL,
			CONSOLE_TEXTMODE_BUFFER,
			NULL);

		SetConsoleScreenBufferSize(tempRoom, SCREEN_SIZE);

		Sprites.DrawSprite(sprite_sheet, (514 * type), 0, 512, 176, tempRoom, 0, 64);
		for (int t = 0; t < TerrainList.size(); t++) {
			TerrainList[t]->draw(tempRoom);
		}

		//Top Left COORD
		COORD start;
		start.X = 0;
		start.Y = 0;

		//Buffer Size
		COORD sizeUD;
		sizeUD.X = 68;
		sizeUD.Y = 17;

		COORD sizeLR = { 34, 34 };

		topWall = new CHAR_INFO[sizeUD.X * sizeUD.Y];
		bottomWall = new CHAR_INFO[sizeUD.X * sizeUD.Y];
		rightWall = new CHAR_INFO[sizeLR.X * sizeLR.Y];
		leftWall = new CHAR_INFO[sizeLR.X * sizeLR.Y];

		SMALL_RECT screenU;
		screenU.Top = 64;
		screenU.Left = 222;
		screenU.Right = 222 + sizeUD.X - 1;
		screenU.Bottom = 64 + sizeUD.Y - 1;

		SMALL_RECT screenD;
		screenD.Top = 64 + 159;
		screenD.Left = 222;
		screenD.Right = 222 + sizeUD.X - 1;
		screenD.Bottom = 64 +159 + sizeUD.Y - 1;

		SMALL_RECT screenL;
		screenL.Top = 64 + 71;
		screenL.Left = 0;
		screenL.Right = 0 + sizeUD.X - 1;
		screenL.Bottom = 64 + 71 + sizeLR.Y - 1;

		SMALL_RECT screenR;
		screenR.Top = 64 + 71;
		screenR.Left = 462 + 16;
		screenR.Right = 462 + 16 + sizeLR.X - 1;
		screenR.Bottom = 64 + 71 + sizeLR.Y - 1;

		ReadConsoleOutput(tempRoom, topWall, sizeUD, start, &screenU);
		ReadConsoleOutput(tempRoom, bottomWall, sizeUD, start, &screenD);
		ReadConsoleOutput(tempRoom, leftWall, sizeLR, start, &screenL);
		ReadConsoleOutput(tempRoom, rightWall, sizeLR, start, &screenR);
	}

	void DrawWalls(HANDLE out) {
		//Top Left COORD
		COORD start;
		start.X = 0;
		start.Y = 0;

		//Buffer Size
		COORD sizeUD;
		sizeUD.X = 68;
		sizeUD.Y = 17;

		COORD sizeLR = { 34, 34 };

		SMALL_RECT screenU;
		screenU.Top = 64;
		screenU.Left = 222;
		screenU.Right = 222 + sizeUD.X - 1;
		screenU.Bottom = 64 + sizeUD.Y - 1;

		SMALL_RECT screenD;
		screenD.Top = 64 + 159;
		screenD.Left = 222;
		screenD.Right = 222 + sizeUD.X - 1;
		screenD.Bottom = 64 + 159 + sizeUD.Y - 1;

		SMALL_RECT screenL;
		screenL.Top = 64 + 71;
		screenL.Left = 0;
		screenL.Right = 0 + sizeUD.X - 1;
		screenL.Bottom = 64 + 71 + sizeLR.Y - 1;

		SMALL_RECT screenR;
		screenR.Top = 64 + 71;
		screenR.Left = 462 + 16;
		screenR.Right = 462 + 16 + sizeLR.X - 1;
		screenR.Bottom = 64 + 71 + sizeLR.Y - 1;

		WriteConsoleOutput(out, topWall, sizeUD, start, &screenU);
		WriteConsoleOutput(out, bottomWall, sizeUD, start, &screenD);
		WriteConsoleOutput(out, leftWall, sizeLR, start, &screenL);
		WriteConsoleOutput(out, rightWall, sizeLR, start, &screenR);
	}

	bool IsNull() {
		return NullRoom;
	}
};

class Trigger {
public:
	virtual bool Check() = 0;
	virtual void Setup(Room * r) = 0;
};

class NULL_TRIGGER : public Trigger {
public:
	bool Check() {
		return false;
	}

	void Setup(Room * r) {

	}
};

class KillTrigger : public Trigger {
private:
	std::vector<Enemy *> *hitList;
	std::vector<Enemy *> targets;
public:
	KillTrigger(std::vector<Enemy *> t) {
		targets = t;
	}

	bool Check() {
		if (hitList->size() <= 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Setup(Room * r) {
		hitList = &r->EnemyList;
		for (int e = 0; e < targets.size(); e++) {
			hitList->push_back(targets[e]->Clone());
		}
	}
};

class Result {
public:
	virtual void Effect() = 0;
	virtual void Setup() = 0;
};

class NULL_RESULT : public Result {
public:
	void Effect() {};

	void Setup() {}
};

class Open : public Result {
private:
	std::vector<Door> doors;
public:
	Open(std::vector<Door> d, Room * r) {
		doors = d;
		for (int x = 0; x < d.size(); x++) {
			r->TerrainList.push_back(&doors[x]);
		}
	}

	void Effect() {
		for (int c = 0; c < doors.size(); c++) {
			doors[c].setOpen(true);
		}
	}

	void Setup() {
		for (int d = 0; d < doors.size(); d++) {
			doors[d].setOpen(false);
		}
	}
};

class Reward : public Result {
private:
	std::vector<PowerUp *> rewards;
	Room * room;
public:
	Reward(std::vector<PowerUp *> rwrds, Room * r) {
		rewards = rwrds;
		room = r;
	}

	void Setup() {

	}

	void Effect() {
		for (int r = 0; r < rewards.size(); r++) {
			room->powerups.push_back(rewards[r]);
		}
	}
};

class Puzzle {
private:
	bool solved = false;
	Trigger * trigger;
	std::vector<Result *> results;
	Room * room;
public:
	Puzzle() {
		trigger = new NULL_TRIGGER;
		results = { new NULL_RESULT };
	}

	Puzzle(Trigger * t, std::vector<Result *> r, Room * room) {
		trigger = t;
		results = r;
		this->room = room;
	}

	void Setup() {
		if (!solved) {
			trigger->Setup(room);
			for (int r = 0; r < results.size(); r++) {
				results[r]->Setup();
			}
		}
	}

	bool Check() {
		if (trigger->Check() && !solved) {
			for (int r = 0; r < results.size(); r++) {
				results[r]->Effect();
			}
			solved = true;
			return true;
		}
		else {
			return false;
		}
	}
};

const COORD ROOM_TOP_WALL = {240, 80};
const COORD ROOM_RIGHT_WALL = {448, 144};
const COORD ROOM_BOTTOM_WALL = {240, 208};
const COORD ROOM_LEFT_WALL = { 32, 144 };

const COORD ROOM_TOP_DOOR = {224, 64};
const COORD ROOM_BOTTOM_DOOR = { 224, 208 };
const COORD ROOM_RIGHT_DOOR = {448, 135};
const COORD ROOM_LEFT_DOOR = { 0, 135 };