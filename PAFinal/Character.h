#ifndef PA9_CHARACTER_H
#define PA9_CHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Character : public sf::Sprite
{
private:
	/* The texture object must be defined as a member of this class
	* and kept loaded in memory to allow SFML to use it */
	sf::Texture texture;

public:
	Character() {
		/* Make the sprite smaller (50% of the original image size) */
		this->setScale(0.5, 0.5);

		/* Load and set the texture for the sprite */
		if (texture.loadFromFile("character.png")) {
			this->setTexture(texture);
		}
	}
};

#endif
