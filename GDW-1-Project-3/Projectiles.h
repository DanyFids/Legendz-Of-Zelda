#pragma once
#include <cmath>


// --------------------------------------------- Links Sword for Sword swings
class Sword : public Projectile { //It's a projectile, that doesnt MOVE! :O | Are you sassing me, young man?

private:

public:	   // x,y coord,                  width*2,height,time,damage,speed
		   // the x+30 and y+3 is to make it appear infront of link, this needs to be changed by direction. sooner or later.
	Sword(int x, int y, Direction _dir) : Projectile(x, y, 32, 16, 0.3f, 1) {
		this->setDir(_dir);
		this->setEnum(PT_SWORD);
		SetSpriteSheet(Sprites.swordSprites);
		SetNumAnim(4);

		switch (_dir) {
		case Up:
			SetCurAnim(0);
			break;
		case Down:
			SetCurAnim(1);
			break;
		case Right:
			SetCurAnim(2);
			break;
		case Left:
			SetCurAnim(3);
			break;
		}
	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
	}

};

//// ------------------------------------------ Sword Projectile shot by Link at FULL HP


class BeamSword : public Projectile { //It's a projectile, that doesnt MOVE! :O | Are you sassing me, young man?

private:


public:	   // x,y coord,                  width*2,height,time, damage, speed
		   // the x+30 and y+3 is to make it appear infront of link, this needs to be changed by direction. sooner or later.
	BeamSword(int x, int y, int x_spd, int y_spd, Direction _dir) : Projectile(x, y, 32, 7, 3.0f, 1) {
		//Sprite sheet
		//set the sprite sheet!
		this->setDir(_dir);
		this->setEnum(PT_BEAMSWORD);
		this->SetSpriteSheet(Sprites.swordSprites);
		

		switch (_dir) {
		case Up:
			SetCurAnim(0);
			SetCurFrame(1);
			break;
		case Down:
				SetCurAnim(1);
				SetCurFrame(1);
				break;
			case Right:
				SetCurAnim(2);
				SetCurFrame(1);
				break;
			case Left:
				SetCurAnim(3);
				SetCurFrame(1);
				break;
		}
		
		//Speeds
		xSpd = x_spd;
		ySpd = y_spd;

	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	void Update(float dt)
	{
		move();
		this->setTime(this->getTime() - dt);
	}

};



		//---------------------------------------------------------Arrows shot by Link

class Arrow : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,							   lifetime, damage
	Arrow(int x, int y,int x_spd,int y_spd, Direction _dir) : Projectile(x, y, 34, 17, 5.0f, 1) {
		this->setDir(_dir);
		this->setEnum(PT_ARROW);
		xSpd = x_spd;
		ySpd = y_spd;

		SetSpriteSheet(Sprites.arrowSprites);
		SetCurFrame(0);
		SetCurAnim(0);
	}

	

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	void Update(float dt)
	{
		move();
		this->setTime(this->getTime() - dt);
	}

};


// ----------------------------------------------------  Firballs for --> Stone Statues,

class Fireball : public Projectile {

private:

public:	   // x,y coord,                  width*2,height,					lifetime, damage, speed 
	Fireball(int x, int y, FCOORD dir) : Projectile(x, y, 20, 10, 10.0f, 1) {
		SetSpriteSheet(Sprites.bombSprites);
		this->xSpd = dir.X * (-8);
		this->ySpd = dir.Y * (-4);
		this->setEnum(PT_FIREBALL);
	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	void Update(float dt)
	{
		move();
		this->setTime(this->getTime() - dt);
	}

};


// --------------------------------------------- Bombs place by Link

class Bomb : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Bomb(int x, int y) : Projectile(x, y, 28, 14, 3.0f, 0) {	   //28 , 14
		this->setEnum(PT_BOMB);
		SetSpriteSheet(Sprites.bombSprites);
		SetCurFrame(0);
	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
		this->nextFrame();

	}

};

// ----------------------------------------- Explosions from bombs

class Explosion : public Projectile {

private:
	

public:	   // x,y coord,                  width*2,height,lifetime, damage, 
	Explosion(int x, int y) : Projectile(x, y, 64, 32, 2.0f, 3) {
		this->setEnum(PT_EXPLOSION);
		this->SetSpriteSheet(Sprites.explosionSprites);
		 
	}


	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
	}

};


//// ------------------------------------------- Boomerangs that are thrown by Link or Goriyas

class Boomerang : public Projectile {

private:
	int startX;
	int startY;
	float startTime;
	bool rebounded = false;
	Entity * parent;

public:	   // x,y coord,                  width*2,height,		   || lifetime, damage,  
	Boomerang(int x, int y, int x_spd, int y_spd, Entity * p) : Projectile(x, y, 16, 8, 5.0f, 1) {
		//this->setDir(_dir);			  //The Entity Pointer should point to it's parent via &player or &goriya etc.
		this->setEnum(PT_BOOMERANG);
		this->SetSpriteSheet(Sprites.boomerangSprites);
		this->SetCurFrame(1);

		xSpd = x_spd;
		ySpd = y_spd;

		startX = x;
		startY = y;
		startTime = this->getTime();

		parent = p;
	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);	
	}

	void rebound() {

		if (this->getTime() <= (this->startTime / 2)&& !rebounded)
		{
			rebounded = true;
		}

		if (rebounded)
		{
			int distX = (parent->GetX() + (parent->GetWidth() / 2)) - this->GetX();
			int distY = (parent->GetY() + (parent->GetHeight() / 2)) - this->GetY();

			float dirScale = sqrt(pow(distX, 2) + pow(distY, 2));
			
			xSpd = (distX / dirScale) * (12);
			ySpd = (distY / dirScale) * (6);

		}
	}

	void Update(float dt)
	{
		move();
		rebound();
		this->setTime(this->getTime() - dt);
		this->nextFrame();
		//These are checks to see if it's near the player/goriya so that it destroys itself
		if (this->HitDetect(parent) && rebounded)
		{
			this->setTime(0.0f);
			
		}
	}

	
	

};
