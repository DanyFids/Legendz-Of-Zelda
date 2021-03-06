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

	void Hurt(int d) {
		//instant explode
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

	void Update(float dt) {
		move();

		xSpd = 0;
		ySpd = 0;
	}
};

class Rope : public Enemy {
private:
	bool attack = true;
	bool l = false, r = false, d = false, u = false;
	bool Movement = false;
	int count = 0;
	int dir = 0;
public:
	Rope(int x, int y) : Enemy(x, y, 32, 14, 1, 1) {
		SetNumAnim(1);
		SetSpriteSheet(Sprites.ropeSprites);
	}
	void Hurt(int d) {
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
		if (l) {
			xSpd = -4;
			ySpd = 0;
			if (attack) {
				xSpd -= 4;
			}
		}
		else if (r) {
			xSpd = 4;
			ySpd = 0;
			if (attack) {
				xSpd += 4;
			}
		}
		else if (d) {
			ySpd = 2;
			xSpd = 0;
			if (attack) {
				ySpd += 2;
			}
		}
		else if (u) {
			ySpd = -2;
			xSpd = 0;
			if (attack) {
				ySpd -= 2;
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
			attack = true;
			l = false;
			d = false;
			r = false;
			u = false;
		}
		//Can Remove Later
		return (willHit(other, 0, 0));
	}
	void Update(float dt) {
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
	void Hurt(int d) {
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

	void Update(float dt) {
		move();
		xSpd = 0;
		ySpd = 0;
	}
};