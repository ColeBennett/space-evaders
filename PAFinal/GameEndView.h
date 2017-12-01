#ifndef SPACEEVADERS_GAMEENDVIEW_H
#define SPACEEVADERS_GAMEENDVIEW_H

#include "View.h"

class GameEndView : public View
{
public:
    GameEndView(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
};

#endif
