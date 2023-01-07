#pragma once
#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{
    sf::Vector2f size;
    sf::Vector2f position;
public:
    Paddle(float x, float y, float width, float height);
    void movement(float speed, float xW);
    void draw(sf::RenderWindow& window);
};
