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
	int hp = 6;
	bool can_attack = true;
	float stop_timer = 0;
public:
	Player(int x, int y) :Entity(x, y, 30, 16) {
		SetNumAnim(1);


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
	
	void Drop(bool drop = false, int per = 0) {
		std::random_device gen;
		std::uniform_int_distribution<> range(1, 5);
		if (!(drop)) {
			per = range(gen);
		}
		switch (per){
		case 1:
			std::cout << "hello world";
		}
	}

	bool Boundries(Entity * other) {
		//Test Wall
		if (GetX() + GetWidth() + xSpd < 32) {
			xSpd = 32 - GetX();
		}
		if (GetY() + GetHeight() + ySpd < 80) {
			ySpd = 80 - GetY();
		}
		if (GetX() + GetWidth() + xSpd > 480) {
			xSpd = 480 - GetX();
		}
		if (GetY() + GetHeight() + ySpd > 224) {
			ySpd = 224 - GetY();
		}
		if (willHit(other, 0, 0)) {

		}
		//Can Remove Later
		return (willHit(other, 0, 0));
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
	int dmg,speed;
	float theta, timer;
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

	float getTime()
	{
		return timer;
	}

	void setTime(float t)
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