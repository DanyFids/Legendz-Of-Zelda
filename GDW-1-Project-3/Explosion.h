#pragma once

class Explosion : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Explosion(int x, int y) : Projectile(x, y, 32, 7, 2, 3, 0) {


	}

	void Hit(Enemy & e) {

		if (this->willHit(&e, 0, 0))
		{
			e.Hurt(this->getDamage());
		}
	}

};