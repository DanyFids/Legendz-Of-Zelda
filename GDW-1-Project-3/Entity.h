#pragma once
/*class Animation {
private:
	int num_frames = 0;
	int cur_frame = 0;
	std::vector<std::vector<std::string>>::iterator it;
public:
	std::vector<std::vector<std::string>> frames;
	
	void AddFrame(std::vector<std::string> f) {
		it = frames.end();
		frames.insert(it, f);
		num_frames++;
	}

	std::vector<std::string>* GetCurFrame() {
		std::vector<std::string>* ret = &frames[cur_frame];

		cur_frame++;
		if (cur_frame > num_frames) {
			cur_frame = 0;
		}

		return ret;
	}
};*/

class Entity {
private:
	int x, y, width, height;
	int cur_anim = 0;
	int num_animations = 0;
public:
	HANDLE sprite_sheet;

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

	void move(int xMv, int yMv) {
		if (!(x + xMv < 0)) {
			x += xMv;
		}
		if (!(y + yMv < 0)) {
			y += yMv;
		}
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

	virtual void HitDetect(Entity * other) = 0;

};