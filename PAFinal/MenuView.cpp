#include "MenuView.h"

MenuView::MenuView(const sf::RenderWindow &window, const sf::Font &font)
{
    gameTitle.setString("space evaders");
    gameTitle.setFont(font);
    gameTitle.setCharacterSize(80);
    gameTitle.setFillColor(sf::Color(242, 167, 19));
    gameTitle.setPosition((window.getSize().x / 2) - (gameTitle.getGlobalBounds().width / 2), (float) (window.getSize().y * .1));

    play.setString("play");
    play.setFont(font);
    play.setCharacterSize(75);
    play.setFillColor(sf::Color(166, 170, 178));
    play.setPosition((window.getSize().x / 2) - (play.getGlobalBounds().width / 2), (float) (window.getSize().y * .3));

    leaderboard.setString("lead");
    leaderboard.setFont(font);
    leaderboard.setCharacterSize(75);
    leaderboard.setFillColor(sf::Color(166, 170, 178));
    leaderboard.setPosition((window.getSize().x / 2) - (leaderboard.getGlobalBounds().width / 2), (float) (window.getSize().y * .4));

    exit.setString("exit");
    exit.setFont(font);
    exit.setCharacterSize(55);
    exit.setFillColor(sf::Color::Red);
    exit.setPosition((window.getSize().x / 2) - (exit.getGlobalBounds().width / 2), (float) (window.getSize().y * .5));
}

void MenuView::draw(sf::RenderWindow &window)
{
    window.draw(gameTitle);
    window.draw(play);
    window.draw(leaderboard);
    window.draw(exit);
}
