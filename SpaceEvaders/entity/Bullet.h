#ifndef SPACEEVADERS_BULLET_H
#define SPACEEVADERS_BULLET_H

#include "Entity.h"

enum BulletType
{
	PLAYER,
	MONSTER
};

class Bullet : public Entity
{
private:
	BulletType type;
	float speedX, speedY;

public:
	Bullet(const BulletType &type)
	{
		this->type = type;
		setScale(.2, .2);
	}

	BulletType getType()
	{
		return type;
	}

	float getSpeedX()
	{
		return speedX;
	}

	float getSpeedY()
	{
		return speedY;
	}

	void setSpeedX(const float &speedX)
	{
		this->speedX = speedX;
	}

	void setSpeedY(const float &speedY)
	{
		this->speedY = speedY;
	}
};

#endif
