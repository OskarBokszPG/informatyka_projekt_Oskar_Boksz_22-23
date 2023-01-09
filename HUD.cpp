#include "HUD.h"

HUD::HUD(float x, float y, float t)
{
	timeLeft = sf::seconds(t);
	font.loadFromFile("Working Together.ttf");
	text.setCharacterSize(24);
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	text.setPosition({ x,y });
}

void HUD::draw(sf::RenderWindow& window)
{
	window.draw(text);
}
void HUD::update() {
	sf::Time elapsed = clock.getElapsedTime();
	if (elapsed >= sf::seconds(1))
	{
		timeLeft -= elapsed;
		clock.restart();
	}
	std::string timeString = std::to_string(timeLeft.asSeconds());
	text.setString(timeString);
}