#ifndef SPACEEVADERS_CHARACTER_H
#define SPACEEVADERS_CHARACTER_H

#include "Entity.h"

class Player : public Entity
{
private:
	bool dead;
	unsigned int kills;
	unsigned int ammo;

public:
	Player() : Entity("assets/character.png")
	{
		/* Make the sprite smaller */
		setScale(0.8, 0.8);
	}

	bool isDead()
	{
		return dead;
	}

	void setDead(const bool isDead)
	{
		dead = isDead;
	}

	unsigned int getKills() const
	{
		return kills;
	}

	unsigned int getAmmo() const
	{
		return ammo;
	}

	void setKills(const unsigned int &kills)
	{
		this->kills = kills;
	}

	void setAmmo(const unsigned int &ammo)
	{
		this->ammo = ammo;
	}
};

#endif
