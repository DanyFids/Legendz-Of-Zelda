#pragma once

#include <SFML/Audio.hpp>


//Sfx
class SoundManager {
private:
	sf::Sound sound;
	sf::Sound music;
public:
	sf::SoundBuffer swingSound;
	sf::SoundBuffer linkDieSound;
	sf::SoundBuffer beamSound;

	sf::SoundBuffer wastedOOF;
	sf::SoundBuffer darkSoulsOOF;

	sf::SoundBuffer linkHurtSound;
	sf::SoundBuffer mcClassic;
	sf::SoundBuffer enemyDie;
	sf::SoundBuffer enemyHit;

	sf::SoundBuffer kaboom;
	sf::SoundBuffer bombPlaced;

	sf::SoundBuffer heartPickup;
	sf::SoundBuffer getItemSound;

	sf::SoundBuffer doorUnlocked;
	sf::SoundBuffer findSecret;
	sf::SoundBuffer fanfare;

	sf::SoundBuffer timeStop;
	sf::SoundBuffer cdiganon;

	sf::SoundBuffer titleThemeBGM;
	sf::SoundBuffer dungeonThemeBGM;
	sf::SoundBuffer fileSelectBGM;
	
	bool LoadCDIGanon() {
		return 	cdiganon.loadFromFile("SFX\\CDIganon.wav");
	}

	bool LoadEnemyDie() {
		return 	enemyDie.loadFromFile("SFX\\LOZ_Enemy_Die.wav");
	}

	bool LoadEnemyHit() {
		return 	enemyHit.loadFromFile("SFX\\LOZ_EnemyHit.wav");
	}

	bool LoadTimeStop() {
		return 	timeStop.loadFromFile("SFX\\TimeStop.wav");
	}
	bool LoadDoorUnlock() {
		return 	doorUnlocked.loadFromFile("SFX\\LOZ_Door_Unlock.wav");
	}
	bool LoadHeartPickup() {
		return 	heartPickup.loadFromFile("SFX\\LOZ_Get_Heart.wav");
	}
	bool LoadGetItem() {
		return 	getItemSound.loadFromFile("SFX\\LOZ_Get_Item.wav");
	}
	bool LoadFanfare() {
		return 	fanfare.loadFromFile("SFX\\LOZ_Fanfare.wav");
	}

	bool LoadBombPlaced() {
		return 	bombPlaced.loadFromFile("SFX\\LOZ_Bomb_Drop.wav");
	}
	bool LoadKaboom() {
		return 	kaboom.loadFromFile("SFX\\LOZ_Bomb_Blow.wav");
	}
	bool LoadLinkHurt() {
		return 	linkHurtSound.loadFromFile("SFX\\LOZ_Link_Hurt.wav");
	}
	bool LoadMC() {
		return 	mcClassic.loadFromFile("SFX\\MinecraftHurt.wav");
	}
	bool LoadWasted() {
		return 	wastedOOF.loadFromFile("SFX\\WastedOOF.wav");
	}
	bool LoadDarkSouls() {
		return 	darkSoulsOOF.loadFromFile("SFX\\YouDiedOOF.wav");
	}

	bool LoadLinkDie() {
		return 	linkDieSound.loadFromFile("SFX\\LOZ_Link_Die.wav");
	}

	bool LoadFindSecret() {
		return 	findSecret.loadFromFile("SFX\\LOZ_Secret.wav");
	}

	bool LoadSwing() {
		return 	swingSound.loadFromFile("SFX\\LOZ_Sword_Slash.wav");
	}

	bool LoadBeamSword() {
		return 	beamSound.loadFromFile("SFX\\LOZ_Sword_Shoot.wav");
	}

	//BGM's

	bool LoadTitleTheme() {
		
		return titleThemeBGM.loadFromFile("BGM\\TitleThemeLoZ.wav");
	}

	bool LoadDungeonTheme() {
		return dungeonThemeBGM.loadFromFile("BGM\\DungeonThemeLoZ.wav");
	}

	bool LoadFileSelect() {
		return fileSelectBGM.loadFromFile("BGM\\FileSelectLoZ.wav");
	}


	// SFX/BGM Players

	void StopMusic() {
		music.stop();
	}

	void PlayTitleTheme() {	//These aren't loaded, they are just streamed.
		music.stop();
		music.setBuffer(titleThemeBGM);
		music.setLoop(true);
		music.play();
	}

	void PlayDungeonTheme() {
		music.stop();
		music.setBuffer(dungeonThemeBGM);
		music.setLoop(true);
		music.play();
	}

	void PlayFileSelect() {
		music.stop();
		music.setBuffer(fileSelectBGM);
		music.setLoop(true);
		music.play();
	}

	// ^ ================= MUSIC ================ ^ \\

	void PlayWasted() {
		music.setBuffer(wastedOOF);
		music.play();
	}

	void PlayDarkSouls() {
		music.setBuffer(darkSoulsOOF);
		music.play();
		music.setLoop(false);
	}

	void PlayCDIGanon() {
		sound.setBuffer(cdiganon);
		sound.play();
	}

	void PlayEnemyDie() {
		sound.setBuffer(enemyDie);
		sound.play();
	}

	void PlayEnemyHit() {
		sound.setBuffer(enemyHit);
		sound.play();
	}

	void PlayFanfare() {
		sound.setBuffer(fanfare);
		sound.play();
	}

	void PlayFindSecret() {
		sound.setBuffer(findSecret);
		sound.play();
	}

	void PlayDoorUnlocked() {
		sound.setBuffer(doorUnlocked);
		sound.play();
	}

	void PlaySwing() {
		sound.setBuffer(swingSound);
		sound.play();
	}

	void PlayLinkHurt() {
		sound.setBuffer(linkHurtSound);
		sound.play();
	}

	void PlayHeartPickup() {
		sound.setBuffer(heartPickup);
		sound.play();
	}

	void PlayGetItem() {
		sound.setBuffer(getItemSound);
		sound.play();
	}

	void PlayMC() {
		sound.setBuffer(mcClassic);
		sound.play();
	}


	void PlayLinkDeath() {
		sound.setBuffer(linkDieSound);
		sound.play();
	}

	

	void PlaySwordBeam() {
		sound.setBuffer(beamSound);
		sound.play();
	}

	void PlayPlacedBomb() {
		sound.setBuffer(bombPlaced);
		sound.play();
	}

	void PlayKaboom() {
		sound.setBuffer(kaboom);
		sound.play();
	}
	void PlayTimeStops() {
		sound.setBuffer(timeStop);
		sound.play();
	}



};

SoundManager sounds;

