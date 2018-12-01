#pragma once
struct Player_Input {
	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool keyRight;
	bool keySpace;
};

struct Player_Info {
	std::string Name = std::string(8, ' ');
	int MaxLife = 6;
	int CurLife = 6;
	int Bombs = 0;
	int Keys = 0;
	int Rupees = 0;
	bool HasMap = false;
	bool HasCompass = false;
	bool file_exists = false;
};

Player_Info PLAYER_FILES[3];

Player_Input player_input;

class Player : public Entity {
private:
	int hp = 6;
	bool can_attack = true;
	float stop_timer = 0;
public:
	Player(int x, int y) :Entity(x, y, 32, 16) {
		SetNumAnim(4);


		SetSpriteSheet(Sprites.playerSprites);

		SetDir(Down);
	}

	bool HitDetect(Entity * other) {
		return false;
	}

	void Hurt(int d) {
		hp -= d;
	}

	void Update(float dt) {
		if (GetX() + xSpd < 0) {
			xSpd = 0 - GetX();
		}

		if (GetY() + ySpd < 0) {
			ySpd = 0 - GetY();
		}

		if (stop_timer <= 0) {
			move();
		}
		else {
			stop_timer -= dt;
			if (stop_timer <= 0) {
				can_attack = true;
			}
		}

		xSpd = 0;
		ySpd = 0;
	}

	bool CanAtk() {
		return can_attack;
	}

	void SwingSword() {
		can_attack = false;
		stop_timer = 1;
	}
};

class Enemy : public Entity {
private:
	int dmg, hp;
	bool invuln;
public:
	Enemy(int x, int y, int w, int h, int hp, int dmg) :Entity(x, y, w, h) {
		this->hp = hp;
		this->dmg = dmg;
	}

	void Hurt(int d) {
		if(!invuln)
			hp -= d;
	}

	int GetHP() {
		return hp;
	}

	void Hit(Player & p) {
		p.Hurt(dmg);
	}

	void SetInvuln(bool i) {
		invuln = i;
	}

	virtual void AI(Player p) = 0;
};

class Terrain : public Entity {
public:
	Terrain(int x, int y, int w, int h):Entity(x, y, w, h) {

	}

	void Update(float dt) {

	}
};

class Projectile : public Entity {
private:
	float timer;
	int dmg;
	Direction dir;
	
public:

	int getDamage()
	{
		return dmg;
	}

	float getTime()
	{
		return timer;
	}

	Direction getDir()
	{
		return dir;
	}

	void setTime(float t)
	{
		timer = t;
	}

	void setDir(Direction _dir)
	{
		dir = _dir;
	}

	Projectile(int x, int y, int w, int h, float time, int dmg) :Entity(x, y, w, h) {
		this->timer = time;
		this->dmg = dmg;
		this->setProjectile();
	}


	void Hit(Player & p) {
		p.Hurt(dmg);
	}

	void Hit(Enemy & e) {
		e.Hurt(dmg);
	}

	void Hit() {

	}

};

class Effect : public Entity {
private:
	float timer;
public:
	Effect(int x, int y, int w, int h, float time) {
		this->timer = time;
	}

	float getTime()
	{
		return timer;
	}

	void setTime(float t)
	{
		timer = t;
	}
};