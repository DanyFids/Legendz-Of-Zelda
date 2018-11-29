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
	std::vector<Puzzle *> puzzles = {};
	std::vector<LockedDoors> lockPairs = {};

public:
	Dungeon() {
		// ================== START ROOM ========================
		rooms[3][7] = Room(
			{	//Terrain List
				new Wall(ROOM_LEFT_WALL),
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
			new Puzzle(new NULL_TRIGGER(), { new NULL_RESULT() }),
			RT_START
			);
		rooms[4][7] = Room(
			{	// Terrain List
				new Wall(ROOM_TOP_WALL),
				new Wall(ROOM_RIGHT_WALL)
			}, 
			{}, // Enemy List, Empty
			new Puzzle(new NULL_TRIGGER(), { new NULL_RESULT() })
			);

		rooms[3][6] = Room(
			{	//Terrain List
				new Wall(ROOM_TOP_WALL),
				new Block(128, 112),
				new Block(128, 176),
				new Block(352, 176),
				new Block(352, 112),
			},
			{}, // Enemy List, Empty
			new Puzzle(new NULL_TRIGGER(), { new NULL_RESULT() })
			);
		rooms[4][6] = Room(
			{	//Terrain List
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
			{}, // Enemy List, Empty
			new Puzzle(new NULL_TRIGGER(), { new NULL_RESULT() })
			);
		rooms[2][6] = Room(
			{	//Terrain List
				new Wall(ROOM_TOP_WALL),
				new Wall(ROOM_RIGHT_WALL),
				new Wall(ROOM_BOTTOM_WALL)
			},
			{}, // Enemy List, Empty
			new Puzzle(new NULL_TRIGGER(), { new NULL_RESULT() })
			);
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
};