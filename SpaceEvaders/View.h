#ifndef SPACEEVADERS_VIEW_H
#define SPACEEVADERS_VIEW_H

#include <SFML/Graphics.hpp>

/* Base class for all of the views */
class View
{
public:
    void draw(const sf::RenderWindow &window);
};

#endif
