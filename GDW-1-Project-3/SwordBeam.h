#pragma once

class BeamSword : public Projectile { //It's a projectile, that doesnt MOVE! :O | Are you sassing me, young man?

private:


public:	   // x,y coord,                  width*2,height,time, damage, speed
		   // the x+30 and y+3 is to make it appear infront of link, this needs to be changed by direction. sooner or later.
	BeamSword(int x, int y, Direction _dir) : Projectile(x + 30, y + 3, 32, 7, 1, 1, 2) {
		this->setDir(_dir);

	}

	void Hit(Enemy & e) {

		if (this->willHit(&e,0,0))
		{
			e.Hurt(this->getDamage());
		}
	}


	void Update()
	{
		this->setTime(this->getTime() - 1);
	}

};
