#ifndef SPACEEVADERS_GAMEOVERVIEW_H
#define SPACEEVADERS_GAMEOVERVIEW_H

#include "../View.h"
#include "../Engine.h"

class GameOverView : public View
{
private:
    sf::RectangleShape bg;
    sf::Text gameOverText;
    sf::Text scoreText;
    sf::Text toMenu;

public:
    GameOverView(Engine &engine, sf::RenderWindow &window);
    void draw(Engine &engine, sf::RenderWindow &window);
};

#endif
