#include "TutorialView.h"

TutorialView::TutorialView(Engine &engine, sf::RenderWindow &window)
{
    bg.setTexture(engine.getBgTexture());
    bg.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));

    title.setString("instructions");
    title.setFont(engine.getFont());
    title.setCharacterSize(100);
    title.setFillColor(sf::Color(66, 134, 244));
    title.setOutlineColor(sf::Color::Cyan);
    title.setOutlineThickness(3.5);
    engine.center(title, window.getSize().y * .1f);

    instructions.setString(
            "welcome to space evaders your goal is to evade all\n"
                    "hazards as long as possible, this includes asteroids\n"
                    "and enemy fire. your score will depend on how long you\n"
                    "last without getting hit. do you have what it takes to\n"
                    "make it to the leaderboard? play and find out.");
    instructions.setFont(engine.getFont());
    instructions.setFillColor(sf::Color(144, 224, 58));
    instructions.setCharacterSize(32);
    engine.center(instructions, window.getSize().y * .25f);

    controls.setString("controls");
    controls.setFont(engine.getFont());
    controls.setFillColor(sf::Color(66, 134, 244));
    controls.setOutlineColor(sf::Color::Cyan);
    controls.setOutlineThickness(3.5);
    controls.setCharacterSize(50);

    engine.center(controls, window.getSize().y * .4f);

    useArrowKeys.setString("use arrow keys to move or...");
    useArrowKeys.setFont(engine.getFont());
    useArrowKeys.setFillColor(sf::Color::Magenta);
    useArrowKeys.setCharacterSize(32);
    engine.center(useArrowKeys, window.getSize().y * .5f);

    up.setString("w: up");
    up.setFont(engine.getFont());
    up.setFillColor(sf::Color::Yellow);
    up.setCharacterSize(30);
    up.setPosition(window.getSize().x * .3f, window.getSize().y * .6f);

    down.setString("s: down");
    down.setFont(engine.getFont());
    down.setFillColor(sf::Color::Yellow);
    down.setCharacterSize(30);
    down.setPosition(window.getSize().x * .6f, window.getSize().y * .6f);

    left.setString("a: left");
    left.setFont(engine.getFont());
    left.setFillColor(sf::Color::Yellow);
    left.setCharacterSize(30);
    left.setPosition(window.getSize().x * .3f, window.getSize().y * .65f);

    right.setString("d: right");
    right.setFont(engine.getFont());
    right.setFillColor(sf::Color::Yellow);
    right.setCharacterSize(30);
    right.setPosition(window.getSize().x * .6f, window.getSize().y * .65f);

    space.setString("space: shoot laser");
    space.setFont(engine.getFont());
    space.setFillColor(sf::Color::Yellow);
    space.setCharacterSize(30);
    engine.center(space, window.getSize().y * .7f);

    toMenu.setString("to menu");
    toMenu.setFont(engine.getFont());
    toMenu.setFillColor(sf::Color::Green);
    toMenu.setCharacterSize(50);
    engine.center(toMenu, window.getSize().y * .8f);
}

void TutorialView::draw(Engine &engine, sf::RenderWindow &window)
{
    window.draw(bg);
    window.draw(title);

    window.draw(instructions);

    window.draw(controls);
    window.draw(useArrowKeys);
    window.draw(up);
    window.draw(down);
    window.draw(left);
    window.draw(right);
    window.draw(space);

    engine.checkButton(toMenu, MENU, sf::Color::Green, sf::Color::Magenta);
    window.draw(toMenu);
}