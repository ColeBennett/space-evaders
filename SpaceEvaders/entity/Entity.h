#ifndef SPACEEVADERS_ENTITY_H
#define SPACEEVADERS_ENTITY_H

#include <SFML/Graphics.hpp>

/* Base class for entities such as player, monster, bullet etc. */
class Entity : public sf::Sprite
{
private:
    sf::Texture texture;
    float speed;

public:
    Entity() {}
    Entity(const std::string textureName)
    {
        if (texture.loadFromFile(textureName)) {
            setTexture(texture);
        }
    }

    float getSpeed() const
    {
        return speed;
    }

    void setSpeed(const float &speed)
    {
        this->speed = speed;
    }
};

#endif
