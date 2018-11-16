#pragma once

class Arrow : public Projectile {

private:


public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Arrow(int x, int y, Direction _dir) : Projectile(x + 30, y + 3, 32, 7, 1, 1, 1) {
		this->setDir(_dir);
	}

	void Hit(Enemy & e) {

		if (this->willHit(& e,0,0))
		{
			e.Hurt(this->getDamage());
		}
	}


	void Update()
	{
		this->setTime(this->getTime() - 1);
	}

};
