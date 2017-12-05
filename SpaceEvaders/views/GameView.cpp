#include "GameView.h"

/**
 * GameView constructor. Initialize all of the text objects and load the textures.
 * @param engine
 * @param window
 */
GameView::GameView(Engine &engine, sf::RenderWindow &window)
{
    bg.setTexture(engine.getBgTexture());
    bg.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

    top.setSize(sf::Vector2f(window.getSize().x, window.getSize().y * .1f));
    top.setFillColor(sf::Color::Black);
    top.setOutlineThickness(3.5);
    top.setOutlineColor(sf::Color::Green);

    gameTitle.setString("space evaders");
    gameTitle.setFont(engine.getFont());
    gameTitle.setCharacterSize(55);
    gameTitle.setFillColor(sf::Color(66, 134, 244));
    gameTitle.setOutlineColor(sf::Color::Cyan);
    gameTitle.setOutlineThickness(3.5);
    engine.center(gameTitle, window.getSize().y * .025f);

    score.setFont(engine.getFont());
    score.setCharacterSize(35);
    score.setFillColor(sf::Color::Yellow);

    ammo.setFont(engine.getFont());
    ammo.setCharacterSize(30);
    ammo.setFillColor(sf::Color::Green);

    kills.setFont(engine.getFont());
    kills.setCharacterSize(30);
    kills.setFillColor(sf::Color::Green);

    player.setSpeed(5);

    bulletTexture.loadFromFile("assets/bullet.png");
    monsterBulletTexture.loadFromFile("assets/monster_bullet.png");
    monsterTexture.loadFromFile("assets/monster.png");
    asteroidTexture.loadFromFile("assets/asteroid.png");
}

/**
 * Reset the game before it starts.
 * @param window
 */
void GameView::reset(Engine &engine, sf::Window &window)
{
    monsterBulletSpeed = 6.0f;
    asteroidSpeed = 1.2f;
    asteroidSpawnRate = 500;

    scoreClock.restart();
    asteroidSpawnClock.restart();
    asteroidSpawnRateClock.restart();
    monsterSpawnClock.restart();
    monsterShootClock.restart();
    ammoRegenClock.restart();

    player.setDead(false);
    player.setKills(0);
    player.setAmmo(10);

    /* position the player bottom center */
    player.setPosition(sf::Vector2f((window.getSize().x / 2) - (player.getGlobalBounds().width / 2),
                       window.getSize().y - player.getGlobalBounds().height));

    engine.getSoundManager().stopGameOverTheme();
    engine.getSoundManager().playTheme();
}

/**
 *
 * @param engine
 */
void GameView::fireBullet(Engine &engine)
{
    if (player.getAmmo() > 0) {
        Bullet bullet(PLAYER);
        bullet.setSpeed(-9.5f);
        bullet.setTexture(bulletTexture);
        bullet.setPosition(
                player.getPosition().x + (player.getGlobalBounds().width / 2) - (bullet.getGlobalBounds().width / 2) - 2,
                player.getPosition().y - (bullet.getGlobalBounds().height / 2));
        bullets.push_back(bullet);
        player.setAmmo(player.getAmmo() - 1);
        engine.getSoundManager().playShoot();
    }
}

/**
 * Update movements and check for collisions.
 * @param engine
 * @param window
 */
void GameView::tick(Engine &engine, sf::RenderWindow &window)
{
    if (!running) {
        reset(engine, window);
        running = true;
    }

    /* modify asteroid spawn rate and speed */
    if (asteroidSpawnRateClock.getElapsedTime().asMilliseconds() >= 5000) {
        if (asteroidSpawnRate >= 250) {
            asteroidSpawnRate -= 10;
        }
        std::cout << "asteroid spawn rate " << asteroidSpawnRate << " ms" << std::endl;
        if (asteroidSpeed < 5.5) {
            asteroidSpeed += 0.1f;
        }
        std::cout << "asteroid speed " << asteroidSpeed << std::endl;
        asteroidSpawnRateClock.restart();
    }

    /* spawn asteroid */
    if (asteroidSpawnClock.getElapsedTime().asMilliseconds() >= asteroidSpawnRate) {
        Asteroid asteroid;
        asteroid.setSpeed(asteroidSpeed);
        float size = (float) engine.random(0.5f, 0.8f);
        asteroid.setScale(size, size);
        asteroid.setTexture(asteroidTexture);
        asteroid.setPosition((float) engine.random(0.0, window.getSize().x - asteroid.getGlobalBounds().width), 0);
        asteroids.push_back(asteroid);
        asteroidSpawnClock.restart();
    }

    /* spawn monster */
    if (monsterSpawnClock.getElapsedTime().asMilliseconds() >= 1200) {
        if (monsters.size() < 1) {
            Monster monster;
            monster.setSpeed(2.5f);
            float size = (float) engine.random(0.8f, 1.0f);
            monster.setScale(size, size);
            monster.setTexture(monsterTexture);
            monster.setPosition((float) engine.random(monster.getGlobalBounds().width, window.getSize().x - 50), 0);

            /* increase the monster bullet speed for each new monster */
            monsterBulletSpeed += 0.15f;

            engine.getSoundManager().playMonsterSpawn();
            monsters.push_back(monster);
        }
        monsterSpawnClock.restart();
    }

    /* monster fires bullet */
    if (monsterShootClock.getElapsedTime().asMilliseconds() >= 2500) {
        for (int i = 0; i < monsters.size(); i++) {
            Bullet bullet(MONSTER);
            bullet.setSpeed(monsterBulletSpeed);
            bullet.setTexture(monsterBulletTexture);
            bullet.setPosition(
                    monsters[i].getPosition().x + (monsters[i].getGlobalBounds().width / 2) -
                    (bullet.getGlobalBounds().width / 2) - 2,
                    monsters[i].getPosition().y - (bullet.getGlobalBounds().height / 2));

            float slope = (player.getPosition().x - monsters[i].getPosition().x) / (player.getPosition().y - monsters[i].getPosition().y);
            bullet.setSpeedX(slope);
            bullet.setSpeedY(slope);
            bullet.setRotation(atan(abs(slope)));
            bullets.push_back(bullet);
            engine.getSoundManager().playShoot();
        }
        monsterShootClock.restart();
    }

    /* ammo regen */
    if (ammoRegenClock.getElapsedTime().asSeconds() >= 3) {
        if (player.getAmmo() < 10) {
            player.setAmmo(player.getAmmo() + 1);
            ammoRegenClock.restart();
        }
    }

    /* prevent character from going off the screen */
    if (player.getPosition().x >= window.getSize().x - player.getGlobalBounds().width) {
        player.setPosition(window.getSize().x - player.getGlobalBounds().width, player.getPosition().y);
    }
    if (player.getPosition().x <= 0) {
        player.setPosition(0, player.getPosition().y);
    }
    if (player.getPosition().y >= window.getSize().y - player.getGlobalBounds().height) {
        player.setPosition(player.getPosition().x, window.getSize().y - player.getGlobalBounds().height);
    }
    if (player.getPosition().y <= window.getSize().y * .1) {
        player.setPosition(player.getPosition().x, window.getSize().y * .1f);
    }

    size_t i, j;
    /* check of player runs into an asteroid */
    for (i = 0; i < asteroids.size(); i++) {
        if (asteroids[i].getGlobalBounds().contains(player.getPosition())
            || player.getGlobalBounds().contains(asteroids[i].getPosition())) {
            engine.getSoundManager().playExplode();
            playerDied(engine);
            return;
        }
    }
    /* check if player runs into a monster */
    for (i = 0; i < monsters.size(); i++) {
        if (monsters[i].getGlobalBounds().contains(player.getPosition())
            || player.getGlobalBounds().contains(monsters[i].getPosition())) {
            engine.getSoundManager().playExplode();
            playerDied(engine);
            return;
        }
    }

    /* move the bullets and check for collision into player and monsters */
    for (i = 0; i < bullets.size(); i++) {
        switch (bullets[i].getType()) {
            case PLAYER:
                bullets[i].move(0, bullets[i].getSpeed());
                break;
            case MONSTER:
                bullets[i].move(bullets[i].getSpeedX(), bullets[i].getSpeed());
                break;
        }

        if (bullets[i].getPosition().y < 0) {
            erase(bullets, i);
            continue;
        }

        switch (bullets[i].getType()) {
            case PLAYER:
                for (j = 0; j < asteroids.size(); j++) {
                    if (asteroids[j].getGlobalBounds().contains(bullets[i].getPosition())) {
                        erase(asteroids, j);
                        erase(bullets, i);
                        engine.getSoundManager().playHit();
                    }
                }
                for (j = 0; j < monsters.size(); j++) {
                    if (monsters[j].getGlobalBounds().contains(bullets[i].getPosition())) {
                        erase(monsters, j);
                        erase(bullets, i);
                        player.setKills(player.getKills() + 1);
                        engine.getSoundManager().playMonsterDeath();
                    }
                }
                break;
            case MONSTER:
                if (player.getGlobalBounds().contains(bullets[i].getPosition())) {
                    engine.getSoundManager().playExplode();
                    playerDied(engine);
                }
                break;
        }
    }

    /* move the asteroids and check if they go off the screen */
    for (i = 0; i < asteroids.size(); i++) {
        if (asteroids[i].getPosition().y > window.getSize().y) {
            erase(asteroids, i);
            continue;
        }
        asteroids[i].move(0, asteroids[i].getSpeed());
    }

    /* move the monsters and check if they go off the screen */
    for (i = 0; i < monsters.size(); i++) {
        monsters[i].move(monsters[i].getSpeed(), 0);
        if (monsters[i].getPosition().y <= 250) {
            monsters[i].move(0, 2);
            continue;
        }
        if (monsters[i].getPosition().x >= window.getSize().x - monsters[i].getGlobalBounds().width) {
            monsters[i].setPosition(window.getSize().x - monsters[i].getGlobalBounds().width, monsters[i].getPosition().y);
            monsters[i].setSpeed(-monsters[i].getSpeed());
            continue;
        }
        if (monsters[i].getPosition().x <= 0) {
            monsters[i].setPosition(0, monsters[i].getPosition().y);
            monsters[i].setSpeed(-monsters[i].getSpeed());
        }
    }
}

/**
 * Player died and the game has ended.
 * @param engine
 */
void GameView::playerDied(Engine &engine)
{
    player.setDead(true);
    bullets.clear();
    asteroids.clear();
    monsters.clear();
    running = false;
    float score = scoreClock.getElapsedTime().asSeconds();
    engine.getLeaderboard().insertInOrder(score);
    engine.getLeaderboard().writeCSV();
    engine.endGame(score);
}

/**
 * Draw all of the entities and text to the screen.
 * @param engine
 * @param window
 */
void GameView::draw(Engine &engine, sf::RenderWindow &window)
{
    window.draw(bg);

    int i;
    for (i = 0; i < asteroids.size(); i++) {
        window.draw(asteroids[i]);
    }
    for (i = 0; i < monsters.size(); i++) {
        window.draw(monsters[i]);
    }
    for (i = 0; i < bullets.size(); i++) {
        window.draw(bullets[i]);
    }
    if (!player.isDead()) {
        window.draw(player);
    }

    window.draw(top);

    std::string scoreText("score: ");
    char buffer[10];
    sprintf(buffer, "%.1f", scoreClock.getElapsedTime().asSeconds());
    scoreText += buffer;
    score.setString(scoreText);
    score.setPosition(window.getSize().x * .025f, 50);
    window.draw(score);

    std::string ammoText("ammo: ");
    ammoText += std::to_string(player.getAmmo());
    ammo.setString(ammoText);
    ammo.setPosition((window.getSize().x - ammo.getGlobalBounds().width) - (window.getSize().x * .025f), 25);
    window.draw(ammo);

    std::string killsText("kills: ");
    killsText += std::to_string(player.getKills());
    kills.setString(killsText);
    kills.setPosition((window.getSize().x - kills.getGlobalBounds().width) - (window.getSize().x * .025f), 75);
    window.draw(kills);

    window.draw(gameTitle);
}

Player & GameView::getPlayer()
{
    return player;
}

/**
 * Found from: https://www.gamedev.net/forums/topic/665250-efficient-way-to-erase-an-element-from-stdvector/
 */
template<typename ContainerType>
void GameView::erase(ContainerType &container, size_t index)
{
    if (index + 1 != container.size()) {
        std::swap(container[index], container.back());
    }
    container.pop_back();
}