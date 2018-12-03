#pragma once
// List of all Flashy Effects Classes

class Smoke : public VisualFX
{
private:

public:
			  //Pos XY		 Pixel W/H		float Time 
	Smoke(int x, int y) : VisualFX(x,y,32,16, 0.5)
	{
		
		this->SetSpriteSheet(Sprites.smokeSprites);
		this->SetCurFrame(0);
	}

	bool HitDetect(Entity * e) {
		return false;
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
	}
};

class Blip : public VisualFX
{
private:

public:
	//Pos XY		 Pixel W/H		float Time 
	Blip(int x, int y) : VisualFX(x, y, 30, 16, 0.5)
	{
		this->SetSpriteSheet(Sprites.blipSprites);
		this->SetCurFrame(1);
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
	}

	bool HitDetect(Entity * e) {
		return false;
	}
};
