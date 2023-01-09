#include "Ball.h"
#include <iostream>


Ball::Ball(float x, float y, float radius, float speedX, float speedY)
{
    position.x = x;
    position.y = y;
	r = radius;
    speed.x = speedX;
    speed.y = speedY;
	setRadius(radius);
	setFillColor(sf::Color::Cyan);
    setPosition(position);
    setOrigin(r, r);
}
void Ball::bounce(float xW, Paddle pros, Invader block)
{
    position = getPosition();
    if (position.x +r > xW || position.x -r < 0) {
        speed.x = -speed.x;
    }
    if (position.y -r < 0) {
        speed.y = -speed.y;
    }
    //if (position.y + r > yW)
    //    speed.y = -speed.y;
    if (getPosition().x + r > pros.getPosition().x - pros.getSize().x / 2.f &&
        getPosition().x - r < pros.getPosition().x + pros.getSize().x / 2.f &&
        getPosition().y + r > pros.getPosition().y - pros.getSize().y / 2.f &&
        getPosition().y - r < pros.getPosition().y + pros.getSize().y / 2.f)
        speed.y = -speed.y;
}


void Ball::movBall() {
    move(speed);
}

void Ball::checkCollision(Invader& invader)
{
    for (int i = 0; i < invader.invaders.size(); i++)
    {
        sf::FloatRect invaderRect = invader.invaders[i].getGlobalBounds();

        if (getPosition().x + r > invaderRect.left
            && getPosition().x + r < invaderRect.left + invaderRect.width
            && getPosition().y + r > invaderRect.top
            && getPosition().y - r < invaderRect.top + invaderRect.height)
        {
            speed.y = -speed.y;
            invader.invaders[i].setColor(sf::Color::Red);
        }
    }
}



void Ball::draw(sf::RenderWindow& window)
{

    window.draw(*this);
}