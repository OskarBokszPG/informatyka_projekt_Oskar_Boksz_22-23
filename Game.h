#pragma once
#include <SFML/Graphics.hpp>
#include "HUD.h"
#include "Ball.h"
#include "Paddle.h"
#include "Invader.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iostream>

class Game
{
	std::string name = "Arkanoid x SpaceInvaders";
	std::string poz1 = "1. Play";
	std::string poz2 = { "2. Records" };
	std::string poz3 = { "3. Help" };
	std::string poz4 = { "4. Exit" };
	std::string over = { "GAME OVER" };
	std::string win = { "YOU WIN" };
	std::string close = { "Czy napewno chcesz wyjsc? Wyjscie wiaze sie z utrata postepow" };
	std::string closeOptions = { "Num1 - Tak	Num2 - Nie" };
	std::string level1 = { "Easy" };
	std::string level2 = { "Hard" };
	std::string cont = { "Nacisnij spacje, aby wrocic do menu" };
	sf::Font menuFont;
	sf::Texture menuTexture;
	sf::Sprite menuBackground;

	sf::Texture gameTexture;
	sf::Sprite gameBackground;

	sf::Text title, play, records, help, exit;

	std::string fileName;
	sf::Text rank;

	bool playSelected;
	bool recordsSelected;
	bool helpSelected;
	bool exitSelected;
	sf::Vector2f changeColors;
	sf::Time elapsedTime;
	sf::Clock clock;

	sf::Texture helpTexture;
	sf::Sprite helpRect;

	sf::Text space;
	sf::Text easy;
	sf::Text hard;
	sf::Text closeGame;
	sf::Text closeGameOp;
	sf::Text gameOver;
	sf::Text youWin;
	sf::Text nickText;
	sf::Event event;
	std::string nick;


	bool poziom = false;
	bool stop = false;
	bool koniecGry;
	bool kolor;
	int l = 1;
	int r;
	int g;
	int b;
	int lvl = 0;
public:
	Game(float xW, float yW);
	void drawBack(sf::RenderWindow& window);
	void drawBackG(sf::RenderWindow& window);
	void update(bool& stan, bool& pause,bool& rec,  sf::RenderWindow& window);
	void drawMenu(sf::RenderWindow& window);
	void stopGame(bool& pause, bool& stan, Paddle& pros, Ball& pilka, Invader& wrog, HUD& czas, sf::RenderWindow& window, sf::Event& ev);
	void drawHelp(bool& pause, sf::RenderWindow& window);
	void winScreen(sf::RenderWindow& window, Invader& enemys, Ball& pilka, Paddle& pros, HUD& czas, bool& stan);
	void level(Paddle& pros, Ball& pilka, Invader& wrog, HUD& czas);

};

