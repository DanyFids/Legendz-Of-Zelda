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
	bool puzzles_solved[7] = { false, false, false, false, false, false, false };
};

Player_Info PLAYER_FILES[3];
Player_Info * player_file;

Player_Info * player_file;

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
		if (invulnTimer <= 0) {
			player_file->CurLife -= d;
			invulnTimer = 15;
		}
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

		if (invulnTimer > 0) {
			invulnTimer--;
		}

		xSpd = 0;
		ySpd = 0;
	}

	bool CanAtk() {
		return can_attack;
	}

	void SwingSword() {
		can_attack = false;
		stop_timer = 0.4f;
	}

	int GetHp() {
		return hp;
	}
};

class Enemy : public Entity {
private:
	int dmg, hp;
	bool invuln;
	EnemyType et;
public:
	Enemy(int x, int y, int w, int h, int hp, int dmg, EnemyType type = ET_DEFAULT) :Entity(x, y, w, h) {
		this->hp = hp;
		this->dmg = dmg;
		this->et = type;
	}

	void Hurt(int d) {
		if(!invuln)
			hp -= d;
	}

	int GetHP() {
		return hp;
	}

	void SetHP(int h) {
		hp = h;
	}

	void Hit(Player & p) {
		p.Hurt(dmg);
	}

	void SetInvuln(bool i) {
		invuln = i;
	}

	EnemyType GetType() {
		return et;
	}

	virtual void AI(Player p) = 0;
	virtual Enemy* Clone() = 0;
};

class Terrain : public Entity {
private:
	float move_timer = MOVE_TIME;
	float moving_timer = 0;
	Direction moveDir;
	bool canMove;
public:
	const float MOVE_TIME = 0.05f;

	Terrain(int x, int y, int w, int h, bool hide = false, bool cM = false) :Entity(x, y, w, h, hide) {
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
	float theta, timer;
	int dmg;
	Direction dir;
	ProjType type;
public:

	float getTheta()
	{
		return theta;
	}

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

	void setTheta(float _theta)
	{
		theta = _theta;
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

	void Hit(Enemy * e);
};

class PowerUp : public Entity {
public:
	PowerUp(int x, int y, int w, int h) :Entity(x, y, w, h) {

	}

	virtual void Effect(Player_Info * stats)=0;

};
