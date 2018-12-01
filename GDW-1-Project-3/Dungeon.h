#pragma once

class LockedDoors {
	int id;
	bool open = false;
	Door * doors[2];

public:
	LockedDoors(int id, Direction door1, Direction door2, Room * room1, Room * room2 ) {

	}
};

class Dungeon {
	Room rooms[8][8];
	std::vector<Puzzle *> puzzles;
	std::vector<LockedDoors> lockPairs = {};

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
				new Block(96, 112),
				new Block(96, 144),
				new Block(96, 176),
				new Block(192, 112),
				new Block(192, 144),
				new Block(192, 176),
				new Block(288, 112),
				new Block(288, 144),
				new Block(288, 176),
				new Block(384, 112),
				new Block(384, 144),
				new Block(384, 176),
			},
			{}, // Enemy List, Empty
			RT_START
			);
		// ================= TRIFORCE ROOM =======================
		rooms[3][0] = Room(
			{
				new Wall(ROOM_TOP_WALL),
				new Wall(ROOM_LEFT_WALL),
				new Wall(ROOM_BOTTOM_WALL),
				new Door(ROOM_RIGHT_DOOR, Right)
			},
			{}
		);

		// =================== BOSS ROOM =========================
		rooms[4][0] = Room(
			{	
				new Wall(ROOM_TOP_WALL),
				new Wall(ROOM_RIGHT_WALL), 
				new Door(ROOM_BOTTOM_DOOR, Down)
			},
			{},
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
			{} // Enemy List, Empty
		);

		rooms[5][1] = Room(
			{	//Terrain List
				new Wall(ROOM_TOP_WALL),
				new Wall(ROOM_RIGHT_WALL),
				new Door(ROOM_BOTTOM_DOOR, Down)
			},
			{}, // Enemy List, Empty
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
			{} // Enemy List, Empty
		);

		rooms[5][2] = Room(
			{	//Terrain List
				new Wall(ROOM_RIGHT_WALL),
				new Door(ROOM_TOP_DOOR, Up)
			},
			{} // Enemy List, Empty
			);

		rooms[5][3] = Room(
			{	//Terrain List
				new Wall(ROOM_RIGHT_WALL),
				new Door(ROOM_LEFT_DOOR, Left)
			},
			{}// Enemy List, Empty
		);

		rooms[4][4] = Room(
			{	//Terrain List
				new Wall(ROOM_LEFT_WALL),
				new Door(ROOM_TOP_DOOR, Up),
				new Door(ROOM_BOTTOM_DOOR, Down),
				new Door(ROOM_RIGHT_DOOR, Right),
				new Block(128, 128),
				new Block(352, 128),
				new Block(128, 160),
				new Block(352, 160)
			},
			{}// Enemy List, Empty
		);

		rooms[5][4] = Room(
			{	//Terrain List
				new Wall(ROOM_RIGHT_WALL),
				new Door(ROOM_LEFT_DOOR, Left)
			},
			{}// Enemy List, Empty
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
			{}// Enemy List, Empty
		);

		rooms[5][5] = Room(
			{	//Terrain List
				new Wall(ROOM_RIGHT_WALL),
				new Block(128, 96),
				new Block(352, 96),
				new Block(128, 176),
				new Block(352, 176)
			},
			{}// Enemy List, Empty
		);
		
		rooms[2][6] = Room(
			{	//Terrain List
				new Wall(ROOM_TOP_WALL),
				new Wall(ROOM_LEFT_WALL),
				new Wall(ROOM_BOTTOM_WALL),
				new Door(ROOM_RIGHT_DOOR, Right)
			},
			{} // Enemy List, Empty
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
			{} // Enemy List, Empty
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
			{} // Enemy List, Empty
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
			{} // Enemy List, Empty
		);

		rooms[4][7] = Room(
			{	// Terrain List
				new Wall(ROOM_BOTTOM_WALL),
				new Wall(ROOM_RIGHT_WALL),
				new Door(ROOM_TOP_DOOR, Up),
				new Door(ROOM_LEFT_DOOR, Left)
			},
			{} // Enemy List, Empty
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

		// puzzles
		puzzles = {

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

			// Puzzle 4
			new Puzzle(
				new KillTrigger({
					new Rope(216, 127),
					new Rope(322, 97),
					new Rope(216, 159),
					new Rope(152, 159),
					new Rope(322, 192),
					new Rope(216, 159),
					new Rope(152, 159),
					new Rope(322, 192)
					}),
				{
					new Open({Door(ROOM_TOP_DOOR,Up)}, r4)
					},
				r4
			),

			new Puzzle(
				new KillTrigger({
					//new Moldorm(256, 96),
					new Moldorm(256, 96)
					}),
				{
					new NULL_RESULT()
				},
				r7
				)
		};
	}

	void DrawMap(HANDLE out, int yOffset, Room * curRoom) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (!rooms[x][y].IsNull()) {
					SetConsoleTextAttribute(out, 1 * 16);
					for (int c = 0; c < 3; c++) {
						GoToXY(out, 32 + (x * 16), 24 + c + yOffset + (y * 4));
						WriteConsole(out, "              ", 14, NULL, NULL);
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

	Room * GetStartRoom() {
		return &rooms[3][7];
	}

	Room * GetNextRoom(Room * curRoom, Direction d) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if (curRoom == &rooms[x][y]) {
					switch (d) {
					case Up:
						if (y != 0)
							return &rooms[x][y - 1];
						else
							return NULL;
					case Down:
						if (y != 7)
							return &rooms[x][y + 1];
						else
							return NULL;
					case Left:
						if (x != 0)
							return &rooms[x - 1][y];
						else
							return NULL;
					case Right:
						if (x != 7)
							return &rooms[x + 1][y];
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
			if (!player_file->puzzles_solved[s]) {
				puzzles[s]->Setup();
			}
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