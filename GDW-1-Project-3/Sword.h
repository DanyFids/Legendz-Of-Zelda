#pragma once

class Sword : public Projectile { //It's a projectile, that doesnt MOVE! :O | Are you sassing me, young man?

private:


public:	   // x,y coord,                  width*2,height,time damage
		   // the x+30 and y+3 is to make it appear infront of link, this needs to be changed by direction. sooner or later.
	Sword(int x, int y,Direction _dir) : Projectile(x+30, y+3, 32, 7, 1, 1 , 0) {
		this->setDir(_dir);

	}

	void Hit(Enemy & e) {

		if (this->willHit(&e,0,0))
		{
			e.Hurt(this->getDamage());
		}
	}

	void Hit(Player & p) {

		//if(this->willHit((Entity) e))	   -- Link gets hit with an Arrow
		p.Hurt(this->getDamage());
	}


	void Update()
	{
		this->setTime(this->getTime() - 1);
	}

};