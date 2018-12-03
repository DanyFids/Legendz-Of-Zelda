#pragma once

class HeartPickup : public PowerUp {
public:
	HeartPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		if (stats->CurLife + 2 > stats->MaxLife) {
			stats->CurLife = stats->MaxLife;
		}
		else {
			stats->CurLife += 2;
		}
	}

	bool HitDetect(Entity * other) {
		return willHit(other,0,0);
	}
	void Update(float dt) {

	}

	};

class HeartContainerPickup : public PowerUp {
public:
	HeartContainerPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->MaxLife += 2;
		stats->CurLife += 2;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}

	void Update(float dt) {

	}

};

class KeyPickup : public PowerUp {
public:
	KeyPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->Keys ++ ;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}

};


class BombPickup : public PowerUp {
public:
	BombPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->Bombs += 3;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}


};

class StopwatchPickup : public PowerUp {
public:
	StopwatchPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}
	void Effect(Player_Info * stats) {
		stop_watch = true;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}


};

class CompassPickup : public PowerUp {
public:
	CompassPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->HasCompass = true;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}


};

class MapPickup : public PowerUp {
public:
	MapPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->HasMap = true;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}


};

class RupeesPickup : public PowerUp {
public:
	RupeesPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}



	void Effect(Player_Info * stats) {
		stats->Rupees += 1;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}


};


class BlueRupeesPickup : public PowerUp {
public:
	BlueRupeesPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->Rupees += 5;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}


};

class FairiesPickup : public PowerUp {
public:
	FairiesPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		if (stats->CurLife + 10 > stats->MaxLife) {
			stats->CurLife += stats->MaxLife - stats->CurLife;
		}
		else {
			stats->CurLife += 10;
		}
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}


};

class Triforce : public PowerUp {
public:
	Triforce(int x, int y) : PowerUp(x, y, 20, 10) {
		
	}

	void Effect(Player_Info stats) {
		Victory();
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}
};