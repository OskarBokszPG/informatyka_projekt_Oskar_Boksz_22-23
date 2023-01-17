#include "HUD.h"
#include <iostream>

HUD::HUD(float x, float y, bool& game)
{
	position.x = x;
	position.y = y;
	//sec = t;
	//timeLeft = sf::seconds(t);
	font.loadFromFile("Working Together.ttf");
	text.setCharacterSize(32);
	text.setFont(font);
	text.setFillColor(sf::Color::Magenta);
	text.setOutlineThickness(2);
	text.setOutlineColor(sf::Color::Black);
	text.setPosition({ x,y });

	liczbPkt.setCharacterSize(32);
	liczbPkt.setFont(font);
	liczbPkt.setFillColor(sf::Color::Black);
	liczbPkt.setOutlineThickness(2);
	liczbPkt.setOutlineColor(sf::Color::Magenta);
	liczbPkt.setPosition({ 0,0 });

	if (!texture.loadFromFile("serduszko.png"))
	{
		std::cout << "Blad w ladowaniu zyc";
	}
	heart.setTexture(texture);
	create();
}
void HUD::create() {
	for (int i = 0; i < life; i++)
	{
		heart.setPosition((position.x - heart.getGlobalBounds().width - 10) + i * (heart.getGlobalBounds().width + 3), position.y - 40);
		hearts.push_back(heart);
	}
}

void HUD::draw(sf::RenderWindow& window)
{
	window.draw(text);
	window.draw(liczbPkt);
	for (int i = 0; i < hearts.size(); i++)
	{
		window.draw(hearts[i]);
	}
}
void HUD::update(bool& stan, bool& game, Ball k) {

	if (lec == true && game == true) {
		elapsed = clock.getElapsedTime();
		punkty = "Punkty: " + std::to_string(k.pkt);
		liczbPkt.setString(punkty);
		if (elapsed >= sf::seconds(1) && stan == false)
		{
			if (timeLeft > sf::Time::Zero) {
				timeLeft -= elapsed;
				clock.restart();
				int minutes = static_cast<int>(timeLeft.asSeconds() / 60);
				int seconds = static_cast<int>(timeLeft.asSeconds()) % 60;
				if (seconds < 10) {
					timeString = std::to_string(minutes) + ":0" + std::to_string(seconds);
				}
				else {
					timeString = std::to_string(minutes) + ":" + std::to_string(seconds);
				}
				text.setString(timeString);
			}
			else {
				text.setString("0:00");
			}

		}
	}
}