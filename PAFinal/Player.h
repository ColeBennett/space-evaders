#ifndef SPACEEVADERS_CHARACTER_H
#define SPACEEVADERS_CHARACTER_H

#include "Entity.h"

class Player : public Entity
{
private:
	/* The texture object must be defined as a member of this class
	* and kept loaded in memory to allow SFML to use it */
	sf::Texture texture;

public:
	Player()
	{
		/* Make the sprite smaller (50% of the original image size) */
		setScale(0.5, 0.5);

		/* Load and set the texture for the sprite */
		if (texture.loadFromFile("character.png")) {
			setTexture(texture);
		}
	}
};

#endif
