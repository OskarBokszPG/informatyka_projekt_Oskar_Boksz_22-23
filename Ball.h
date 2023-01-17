#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Invader.h"
#include "HUD.h"
class Ball :public sf::Sprite
{
	sf::Texture texture;
	float r;
public:
	sf::Vector2f position;
	float xS;
	float yS;
	sf::Vector2f speed;
	friend class HUD;
	bool rusz = true;
	int pkt = 0;
	Ball(float x, float y);

	void bounce(float xW, Paddle pros);

	void movBall();

	void checkCollision(Invader& invader);

	void lossLife(float yW, HUD& k);

	void draw(sf::RenderWindow& window);
};
