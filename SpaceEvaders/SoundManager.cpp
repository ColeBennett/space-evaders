#include "SoundManager.h"

SoundManager::SoundManager()
{
    themeBuffer.loadFromFile("assets/theme.wav");
    theme.setBuffer(themeBuffer);
    theme.setLoop(true);

    gameOverThemeBuffer.loadFromFile("assets/game_over_theme.wav");
    gameOverTheme.setBuffer(gameOverThemeBuffer);
    gameOverTheme.setLoop(true);

    clickBuffer.loadFromFile("assets/click.wav");
    click.setBuffer(clickBuffer);

    shootBuffer.loadFromFile("assets/shoot.wav");
    shoot.setBuffer(shootBuffer);

    hitBuffer.loadFromFile("assets/hit.wav");
    hit.setBuffer(hitBuffer);

    explodeBuffer.loadFromFile("assets/explode.wav");
    explode.setBuffer(explodeBuffer);

    monsterSpawnBuffer.loadFromFile("assets/monster_spawn.wav");
    monsterSpawn.setBuffer(monsterSpawnBuffer);

    monsterDeathBuffer.loadFromFile("assets/monster_death.wav");
    monsterDeath.setBuffer(monsterDeathBuffer);
}

void SoundManager::playTheme()
{
    theme.play();
}

void SoundManager::stopTheme()
{
    theme.pause();
}

void SoundManager::playGameOver()
{
    gameOverTheme.play();
}

void SoundManager::stopGameOverTheme()
{
    gameOverTheme.pause();
}

void SoundManager::playClick()
{
    click.play();
}

void SoundManager::playShoot()
{
    shoot.play();
}

void SoundManager::playHit()
{
    hit.play();
}

void SoundManager::playExplode()
{
    explode.play();
}

void SoundManager::playMonsterSpawn()
{
    monsterSpawn.play();
}

void SoundManager::playMonsterDeath()
{
    monsterDeath.play();
}