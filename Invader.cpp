#include "Invader.h"
#include <iostream>

Invader::Invader(float x, float y, float numInv)
{
    position.x = x;
    position.y = y;
    liczbaInv = numInv;
    texture.loadFromFile("invader.png");
    sprite.setScale(0.13f, 0.13f);
    sprite.setTexture(texture);
    create();
}
void Invader::mov(float xW)
{
    if (rusz == true) {
        elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() >= 1.0f) {
            if (direction) {
                for (int i = 0; i < invaders.size(); i++)
                {
                    invaders[i].move(speed, 0);
                }
            }
            else {
                for (int i = 0; i < invaders.size(); i++)
                {
                    invaders[i].move(-speed, 0);
                }
            }
            if (invaders[invaders.size() - 1].getPosition().x + invaders[invaders.size() - 1].getGlobalBounds().width >= xW ) {
                direction = false;
                for (int i = 0; i < invaders.size(); i++) {
                    invaders[i].move(0, 80);
                }
            }
            else if (invaders[0].getPosition().x <= 0) {
                direction = true;
                for (int i = 0; i < invaders.size(); i++) {
                    invaders[i].move(0, 80);
                }
            }
            clock.restart();
        }
    }
}
void Invader::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < invaders.size(); i++)
    {
        window.draw(invaders[i]);
    }

}

void Invader::create()
{
    for (int i = 0; i < liczbaInv; i++)
    {
        if (i > 9)
        {
            sprite.setPosition(position.x + (i % 10) * (sprite.getGlobalBounds().width), position.y + sprite.getGlobalBounds().height * (i / 10));
        }
        else
        {
            sprite.setPosition(position.x + i * (sprite.getGlobalBounds().width), position.y);
        }
        invaders.push_back(sprite);
    }
}


void Invader::invDelete()
{
    invaders.clear();
}
