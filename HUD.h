#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include <iostream>
class HUD
{
    sf::Font font;
    sf::Time elapsed;
    sf::Texture texture;
    std::string punkty;
    sf::Text liczbPkt;
    sf::Vector2f position;

public:
    sf::Time timeLeft;
    std::string timeString;
    int sec;
    sf::Text text;
    sf::Clock clock;
    sf::Sprite heart;
    std::vector<sf::Sprite> hearts;
    int life = 3;
    bool lec = true;
    HUD(float x, float y, bool& game);
    void draw(sf::RenderWindow& window);
    void update(bool& stan, bool& game, Ball k);
    void create();
};


