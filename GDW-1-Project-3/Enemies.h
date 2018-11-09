#pragma once

class SpikeTrap : public Enemy {
private:

public:
	SpikeTrap(int x, int y) :Enemy(x, y, 30, 16, 1, 1) {
		SetNumAnim(1);

		SetSpriteSheet(Sprites.enemySprites);
	}

	void Hurt(int d) {

	}

	void AI() {

	}

	void HitDetect(Entity * other) {

	}
};