#pragma once

class Fireball : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Fireball(int x, int y, float _theta) : Projectile(x + 30, y + 3, 32, 7, 1, 1, 1) {
		this->setTheta(_theta);

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
