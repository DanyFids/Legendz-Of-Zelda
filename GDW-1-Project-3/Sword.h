#pragma once

class Sword : public Projectile { //It's a projectile, that doesnt MOVE! :O | Are you sassing me, young man?

private:


public:	   // x,y coord,                  width*2,height,time damage
		   // the x+30 and y+3 is to make it appear infront of link, this needs to be changed by direction. sooner or later.
	Sword(int x, int y, Direction d) : Projectile(x, y, 32, 16, 1, 1 , 0) {
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