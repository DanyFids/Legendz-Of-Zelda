#pragma once
struct Player_Input {
	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool keyRight;
	bool keySpace;
};

Player_Input player_input;

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

Player_Info * player_file;

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

	virtual void AI(Player p) = 0;
};

class Terrain : public Entity {
private:
	float move_timer = MOVE_TIME;
	float moving_timer = 0;
	Direction moveDir;
	bool canMove;
public:
	const float MOVE_TIME = 0.05f;

	Terrain(int x, int y, int w, int h, bool cM = false) :Entity(x, y, w, h) {
		canMove = cM;
	}

	bool CanMove() {
		return canMove;
	}

	void Update(float dt) {
		if (move_timer > 0) {
			move_timer -= dt;
			if (move_timer <= 0) {
				moving_timer = 2.0f;
			}
		}
		else {
			if (moving_timer > 0) {
				switch (GetMvDir()) {
				case Up:
					ySpd = -1;
					xSpd = 0;
					break;
				case Down:
					ySpd = 1;
					xSpd = 0;
					break;
				case Left:
					ySpd = 0;
					xSpd = -1;
					break;
				case Right:
					ySpd = 0;
					xSpd = 1;
					break;
				}
				move();
				moving_timer -= dt;
				if (moving_timer <= 0) {
					canMove = false;
				}
			}
		}
	}

	bool isMoving() {
		if (moving_timer > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void SetMvDir(Direction d) {
		moveDir = d;
	}

	Direction GetMvDir() {
		return moveDir;
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

class PowerUp : public Entity {
public:
	virtual void Effect(Player_Info stats)=0;

};
