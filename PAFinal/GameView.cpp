#include "GameView.h"

GameView::GameView(sf::RenderWindow &window)
{
    player.setPosition(sf::Vector2f((window.getSize().x - player.getScale().x) / 2, window.getSize().y));
}

void GameView::draw(sf::RenderWindow &window)
{
    /* Prevent character from going off the screen */
    if (player.getPosition().x + player.getLocalBounds().width >= window.getSize().x
        || player.getPosition().x < 0
        || player.getPosition().y + player.getLocalBounds().height >= window.getSize().y
        || player.getPosition().y < 0) {
        player.setPosition(500, 500);
        return;
    }

    /* Collision detection */
    // ...

    window.draw(player);
}

Player & GameView::getPlayer() const
{
    return player;
}