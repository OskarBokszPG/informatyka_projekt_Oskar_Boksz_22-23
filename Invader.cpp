#include "Invader.h"
#include <iostream>

Invader::Invader(float x, float y, int numInv)
{
    speed = 5;
    position.x = x;
    position.y = y;
    texture.loadFromFile("invader.png");
    for (int i = 0; i < numInv; i++)
    {
        sprite.setTexture(texture);
        sprite.setScale(0.09f, 0.09f);
        sprite.setPosition(position.x + i * (sprite.getGlobalBounds().width + 3), position.y);
        invaders.push_back(sprite);
    }
}
void Invader::mov()   
{
    sf::Vector2f currPos = invaders[0].getPosition();
    sf::Time elapsedTime = clock.getElapsedTime();

    if (elapsedTime.asSeconds() >= 1.0f) {
        currPos.x += speed;
        clock.restart();
    }

    for (auto& sprite : invaders)
    {
    sprite.setPosition(currPos);
    currPos.x += sprite.getGlobalBounds().width + 3;
    }
}

void Invader::draw(sf::RenderWindow& window)
{
    for (auto& sprite : invaders)
    {
        window.draw(sprite);
    }
}