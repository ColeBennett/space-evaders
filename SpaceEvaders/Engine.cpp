#include "Engine.h"
#include "views/MenuView.h"
#include "views/GameView.h"
#include "views/GameOverView.h"
#include "views/LeaderboardView.h"
#include "views/TutorialView.h"

/**
 * Engine constructor. Load the background texture and
 * read the scores file for the leaderboard.
 */
Engine::Engine()
{
    sf::Texture *texture = new sf::Texture;
    texture->loadFromFile("assets/bg.jpg");
    bgTexture = texture;

    leaderboard.printLeaderBoard();

    state = MENU;
}

/**
 * Engine destructor.
 */
Engine::~Engine()
{
    delete bgTexture;
}

/**
 * Creates the window, handles the events, and draws the views to the window.
 */
void Engine::run()
{
    window.create(sf::VideoMode(1600, 1400), "Space Evaders");
    window.setFramerateLimit(100);
    font.loadFromFile("assets/Dream MMA.ttf");

    bool upPressed = false, downPressed = false,
            leftPressed = false, rightPressed = false,
            spacePressed = false;

    /* Views */
    MenuView menuView(*this, window);
    GameView gameView(*this, window);
    GameOverView gameOver(*this, window);
    LeaderboardView leaderboardView(*this, window);
    TutorialView tutorialView(*this, window);

    long frames = 0;
    sf::Clock clock;
    bool loadedMusic = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }

            if (state == IN_GAME) {
                if (event.type == sf::Event::KeyPressed) {
                    if (!upPressed &&
                        (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)) {
                        upPressed = true;
                    }
                    if (!downPressed &&
                        (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)) {
                        downPressed = true;
                    }
                    if (!leftPressed &&
                        (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)) {
                        leftPressed = true;
                    }
                    if (!rightPressed &&
                        (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)) {
                        rightPressed = true;
                    }
                    if (!spacePressed && event.key.code == sf::Keyboard::Space) {
                        spacePressed = true;
                    }
                } else if (event.type == sf::Event::KeyReleased) {
                    if (upPressed &&
                        (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)) {
                        upPressed = false;
                    }
                    if (downPressed &&
                        (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)) {
                        downPressed = false;
                    }
                    if (leftPressed &&
                        (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)) {
                        leftPressed = false;
                    }
                    if (rightPressed &&
                        (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)) {
                        rightPressed = false;
                    }
                    if (spacePressed && event.key.code == sf::Keyboard::Space) {
                        spacePressed = false;
                    }
                }
            }
        }

        if (state == IN_GAME) {
            if (gameView.getPlayer().isDead()) {
                upPressed = downPressed = leftPressed = rightPressed = spacePressed = false;
            }
            if (!gameView.getPlayer().isDead()) {
                if (upPressed) {
                    gameView.getPlayer().move(0, -gameView.getPlayer().getSpeed());
                }
                if (downPressed) {
                    gameView.getPlayer().move(0, gameView.getPlayer().getSpeed());
                }
                if (leftPressed) {
                    gameView.getPlayer().move(-gameView.getPlayer().getSpeed(), 0);
                }
                if (rightPressed) {
                    gameView.getPlayer().move(gameView.getPlayer().getSpeed(), 0);
                }
                if (spacePressed) {
                    gameView.fireBullet(*this);
                }
            }
            gameView.tick(*this, window);
        }

        window.clear();
        /* update and draw the views */
        switch (state) {
            case MENU:
                menuView.draw(*this, window);
                break;
            case LEADERBOARD:
                leaderboardView.draw(*this, window);
                break;
            case IN_GAME:
                gameView.draw(*this, window);
                break;
            case GAME_OVER:
                gameOver.draw(*this, window);
                break;
            case TUTORIAL:
                tutorialView.draw(*this, window);
                break;
            default:
                break;
        }
        spacePressed = false;
        window.display();

        if (!loadedMusic) {
            loadedMusic = true;
            soundManager.playTheme();
        }

        frames++;
        if (clock.getElapsedTime().asMilliseconds() >= 1000) {
            cout << "FPS: " << frames << endl;
            clock.restart();
            frames = 0;
        }
    }
}

/**
 * Change the view to the game over screen.
 * @param score the player's score
 */
void Engine::endGame(const float &score)
{
    lastScore = score;
    soundManager.stopTheme();
    soundManager.playGameOver();
    state = GAME_OVER;
}

/**
 * Center text in the window.
 * @param text the text to center
 * @param y the y coordinate position
 */
void Engine::center(sf::Text &text, float y)
{
    if (y == 0) y = window.getSize().y / 2;
    text.setPosition((window.getSize().x / 2) - (text.getGlobalBounds().width / 2), y);
}

/**
 * Checks if a button is pressed and change the view.
 * @param button 
 * @param toState new state 
 * @param buttonColor default button color
 * @param highlightColor highlighted button color
 * @return true if the button is pressed
 */
bool Engine::checkButton(sf::Text &button, const State &toState, const sf::Color &buttonColor, const sf::Color &highlightColor)
{
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    if (button.getGlobalBounds().contains(mouse)) {
        button.setFillColor(highlightColor);
        if (pressed) {
            /* button is pressed */
            soundManager.playClick();
            if (state == IN_GAME && toState == MENU) {
                soundManager.stopGameOverTheme();
                soundManager.playTheme();
            }
            state = toState;
        }
    } else {
        button.setFillColor(buttonColor);
    }
    return pressed;
}

/**
 * range: [min, max)
 */
int Engine::random(int min, int max)
{
    static bool first = true;
    if (first) {
        srand((unsigned) time(NULL));
        first = false;
    }
    return min + rand() % (max - min);
}

double Engine::random(double M, double N)
{
    return M + (rand() / (RAND_MAX / (N-M)));
}

sf::RenderWindow & Engine::getWindow()
{
    return window;
}

SoundManager & Engine::getSoundManager()
{
    return soundManager;
}

sf::Texture *Engine::getBgTexture()
{
    return bgTexture;
}

sf::Font & Engine::getFont()
{
    return font;
}

float Engine::getScore() const
{
    return lastScore;
}

LeaderBoard & Engine::getLeaderboard()
{
    return leaderboard;
}