#ifndef SPACEEVADERS_ENGINE_H
#define SPACEEVADERS_ENGINE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "time.h"
#include "Player.h"
#include "MenuView.h"
#include "GameView.h"
#include "GameEndView.h"
#include "Leaderboard.h"
#include "TutorialView.h"

using std::cout;
using std::endl;

enum State
{
	MAIN_MENU,
	LEADERBOARD,
	IN_GAME,
	GAME_END_SCREEN,
    TUTORIAL,
};

class Engine
{
private:
	sf::RenderWindow window;
	sf::Font font;
	State state;

public:
	Engine();
	~Engine();

	void run();
	void center(sf::Text &text, float y = 0);
	int random(int min, int max);
	sf::RenderWindow & getWindow() const;
};

#endif
