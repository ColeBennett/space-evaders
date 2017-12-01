#include "Engine.h"

Engine::Engine()
{
    state = MAIN_MENU;
}

Engine::~Engine()
{

}

void Engine::run()
{
    window.create(sf::VideoMode(1200, 1000), "Space Evaders");

    // load font
    if (!font.loadFromFile("Dream MMA.ttf")) {
        // failed to load
    }

    bool upPressed = false, downPressed = false,
            leftPressed = false, rightPressed = false;
    const float characterSpeed = 1.5;

    /* Views */
    MenuView menuView(window, font);
    GameView gameView(window);
    GameEndView gameEndView(window);
    LeaderboardView leaderboardView(window);
//    TutorialView tutorialView(window);

    long frameIndex = 0;
    long fpsPerSec = 0, secondStart = 0;
//    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
//    auto epoch = now_ms.time_since_epoch();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }

            switch (state) {
                case MAIN_MENU:
                    // check button clicks
                    if (event.mouseButton.x != 0 && event.mouseButton.y != 0) {

                    }
                    break;
                case LEADERBOARD:

                    break;
                case IN_GAME:
                    if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
                        if (event.type == sf::Event::KeyPressed) {
                            upPressed = true;
                        } else if (event.type == sf::Event::KeyReleased) {
                            upPressed = false;
                        }
                    } else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
                        if (event.type == sf::Event::KeyPressed) {
                            downPressed = true;
                        } else if (event.type == sf::Event::KeyReleased) {
                            downPressed = false;
                        }
                    } else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
                        if (event.type == sf::Event::KeyPressed) {
                            leftPressed = true;
                        } else if (event.type == sf::Event::KeyReleased) {
                            leftPressed = false;
                        }
                    } else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
                        if (event.type == sf::Event::KeyPressed) {
                            rightPressed = true;
                        } else if (event.type == sf::Event::KeyReleased) {
                            rightPressed = false;
                        }
                    }
                    break;
                case GAME_END_SCREEN:

                    break;
                default:
                    break;
            }
        }

        window.clear();

        /* update and draw the views */
        switch (state) {
            case MAIN_MENU:
                menuView.draw(window);
                break;
            case LEADERBOARD:
                leaderboardView.draw(window);
                break;
            case IN_GAME:
                if (upPressed) {
                    gameView.getPlayer().move(0, -characterSpeed);
                }
                if (downPressed) {
                    gameView.getPlayer().move(0, characterSpeed);
                }
                if (leftPressed) {
                    gameView.getPlayer().move(-characterSpeed, 0);
                }
                if (rightPressed) {
                    gameView.getPlayer().move(characterSpeed, 0);
                }
                gameView.draw(window);
                break;
            case GAME_END_SCREEN:
                gameEndView.draw(window);
                break;
            case TUTORIAL:
//                tutorialView.draw(window);
                break;
            default:
                break;
        }
        window.display();

        fpsPerSec++;
        if (clock() - secondStart >= 1000) {
            cout << "FPS: " << fpsPerSec << endl;
            secondStart = clock();
            fpsPerSec = 0;
        }

        frameIndex++;
        if (frameIndex == LONG_MAX) {
            frameIndex = 0;
        }
    }
}

void Engine::center(sf::Text &text, float y)
{
    if (y == 0) y = window.getSize().y / 2;
    text.setPosition((window.getSize().x / 2) - (text.getGlobalBounds().width / 2), y);
}

int Engine::random(int min, int max) //range : [min, max)
{
    static bool first = true;
    if (first) {
        srand(time(NULL)); //seeding for the first time only
        first = false;
    }
    return min + rand() % (max - min);
}

sf::RenderWindow & Engine::getWindow() const
{
    return window;
}