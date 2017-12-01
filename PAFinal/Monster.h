#ifndef SPACEEVADERS_CHARACTER_H
#define SPACEEVADERS_CHARACTER_H

#inclide "Entity.h"

class Monster : public Entity
{
private:
	sf::Texture texture;

public:
	Monster()
	{
		setScale(0.5, 0.5);

		if (texture.loadFromFile("monster.png")) {
			setTexture(texture);
		}
	}
};

#endif
