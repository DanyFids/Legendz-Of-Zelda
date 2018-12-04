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


	sf::SoundBuffer titleThemeBGM;
	sf::SoundBuffer dungeonThemeBGM;
	sf::SoundBuffer fileSelectBGM;

	bool LoadWasted() {
		return 	linkDieSound.loadFromFile("SFX\\WastedOOF.wav");
	}
	bool LoadDarkSouls() {
		return 	linkDieSound.loadFromFile("SFX\\YouDiedOOF.wav");
	}

	bool LoadLinkDie() {
		return 	linkDieSound.loadFromFile("SFX\\LOZ_Link_Die.wav");
	}

	bool LoadSwing() {
		return 	swingSound.loadFromFile("SFX\\LOZ_Sword_Slash.wav");
	}

	bool LoadBeamSword() {
		return 	beamSound.loadFromFile("SFX\\LOZ_Sword_Shoot.wav");
	}

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

	

	void PlaySwing() {
		sound.setBuffer(swingSound);
		sound.play();
	}


	void PlayLinkDeath() {
		sound.setBuffer(linkDieSound);
		sound.play();
	}

	void PlayWasted() {
		sound.setBuffer(wastedOOF);
		sound.play();
	}

	void PlayDarkSouls() {
		sound.setBuffer(darkSoulsOOF);
		sound.play();
	}

	void PlaySwordBeam() {
		sound.setBuffer(beamSound);
		sound.play();
	}



};

SoundManager sounds;

