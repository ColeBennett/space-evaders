#ifndef SPACEEVADERS_ENGINE_H
#define SPACEEVADERS_ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "time.h"
#include "entity/Player.h"
#include "SoundManager.h"
#include "leaderboard/LeaderBoard.h"

using std::cout;
using std::endl;

enum State
{
	MENU,
	LEADERBOARD,
	IN_GAME,
	GAME_OVER,
    TUTORIAL,
};

class Engine
{
private:
	sf::RenderWindow window;
    SoundManager soundManager;
	sf::Texture *bgTexture;
	sf::Font font;
	float lastScore;
	LeaderBoard leaderboard;

public:
    State state;
    Engine();
    ~Engine();

	void run();
	void endGame(const float &score);
	void center(sf::Text &text, float y = 0);
	bool checkButton(sf::Text &button, const State &toState,
					 const sf::Color &buttonColor, const sf::Color &highlightColor);
	int random(int min, int max);
	double random(double M, double N);
	sf::RenderWindow & getWindow();
	sf::Texture * getBgTexture();
    sf::Font & getFont();
    SoundManager & getSoundManager();
	float getScore() const;
	LeaderBoard & getLeaderboard();
};

#endif
