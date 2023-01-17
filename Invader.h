#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Invader : public sf::Sprite
{
	sf::Texture texture;
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Clock clock;
	sf::Time elapsedTime;
public:
	friend class Ball;
	std::vector<sf::Sprite> invaders;
	int liczbaInv;
	bool rusz = true;
	bool direction = true;
	float speed;
	Invader(float x, float y, float numInv);
	void create();
	void invDelete();
	void mov(float xW);
	void draw(sf::RenderWindow& window);
};