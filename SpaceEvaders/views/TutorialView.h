#ifndef SPACEEVADERS_TUTORIAL_H
#define SPACEEVADERS_TUTORIAL_H

#include "../View.h"
#include "../Engine.h"

class TutorialView : public View
{
private:
    sf::RectangleShape bg;
    sf::Text title;
    sf::Text instructions;
    sf::Text controls;
    sf::Text useArrowKeys;
    sf::Text up, down, left, right, space;
    sf::Text toMenu;

public:
    TutorialView(Engine &engine, sf::RenderWindow &window);
    void draw(Engine &engine, sf::RenderWindow &window);
};

#endif
