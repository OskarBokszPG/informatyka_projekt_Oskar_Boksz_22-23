#include "HUD.h"

HUD::HUD()
{
sf::RectangleShape line(sf::Vector2f(1400, 5));
line.setOrigin(0, 1200);
line.rotate(90);
}

void HUD::rysuj(sf::RenderWindow& window)
{
	//window.draw(*this);
}
