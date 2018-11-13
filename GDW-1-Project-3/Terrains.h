#pragma once
class Wall : public Terrain {

public:
	Wall(int x, int y) : Terrain(x, y, 16, 16) {
		
	}

	void HitDetect(Entity * other) {
		
	}
};