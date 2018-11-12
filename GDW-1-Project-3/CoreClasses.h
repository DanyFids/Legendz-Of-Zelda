#pragma once
struct Player_Input {
	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool keyRight;
	bool keySpace;
};

Player_Input player_input;

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

	void Update() {
		move();

		xSpd = 0;
		ySpd = 0;
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

	void Update() {

	}
};

class Projectile : public Entity {
private:
	int dmg, timer;
public:
	int getDamage()
	{
		return dmg;
	}

	int getTime()
	{
		return timer;
	}

	void setTime(int t)
	{
		timer = t;
	}

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