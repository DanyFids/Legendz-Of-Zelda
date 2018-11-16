#pragma once

#include <SFML/Audio.hpp>

//Sfx
class SoundManager {
private:
	sf::Sound sound;
public:
	sf::SoundBuffer swingSound;
	sf::SoundBuffer beamSound;

	bool LoadSwing() {
		return 	swingSound.loadFromFile("SFX\\LOZ_Sword_Slash.wav");
	}

	bool LoadBeamSword() {
		return 	beamSound.loadFromFile("SFX\\LOZ_Sword_Shoot.wav");
	}

	void PlaySwing() {
		sound.setBuffer(swingSound);
		sound.play();
	}
};

SoundManager sounds;
