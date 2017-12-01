#ifndef SPACEEVADERS_LEADERBOARD_H
#define SPACEEVADERS_LEADERBOARD_H

#include "View.h"

class LeaderboardView : public View
{

public:
    LeaderboardView(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
};

#endif
