#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "HUD.h"
#include "Invader.h"
#include "Game.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1400, 800), "Arkanoid x SpaceInvaders");
	window.setFramerateLimit(60);
	Ball kulka(20.f, 700.f, 10.f, 0.5f, -5.f); //Ustawiam pozycjê pocz¹tkow¹,promieñ kulki oraz prêdkoœæ
	Paddle paletka(400.f, 700.f, 200.f, 20.f); //Ustawiam pozycjê pocz¹tkow¹ oraz wymiary paletki
	Invader przeciwnik(20,10, 10);
	HUD zegar(1250, 50, 120);		//Ustawiam wspó³rzêdne po³o¿enia zegara i czas jaki ma odliczaæ w sekundach

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
		kulka.checkCollision(przeciwnik);
		przeciwnik.mov();
		zegar.update();
		zegar.draw(window);
		sf::RectangleShape line(sf::Vector2f(1400, 2));
		line.setOrigin(0, 1200);
		line.rotate(90);
		window.draw(line);
		paletka.movement(5.f, line.getOrigin().y - line.getSize().y); //Ustawiam prêdkoœæ i granicê ruchu prawostronnego paletki
		paletka.draw(window);
		kulka.draw(window);
		kulka.bounce(line.getOrigin().y, paletka, przeciwnik); //Ustawiam elementy od których pi³ka ma siê odbijaæ
		kulka.movBall();
		przeciwnik.draw(window);
		window.display();
	}
	return 0;
}
