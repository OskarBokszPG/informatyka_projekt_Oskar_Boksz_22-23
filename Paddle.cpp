#include "Paddle.h"
#include <iostream>

Paddle::Paddle(float x, float y)
{
    position.x = x;
    position.y = y;
    texture.loadFromFile("paddle.png");
    if (!texture.loadFromFile("paddle.png"))
    {
        std::cout << "Blad w ladowaniu paddle";
    };
    setTexture(texture);
    setColor(sf::Color::Magenta);
    setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
    setPosition(position);
}

void Paddle::movement(float xW)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && getPosition().x - (getGlobalBounds().width / 2) > 0 && rusz==true)
    {
        move(-speed, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && getPosition().x + (getGlobalBounds().width /2) < xW && rusz == true)
    {
        move(speed, 0);
    }
}

void Paddle::draw(sf::RenderWindow& window)
{
    window.draw(*this);
}
