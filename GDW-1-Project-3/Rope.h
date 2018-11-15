
class rope : public Enemy {
private:
	bool attack = true;
	bool l = false, r = false, d = false, u = false;
	bool Movement = false;
	int count = 0;
	int dir = 0;
public:
	rope(int x, int y) : Enemy(x, y, 30, 16, 1, 1) {
		SetNumAnim(1);
		SetSpriteSheet(Sprites.enemySprites);
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
	void Update() {
		move();
		xSpd = 0;
		ySpd = 0;
	}
};
class gel : public Enemy {
private:
	bool bounce = false;
	bool hasMoved = false;
	int counter = 0;
	int count = 0;
	int dir = 0;
public:
	gel(int x, int y) : Enemy(x, y, 30, 16, 1, 1) {
		SetNumAnim(1);
		SetSpriteSheet(Sprites.enemySprites);
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

	void Update() {
		move();
		xSpd = 0;
		ySpd = 0;
	}
};