#pragma once
#include <SFML/Graphics.hpp>
class Game
{
	sf::RenderWindow* window;
	sf::Event ev;
	void windowPropeties();
	void windowLoop();
public:
	Game();
	void update();
};

