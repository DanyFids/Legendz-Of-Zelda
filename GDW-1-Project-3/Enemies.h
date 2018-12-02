#pragma once


class SpikeTrap : public Enemy {
private:
	COORD origin;
	bool attack = true;
	bool l = false, r = false, u = false, d = false;
public:
	SpikeTrap(int x, int y) :Enemy(x, y, 32, 16, 1, 1) {
		SetNumAnim(1);
		
		SetSpriteSheet(Sprites.spiketrapSprites);

		origin.X = x;
		origin.Y = y;

		SetInvuln(true);
	}

	void AI(Player p) {
		//Resuming Attack formation
		if (!attack && GetX() == origin.X && GetY() == origin.Y) {
			attack = true;
		}

		//Spotting Player
		if (attack == true && l == false && r == false && d == false && u == false) {
			if (p.GetX() <= GetX() + GetWidth() && p.GetX() + p.GetWidth() >= GetX()) {
				if (GetY() + GetHeight() < p.GetY()) {	
					d = true;
				}
				else if ((p.GetY() + p.GetHeight()) < GetY()) {	
					u = true;
				}
			}
			else if (p.GetY() <= GetY() + GetHeight() && p.GetY() + p.GetHeight() >= GetY()) {
				if (GetX() + GetWidth() < p.GetX()) {
					r = true;
				}
				else if ((p.GetX() + p.GetWidth()) < GetX()) {
					l = true;
				}
			}
		}
		//Returning to orgin
		else if (attack == false && l == false && r == false && d == false && u == false) {
			if (GetY() != origin.Y) {
				if (GetY() < origin.Y) {
					d = true;
				}
				else if (origin.Y < GetY()) {
					u = true;
				}
			}
			else if (GetX() != origin.X) {
				if (GetX() < origin.X) {
					r = true;
				}
				else if (origin.X < GetX()) {
					l = true;
				}
			}

		}
		//Attack Movement
		if (l) {
			xSpd = -4;
			if (attack) {
				xSpd -= 4;
			}
		}
		else if (r) {
			xSpd = 4;
			if (attack) {
				xSpd += 4;
			}
		}
		else if (d) {
			ySpd = 2;
			if (attack) {
				ySpd += 2;
			}
		}
		else if (u) {
			ySpd = -2;
			if (attack) {
				ySpd -= 2;
			}
		}
		//Return to orgin
		if (!attack && l && GetX() + xSpd <= origin.X) {
			xSpd = origin.X - GetX();
			l = false;
		}

		if (!attack && r && GetX() + xSpd >= origin.X) {
			xSpd = origin.X - GetX();
			r = false;
		}

		if (!attack && u && GetY() + ySpd <= origin.Y) {
			ySpd = origin.Y - GetY();
			u = false;
		}

		if (!attack && d && GetY() + ySpd >= origin.Y) {
			ySpd = origin.Y - GetY();
			d = false;
		}
	}

	bool HitDetect(Entity * other) {
		//Test Wall
		if (GetX() + xSpd < 0) {
			xSpd = 0 - GetX();
			attack = false;
			l = false;
		}
		if (GetY() + ySpd < 0) {
			ySpd = 0 - GetY();
			attack = false;
			u = false;
		}
		if (GetX() + xSpd > 482) {
			xSpd = 482 - GetX();
			attack = false;
			r = false;
		}
		if (GetY() + ySpd > 208) {
			ySpd = 208 - GetY();
			attack = false;
			d = false;
		}
		//Can Remove Later

		if (willHit(other, 0, 0)) {
			attack = false;
			l = false;
			r = false;
			u = false;
			d = false;
		}

		return willHit(other, 0, 0);
	}

	void hitTerrain() {
	}

	void Update(float dt) {
		move();

		xSpd = 0;
		ySpd = 0;
	}
};

class Keese : public Enemy {
private:
	//Move randomly, periodically stop, can fly over blocks, cannot fly through walls

	bool rest = false;
	int rested = 0;
	bool hasMoved = false;
	int count = 0;
	bool wellRested = false;
	int restTimer = 0;
	int dir = 0;
	int sleepy = 0;
	
public:
	Keese(int x, int y) :Enemy(x, y, 32, 8, 1, 1) {
		SetNumAnim(1);

		SetSpriteSheet(Sprites.keeseSprites);

	}

	void AI(Player p) {
		std::random_device gen;
		std::uniform_int_distribution<> range(1, 8);

		if (!(wellRested)) {
			std::uniform_int_distribution<> spook(1, 200);
			sleepy = spook(gen);
			if (sleepy == 37) {
				rest = true;
			}
		}

		if (!(hasMoved)) {
			dir = range(gen);
		}
		if (!(rest)) {
			switch (dir)
			{
			case 1:
				//up
				ySpd = -1;
				hasMoved = true;
				break;
			case 2:
				//up right
				xSpd = 2;
				ySpd = -1;
				hasMoved = true;
				break;
			case 3:
				//right
				xSpd = 2;
				hasMoved = true;
				break;
			case 4:
				//down right
				xSpd = 2;
				ySpd = 1;
				hasMoved = true;
				break;
			case 5:
				//down
				ySpd = 1;
				hasMoved = true;
				break;
			case 6:
				//down left
				xSpd = -2;
				ySpd = 1;
				hasMoved = true;
				break;
			case 7:
				//left
				xSpd = -2;
				hasMoved = true;
				break;
			case 8:
				//left up
				xSpd = -2;
				ySpd = -1;
				hasMoved = true;
				break;
			}
		}
		if (hasMoved) {
			count++;
		}
		if (count >= 15) {
			hasMoved = false;
			count = 0;
		}

		if (rest) {
			rested++;
		}
		if (rested >= 40) {
			rest = false;
			rested = 0;
		}

		if (wellRested) {
			restTimer++;
			sleepy = 0;
		}
		if (restTimer >= 80) {
			wellRested = false;
			restTimer = 0;
		}
	}

	bool HitDetect(Entity * other) {
		//Cannot fly over walls

		//Test Wall
		if (GetX() + xSpd < 0) {
			xSpd = 0 - GetX();
		}
		if (GetY() + ySpd < 0) {
			ySpd = 0 - GetY();
		}
		if (GetX() + xSpd > 482) {
			xSpd = 482 - GetX();
		}
		if (GetY() + ySpd > 208) {
			ySpd = 208 - GetY();
		}
		//Can Remove Later
		
		return willHit(other, 0, 0);
	}

	void hitTerrain() {
	}

	void Update(float dt) {
		move();

		xSpd = 0;
		ySpd = 0;
	}
};

class Statue : public Enemy {
private:
	bool hasFired = false;
	int count = 0;
	COORD origin;
	float dirScale;
	FCOORD norDir;
	bool attack = false;
	bool innert = false;
public:

	std::vector<Projectile *> fireballs;
	Statue(int x, int y) :Enemy(x, y, 32, 16, 1, 1) {
		SetNumAnim(1);

		SetSpriteSheet(Sprites.spiketrapSprites);

		origin.X = x;
		origin.Y = y;

		SetInvuln(true);
	}

	FCOORD getFCOORD()
	{
		return norDir;
	}

	void AI(Player p) {

		COORD direction;
		//From orgin, fireball moves to the set location.

		direction.X = (origin.X - p.GetX());
		direction.Y = (origin.Y - p.GetY());

		dirScale = sqrt(pow(direction.X,2) + pow(direction.Y,2));

		norDir.X = direction.X / dirScale;
		norDir.Y = direction.Y / dirScale;

		if (count > 0) {
			count--;
		}
		if (count == 0) {
			count = 20;
			this->projectiles.push_back(new Fireball((this->GetX() + (this->GetWidth()/2) - 10), (this->GetY() + (this->GetHeight() / 2) - 5), norDir));
		}

	}

	bool HitDetect(Entity * other) {
		//Test Wall
		if (GetX() + xSpd < 0) {
			xSpd = 0 - GetX();
			attack = false;
		}
		if (GetY() + ySpd < 0) {
			ySpd = 0 - GetY();
			attack = false;
		}
		if (GetX() + xSpd > 482) {
			xSpd = 482 - GetX();
			attack = false;
		}
		if (GetY() + ySpd > 208) {
			ySpd = 208 - GetY();
			attack = false;
		}
		//Can Remove Later

		if (willHit(other, 0, 0)) {
			
		}

		return willHit(other, 0, 0);
	}

	void hitTerrain() {
	}

	void Update(float dt) {
		move();

		xSpd = 0;
		ySpd = 0;
	}

	Enemy * Clone() {
		return new Statue(*this);
	}
};

const float ROPE_COOLDOWN = 2.0f;
class Rope : public Enemy {
private:
	bool attack = true;
	bool canAttack = false;
	bool l = false, r = false, d = false, u = false;
	bool Movement = false;
	float cooldown = ROPE_COOLDOWN;
	int count = 0;
	int dir = 0;
public:
	Rope(int x, int y) : Enemy(x, y, 32, 14, 1, 1) {
		SetNumAnim(1);
		SetSpriteSheet(Sprites.ropeSprites);
	}

	void AI(Player p) {
		//Movement for the rope
		std::random_device gen;
		std::uniform_int_distribution<> range(1, 4);

		if (!(Movement)) {
			dir = range(gen);
		}

		switch (dir)
		{
		case 1:
			//up
			ySpd = -1;
			Movement = true;
			break;
		case 2:
			//Down
			ySpd = 1;
			Movement = true;
			break;
		case 3:
			//right
			xSpd = 2;
			Movement = true;
			break;
		case 4:
			//left
			xSpd = -2;
			Movement = true;
			break;
		}
		if (Movement) {
			count++;
		}
		if (count >= 60) {
			Movement = false;
			count = 0;
		}

		//Charge Link
		if (canAttack == true && l == false && r == false && d == false && u == false) {
			if (p.GetX() <= GetX() + GetWidth() && p.GetX() + p.GetWidth() >= GetX()) {
				if (GetY() + GetHeight() < p.GetY()) {
					d = true;
					attack = true;
					canAttack = false;
				}
				else if ((p.GetY() + p.GetHeight()) < GetY()) {
					u = true;
					attack = true;
					canAttack = false;
				}
			}
			else if (p.GetY() <= GetY() + GetHeight() && p.GetY() + p.GetHeight() >= GetY()) {
				if (GetX() + GetWidth() < p.GetX()) {
					r = true;
					attack = true;
					canAttack = false;
				}
				else if ((p.GetX() + p.GetWidth()) < GetX()) {
					l = true;
					attack = true;
					canAttack = false;
				}
			}
		}
		if (l) {
			xSpd = -2;
			ySpd = 0;
			if (attack) {
				xSpd -= 2;
			}
		}
		else if (r) {
			xSpd = 2;
			ySpd = 0;
			if (attack) {
				xSpd += 2;
			}
		}
		else if (d) {
			ySpd = 1;
			xSpd = 0;
			if (attack) {
				ySpd += 1;
			}
		}
		else if (u) {
			ySpd = -1;
			xSpd = 0;
			if (attack) {
				ySpd -= 1;
			}
		}

		if (cooldown <= 0) {
			canAttack = true;
		}
	}
	bool HitDetect(Entity * other) {
		//Test Wall
		bool hitWall = false;
		if (GetX() + xSpd < 0) {
			xSpd = 0 - GetX();
			hitWall = true;
		}
		if (GetY() + ySpd < 0) {
			ySpd = 0 - GetY();
			hitWall = true;
		}
		if (GetX() + xSpd > 482) {
			xSpd = 482 - GetX();
			hitWall = true;
		}
		if (GetY() + ySpd > 208) {
			ySpd = 208 - GetY();
			hitWall = true;
		}

		if (hitWall) {
			hitTerrain();
		}

		if (willHit(other, 0, 0)) {
			if (l || d || r || u) {
				Movement = false;
			}
			attack = true;
			l = false;
			d = false;
			r = false;
			u = false;
		}
		//Can Remove Later
		return (willHit(other, 0, 0));
	}

	void hitTerrain() {
		cooldown = ROPE_COOLDOWN;
		canAttack = false;
		attack = false;
		l = false;
		d = false;
		r = false;
		u = false;
		return;
	}

	void Update(float dt) {
		if (cooldown > 0) {
			cooldown -= dt;
			if (cooldown <= 0) {
				canAttack = true;
			}
		}
		move();
		xSpd = 0;
		ySpd = 0;
	}
};
class Gel : public Enemy {
private:
	bool bounce = false;
	bool hasMoved = false;
	int counter = 0;
	int count = 0;
	int dir = 0;
public:
	Gel(int x, int y) : Enemy(x, y, 12, 8, 1, 1) {
		SetNumAnim(1);
		SetSpriteSheet(Sprites.gelSprites);
	}

	void AI(Player p) {
		std::random_device gen;
		std::uniform_int_distribution<> range(1, 4);

		if (!(bounce)) {
			dir = range(gen);
		}

		switch (dir)
		{
		case 1:
			//up
			if (!(hasMoved)) {
				ySpd = -1;
				bounce = true;
				hasMoved = true;
			}
			break;
		case 2:
			//Down
			if (!(hasMoved)) {
				ySpd = 1;
				bounce = true;
				hasMoved = true;
			}
			break;
		case 3:
			//right
			if (!(hasMoved)) {
				xSpd = 2;
				bounce = true;
				hasMoved = true;
			}
			break;
		case 4:
			//left
			if (!(hasMoved)) {
				xSpd = -2;
				bounce = true;
				hasMoved = true;
			}
			break;
		}
		if (bounce) {
			count++;
		}
		if (count >= 10) {
			bounce = false;
			count = 0;
		}
		if (hasMoved) {
			counter++;
		}
		if (counter >= 6) {
			hasMoved = false;
			counter = 0;
		}
	}
	bool HitDetect(Entity * other) {
		//Test Wall
		if (GetX() + xSpd < 0) {
			xSpd = 0 - GetX();
		}
		if (GetY() + ySpd < 0) {
			ySpd = 0 - GetY();
		}
		if (GetX() + xSpd > 482) {
			xSpd = 482 - GetX();
		}
		if (GetY() + ySpd > 208) {
			ySpd = 208 - GetY();
		}
		if (willHit(other, 0, 0)) {

		}
		//Can Remove Later
		return (willHit(other, 0, 0));
	}

	void hitTerrain() {
	}

	void Update(float dt) {
		move();
		xSpd = 0;
		ySpd = 0;
	}
};
class Dodongo : public Enemy {
private:
	bool walk = false;
	bool hasMoved = false;
	int counter = 0;
	int count = 0;
	int dir = 0;
public:
	Dodongo(int x, int y) : Enemy(x, y, 12, 8, 1, 1) {
		SetNumAnim(1);
		setBoss(true);
		SetSpriteSheet(Sprites.gelSprites);
	}

	void AI(Player p) {
		std::random_device gen;
		std::uniform_int_distribution<> range(1, 4);

		if (!(walk)) {
			dir = range(gen);
		}

		switch (dir)
		{
		case 1:
			//up
			if (!(hasMoved)) {
				ySpd = -2;
				walk = true;
				hasMoved = true;
			}
			break;
		case 2:
			//Down
			if (!(hasMoved)) {
				ySpd = 2;
				walk = true;
				hasMoved = true;
			}
			break;
		case 3:
			//right
			if (!(hasMoved)) {
				xSpd = 4;
				walk = true;
				hasMoved = true;
			}
			break;
		case 4:
			//left
			if (!(hasMoved)) {
				xSpd = -4;
				walk = true;
				hasMoved = true;
			}
			break;
		}
		if (walk) {
			count++;
		}
		if (count >= 55) {
			walk = false;
			count = 0;
		}
		if (hasMoved) {
			counter++;
		}
		if (counter >= 1) {
			hasMoved = false;
			counter = 0;
		}
	}
	bool HitDetect(Entity * other) {
		//Test Wall
		if (GetX() + xSpd < 0) {
			xSpd = 0 - GetX();
		}
		if (GetY() + ySpd < 0) {
			ySpd = 0 - GetY();
		}
		if (GetX() + xSpd > 482) {
			xSpd = 482 - GetX();
		}
		if (GetY() + ySpd > 208) {
			ySpd = 208 - GetY();
		}
		if (willHit(other, 0, 0)) {

		}
		//Can Remove Later


		return (willHit(other, 0, 0));
	}

	void Update(float dt) {
		move();
		xSpd = 0;
		ySpd = 0;
	}
	void hitTerrain() {
	}

	Enemy * Clone() {
		return new Dodongo(*this);
	}
};

const float GORYIA_COOLDOWN = 10.0f;
class Goryia : public Enemy {
private:
	bool hop = false;
	bool hasMoved = false;
	float cooldown = 0;
	bool isBlue = false;
	int add = 0;
	int counter = 0;
	int count = 0;
	int dir = 0;
	int getX = 0;
	int getY = 0;
public:
	Goryia(int x, int y, bool b) : Enemy(x, y, 12, 8, 3, 1) {
		SetNumAnim(1);
		isBlue = b;
		getX = x;
		getY = y;
		if (isBlue) {
			setHP(5);
		}
		SetSpriteSheet(Sprites.gelSprites);
	}
	void AI(Player p) {
		if (cooldown <= 0) {
			std::random_device gen;
			std::uniform_int_distribution<> range(1, 4);
			std::uniform_int_distribution<> willThrow(1, 4);

			if (!(hop)) {
				int wT = willThrow(gen);
				if (wT == 1) {
					switch (dir) {
					case 1:
						projectiles.push_back(new Boomerang(getX, getY, 0, -1, Up));
						break;
					case 2:
						projectiles.push_back(new Boomerang(getX, getY, 0, 1, Down));
						break;
					case 3:
						projectiles.push_back(new Boomerang(getX, getY, 2, 0, Right));
						break;
					case 4:
						projectiles.push_back(new Boomerang(getX, getY, -2, 0, Left));
						break;
					}
					cooldown = GORYIA_COOLDOWN;
					return;
				}
				else {
					dir = range(gen);
				}
			}
			switch (dir)
			{
			case 1:
				//up
				if (!(hasMoved)) {
					ySpd = -1;
					hop = true;
					hasMoved = true;
					
					
				}
				break;
			case 2:
				//Down
				if (!(hasMoved)) {
					ySpd = 1;
					hop = true;
					hasMoved = true;
					
				}
				break;
			case 3:
				//right
				if (!(hasMoved)) {
					xSpd = 2;
					hop = true;
					hasMoved = true;
					
				}
				break;
			case 4:
				//left
				if (!(hasMoved)) {
					xSpd = -2;
					hop = true;
					hasMoved = true;
					
				}
				break;
			}
			if (hop) {
				count++;
			}
			if (count >= 30) {
				hop = false;
				count = 0;
			}
			if (hasMoved) {
				counter++;
			}
			if (counter >= 4) {
				hasMoved = false;
				counter = 0;
			}
		}
	}
	bool HitDetect(Entity * other) {
		//Test Wall
		if (GetX() + xSpd < 0) {
			xSpd = 0 - GetX();
		}
		if (GetY() + ySpd < 0) {
			ySpd = 0 - GetY();
		}
		if (GetX() + xSpd > 482) {
			xSpd = 482 - GetX();
		}
		if (GetY() + ySpd > 208) {
			ySpd = 208 - GetY();
		}
		if (willHit(other, 0, 0)) {

		}
		//Can Remove Later
		return (willHit(other, 0, 0));
	}

	void hitTerrain() {
	}

	void Update(float dt) {
		move();
		cooldown -= dt;
		xSpd = 0;
		ySpd = 0;

		for (int b = 0; b < projectiles.size(); b++) {
			projectiles[b]->Update(dt);
		}
	}
	Enemy * Clone() {
		return new Goryia(*this);
	}
};