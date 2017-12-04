#ifndef SPACEEVADERS_LEADERBOARD_H
#define SPACEEVADERS_LEADERBOARD_H

#include "../View.h"
#include "../Engine.h"

class LeaderboardView : public View
{
private:
    sf::RectangleShape bg;
    sf::Text title;
    sf::Text toMenu;

public:
    LeaderboardView(Engine &engine, sf::RenderWindow &window);
    void draw(Engine &engine, sf::RenderWindow &window);
};

#endif
