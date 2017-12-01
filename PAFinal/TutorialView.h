#ifndef SPACEEVADERS_GAMEENDVIEW_H
#define SPACEEVADERS_GAMEENDVIEW_H

#include "View.h"

class TutorialView : public View
{
public:
    TutorialView(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
};

#endif
