#ifndef SPACEEVADERS_VIEW_H
#define SPACEEVADERS_VIEW_H

#include <SFML/Graphics.hpp>
#include "Engine.h"

/* Abstract base class for all of the views */
class View
{
public:
    virtual void draw(Engine &engine, sf::RenderWindow &window) = 0;
};

#endif
