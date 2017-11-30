#ifndef PA9_WALL_H
#define PA9_WALL_H

#include <SFML/Graphics.hpp>
#include <iostream>
class Wall : public sf::RectangleShape
{
public:
	float startX, startY;
	Wall(const sf::Color &newColor) {
		this->setFillColor(newColor);
	}
};

#endif