#pragma once

#include <SFML/Audio.hpp>

//Sfx
class SoundManager {
private:
	sf::Sound sound;
	sf::Sound music;
public:
	sf::SoundBuffer swingSound;
	sf::SoundBuffer beamSound;
	sf::SoundBuffer titleThemeBGM;
	sf::SoundBuffer dungeonThemeBGM;

	// SFX/BGM Loaders

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


	// SFX/BGM Players

	void PlayTitleTheme() {	//These aren't loaded, they are just streamed.
		music.setBuffer(titleThemeBGM);
		music.play();
	}

	void PlayDungeonTheme() {
		music.setBuffer(dungeonThemeBGM);
		music.play();
	}

	void StopMusic() {
		music.stop();
	}

	void PlaySwing() {
		sound.setBuffer(swingSound);
		sound.play();
	}

	void PlaySwordBeam() {
		sound.setBuffer(beamSound);
		sound.play();
	}

};

SoundManager sounds;

