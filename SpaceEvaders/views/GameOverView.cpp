#include "GameOverView.h"

GameOverView::GameOverView(Engine &engine, sf::RenderWindow &window)
{
    bg.setTexture(engine.getBgTexture());
    bg.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

    gameOverText.setString("game over");
    gameOverText.setFont(engine.getFont());
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setOutlineColor(sf::Color(207, 214, 27));
    gameOverText.setOutlineThickness(4);
    gameOverText.setCharacterSize(160);
    engine.center(gameOverText, window.getSize().y * .25f);

    scoreText.setString("score");
    scoreText.setFont(engine.getFont());
    scoreText.setFillColor(sf::Color::Magenta);
    scoreText.setCharacterSize(75);

    toMenu.setString("to menu");
    toMenu.setFont(engine.getFont());
    toMenu.setFillColor(sf::Color::Green);
    toMenu.setCharacterSize(50);
    engine.center(toMenu, window.getSize().y * .8f);
}

void GameOverView::draw(Engine &engine, sf::RenderWindow &window)
{
    window.draw(bg);
    window.draw(gameOverText);

    std::string s("score: ");
    char buffer[10];
    sprintf(buffer, "%.1f", engine.getScore());
    s += buffer;
    scoreText.setString(s);
    engine.center(scoreText, window.getSize().y * .45f);
    window.draw(scoreText);

    engine.checkButton(toMenu, MENU, sf::Color::Green, sf::Color(166, 170, 178));
    window.draw(toMenu);
}
