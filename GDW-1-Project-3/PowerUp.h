#pragma once

class HeartPickup : public PowerUp {
public:
	HeartPickup(int x, int y) : PowerUp(x, y, 16, 8) {
		SetSpriteSheet(Sprites.heartSprites);
		SetCurAnim(0);
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

	PowerUp * Clone() {
		return new HeartPickup(*this);
	}

	};

class HeartContainerPickup : public PowerUp {
public:
	HeartContainerPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.heartSprites);
	}


	void Effect(Player_Info * stats) {
		stats->MaxLife += 2;
		stats->CurLife += 2;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}

	PowerUp * Clone() {
		return new HeartContainerPickup(*this);
	}

};

class KeyPickup : public PowerUp {
public:
	KeyPickup(int x, int y) : PowerUp(x, y, 16, 16) {
		SetSpriteSheet(Sprites.keySprites);
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
	BombPickup(int x, int y) : PowerUp(x, y, 28, 14) {
		SetSpriteSheet(Sprites.bombSprites);
		SetCurFrame(0);
	}


	void Effect(Player_Info * stats) {
		stats->Bombs += 3;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}
	void Update(float dt) {
	}
};

class StopwatchPickup : public PowerUp {
public:
	StopwatchPickup(int x, int y) : PowerUp(x, y, 22, 16) {
		SetSpriteSheet(Sprites.stopwatchSprites);
	}
	void Effect(Player_Info * stats) {
		stop_watch = true;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}
	void Update(float dt) {
	}
};

class CompassPickup : public PowerUp {
public:
	CompassPickup(int x, int y) : PowerUp(x, y, 26, 13) {
		SetSpriteSheet(Sprites.compassSprites);
	}


	void Effect(Player_Info * stats) {
		stats->HasCompass = true;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}
	void Update(float dt) {
	}
};

class MapPickup : public PowerUp {
public:
	MapPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.mapSprites);
	}


	void Effect(Player_Info * stats) {
		stats->HasMap = true;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}
	void Update(float dt) {
	}
};

class RupeesPickup : public PowerUp {
public:
	RupeesPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.rupeeSprites);
	}



	void Effect(Player_Info * stats) {
		stats->Rupees += 1;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}
	void Update(float dt) {

	}
};


class BlueRupeesPickup : public PowerUp {
public:
	BlueRupeesPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.rupeeSprites);
	}


	void Effect(Player_Info * stats) {
		stats->Rupees += 5;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}
	void Update(float dt) {
	}
};

class FairiesPickup : public PowerUp {
public:
	FairiesPickup(int x, int y) : PowerUp(x, y, 34, 17) {
		SetSpriteSheet(Sprites.fairySprites);
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
	void Update(float dt) {

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