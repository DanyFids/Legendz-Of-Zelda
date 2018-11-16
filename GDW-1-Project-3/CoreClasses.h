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

	bool HitDetect(Entity * other) {
		return false;
	}

	void Hurt(int d) {
		hp -= d;
	}

	void Update() {
		if (GetX() + xSpd < 0) {
			xSpd = 0 - GetX();
		}

		if (GetY() + ySpd < 0) {
			ySpd = 0 - GetY();
		}


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

	virtual void AI(Player p) = 0;
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
	int dmg, timer,speed;
	float theta;
	Direction dir;
public:
	float getTheta()
	{
		return theta;
	}

	int getDamage()
	{
		return dmg;
	}

	int getSpeed()
	{
		return speed;
	}

	int getTime()
	{
		return timer;
	}

	Direction getDir()
	{
		return dir;
	}

	void setTime(int t)
	{
		timer = t;
	}

	void setSpeed(int s)
	{
		speed = s;
	}

	void setTheta(float _theta)
	{
		theta = _theta;
	}

	void setDir(Direction _dir)
	{
		dir = _dir;
	}

	Projectile(int x, int y, int w, int h, int time, int dmg, int speed) :Entity(x, y, w, h) {
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