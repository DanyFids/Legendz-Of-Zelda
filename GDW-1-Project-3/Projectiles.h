#pragma once

class Sword : public Projectile { //It's a projectile, that doesnt MOVE! :O | Are you sassing me, young man?

private:


public:	   // x,y coord,                  width*2,height,time damage
		   // the x+30 and y+3 is to make it appear infront of link, this needs to be changed by direction. sooner or later.
	Sword(int x, int y, Direction d) : Projectile(x, y, 32, 16, 1, 1) {
		SetSpriteSheet(Sprites.swordSprites);

	}


	void Update(float dt)
	{
		this->setTime(this->getTime() - 1);
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}
	
};

class Fireball : public Projectile {

private:
	
public:       // x,y coord,                  width*2,height,                    lifetime, damage, speed 
	Fireball(int x, int y, float _Xdir, float _Ydir) : Projectile(x, y, 32, 8, 1.0f, 1) {
		SetSpriteSheet(Sprites.keeseSprites);
		xSpd = _Xdir + 1;
		ySpd = _Ydir + 1;
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

class Arrow : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Arrow(int x, int y) : Projectile(x + 30, y + 3, 32, 7, 1, 1) {


	}

	void Hit(Enemy & e) {

		//if(this->willHit((Entity)e))	   //-- dont work yet, but if it actually touhes a baddie hurt it.
		e.Hurt(this->getDamage());
	}


	void Update()
	{
		this->setTime(this->getTime() - 1);
	}

};