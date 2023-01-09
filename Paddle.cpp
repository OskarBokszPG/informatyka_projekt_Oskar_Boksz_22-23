#include "Paddle.h"
#include <iostream>

Paddle::Paddle(float x, float y, float width, float height)
{
    position.x = x;
    position.y = y;
    size.x = width;
    size.y = height;
    setPosition(position);
    setSize(size);
    setFillColor(sf::Color::White);
    setOrigin(width / 2, height / 2);
}

void Paddle::movement(float speed, float xW)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && getPosition().x - size.x/2 > 0)
    {
        move(-speed, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && getPosition().x + size.x /2 < xW)
    {
        move(speed, 0);
    }
}

void Paddle::draw(sf::RenderWindow& window)
{
    window.draw(*this);
}
