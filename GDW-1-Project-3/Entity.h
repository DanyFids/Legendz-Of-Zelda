#pragma once

class Entity {
private:
	int x, y;
	int width, height;
	int cur_anim = 0;
	int num_animations = 0;
	bool flying;
	Direction dir;
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
		int drX = 0;
		if (x < 0) {
			drX = -x;
		}

		int drY = 0;
		if (y < 0) {
			drY = -y;
		}

		CHAR_INFO *outBuff = new CHAR_INFO[width * height];
		CHAR_INFO *transBuff = new CHAR_INFO[width * height];

		//Area to read/write
		SMALL_RECT screen;
		screen.Top = drY;
		screen.Left = drX;
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
		size.X = width - drX;
		size.Y = height - drY;

		ReadConsoleOutput(sprite_sheet, outBuff, size, start, &screen);

		screen.Top = y + drY;
		screen.Left = x + drX;
		screen.Right = width + x - 1;
		screen.Bottom = height + y - 1;

		ReadConsoleOutput(out, transBuff, size, pos, &screen);

		for (int p = 0; p < (width * height); p++) {
			if (outBuff[p].Attributes == 7) {
				outBuff[p] = transBuff[p];
			}
		}

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

	void SetDir(Direction d) {
		dir = d;
	}

	Direction GetDir() {
		return dir;
	}

	virtual bool HitDetect(Entity * other) = 0;
	virtual void Update(float dt) = 0;
};