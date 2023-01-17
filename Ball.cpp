#include "Ball.h"
#include <iostream>


Ball::Ball(float x, float y)
{
    position.x = x;
    position.y = y;
    //xS = speedX;
    //yS = speedY;
    texture.loadFromFile("ball.png");
    if (!texture.loadFromFile("ball.png"))
    {
        std::cout << "Blad w ladowaniu paddle";
    };
    setTexture(texture);
    r = getGlobalBounds().width / 2;
    setOrigin(r,r);
    setPosition(position);
}

void Ball::bounce(float xW, Paddle pros)
{
    if (getPosition().x + r > xW || getPosition().x - r < 0) {
        speed.x = -speed.x;
    }
    if (getPosition().y - r < 0) {
        speed.y = -speed.y;
    }
    if (getPosition().x + r > pros.getPosition().x - (pros.getGlobalBounds().width / 2) &&
        getPosition().x - r < pros.getPosition().x + (pros.getGlobalBounds().width / 2) &&
        getPosition().y + r > pros.getPosition().y - ((pros.getGlobalBounds().height) / 2) &&
        getPosition().y - r < pros.getPosition().y + (pros.getGlobalBounds().height) / 2)
    {
        float g = sqrt((speed.x * speed.x) + (speed.y * speed.y));
        speed.x = 8 * ((getPosition().x + r) - pros.getPosition().x) / pros.getGlobalBounds().width;
        speed.y = -sqrt((g * g) - (speed.x * speed.x));
    }
}


void Ball::movBall() {
    if(rusz == true)
        move(speed);
}

void Ball::checkCollision(Invader& invader)
{
    for (int i = 0; i < invader.invaders.size(); i++)
    {
        sf::FloatRect invaderRect = invader.invaders[i].getGlobalBounds();
        if (getGlobalBounds().intersects(invaderRect))
        {
            if (getPosition().y + r < invaderRect.top + (invaderRect.height / 2))
            {
                speed.x = -speed.x;
            }
            speed.y = -speed.y;
            invader.invaders.erase(invader.invaders.begin() + i);
            pkt++;
        }
    }
}


void Ball::draw(sf::RenderWindow& window)
{
    window.draw(*this);
}

void Ball::lossLife(float yW, HUD& k)
{
    if (getPosition().y - r > yW) {
        k.life--;
        if (k.hearts.size() > 0) {
            setPosition(position);
            speed.y = -yS;
            speed.x = xS;
            k.hearts.erase(k.hearts.begin(), k.hearts.begin() + (k.hearts.size() - k.life));
        }
    }
}
