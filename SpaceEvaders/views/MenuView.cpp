#include "MenuView.h"

MenuView::MenuView(Engine &engine, const sf::RenderWindow &window)
{
    sf::Texture *texture = new sf::Texture;
    texture->loadFromFile("assets/bg_front.jpg");
    bgTexture = texture;
    bg.setTexture(texture);
    bg.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

    gameTitle.setString("space evaders");
    gameTitle.setFont(engine.getFont());
    gameTitle.setCharacterSize(100);
    gameTitle.setFillColor(sf::Color(66, 134, 244));
    gameTitle.setOutlineColor(sf::Color::Cyan);
    gameTitle.setOutlineThickness(3.5);
    engine.center(gameTitle, window.getSize().y * .1f);

    play.setString("play");
    play.setFont(engine.getFont());
    play.setCharacterSize(75);
    play.setFillColor(sf::Color(166, 170, 178));
    engine.center(play, window.getSize().y * .3f);

    leaderboard.setString("top scores");
    leaderboard.setFont(engine.getFont());
    leaderboard.setCharacterSize(75);
    leaderboard.setFillColor(sf::Color(166, 170, 178));
    engine.center(leaderboard, window.getSize().y * .4f);

    tutorial.setString("rules");
    tutorial.setFont(engine.getFont());
    tutorial.setCharacterSize(75);
    tutorial.setFillColor(sf::Color(166, 170, 178));
    engine.center(tutorial, window.getSize().y * .5f);

    exit.setString("exit");
    exit.setFont(engine.getFont());
    exit.setCharacterSize(55);
    exit.setFillColor(sf::Color::Red);
    engine.center(exit, window.getSize().y * .6f);
}

MenuView::~MenuView()
{
    delete bgTexture;
}

void MenuView::draw(Engine &engine, sf::RenderWindow &window)
{
    window.draw(bg);

    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    sf::Color buttonColor = sf::Color::Green;
    engine.checkButton(play, IN_GAME, buttonColor, sf::Color(166, 170, 178));
    engine.checkButton(leaderboard, LEADERBOARD, buttonColor, sf::Color(166, 170, 178));
    engine.checkButton(tutorial, TUTORIAL, buttonColor, sf::Color(166, 170, 178));

    if (exit.getGlobalBounds().contains(mouse)) {
        exit.setFillColor(sf::Color::Magenta);
        if (pressed) {
            window.close();
        }
    } else {
        exit.setFillColor(sf::Color::Red);
    }

    window.draw(gameTitle);
    window.draw(play);
    window.draw(leaderboard);
    window.draw(tutorial);
    window.draw(exit);
}
