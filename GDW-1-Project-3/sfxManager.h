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
	sf::SoundBuffer fileSelectBGM;


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

	void PlaySwordBeam() {
		sound.setBuffer(beamSound);
		sound.play();
	}

};

SoundManager sounds;


