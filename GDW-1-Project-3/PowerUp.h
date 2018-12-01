#pragma once

class HeartPickup : public PowerUp {
public:



	void Effect(Player_Info stats) {
		stats.CurLife += 2;
	}

	bool HitDetect(Player * p) {
		return willHit(p,0,0);
	}

	};

class HeartContainerPickup : public PowerUp {
public:



	void Effect(Player_Info stats) {
		stats.MaxLife += 2;
	}

	bool HitDetect(Player * p) {
		return willHit(p, 0, 0);
	}


};

class KeyPickup : public PowerUp {
public:



	void Effect(Player_Info stats) {
		stats.Keys ++ ;
	}

	bool HitDetect(Player * p) {
		return willHit(p, 0, 0);
	}


};


class BombPickup : public PowerUp {
public:



	void Effect(Player_Info stats) {
		stats.Bombs++;
	}

	bool HitDetect(Player * p) {
		return willHit(p, 0, 0);
	}


};

class StopwatchPickup : public PowerUp {
public:



	//void Effect(Player_Info stats) {
	//	stop_watch = true;
	//}

	bool HitDetect(Player * p) {
		return willHit(p, 0, 0);
	}


};

class CompassPickup : public PowerUp {
public:



	void Effect(Player_Info stats) {
		stats.HasCompass = true;
	}

	bool HitDetect(Player * p) {
		return willHit(p, 0, 0);
	}


};

class MapPickup : public PowerUp {
public:



	void Effect(Player_Info stats) {
		stats.HasMap = true;
	}

	bool HitDetect(Player * p) {
		return willHit(p, 0, 0);
	}


};

class RupeesPickup : public PowerUp {
public:



	void Effect(Player_Info stats) {
		stats.CurLife += 1;
	}

	bool HitDetect(Player * p) {
		return willHit(p, 0, 0);
	}


};


class BlueRupeesPickup : public PowerUp {
public:



	void Effect(Player_Info stats) {
		stats.Rupees += 5;
	}

	bool HitDetect(Player * p) {
		return willHit(p, 0, 0);
	}


};

class FairiesPickup : public PowerUp {
public:



	void Effect(Player_Info stats) {
		stats.CurLife += 10;
	}

	bool HitDetect(Player * p) {
		return willHit(p, 0, 0);
	}


};