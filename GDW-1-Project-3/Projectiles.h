#pragma once


// --------------------------------------------- Links Sword for Sword swings
class Sword : public Projectile { //It's a projectile, that doesnt MOVE! :O | Are you sassing me, young man?

private:

public:	   // x,y coord,                  width*2,height,time,damage,speed
	   // the x+30 and y+3 is to make it appear infront of link, this needs to be changed by direction. sooner or later.
	Sword(int x, int y, Direction _dir) : Projectile(x, y, 32, 16, 0.2f, 1) {
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
	BeamSword(int x, int y, Direction _dir) : Projectile(x, y, 32, 7, 1.0f, 1) {
		this->setDir(_dir);

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



		//---------------------------------------------------------Arrows shot by Link

class Arrow : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Arrow(int x, int y, Direction _dir) : Projectile(x + 30, y + 3, 32, 7, 1.0f, 1) {
		this->setDir(_dir);
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


// ----------------------------------------------------  Firballs for --> Stone Statues,

class Fireball : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,					lifetime, damage, speed 
	Fireball(int x, int y, FCOORD dir) : Projectile(x, y, 20, 10, 1.0f, 1) {
		SetSpriteSheet(Sprites.bombSprites);
		this->xSpd = dir.X * (-6);
		this->ySpd = dir.Y * (-3);
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
	Bomb(int x, int y) : Projectile(x, y, 32, 16, 100.0f, 0) {
		SetSpriteSheet(Sprites.bombSprites);
		this->setEnum(PT_BOMB);

	}

	bool HitDetect(Entity * e)
	{
		if (e) {
			return true;
		}
			
		return false; 
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
	}

};

// ----------------------------------------- Explosions from bombs

class Explosion : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 

	Explosion(int x, int y) : Projectile(x, y, 32, 7, 1.0f, 3) {


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
	int maxRange = 15;
	int startX;
	int startY;
	float startTime;

public:	   // x,y coord,                  width*2,height,		   || lifetime, damage, speed 
	Boomerang(int x, int y, Direction _dir) : Projectile(x, y, 32, 7, 10, 1) {
		this->setDir(_dir);
		startX = x;
		startY = y;
		startTime = this->getTime();
	}

	bool HitDetect(Entity * e)
	{
		return willHit(e, 0, 0);
	}

	void Update(float dt)
	{
		this->setTime(this->getTime() - dt);
	}

	void rebound() {

		if (this->getTime() == startTime / 2)
		{
			switch (this->GetDir())
			{
			case Left:
				this->SetDir(Right);
				break;
			case Right:
				this->SetDir(Left);
				break;
			case Up:
				this->SetDir(Down);
				break;
			case Down:
				this->SetDir(Up);
				break;
			}
		}
	}
	

};
