#ifndef SPACEEVADERS_ASTEROID_H
#define SPACEEVADERS_ASTEROID_H

#include "Entity.h"

class Asteroid : public Entity
{
public:
	Asteroid()
	{
		setScale(0.6, 0.6);
	}
};

#endif
