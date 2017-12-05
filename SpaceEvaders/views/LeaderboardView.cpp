#include "LeaderboardView.h"

LeaderboardView::LeaderboardView(Engine &engine, sf::RenderWindow &window)
{
    bg.setTexture(engine.getBgTexture());
    bg.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

    title.setString("leaderboard");
    title.setFont(engine.getFont());
    title.setCharacterSize(100);
    title.setFillColor(sf::Color(66, 134, 244));
    title.setOutlineColor(sf::Color::Cyan);
    title.setOutlineThickness(3.5);
    engine.center(title, window.getSize().y * .1f);

    toMenu.setString("to menu");
    toMenu.setFont(engine.getFont());
    toMenu.setFillColor(sf::Color::Green);
    toMenu.setCharacterSize(50);
    engine.center(toMenu, window.getSize().y * .8f);
}

void LeaderboardView::draw(Engine &engine, sf::RenderWindow &window)
{
    window.draw(bg);
    window.draw(title);

    float y = window.getSize().y * .25f;
    int position = 1;
    LeaderboardEntry *pCur = engine.getLeaderboard().getHeadPtr();
    while (pCur != nullptr && position <= 10) {
        std::string s;
        s += std::to_string(position++);
        s += ": ";

        char buffer[10];
        sprintf(buffer, "%.1f", pCur->getScore());
        s += buffer;

        sf::Text text;
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Magenta);
        text.setFont(engine.getFont());
        text.setString(s);

        text.setPosition(window.getSize().x * 0.42f, y);
        window.draw(text);

        y += 60;
        pCur = pCur->getNext();
    }

    engine.checkButton(toMenu, MENU, sf::Color::Green, sf::Color(166, 170, 178));
    window.draw(toMenu);
}