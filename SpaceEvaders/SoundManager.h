#ifndef SPACEEVADERS_SOUNDMANAGER_H
#define SPACEEVADERS_SOUNDMANAGER_H

#include <SFML/Audio.hpp>

class SoundManager
{
private:
    sf::SoundBuffer themeBuffer;
    sf::Sound theme;

    sf::SoundBuffer gameOverThemeBuffer;
    sf::Sound gameOverTheme;

    sf::SoundBuffer clickBuffer;
    sf::Sound click;

    sf::SoundBuffer shootBuffer;
    sf::Sound shoot;

    sf::SoundBuffer hitBuffer;
    sf::Sound hit;

    sf::SoundBuffer explodeBuffer;
    sf::Sound explode;

    sf::SoundBuffer monsterSpawnBuffer;
    sf::Sound monsterSpawn;

    sf::SoundBuffer monsterDeathBuffer;
    sf::Sound monsterDeath;

public:
    SoundManager();

    void playTheme();
    void stopTheme();
    void playGameOver();
    void stopGameOverTheme();
    void playClick();
    void playShoot();
    void playHit();
    void playExplode();
    void playMonsterSpawn();
    void playMonsterDeath();
};


#endif
