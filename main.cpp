#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "HUD.h"
#include "Invader.h"
#include "Game.h"
#include <iostream>



int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Arkanoid x SpaceInvaders");
	window.setFramerateLimit(60);

	bool pauza = false;
	bool rec = false;
	bool graj = false;

	Ball kulka(640.f, 360.f); //Ustawiam pozycjê pocz¹tkow¹,promieñ kulki
	Paddle paletka(640.f, 640.f); //Ustawiam pozycjê pocz¹tkow¹
	Invader przeciwnicy(5,40, 20);
	HUD zegar(1200, 50, graj);		//Ustawiam wspó³rzêdne po³o¿enia zegara
	Game gra(1280, 720);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (graj)
		{
			window.clear();
			gra.drawBackG(window);
			gra.level(paletka, kulka, przeciwnicy, zegar);
			gra.winScreen(window, przeciwnicy, kulka, paletka, zegar, graj);
			kulka.checkCollision(przeciwnicy);
			zegar.update(pauza,graj, kulka);
			zegar.draw(window);
			paletka.movement(window.getSize().x);
			paletka.draw(window);
			kulka.draw(window);
			przeciwnicy.mov(window.getSize().x);
			kulka.bounce(window.getSize().x, paletka); 
			kulka.lossLife(window.getSize().y, zegar);
			kulka.movBall();
			przeciwnicy.draw(window);
			gra.drawHelp(pauza, window);
			gra.stopGame(pauza,graj, paletka, kulka, przeciwnicy, zegar, window, event);
			window.display();
		}
		if (graj == false) {
			window.clear();
			gra.drawBack(window);
			if (rec == false) {
				gra.drawMenu(window);
			}
			gra.drawHelp(pauza, window);
			gra.update(graj, pauza,rec, window);
			window.display();
		}
	}
	return 0;
}

