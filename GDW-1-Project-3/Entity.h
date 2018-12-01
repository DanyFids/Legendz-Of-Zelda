#pragma once

class Entity {
private:
	int x, y;
	int width, height;
	int cur_anim = 0;
	int num_animations = 0;
	int cur_frame = 0;
	std::vector<int> num_frames;
	bool flying;
	Direction dir;
	bool isProjectile = false;
	bool isPlayer = false;
	ProjType type;
public:
	HANDLE sprite_sheet;
	int xSpd, ySpd;

	Entity() {
		x = 0;
		y = 0;
		width = 0;
		height = 0;
	}

	Entity(int x, int y, int w, int h, bool isP = false) {
		this->x = x;
		this->y = y;
		width = w;
		height = h;
		isPlayer = isP;
	}

	int GetX() {
		return x;
	}

	int GetY() {
		return y;
	}

	int GetWidth() {
		return width;
	}

	int GetHeight() {
		return height;
	}

	bool IsFlying() {
		return flying;
	}

	void setFly(bool f) {
		flying = f;
	}

	bool willHit(Entity * other, int offsetX, int offsetY) {
		if (other->GetX() + offsetX < x + width && other->GetX() + other->GetWidth() + offsetX > x && other->GetY() + offsetY < y + height && other->GetY() + other->GetHeight() + offsetY > y) {
			return true;
		}
		else {
			return false;
		}
	}

	void move() {
		x += xSpd;
		y += ySpd;
	}
	
	void draw(HANDLE out) {
		Sprites.DrawSprite(sprite_sheet, (width+2) * cur_anim, (height + 1) * cur_frame, width, height, out, x, y);
	}

	void SetNumAnim(int num) {
		num_animations = num;
	}

	void SetCurAnim(int id) {
		cur_anim = id;
	}

	void SetCurFrame(int id) {
		cur_frame = id;
	}

	void SetSpriteSheet(HANDLE s) {
		sprite_sheet = s;
	}

	void SetDir(Direction d) {
		dir = d;
	}

	Direction GetDir() {
		return dir;
	}

	ProjType getEnum()
	{
		return type;
	}

	void setEnum(ProjType t)
	{
		type = t;
	}

	void setProjectile()
	{
		isProjectile = true;
	}

	bool getProjectile()
	{
		return isProjectile;
	}

	bool IsPlayer() {
		return isPlayer;
	}

	virtual bool HitDetect(Entity * other) = 0;
	virtual void Update(float dt) = 0;
};