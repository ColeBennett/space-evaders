#ifndef SPACEEVADERS_GAMEVIEW_H
#define SPACEEVADERS_GAMEVIEW_H

#include "../View.h"
#include "../Engine.h"
#include "../entity/Player.h"
#include "../entity/Asteroid.h"
#include "../entity/Monster.h"
#include "../entity/Bullet.h"
#include <vector>
#include <cmath>

class GameView : public View
{
private:
    Player player;
    bool running;

    sf::Clock scoreClock, asteroidSpawnClock, asteroidSpawnRateClock,
            monsterSpawnClock, monsterShootClock, ammoRegenClock;

    sf::Texture bulletTexture;
    sf::Texture monsterTexture;
    sf::Texture asteroidTexture;
    sf::Texture monsterBulletTexture;

    float asteroidSpeed;
    int asteroidSpawnRate;

    std::vector<Bullet> bullets;
    std::vector<Asteroid> asteroids;
    std::vector<Monster> monsters;

    sf::RectangleShape bg;
    sf::RectangleShape top;
    sf::Text gameTitle, score, ammo, kills;

    void playerDied(Engine &engine);

public:
    GameView(Engine &engine, sf::RenderWindow &window);
    void reset(sf::Window &window);
    void fireBullet(Engine &engine);
    void tick(Engine &engine, sf::RenderWindow &window);
    void draw(Engine &engine, sf::RenderWindow &window);
    Player & getPlayer();

    template<typename ContainerType>
    void erase(ContainerType &container, size_t index);
};

#endif
