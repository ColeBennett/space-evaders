#ifndef SPACEEVADERS_GAMEVIEW_H
#define SPACEEVADERS_GAMEVIEW_H

#include "View.h"
#include "Player.h"

class GameView : public View
{
private:
    Player player;

public:
    GameView(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);

    Player & getPlayer() const;
};

#endif
