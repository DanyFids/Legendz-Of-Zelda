#pragma once
struct Player_Input {
	bool keyUp;
	bool keyDown;
	bool keyLeft;
	bool keyRight;
	bool keySpace;
};

typedef struct _FCOORD {
	float X;
	float Y;
} FCOORD, *FPCOORD;

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

Player_Input player_input;

class Projectile;


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

const float STUNTIME = 3.0f;

class PowerUp;

class Enemy : public Entity {
private:
	int dmg, hp;
	bool invuln;
	float stunTimer = 0.0f;
	EnemyType et;
	bool hasFired;
	bool isDodongo = false;
	FCOORD location;
public:
	std::vector<Projectile *> projectiles;

	Enemy(int x, int y, int w, int h, int hp, int dmg) :Entity(x, y, w, h) {
		this->hp = hp;
		this->dmg = dmg;

		this->location.X = x;
		this->location.Y = y;
		
	}

	void stun()
	{
		stunTimer = STUNTIME;
	}

	float getStunTime() {
		return stunTimer;
	}
	void setStunTime(float t) {
		stunTimer = t;
	}


	void Hurt(int d) {
		if(!invuln)
			hp -= d;
	}

	void Death() {

	}

	void setBoss(bool _boss) {
		isDodongo = _boss;
	}

	bool getBoss() {
		return isDodongo;
	}

	FCOORD getFCOORD()
	{
		return location;
	}

	bool getAttackState()
	{
		return hasFired;
	}

	void setAttackState()
	{
		hasFired = true;
	}

	void setHP(int _hp) {
		hp = _hp;
	}

	int GetHP() {
		return hp;
	}


	void Hit(Player & p) {
		p.Hurt(dmg);
	}

	EnemyType GetType() {
		return et;
	}

	void SetInvuln(bool i) {
		invuln = i;
	}

	void Drop(std::vector<PowerUp *> * pl);


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


	void move();
	
	void draw(HANDLE out);

	virtual void AI(Player p) = 0;
	virtual void hitTerrain() = 0;
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
};


class PowerUp : public Entity {
public:
	PowerUp(int x, int y, int w, int h) :Entity(x, y, w, h) {

	}

	void Update(float dt) {

	}


	virtual void Effect(Player_Info * stats)=0;

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