#pragma once
// List of all Flashy Effects Classes

class Smoke : public VisualFX
{
private:
	float startTime;
public:
			  //Pos XY		 Pixel W/H		float Time 
	Smoke(int x, int y) : VisualFX(x,y,32,16, 0.4)
	{
		startTime = this->getTime();
		this->SetSpriteSheet(Sprites.smokeSprites);
		this->SetCurFrame(0);
	}

	bool HitDetect(Entity * e) {
		return false;
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
		if (this->getTime() <= startTime / 2) {
			SetCurFrame(1);
		}
	}
};

class Blip : public VisualFX
{
private:
	float startTime;
public:
	//Pos XY		 Pixel W/H		float Time 
	Blip(int x, int y) : VisualFX(x, y, 30, 16, 0.3)
	{
		this->SetSpriteSheet(Sprites.blipSprites);
		this->SetCurFrame(1);
		startTime = this->getTime();
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
		if (this->getTime() <= startTime / 2) {
			this->SetCurFrame(0);
		}
	}

	bool HitDetect(Entity * e) {
		return false;
	}
};
