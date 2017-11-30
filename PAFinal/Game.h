#ifndef PA9_GAME_H
#define PA9_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Character.h"
#include "Wall.h"
#include "Leaderboard.h"
#include "time.h"

using std::cout;
using std::endl;

enum State
{
	MAIN_MENU,
	LEADERBOARD,
	IN_GAME,
	GAME_END_SCREEN,
};

class Game
{
private:
	State state;

public:
	Game();
	~Game();

	void run();
	int random(int min, int max);
};

#endif
