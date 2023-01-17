#pragma once
#include <SFML/Graphics.hpp>

class Paddle : public sf::Sprite
{

    sf::Texture texture;
    sf::Sprite sprite;
public:
    sf::Vector2f position;
    int speed;
    bool rusz = true;
    Paddle(float x, float y);
    void movement(float xW);
    void draw(sf::RenderWindow& window);
};
