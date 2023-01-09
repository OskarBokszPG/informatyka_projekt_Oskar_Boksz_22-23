#pragma once
#include <SFML/Graphics.hpp>
class HUD
{
    sf::Time timeLeft;
    sf::Font font;
    sf::Text text;
    sf::Clock clock;
public:
    HUD(float x, float y, float t);
    void draw(sf::RenderWindow& window);
    void update();
};


