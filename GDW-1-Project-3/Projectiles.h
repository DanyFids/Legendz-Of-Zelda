#pragma once

// --------------------------------------------- Links Sword for Sword swings

class Sword : public Projectile { //It's a projectile, that doesnt MOVE! :O | Are you sassing me, young man?

private:


public:	   // x,y coord,                  width*2,height,time,damage,speed
		   // the x+30 and y+3 is to make it appear infront of link, this needs to be changed by direction. sooner or later.
	Sword(int x, int y, Direction _dir) : Projectile(x, y, 32, 16, 0.2, 1, 0) {
		this->setDir(_dir);
		SetSpriteSheet(Sprites.swordSprites);
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
	BeamSword(int x, int y, Direction _dir) : Projectile(x, y, 32, 7, 1, 1, 2) {
		this->setDir(_dir);

	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	void Update()
	{
		this->setTime(this->getTime() - 1);
	}

};



		//---------------------------------------------------------Arrows shot by Link

class Arrow : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Arrow(int x, int y, Direction _dir) : Projectile(x + 30, y + 3, 32, 7, 1, 1, 1) {
		this->setDir(_dir);
	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	void Update()
	{
		this->setTime(this->getTime() - 1);
	}

};


// ----------------------------------------------------  Firballs for --> Stone Statues,

class Fireball : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Fireball(int x, int y, float _theta) : Projectile(x + 30, y + 3, 32, 7, 1, 1, 1) {
		this->setTheta(_theta);

	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	void Update()
	{
		this->setTime(this->getTime() - 1);
	}

};


// --------------------------------------------- Bombs place by Link

class Bomb : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Bomb(int x, int y) : Projectile(x, y, 32, 7, 3, 0, 0) {


	}

	bool HitDetect(Entity * e)
	{
		return false;
	}

};


// ----------------------------------------- Explosions from bombs

class Explosion : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Explosion(int x, int y) : Projectile(x, y, 32, 7, 2, 3, 0) {


	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

};


//// ------------------------------------------- Boomerangs that are thrown by Link or Goriyas

class Boomerang : public Projectile {

private:
	int maxRange = 15;
	int startX;
	int startY;

public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Boomerang(int x, int y, Direction _dir) : Projectile(x, y, 32, 7, 7, 1, 1) {
		this->setDir(_dir);
		startX = x;
		startY = y;
	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	// if boomerang is past the max range from it's parent* (thrower)	   return true
	bool checkRange(Entity & parent)
	{
		if (this->getDir() == Left || this->getDir() == Right)
		{
			if (sqrt(pow(this->GetX() * 2, 2) - pow(parent.GetX() * 2, 2)) >= this->maxRange)
			{
				return true;
			}
		}

		if (this->getDir() == Up || this->getDir() == Down)
		{
			if (sqrt(pow(this->GetY(), 2) - pow(parent.GetY(), 2)) >= this->maxRange)
			{
				return true;
			}
		}

		return false;

	}

};

