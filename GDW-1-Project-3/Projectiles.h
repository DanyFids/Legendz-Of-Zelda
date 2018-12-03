#pragma once


// --------------------------------------------- Links Sword for Sword swings
class Sword : public Projectile { //It's a projectile, that doesnt MOVE! :O | Are you sassing me, young man?

private:

public:	   // x,y coord,                  width*2,height,time,damage,speed
	   // the x+30 and y+3 is to make it appear infront of link, this needs to be changed by direction. sooner or later.
	Sword(int x, int y, Direction _dir) : Projectile(x, y, 32, 16, 0.2f, 1) {
		this->setDir(_dir);
		this->setEnum(PT_SWORD);
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
	BeamSword(int x, int y, int x_spd, int y_spd, Direction _dir) : Projectile(x, y, 32, 7, 1.0f, 1) {
		//Sprite sheet
		this->setDir(_dir);
		this->setEnum(PT_BEAMSWORD);
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
	Arrow(int x, int y,int x_spd,int y_spd, Direction _dir) : Projectile(x, y, 34, 17, 10.0f, 1) {
		this->setDir(_dir);
		this->setEnum(PT_ARROW);
		xSpd = x_spd;
		ySpd = y_spd;

		SetSpriteSheet(Sprites.arrowSprites);
		SetCurFrame(0);
		SetCurAnim(3);
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
	Bomb(int x, int y) : Projectile(x, y, 28, 14, 10.0f, 0) {
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
	}

};

// ----------------------------------------- Explosions from bombs

class Explosion : public Projectile {

private:
	

public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Explosion(int x, int y) : Projectile(x, y, 32, 7, 1.0f, 3) {
		this->setEnum(PT_EXPLOSION);
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

public:	   // x,y coord,                  width*2,height,		   || lifetime, damage, speed 
	Boomerang(int x, int y, int x_spd, int y_spd, Direction _dir) : Projectile(x, y, 32, 7, 5.0f, 1) {
		this->setDir(_dir);
		this->setEnum(PT_BOOMERANG);

		xSpd = x_spd;
		ySpd = y_spd;

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
		move();
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
