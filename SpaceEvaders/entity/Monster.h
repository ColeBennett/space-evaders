#ifndef SPACEEVADERS_MONSTER_H
#define SPACEEVADERS_MONSTER_H

#include "Entity.h"

class Monster : public Entity
{
public:
	Monster()
	{
		setScale(0.3, 0.3);
	}
};

#endif
