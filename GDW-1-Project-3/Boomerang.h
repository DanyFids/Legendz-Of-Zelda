#pragma once

class Boomerang : public Projectile {

private:
	int maxRange = 15;

public:	   // x,y coord,                  width*2,height,lifetime, damage, speed 
	Boomerang(int x, int y, Direction _dir) : Projectile(x, y, 32, 7, 7, 1, 1) {
		this->setDir(_dir);

	}

	void Hit(Player & p) {

		if (this->willHit(&p, 0, 0))
		{
			p.Hurt(this->getDamage());
		}
	}

	void Hit(Enemy & e) {

		if (this->willHit(& e, 0, 0))
		{
			e.Hurt(this->getDamage());
		}
	}
	// if boomerange is past the max range from it's parent* (thrower)	   return true
	bool checkRange(Entity & parent)
	{
		if (this->getDir() == Left || this->getDir() == Right)
		{
			if (sqrt(pow(this->GetX()*2, 2) - pow(parent.GetX()*2, 2)) >= this->maxRange)
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
