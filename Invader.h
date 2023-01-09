#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Invader : public sf::Sprite
{
	std::vector<sf::Sprite> invaders;
	sf::Texture texture;
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Clock clock;

public:
	friend class Ball;
	float speed;
	Invader(float x, float y, int numInv);
	void mov(float xW);
	void draw(sf::RenderWindow& window);
};