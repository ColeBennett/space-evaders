#ifndef SPACEEVADERS_MENU_H
#define SPACEEVADERS_MENU_H

#include "View.h"

class MenuView : public View
{
private:
    sf::Text gameTitle, play, leaderboard, exit;

public:
    MenuView(const sf::RenderWindow &window, const sf::Font &font);
    void draw(sf::RenderWindow &window);
};

#endif
