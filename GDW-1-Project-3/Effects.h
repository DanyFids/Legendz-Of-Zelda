#pragma once
// List of all Flashy Effects Classes

class Smoke : public Effect
{
private:

public:
			  //Pos XY		 Pixel W/H		float Time 
	Smoke(int x, int y) : Effect(x,y , 64,32, 0.5f)
	{
		
		this->SetSpriteSheet(Sprites.smokeSprites);
		this->SetCurFrame(0);
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
	}
};

class Blip : public Effect
{
private:

public:
	//Pos XY		 Pixel W/H		float Time 
	Blip(int x, int y) : Effect(x, y, 30, 16, 0.5f)
	{
		this->SetSpriteSheet(Sprites.blipSprites);
		this->SetCurFrame(0);
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
	}
};
