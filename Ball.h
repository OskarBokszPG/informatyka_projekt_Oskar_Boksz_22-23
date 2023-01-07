#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Ball :public sf::CircleShape
{
	sf::Vector2f position;
	sf::Vector2f speed;
	float r;
public:
	Ball(float x, float y, float radius, float speedX, float speedY);
	void kolizja(float xW, float yW);
	void movBall();
	void bounce(Paddle pros);
	void draw(sf::RenderWindow& window);
};
