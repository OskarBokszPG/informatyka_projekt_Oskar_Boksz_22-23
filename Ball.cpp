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
	setFillColor(sf::Color::Red);
    setPosition({x,y});
    setOrigin(r, r);
}
void Ball::kolizja(float xW, float yW)
{
    position = getPosition();
    if (position.x +r > xW || position.x -r < 0) {
        speed.x = -speed.x;
    }
    if (position.y -r < 0) {
        speed.y = -speed.y;
    }
    //if (position.y + r > yW)
    //    return 0;
}
void Ball::movBall() {
    move(speed);
}

void Ball::bounce(Paddle pros) {
    pros.getPosition();
    pros.getSize();
    if (getPosition().x + r > pros.getPosition().x - pros.getSize().x / 2.f &&
        getPosition().x - r < pros.getPosition().x + pros.getSize().x / 2.f &&
        getPosition().y + r > pros.getPosition().y - pros.getSize().y / 2.f &&
        getPosition().y - r < pros.getPosition().y + pros.getSize().y / 2.f)
        speed.y = -speed.y;
}

void Ball::draw(sf::RenderWindow& window)
{

    window.draw(*this);
}