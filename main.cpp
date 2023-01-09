#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "HUD.h"
#include "Invader.h"
#include "Game.h"
#include <iostream>



int main()
{
	sf::RenderWindow window(sf::VideoMode(1400, 800), "Arkanoid x SpaceInvaders");
	window.setFramerateLimit(60);
	Ball kulka(20.f, 700.f, 10.f, 0.5f, -5.f); //Ustawiam pozycj� pocz�tkow�,promie� kulki oraz pr�dko��
	Paddle paletka(400.f, 700.f, 200.f, 20.f); //Ustawiam pozycj� pocz�tkow� oraz wymiary paletki
	Invader rzad1(20,10, 10);
	Invader rzad2(60, 60 ,10);
	HUD zegar(1250, 50, 120);		//Ustawiam wsp�rz�dne po�o�enia zegara i czas jaki ma odlicza� w sekundach

	sf::Texture texture;
	if (!texture.loadFromFile("tlo.png"))
	{
		std::cout << "Blad w ladowaniu tla";
	}
	sf::Sprite background;
	background.setTexture(texture);
	background.setPosition(0, 0);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}
		window.clear();
		background.setScale(
			static_cast<float>(window.getSize().x) / texture.getSize().x,
			static_cast<float>(window.getSize().y) / texture.getSize().y
		);
		window.draw(background);
		kulka.checkCollision(rzad1);
		kulka.checkCollision(rzad2);
		zegar.update();
		zegar.draw(window);
		sf::RectangleShape line(sf::Vector2f(1400, 2));
		line.setOrigin(0, 1200);
		line.rotate(90);
		window.draw(line);
		paletka.movement(5.f, line.getOrigin().y - line.getSize().y); //Ustawiam pr�dko�� i granic� ruchu prawostronnego paletki
		paletka.draw(window);
		kulka.draw(window);
		rzad1.mov(line.getOrigin().y);
		rzad2.mov(line.getOrigin().y);
		kulka.bounce(line.getOrigin().y, paletka); //Ustawiam elementy od kt�rych pi�ka ma si� odbija�
		kulka.movBall();
		kulka.lossLife(window.getSize().y);
		rzad1.draw(window);
		rzad2.draw(window);
		window.display();
	}

	return 0;
}
