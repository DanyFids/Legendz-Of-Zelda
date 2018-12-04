#pragma once

class LockedDoorPair {
	bool open = false;
	LockedDoor * doors[2];
	int id;

public:
	LockedDoorPair(int id, Direction door1, Direction door2, Room * room1, Room * room2 ) {
		this->id = id;

		LockedDoor * tempDoor = NULL;
		switch (door1) {
		case Up:
			tempDoor = new LockedDoor(ROOM_TOP_DOOR, Up, this);
			break;
		case Down:
			tempDoor = new LockedDoor(ROOM_BOTTOM_DOOR, Down, this);
			break;
		case Right:
			tempDoor = new LockedDoor(ROOM_RIGHT_DOOR, Right, this);
			break;
		case Left:
			tempDoor = new LockedDoor(ROOM_LEFT_DOOR, Left, this);
			break;
		}
		doors[0] = tempDoor;

		switch (door2) {
		case Up:
			tempDoor = new LockedDoor(ROOM_TOP_DOOR, Up, this);
			break;
		case Down:
			tempDoor = new LockedDoor(ROOM_BOTTOM_DOOR, Down, this);
			break;
		case Right:
			tempDoor = new LockedDoor(ROOM_RIGHT_DOOR, Right, this);
			break;
		case Left:
			tempDoor = new LockedDoor(ROOM_LEFT_DOOR, Left, this);
			break;
		}
		doors[1] = tempDoor;

		room1->TerrainList.push_back(doors[0]);
		room2->TerrainList.push_back(doors[1]);
	}

	void OpenDoors() {
		doors[0]->setOpen(true);
		doors[1]->setOpen(true);
	}
};

class BombablePair {
	bool open = false;
	BombableWall * walls[2];
	int id;
public:
	BombablePair(int id, Direction door1, Direction door2, Room * room1, Room * room2) {
		this->id = id;
		BombableWall * tempWall = NULL;
		switch (door1) {
		case Up:
			tempWall = new BombableWall(ROOM_TOP_WALL, Up, this);
			break;
		case Down:
			tempWall = new BombableWall(ROOM_BOTTOM_WALL, Down, this);
			break;
		case Right:
			tempWall = new BombableWall(ROOM_RIGHT_WALL, Right, this);
			break;
		case Left:
			tempWall = new BombableWall(ROOM_LEFT_WALL, Left, this);
			break;
		}
		walls[0] = tempWall;

		switch (door2) {
		case Up:
			tempWall = new BombableWall(ROOM_TOP_WALL, Up, this);
			break;
		case Down:
			tempWall = new BombableWall(ROOM_BOTTOM_WALL, Down, this);
			break;
		case Right:
			tempWall = new BombableWall(ROOM_RIGHT_WALL, Right, this);
			break;
		case Left:
			tempWall = new BombableWall(ROOM_LEFT_WALL, Left, this);
			break;
		}
		walls[1] = tempWall;

		room1->TerrainList.insert(room1->TerrainList.begin(), walls[0]);
		room2->TerrainList.insert(room2->TerrainList.begin(), walls[1]);
	}

	void OpenWalls() {
		walls[0]->setGone(true);
		walls[1]->setGone(true);

		player_file->bombsOpened[id] = true;
	}
};

class Dungeon {
	Room rooms[8][8];
	std::vector<Puzzle *> puzzles;
	std::vector<LockedDoorPair *> lockPairs = {};
	std::vector<BombablePair *> bombPairs = {};

public:
	Dungeon() {
		// ROOMS
		// ================== START ROOM ========================
		rooms[3][7] = Room(
			{	//Terrain List
				new Wall(ROOM_LEFT_WALL),
				new Door(ROOM_TOP_DOOR, Up, true),
				new Door(ROOM_BOTTOM_DOOR, Down, false),
				new Door(ROOM_RIGHT_DOOR, Right, true),
			},
			{
			}, // Enemy List, Empty
			{
				new Statue(96, 112, true),
				new Statue(96, 144, true),
				new Statue(96, 176, true),
				new Statue(192, 112, true),
				new Statue(192, 144, true),
				new Statue(192, 176, true),
				new Statue(288, 112, true),
				new Statue(288, 144, true),
				new Statue(288, 176, true),
				new Statue(384, 112, true),
				new Statue(384, 144, true),
				new Statue(384, 176, true)
			},
			{},
			RL_ULD,
			RT_START
			);
		// ================= TRIFORCE ROOM =======================
		rooms[3][0] = Room(
			{
				new Wall(ROOM_TOP_WALL),
				new Wall(ROOM_LEFT_WALL),
				new Wall(ROOM_BOTTOM_WALL),
				new Door(ROOM_RIGHT_DOOR, Right),

				new Block(64 + (32 * 1), 96 + (16 * 1)),
				new Block(64 + (32 * 2), 96 + (16 * 1)),
				new Block(64 + (32 * 3), 96 + (16 * 1)),
				new Block(64 + (32 * 4), 96 + (16 * 1)),
				new Block(64 + (32 * 5), 96 + (16 * 1)),
				new Block(64 + (32 * 6), 96 + (16 * 1)),
				new Block(64 + (32 * 7), 96 + (16 * 1)),
				new Block(64 + (32 * 8), 96 + (16 * 1)),
				new Block(64 + (32 * 9), 96 + (16 * 1)),
				new Block(64 + (32 * 10), 96 + (16 * 1)),
				new Block(64 + (32 * 1), 96 + (16 * 2)),
				new Block(64 + (32 * 10), 96 + (16 * 2)),
				new Block(64 + (32 * 1), 96 + (16 * 3)),
				new Block(64 + (32 * 10), 96 + (16 * 3)),
				new Block(64 + (32 * 1), 96 + (16 * 4)),
				new Block(64 + (32 * 10), 96 + (16 * 4)),
				new Block(64 + (32 * 1), 96 + (16 * 5)),
				new Block(64 + (32 * 2), 96 + (16 * 5)),
				new Block(64 + (32 * 3), 96 + (16 * 5)),
				new Block(64 + (32 * 4), 96 + (16 * 5)),
				new Block(64 + (32 * 7), 96 + (16 * 5)),
				new Block(64 + (32 * 8), 96 + (16 * 5)),
				new Block(64 + (32 * 9), 96 + (16 * 5)),
				new Block(64 + (32 * 10), 96 + (16 * 5))
			},
			{},
			{
				new Statue(64 + (32 * 4), 96 + (16 * 2), true),
				new Statue(64 + (32 * 3), 96 + (16 * 3), true),
				new Statue(64 + (32 * 7), 96 + (16 * 2), true),
				new Statue(64 + (32 * 8), 96 + (16 * 3), true)
			},
			{
				new Triforce(64 + (32 * 6) - 10, 96 + (16 * 4) - 10)
			},
			RL_L
		);

		// =================== BOSS ROOM =========================
		rooms[4][0] = Room(
			{	
				new Wall(ROOM_TOP_WALL),
				new Wall(ROOM_RIGHT_WALL), 
				new Door(ROOM_BOTTOM_DOOR, Down)
			},
			{},
			{},
			{},
			RL_DR,
			RT_BOSS
		);

		// =========== MINI BOSS ROOM ===========
		rooms[4][3] = Room(
			{	//Terrain List
				new Wall(ROOM_LEFT_WALL),
				new Door(ROOM_BOTTOM_DOOR, Down),
				new Door(ROOM_TOP_DOOR, Up),
				new Door(ROOM_RIGHT_DOOR, Right)
			},
			{},// Enemy List, Empty
			{},
			{},
			RL_ULD,
			RT_MINI_BOSS
		);

		// OTHER ROOMS
		rooms[4][1] = Room(
			{	//Terrain List
				new Wall(ROOM_LEFT_WALL),
				new Block(96, 112),
				new Block(96, 144),
				new Block(96, 176),
				new Block(160, 112),
				new Block(160, 144),
				new Block(160, 176),
				new Block(224, 112),
				new Block(224, 144),
				new Block(224, 176),
				new Block(256, 112),
				new Block(256, 144),
				new Block(256, 176),
				new Block(320, 112),
				new Block(320, 144),
				new Block(320, 176),
				new Block(384, 112),
				new Block(384, 144),
				new Block(384, 176)
			},
			// Enemy List, Empty
			{},
			{},
			{},
			RL_UD
		);

		rooms[5][1] = Room(
			{	//Terrain List
				new Wall(ROOM_TOP_WALL),
				new Wall(ROOM_RIGHT_WALL),
				new Door(ROOM_BOTTOM_DOOR, Down)
			},
			{}, // Enemy List, Empty
			{},
			{},
			RL_D,
			RT_SECRET
		);

		rooms[4][2] = Room(
			{	//Terrain List
				new Wall(ROOM_LEFT_WALL),
				new Door(ROOM_BOTTOM_DOOR, Down),
				new Block(128, 128),
				new Block(128, 144),
				new Block(128, 160),
				new Block(160, 128),
				new Block(160, 144),
				new Block(160, 160),
				new Block(320, 128),
				new Block(320, 144),
				new Block(320, 160),
				new Block(352, 128),
				new Block(352, 144),
				new Block(352, 160)
			},
			{}, // Enemy List, Empty
			{},
			{},
			RL_ULD
		);

		rooms[5][2] = Room(
			{	//Terrain List
				new Wall(ROOM_RIGHT_WALL),
				new Door(ROOM_TOP_DOOR, Up)
			},
			{}, // Enemy List, Empty
			{},
			{},
			RL_UR
			);

		rooms[5][3] = Room(
			{	//Terrain List
				new Wall(ROOM_RIGHT_WALL),
				new Door(ROOM_LEFT_DOOR, Left)
			},
			{ // Enemy List
				new Keese(64 + (32 * 3), 96 + (16 * 0)),
				new Keese(64 + (32 * 10), 96 + (16 * 1)),
				new Keese(64 + (32 * 11), 96 + (16 * 3)),
				new Keese(64 + (32 * 10), 96 + (16 * 5)),
			},
			{
				new SpikeTrap(64, 96),
				new SpikeTrap(64, 192),
				new SpikeTrap(64 + (176 * 2), 96),
				new SpikeTrap(64 + (176 * 2), 192),
			},
			{
				new BombPickup(264, 145)
			},
			RL_R
		);

		rooms[4][4] = Room(
			{	//Terrain List
				new Wall(ROOM_LEFT_WALL),
				new Door(ROOM_TOP_DOOR, Up),
				new Door(ROOM_RIGHT_DOOR, Right),
				new Block(128, 128),
				new Block(352, 128),
				new Block(128, 160),
				new Block(352, 160)
			},
			{},// Enemy List, Empty
			{},
			{},
			RL_ULD
		);

		rooms[5][4] = Room(
			{	//Terrain List
				new Wall(ROOM_RIGHT_WALL),
				new Door(ROOM_LEFT_DOOR, Left)
			},
			{},// Enemy List, Empty
			{
				new Statue(64 + (32 * 0), 94 + (16 * 0), false),
				new Statue(64 + (32 * 11), 94 + (16 * 0), false),
				new Statue(64 + (32 * 0), 94 + (16 * 6), false),
				new Statue(64 + (32 * 11), 94 + (16 * 6), false)
			},
			{},
			RL_R
		);

		rooms[4][5] = Room(
			{	//Terrain List
				new Wall(ROOM_LEFT_WALL),
				new Door(ROOM_TOP_DOOR, Up),
				new Door(ROOM_BOTTOM_DOOR, Down),
				new Block(96, 112),
				new Block(96, 176),
				new Block(128, 112),
				new Block(128, 176),
				new Block(224, 144),
				new Block(256, 144),
				new Block(352, 112),
				new Block(352, 176),
				new Block(384, 112),
				new Block(384, 176)
			},
			{},// Enemy List, Empty
			{},
			{},
			RL_ULD
		);

		rooms[5][5] = Room(
			{	//Terrain List
				new Wall(ROOM_RIGHT_WALL),
				new Block(128, 112),
				new Block(352, 112),
				new Block(128, 176),
				new Block(352, 176)
			},
			{
				new Gel(80 + (32 * 10) - 6, 104 + (16 * 1) - 4),
				new Gel(80 + (32 * 6) - 6, 104 + (16 * 2) - 4),
				new Gel(80 + (32 * 8) - 6, 104 + (16 * 2) - 4),
				new Gel(80 + (32 * 6) - 6, 104 + (16 * 4) - 4),
				new Gel(80 + (32 * 8) - 6, 104 + (16 * 4) - 4)
			},// Enemy List, Empty
			{},
			{},
			RL_R
		);
		
		rooms[2][6] = Room(
			{	//Terrain List
				new Wall(ROOM_TOP_WALL),
				new Wall(ROOM_LEFT_WALL),
				new Wall(ROOM_BOTTOM_WALL),
				new Door(ROOM_RIGHT_DOOR, Right)
			},
			{ // Enemy List
			}, 
			{},
			{
			},
			RL_L
		);

		rooms[3][6] = Room(
			{	//Terrain List
				new Wall(ROOM_TOP_WALL),
				new Door(ROOM_RIGHT_DOOR, Right),
				new Door(ROOM_BOTTOM_DOOR, Down),
				new Block(128, 112),
				new Block(128, 176),
				new Block(352, 176),
				new Block(352, 112),
			},
			{}, // Enemy List, Empty
			{},
			{},
			RL_LDR
			);
		rooms[4][6] = Room(
			{	//Terrain List
				new Door(ROOM_TOP_DOOR, Up),
				new Door(ROOM_LEFT_DOOR, Left),
				new Door(ROOM_BOTTOM_DOOR, Down),
				new Block(96, 112),
				new Block(96, 144),
				new Block(96, 176),
				new Block(160, 112),
				new Block(160, 144),
				new Block(160, 176),
				new Block(224, 112),
				new Block(224, 144),
				new Block(224, 176),
				new Block(256, 112),
				new Block(256, 144),
				new Block(256, 176),
				new Block(320, 112),
				new Block(320, 144),
				new Block(320, 176),
				new Block(384, 112),
				new Block(384, 144),
				new Block(384, 176)
			},
			// Enemy List
			{
				new Rope(170, 96),
				new Rope(240, 128),
				new Rope(170, 160)
			}, 
			{},
			{},
			RL_ULDR
			);

		rooms[5][6] = Room(
			{	//Terrain List
				new Wall(ROOM_RIGHT_WALL),
				new Wall(ROOM_BOTTOM_WALL),
				new Block(224, 128),
				new Block(224, 144),
				new Block(224, 160),
				new Block(256, 128),
				new Block(256, 144),
				new Block(256, 160)
			},
			// Enemies
			{
				new Gel(80 + (32 * 3) - 6, 104 - 4),
				new Gel(80 + (32 * 10) - 6, 104 + (16 * 1) - 4),
				new Gel(80 + (32 * 8) - 6, 104 + (16 * 3) - 4),
				new Gel(80 + (32 * 11) - 6, 104 + (16 * 4) - 4),
				new Gel(80 + (32 * 8) - 6, 104 + (16 * 5) - 4),
				new Gel(80 + (32 * 3) - 6, 104 + (16 * 6) - 4)
			}, 
			// Hazards
			{},
			// Pick Ups
			{
			},
			RL_R
		);

		rooms[4][7] = Room(
			{	// Terrain List
				new Wall(ROOM_BOTTOM_WALL),
				new Wall(ROOM_RIGHT_WALL),
				new Door(ROOM_TOP_DOOR, Up),
				new Door(ROOM_LEFT_DOOR, Left)
			},
			{}, // Enemy List, Empty
			{},
			{},
			RL_UR
		);


		// PUZZLES
		// puzzle rooms
		Room * r1 = &rooms[4][7];
		Room * r2 = &rooms[3][6];
		Room * r3 = &rooms[5][4];
		Room * r4 = &rooms[4][2];
		Room * r5 = &rooms[4][1];
		Room * r6 = &rooms[4][0];
		Room * r7 = &rooms[4][3];
		Room * r8 = &rooms[5][2];
		Room * r9 = &rooms[2][6];
		Room * r10 = &rooms[4][4];

		// puzzles
		puzzles = {
			// Puzzle 1
			new Puzzle(
				new KillTrigger({
						new Rope(216, 127),
						new Rope(322, 97),
						new Rope(216, 159),
						new Rope(152, 159),
						new Rope(322, 192)
					}),
				{
					new Reward({
						new KeyPickup(264, 145)
					}, r1)
				},
				r1
			),

			// Puzzle 2
			new Puzzle(
				new KillTrigger({
					new Rope(216, 127),
					new Rope(322, 97),
					new Rope(216, 159),
					new Rope(152, 159),
					new Rope(322, 192)
					}),
				{
					new Open({Door(ROOM_LEFT_DOOR,Left)}, r2)
					},
				r2
			),

			// Puzzle 3
			new Puzzle(
				new KillTrigger({
					new Goryia(64 + (32 * 3), 96 + (16 * 0), true),
					new Goryia(64 + (32 * 8), 96 + (16 * 0), true),
					new Goryia(64 + (32 * 4), 96 + (16 * 2), true)
					}),
				{
					new Reward({new HeartContainerPickup(264, 145)}, r3)
				},
				r3
			),

			// Puzzle 4
			new Puzzle(
				new KillTrigger({
					new Rope(64 + (32 * 2), 96 + (16 * 0)),
					new Rope(64 + (32 * 9), 96 + (16 * 0)),
					new Rope(64 + (32 * 0), 96 + (16 * 1)),
					new Rope(64 + (32 * 4), 96 + (16 * 1)),
					new Rope(64 + (32 * 7), 96 + (16 * 1)),
					new Rope(64 + (32 * 10), 96 + (16 * 1)),
					new Rope(64 + (32 * 4), 96 + (16 * 3)),
					new Rope(64 + (32 * 7), 96 + (16 * 3))
					}),
				{
					new Open({Door(ROOM_TOP_DOOR,Up)}, r4)
				},
				r4
			),

			//Puzzle 5
			new Puzzle(
				new KillTrigger({
					new Goryia( 64 + (32 * 3), 96 + (16 * 0), false),
					new Goryia(64 + (32 * 8), 96 + (16 * 0), false),
					new Goryia(64 + (32 * 4), 96 + (16 * 2), false),
					new Goryia(64 + (32 * 3), 96 + (16 * 4), false),
					new Goryia(64 + (32 * 8), 96 + (16 * 4), false)
				}),
				{
					new Open({
						Door(ROOM_TOP_DOOR, Up),
						Door(ROOM_BOTTOM_DOOR, Down)
					}, r5),
					new Reward({new BombPickup(424, 96)}, r5)
				},
				r5
			),

			// Puzzle 6
			new Puzzle(
				new KillTrigger({
					new Dodongo(512 - 128, 96)
					}),
				{
					new Open({
						Door(ROOM_LEFT_DOOR, Left)
						}, r6),
					new Reward({
						new HeartContainerPickup(256, 96 + (16 * 3))
					}, r6)
				},
				r6
			),

			// Puzzle 7
			new Puzzle(
				new KillTrigger({
					new Moldorm(256, 96),
					new Moldorm(256, 96)
					}),
				{
					new Reward({
						new KeyPickup(264, 145)
					}, r7)
				},
				r7
				),

			// Puzzle 8
			new Puzzle(
				new KillTrigger({
					new Gel(80 + (32 * 3) - 6, 104 - 4),
					new Gel(80 + (32 * 10) - 6, 104 + (16 * 1) - 4),
					new Gel(80 + (32 * 11) - 6, 104 + (16 * 3) - 4),
					new Gel(80 + (32 * 8) - 6, 104 + (16 * 4) - 4),
					new Gel(80 + (32 * 3) - 6, 104 + (16 * 5) - 4)

				}),
				{
					new Reward({
						new BlueRupeesPickup(264, 145)
					},
					r8)},
				r8
			),

			// Puzzle 9
			new Puzzle(
				new KillTrigger({
					new Rope(216, 127),
					new Rope(322, 97),
					new Rope(216, 159),
					new Rope(152, 159),
					new Rope(152, 159),
					new Rope(322, 192)
					}),
				{
					new Reward({
						new KeyPickup(264, 145)
						},r9)
				},
				r9
			),

			// Puzzle 10
				
			new Puzzle(
				new KillTrigger({
					new Rope(64 + (32 * 8) , 96 + (16 * 0)),
					new Rope(64 + (32 * 4) , 96 + (16 * 2)),
					new Rope(64 + (32 * 7) , 96 + (16 * 2)),
					new Rope(64 + (32 * 5) , 96 + (16 * 3)),
					new Rope(64 + (32 * 3) , 96 + (16 * 4))
				}), {
					new Open({
						Door(ROOM_BOTTOM_DOOR, Down)
					}, r10),
					new Reward({new KeyPickup(264, 145)}, r10)
				},
				r10
			)
		};

		lockPairs = {
			new LockedDoorPair(0,Right, Left, &rooms[4][6], &rooms[5][6]),
			new LockedDoorPair(1,Right, Left, &rooms[4][5], &rooms[5][5]),
			new LockedDoorPair(2,Right, Left, &rooms[4][2], &rooms[5][2])
		};

		bombPairs = {
			new BombablePair(0, Up, Down, &rooms[5][6], &rooms[5][5]),
			new BombablePair(1, Up, Down, &rooms[5][5], &rooms[5][4]),
			new BombablePair(2, Up, Down, &rooms[5][4], &rooms[5][3]),
			new BombablePair(3, Up, Down, &rooms[5][3], &rooms[5][2]),
			new BombablePair(4, Right, Left, &rooms[4][1], &rooms[5][1])
		};
	}

	void DrawMap(HANDLE out, int yOffset, Room * curRoom) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (player_file->HasMap) {
					if (!rooms[x][y].IsNull()) {
						SetConsoleTextAttribute(out, 1 * 16);
						for (int c = 0; c < 3; c++) {
							GoToXY(out, 32 + (x * 16), 24 + c + yOffset + (y * 4));
							WriteConsole(out, "              ", 14, NULL, NULL);
						}
					}
				}
				if (player_file->HasCompass && &rooms[x][y] == &rooms[3][0]) {
					SetConsoleTextAttribute(out, 12 * 16);
					for (int c = 0; c < 3; c++) {
						GoToXY(out, 32 + (x * 16) + 4, 24 + c + yOffset + (y * 4));
						WriteConsole(out, "      ", 6, NULL, NULL);
					}
				}

				if (curRoom == &rooms[x][y]) {
					SetConsoleTextAttribute(out, 10 * 16);
					for (int c = 0; c < 3; c++) {
						GoToXY(out, 32 + (x * 16) + 4, 24 + c + yOffset + (y * 4));
						WriteConsole(out, "      ", 6, NULL, NULL);
					}
				}
			}
		}
	}

	void DrawInvMap(HANDLE out) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (player_file->map_discovered[x][y]) {
					rooms[x][y].DrawMap(out, 240 + (16 * x), 103 + (8 * y));
				}
			}
		}
	}

	Room * GetStartRoom() {
		player_file->map_discovered[3][7] = true;
		return &rooms[3][7];
	}

	void GenerateRoomWalls() {
		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				if (!rooms[x][y].IsNull()) {
					rooms[x][y].GenerateWalls();
				}
			}
		}
	}

	Room * GetNextRoom(Room * curRoom, Direction d) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (curRoom == &rooms[x][y]) {
					switch (d) {
					case Up:
						if (y != 0) {
							player_file->map_discovered[x][y-1] = true;
							return &rooms[x][y - 1];
						}
						else
							return NULL;
					case Down:
						if (y != 7) {
							player_file->map_discovered[x][y+1] = true;
							return &rooms[x][y + 1];
						}
						else
							return NULL;
					case Left:
						if (x != 0) {
							player_file->map_discovered[x-1][y] = true;
							return &rooms[x - 1][y];
						}
						else
							return NULL;
					case Right:
						if (x != 7) {
							player_file->map_discovered[x+1][y] = true;
							return &rooms[x + 1][y];
						}
						else
							return NULL;
					}
				}
			}
		}
		return NULL;
	}

	void SetupDungeon() {
		for (int s = 0; s < puzzles.size(); s++) {
			puzzles[s]->Setup();
			if (player_file->puzzles_solved[s]) {
				puzzles[s]->Solve();
			}
		}

		for (int ld = 0; ld < lockPairs.size(); ld++) {
			if (player_file->LocksOpened[ld]) {
				lockPairs[ld]->OpenDoors();
			}
		}

		for (int bw = 0; bw < bombPairs.size(); bw++) {
			if (player_file->bombsOpened[bw]) {
				bombPairs[bw]->OpenWalls();
			}
		}

		if (!player_file->HasCompass) {
			rooms[5][6].powerups.push_back(new CompassPickup(64 + (178) * 2, 99));
		}

		if (!player_file->HasMap) {
			rooms[5][5].powerups.push_back(new MapPickup(64 + 200, 64+65));
		}
	}

	void CheckPuzzles() {
		for (int p = 0; p < puzzles.size(); p++) {
			if (puzzles[p]->Check()) {
				player_file->puzzles_solved[p] = true;
			}
		}
	}
};


Dungeon LEVEL2;