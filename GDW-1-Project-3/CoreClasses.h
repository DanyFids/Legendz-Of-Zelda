#pragma once
class Player : public Entity {
private:
	int hp = 5;
public:
	Player(int x, int y) :Entity(x, y, 30, 16) {
		SetNumAnim(1);


		SetSpriteSheet(Sprites.playerSprites);

	}

	void HitDetect(Entity * other) {

	}

	void Hurt(int d) {
		hp -= d;
	}

};

class Enemy : public Entity {
private:
	int dmg, hp;
public:
	Enemy(int x, int y, int w, int h, int hp, int dmg) :Entity(x, y, w, h) {
		this->hp = hp;
		this->dmg = dmg;
	}

	void Hurt(int d) {
		hp -= d;
	}

	int GetHP() {
		return hp;
	}

	void Hit(Player & p) {
		p.Hurt(dmg);
	}

	virtual void AI() = 0;
};

class Terrain : public Entity {
public:
	Terrain(int x, int y, int w, int h):Entity(x, y, w, h) {

	}
};

class Projectile : public Entity {
private:
	int dmg, timer;
public:
	Projectile(int x, int y, int w, int h, int time, int dmg) :Entity(x, y, w, h) {
		this->timer = time;
		this->dmg = dmg;
	}

	void Hit(Player & p) {
		p.Hurt(dmg);
	}

	void Hit(Enemy & e) {
		e.Hurt(dmg);
	}
};