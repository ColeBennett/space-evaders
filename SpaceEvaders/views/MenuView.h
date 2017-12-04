#ifndef SPACEEVADERS_MENU_H
#define SPACEEVADERS_MENU_H

#include "../View.h"
#include "../Engine.h"

class MenuView : public View
{
private:
    sf::Text gameTitle, play, leaderboard, tutorial, exit;
    sf::Clock clock;
    sf::Texture *bgTexture;
    sf::RectangleShape bg;
    int lastRotationAngle;

public:
    MenuView(Engine &engine, const sf::RenderWindow &window);
    ~MenuView();
    void draw(Engine &engine, sf::RenderWindow &window);
};

#endif
