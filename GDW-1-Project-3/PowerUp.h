#pragma once

class HeartPickup : public PowerUp {
public:
	HeartPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->CurLife += 2;
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
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->MaxLife += 2;
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
	KeyPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->Keys ++ ;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}

	PowerUp * Clone() {
		return new KeyPickup(*this);
	}

};


class BombPickup : public PowerUp {
public:
	BombPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->Bombs++;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}

	PowerUp * Clone() {
		return new BombPickup(*this);
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

	PowerUp * Clone() {
		return new StopwatchPickup(*this);
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

	PowerUp * Clone() {
		return new CompassPickup(*this);
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

	PowerUp * Clone() {
		return new MapPickup(*this);
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

	PowerUp * Clone() {
		return new RupeesPickup(*this);
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

	PowerUp * Clone() {
		return new BlueRupeesPickup(*this);
	}
};

class FairiesPickup : public PowerUp {
public:
	FairiesPickup(int x, int y) : PowerUp(x, y, 32, 16) {
		SetSpriteSheet(Sprites.blockSprites);
	}


	void Effect(Player_Info * stats) {
		stats->CurLife += 10;
	}

	bool HitDetect(Entity * other) {
		return willHit(other, 0, 0);
	}

	PowerUp * Clone() {
		return new FairiesPickup(*this);
	}
};