#include "Game.h"

Game::Game()
{
	// (temporary) change to MAIN_MENU later
	state = IN_GAME;
}

Game::~Game()
{

}

void Game::run()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "<GAME TITLE>");
	const float width = window.getSize().x, height = window.getSize().y;

	// Declare a new font
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		// error...
	}

	/* Position character at bottom center */
	Character character;
	character.setPosition(sf::Vector2f((window.getSize().x - character.getScale().x) / 2, window.getSize().y));

	bool upPressed = false, downPressed = false,
		leftPressed = false, rightPressed = false;
	long frameIndex = 0;
	float characterSpeed = 1.5;
	float wallSpeed = 1.5;
	sf::Color wallColor = sf::Color::Red;
	std::vector<Wall> walls;

	Wall wall(wallColor);
	wall.startY = height - 100;
	wall.setPosition(0, height - 100);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
			if (state == IN_GAME) {
				if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
					if (event.type == sf::Event::KeyPressed) {
						upPressed = true;
					}
					else if (event.type == sf::Event::KeyReleased) {
						upPressed = false;
					}
				}
				if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
					if (event.type == sf::Event::KeyPressed) {
						downPressed = true;
					}
					else if (event.type == sf::Event::KeyReleased) {
						downPressed = false;
					}
				}
				if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
					if (event.type == sf::Event::KeyPressed) {
						leftPressed = true;
					}
					else if (event.type == sf::Event::KeyReleased) {
						leftPressed = false;
					}
				}
				if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
					if (event.type == sf::Event::KeyPressed) {
						rightPressed = true;
					}
					else if (event.type == sf::Event::KeyReleased) {
						rightPressed = false;
					}
				}
			}
		}

		window.clear();
		switch (state) {
		case MAIN_MENU:
			//                sf::Text text("Test", font);
			//                text.setPosition(500, 500);
			//                window.draw(text);
			break;
		case LEADERBOARD:

			break;
		case IN_GAME:
			/* Prevent character from going off the screen */
			if (character.getPosition().x + character.getLocalBounds().width >= window.getSize().x
				|| character.getPosition().x < 0
				|| character.getPosition().y + character.getLocalBounds().height >= window.getSize().y
				|| character.getPosition().y < 0) {
				character.setPosition(500, 500);
				continue;
			}

			/* Collision detection */
			// ...


			if (upPressed) {
				character.move(0, -characterSpeed);
			}
			if (downPressed) {
				character.move(0, characterSpeed);
			}
			if (leftPressed) {
				character.move(-characterSpeed, 0);
			}
			if (rightPressed) {
				character.move(characterSpeed, 0);
			}
			window.draw(character);

			if (frameIndex % 10 == 0) {
				wall.setSize(sf::Vector2f(random(200, 300), random(50, 100)));
				wall.move(0, -wallSpeed);
			}
			window.draw(wall);
			break;
		case GAME_END_SCREEN:

			break;
		default:
			break;
		}

		window.display();
		frameIndex++;
		if (frameIndex == LONG_MAX) {
			frameIndex = 0;
		}
	}
}

int Game::random(int min, int max) //range : [min, max)
{
	static bool first = true;
	if (first) {
		srand(time(NULL)); //seeding for the first time only!
		first = false;
	}
	return min + rand() % (max - min);
}