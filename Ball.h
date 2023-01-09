#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Invader.h"
class Ball :public sf::CircleShape
{
	sf::Texture texture;
	sf::Vector2f position;
	sf::Vector2f speed;
	int playerLife;
	float r;
public:
	Ball(float x, float y, float radius, float speedX, float speedY);

	void bounce(float xW, Paddle pros);

	void movBall();

	void checkCollision(Invader& invader);

	void lossLife(float yW);

	void draw(sf::RenderWindow& window);
};
