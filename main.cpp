#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "HUD.h"
#include "Game.h"
#include <time.h>



int main()
{
	sf::RenderWindow window(sf::VideoMode(1400, 800), "Arkanoid x SpaceInvaders");
	window.setFramerateLimit(60);
	Ball kulka(300.f, 500.f, 20.f, 4.f,5.f); //Ustawiam pozycjê pocz¹tkow¹,promieñ kulki oraz prêdkoœæ
	Paddle paletka(400.f, 700.f, 200.f, 20.f); //Ustawiam pozycjê pocz¹tkow¹ oraz wymiary paletki
	int r = 0;
	int g = 0;
	int b = 0;

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
		window.clear(sf::Color(r,g,b));
		//sf::RectangleShape line(sf::Vector2f(1400, 5));
		//line.setOrigin(0, 1200);
		//line.rotate(90);
		//window.draw(line);
		if (r != 255 || g != 255 || b != 255)
			r++, b++;
		paletka.movement(5.f, window.getSize().x); //Ustawiam prêdkoœæ i granicê ruchu prawostronnego
		paletka.draw(window);
		kulka.draw(window);
		kulka.kolizja(window.getSize().x, window.getSize().y); //Ustawiam prêdkoœæ kulki x i y oraz granice okienka
		kulka.movBall();
		kulka.bounce(paletka);
		window.display();
	}
	return 0;
}
