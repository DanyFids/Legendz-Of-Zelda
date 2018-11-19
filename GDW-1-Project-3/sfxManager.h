#pragma once

#include <SFML/Audio.hpp>

//Sfx
class SoundManager {
private:
	sf::Sound sound;
	sf::Music music;
public:
	sf::SoundBuffer swingSound;
	sf::SoundBuffer beamSound;

	// SFX/BGM Loaders

	bool LoadSwing() {
		return 	swingSound.loadFromFile("SFX\\LOZ_Sword_Slash.wav");
	}

	bool LoadBeamSword() {
		return 	beamSound.loadFromFile("SFX\\LOZ_Sword_Shoot.wav");
	}


	// SFX/BGM Players

	void PlayTitleTheme() {	//These aren't loaded, they are just streamed.
		music.openFromFile("BGM\\TitleThemeLoZ.wav");
		music.play();
	}

	void PlayDungeonTheme() {
		music.openFromFile("BGM\\DungeonThemeLoZ.wav");
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

