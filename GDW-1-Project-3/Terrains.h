#pragma once
class Wall : public Terrain {

public:
	Wall(int x, int y) : Terrain(x, y, 32, 16, true) {
		SetSpriteSheet(Sprites.blockSprites);
	}
	Wall(int x, int y, int w, int h) : Terrain(x, y, w, h, true) {
		SetSpriteSheet(Sprites.blockSprites);
	}
	Wall(COORD XY) : Terrain(XY.X, XY.Y, 32, 16, true) {
		SetSpriteSheet(Sprites.blockSprites);
	}

	bool HitDetect(Entity * other) {
		if (willHit(other, other->xSpd, other->ySpd)) {
			if (willHit(other, other->xSpd, 0)) {
				if (other->xSpd > 0) {
					other->xSpd = GetX() - (other->GetX() + other->GetWidth());
				}
				else {
					other->xSpd = (GetX() + GetWidth()) - other->GetX();
				}
			}
			if (willHit(other, 0, other->ySpd)) {
				if (other->ySpd > 0) {
					other->ySpd = GetY() - (other->GetY() + other->GetHeight());
				}
				else {
					other->ySpd = (GetY() + GetHeight()) - other->GetY();
				}
				
				
			}
			if (willHit(other, other->xSpd, other->ySpd)) {
				if (other->xSpd > 0) {
					other->xSpd = GetX() - (other->GetX() + other->GetWidth());
				}
				else {
					other->xSpd = (GetX() + GetWidth()) - other->GetX();
				}
				if (other->ySpd > 0) {
					other->ySpd = GetY() - (other->GetY() + other->GetHeight());
				}
				else {
					other->ySpd = (GetY() + GetHeight()) - other->GetY();
				}
			}
		}

		return true;
	}

};

class Block : public Terrain {

public:
	Block(int x, int y) : Terrain(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}

	bool HitDetect(Entity * other) {
		if (!other->IsFlying()) {
			if (willHit(other, other->xSpd, other->ySpd)) {
				if (willHit(other, other->xSpd, 0)) {
					if (other->xSpd > 0) {
						other->xSpd = GetX() - (other->GetX() + other->GetWidth());
					}
					else {
						other->xSpd = (GetX() + GetWidth()) - other->GetX();
					}
				}
				if (willHit(other, 0, other->ySpd)) {
					if (other->ySpd > 0) {
						other->ySpd = GetY() - (other->GetY() + other->GetHeight());
					}
					else {
						other->ySpd = (GetY() + GetHeight()) - other->GetY();
					}


				}
				if (willHit(other, other->xSpd, other->ySpd)) {
					if (other->xSpd > 0) {
						other->xSpd = GetX() - (other->GetX() + other->GetWidth());
					}
					else {
						other->xSpd = (GetX() + GetWidth()) - other->GetX();
					}
					if (other->ySpd > 0) {
						other->ySpd = GetY() - (other->GetY() + other->GetHeight());
					}
					else {
						other->ySpd = (GetY() + GetHeight()) - other->GetY();
					}
				}
			}
		}

		return false;
	}
};
class Hole : public Terrain {

public:
	Hole(int x, int y) : Terrain(x, y, 32, 16) {
		//SetSpriteSheet(Sprites.enemySprites);
	}

	bool HitDetect(Entity * other) {
		if (!other->IsFlying()) {
			if (willHit(other, other->xSpd, other->ySpd)) {
				if (willHit(other, other->xSpd, 0)) {
					if (other->xSpd > 0) {
						other->xSpd = GetX() - (other->GetX() + other->GetWidth());
					}
					else {
						other->xSpd = (GetX() + GetWidth()) - other->GetX();
					}
				}
				if (willHit(other, 0, other->ySpd)) {
					if (other->ySpd > 0) {
						other->ySpd = GetY() - (other->GetY() + other->GetHeight());
					}
					else {
						other->ySpd = (GetY() + GetHeight()) - other->GetY();
					}


				}
				if (willHit(other, other->xSpd, other->ySpd)) {
					if (other->xSpd > 0) {
						other->xSpd = GetX() - (other->GetX() + other->GetWidth());
					}
					else {
						other->xSpd = (GetX() + GetWidth()) - other->GetX();
					}
					if (other->ySpd > 0) {
						other->ySpd = GetY() - (other->GetY() + other->GetHeight());
					}
					else {
						other->ySpd = (GetY() + GetHeight()) - other->GetY();
					}
				}
			}
		}

	}
};
class Door : public Terrain {
private:
	bool open;
public:
	Door(int x, int y, bool isO = true) : Terrain(x, y, 64, 32) {
		SetSpriteSheet(Sprites.doorSprites);
		open = isO;
	}
	Door(COORD XY, Direction d, bool isO = true) : Terrain(XY.X, XY.Y, 64, 32) {
		SetSpriteSheet(Sprites.doorSprites);
		open = isO;
		SetNumAnim(4);
		switch (d) {
		case Down:
			SetCurAnim(0);
			break;
		case Up:
			SetCurAnim(1);
			break;
		case Left:
			SetCurAnim(2);
			break;
		case Right:
			SetCurAnim(3);
		}

		if (isO) {
			SetCurFrame(0);
		}
		else {
			SetCurFrame(1);
		}
	}

	bool IsOpen() {
		return open;
	}

	void setOpen(bool f) {
		open = f;
		if (open) {
			SetCurFrame(0);
		}
		else {
			SetCurFrame(1);
		}
	}

	bool HitDetect(Entity * other) {
		if (!IsOpen()) {
			bool nope = willHit(other, other->xSpd, other->ySpd);
			if (willHit(other, other->xSpd, other->ySpd)) {
				if (willHit(other, other->xSpd, 0)) {
					if (other->xSpd > 0) {
						other->xSpd = GetX() - (other->GetX() + other->GetWidth());
					}
					else {
						other->xSpd = (GetX() + GetWidth()) - other->GetX();
					}
				}
				if (willHit(other, 0, other->ySpd)) {
					if (other->ySpd > 0) {
						other->ySpd = GetY() - (other->GetY() + other->GetHeight());
					}
					else {
						other->ySpd = (GetY() + GetHeight()) - other->GetY();
					}


				}
				if (willHit(other, other->xSpd, other->ySpd)) {
					if (other->xSpd > 0) {
						other->xSpd = GetX() - (other->GetX() + other->GetWidth());
					}
					else {
						other->xSpd = (GetX() + GetWidth()) - other->GetX();
					}
					if (other->ySpd > 0) {
						other->ySpd = GetY() - (other->GetY() + other->GetHeight());
					}
					else {
						other->ySpd = (GetY() + GetHeight()) - other->GetY();
					}
				}
			}

			return nope;
		}

		return false;

	}
};