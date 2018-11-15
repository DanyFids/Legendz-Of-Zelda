#pragma once

class Entity {
private:
	int x, y, width, height;
	int cur_anim = 0;
	int num_animations = 0;
public:
	HANDLE sprite_sheet;
	int xSpd, ySpd;

	Entity() {
		x = 0;
		y = 0;
		width = 0;
		height = 0;
	}

	Entity(int x, int y, int w, int h) {
		this->x = x;
		this->y = y;
		width = w;
		height = h;
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

	bool willHit(Entity * other, int offsetX, int offsetY) {
		if (other->GetX() < x + width + offsetX && other->GetX() + other->GetWidth() > x + offsetX && other->GetY() < y + height + offsetY && other->GetY() + other->GetHeight() > y + offsetY) {
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
		CHAR_INFO *outBuff = new CHAR_INFO[width * height];

		//Area to read/write
		SMALL_RECT screen;
		screen.Top = 0;
		screen.Left = 0;
		screen.Right = width - 1;
		screen.Bottom = height - 1;

		//Top Left COORD
		COORD start;
		start.X = 0;
		start.Y = 0;

		//Position
		COORD pos;
		pos.X = 0;
		pos.Y = 0;

		//Buffer Size
		COORD size;
		size.X = width;
		size.Y = height;

		ReadConsoleOutput(sprite_sheet, outBuff, size, start, &screen);

		screen.Top = y;
		screen.Left = x;
		screen.Right = width + x - 1;
		screen.Bottom = height + y - 1;

		WriteConsoleOutput(out, outBuff, size, pos, &screen);

	}

	void SetNumAnim(int num) {
		num_animations = num;
	}

	void SetCurAnim(int id) {
		cur_anim = id;
	}

	void SetSpriteSheet(HANDLE s) {
		sprite_sheet = s;
	}

	virtual bool HitDetect(Entity * other) = 0;
	virtual void Update() = 0;
};