#pragma once

class Arrow : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,time damage 
	Arrow(int x, int y) : Projectile(x + 30, y + 3, 32, 7, 1, 1) {


	}

	void Hit(Enemy & e) {

		//if(this->willHit((Entity) e))	   -- dont work yet, but if it actually touhes a baddie hurt it.
		e.Hurt(this->getDamage());
	}


	void Update()
	{
		this->setTime(this->getTime() - 1);
	}

};
