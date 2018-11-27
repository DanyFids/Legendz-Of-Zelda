#pragma once
class Wall : public Terrain {

public:
	Wall(int x, int y) : Terrain(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}

	bool HitDetect(Entity * other) {
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

};

class Block : public Terrain {

public:
	Block(int x, int y) : Terrain(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}

	bool HitDetect(Entity * other) {
		bool nope = willHit(other, other->xSpd, other->ySpd);
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
		return nope;
	}
};
class Hole : public Terrain {

public:
	Hole(int x, int y) : Terrain(x, y, 32, 16) {
		//SetSpriteSheet(Sprites.enemySprites);
	}

	bool HitDetect(Entity * other) {
		bool nope = willHit(other, other->xSpd, other->ySpd);
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
		return nope;
	}
};
class Door : public Terrain {
private:
	bool open;
public:
	Door(int x, int y) : Terrain(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}
	bool IsOpen() {
		return open;
	}

	void setOpen(bool f) {
		open = f;
	}

	bool HitDetect(Entity * other) {
		bool nope = willHit(other, other->xSpd, other->ySpd);
		if (!IsOpen()) {
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
		return nope;
	}
};

class MoveableBlock : public Terrain {
private:
	bool playerHit = false;
	bool lock = false;
public:
	bool HitDetect(Entity * other) {
		bool nope = willHit(other, other->xSpd, other->ySpd);
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

		if (nope) {
			SetMvDir(other->GetDir());
		}

		return nope;

	}

	void Lock() {
		lock = true;
	}

	void Unlock() {
		lock = false;
	}
};

class BombableWall : public Terrain {
private:
public:

	bool HitDetect(Entity * other) {
		bool nope = willHit(other, other->xSpd, other->ySpd);
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

		return nope;
	}
};


class LockedDoor : public Terrain {
private:
	bool open;
public:
	LockedDoor(int x, int y) : Terrain(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}
	bool IsOpen() {
		return open;
	}

	void setOpen(bool f) {
		open = f;
	}

	bool HitDetect(Entity * other) {
		bool nope = willHit(other, other->xSpd, other->ySpd);
		if (!IsOpen() && (player_file->Keys == 0)) {
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
		else {
				open = true;
				player_file->Keys -= 1;

			}
		}
		return nope;
	}
};
