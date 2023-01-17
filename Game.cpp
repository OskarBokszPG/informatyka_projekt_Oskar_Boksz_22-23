#include "Game.h"


Game::Game(float xW, float yW)
{
	srand(time(NULL));
	playSelected = true;
	recordsSelected = false;
	helpSelected = false;
	exitSelected = false;
	kolor = false;


	if (!menuTexture.loadFromFile("tloM.jpg"))
	{
		std::cout << "Blad w ladowaniu tla menu";
	}

	menuBackground.setTexture(menuTexture);
	menuBackground.setPosition(0, 0);
	menuBackground.setScale(
		static_cast<float>(xW) / menuTexture.getSize().x,
		static_cast<float>(yW) / menuTexture.getSize().y
	);

	if (!gameTexture.loadFromFile("tloG.jpg"))
	{
		std::cout << "Blad w ladowaniu tla gry";
	}

	gameBackground.setTexture(gameTexture);
	gameBackground.setPosition(0, 0);
	gameBackground.setScale(
		static_cast<float>(xW) / gameTexture.getSize().x,
		static_cast<float>(yW) / gameTexture.getSize().y);

	if (!helpTexture.loadFromFile("tele.png"))
	{
		std::cout << "Blad w ladowaniu help";
	}
	helpRect.setTexture(helpTexture);
	helpRect.setOrigin(helpRect.getGlobalBounds().width/2 , helpRect.getGlobalBounds().height/2 );
	helpRect.setPosition(xW / 2, yW / 2);

	menuFont.loadFromFile("Working Together.ttf");
	if (!menuFont.loadFromFile("Working Together.ttf"))
	{
		std::cout << "Blad w ladowaniu czcionki";
	}
	title.setFont(menuFont);
	title.setCharacterSize(84);
	title.setFillColor(sf::Color::Cyan);
	title.setOutlineThickness(6);
	title.setOutlineColor(sf::Color::Magenta);
	title.setStyle(sf::Text::Bold);
	title.setString(name);
	title.setPosition(xW / 2 - title.getGlobalBounds().width /2,  32);

	play.setFont(menuFont);
	play.setCharacterSize(68);
	play.setOutlineThickness(3);
	play.setString(poz1);
	play.setPosition(xW / 2 - play.getGlobalBounds().width / 2, yW / 2 - (68 * 2));

	records.setFont(menuFont);
	records.setCharacterSize(68);
	records.setOutlineThickness(3);
	records.setString(poz2);
	records.setPosition(xW / 2 - records.getGlobalBounds().width / 2, yW / 2 - 68);

	help.setFont(menuFont);
	help.setCharacterSize(68);
	help.setOutlineThickness(3);
	help.setString(poz3);
	help.setPosition(xW / 2 - help.getGlobalBounds().width/2, yW / 2);

	exit.setFont(menuFont);
	exit.setCharacterSize(68);
	exit.setOutlineThickness(3);
	exit.setString(poz4);
	exit.setPosition(xW / 2 - exit.getGlobalBounds().width/2, yW / 2 + 68);

	gameOver.setFont(menuFont);
	gameOver.setCharacterSize(82);
	gameOver.setOutlineThickness(3);
	gameOver.setFillColor(sf::Color::Magenta);
	gameOver.setOutlineColor(sf::Color::White);
	gameOver.setString(over);
	gameOver.setPosition(xW / 2 - gameOver.getGlobalBounds().width / 2, yW / 2 - gameOver.getGlobalBounds().height);

	youWin.setFont(menuFont);
	youWin.setCharacterSize(82);
	youWin.setOutlineThickness(3);
	youWin.setFillColor(sf::Color::Magenta);
	youWin.setOutlineColor(sf::Color::White);
	youWin.setString(win);
	youWin.setPosition(xW / 2 - youWin.getGlobalBounds().width / 2, yW / 2 - youWin.getGlobalBounds().height);
	
	space.setFont(menuFont);
	space.setCharacterSize(50);
	space.setOutlineThickness(3);
	space.setFillColor(sf::Color::Yellow);
	space.setOutlineColor(sf::Color::Magenta);
	space.setString(cont);
	space.setPosition(xW / 2 -	space.getGlobalBounds().width / 2, yW / 2 - space.getGlobalBounds().height + youWin.getGlobalBounds().height);

	closeGame.setFont(menuFont);
	closeGame.setCharacterSize(50);
	closeGame.setOutlineThickness(3);
	closeGame.setFillColor(sf::Color::Magenta);
	closeGame.setOutlineColor(sf::Color::White);
	closeGame.setString(close);
	closeGame.setPosition(xW / 2 - closeGame.getGlobalBounds().width / 2, yW / 2 - closeGame.getGlobalBounds().height);

	closeGameOp.setFont(menuFont);
	closeGameOp.setCharacterSize(50);
	closeGameOp.setOutlineThickness(3);
	closeGameOp.setFillColor(sf::Color::Yellow);
	closeGameOp.setOutlineColor(sf::Color::Magenta);
	closeGameOp.setString(closeOptions);
	closeGameOp.setPosition(xW / 2 - closeGameOp.getGlobalBounds().width / 2, yW / 2 - closeGameOp.getGlobalBounds().height + closeGame.getGlobalBounds().height);

	nickText.setString("Wpisz swoj nick: ");
	nickText.setFont(menuFont);
	nickText.setCharacterSize(24);
	nickText.setFillColor(sf::Color::Yellow);
	nickText.setPosition(xW / 2 - nickText.getGlobalBounds().width / 2, yW / 2 - nickText.getGlobalBounds().height - 50);

	std::string fileName = "ranking.txt";
	this->fileName = fileName;
	rank.setFont(menuFont);
	rank.setFillColor(sf::Color::Magenta);
	rank.setCharacterSize(46);
	rank.setOutlineThickness(4);
	rank.setOutlineColor(sf::Color::Yellow);
	rank.setPosition(xW / 2 - nickText.getGlobalBounds().width / 2- 155, 135);

	easy.setFont(menuFont);
	easy.setCharacterSize(70);
	easy.setOutlineThickness(3);
	easy.setFillColor(sf::Color::Black);
	easy.setOutlineColor(sf::Color::Magenta);
	easy.setString(level1);
	easy.setPosition(xW / 2 - easy.getGlobalBounds().width / 2 -90, yW / 2 - easy.getGlobalBounds().height);

	hard.setFont(menuFont);
	hard.setCharacterSize(70);
	hard.setOutlineThickness(3);
	hard.setFillColor(sf::Color::Black);
	hard.setOutlineColor(sf::Color::Magenta);
	hard.setString(level2);
	hard.setPosition(xW / 2 - hard.getGlobalBounds().width / 2 + easy.getGlobalBounds().width / 2 + 55, yW / 2 - hard.getGlobalBounds().height);
}

void Game::drawBack(sf::RenderWindow& window)
{
	elapsedTime = clock.getElapsedTime();
	if (elapsedTime.asSeconds() >= 5.0f) {
		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;
		clock.restart();
	}
	if (kolor == true) {
		if (r != 255) {
			r++;
		}
		else if (g != 255) {
			g++;
		}
		else if (b != 255) {
			b++;
		}
		else
			kolor = false;
		menuBackground.setColor(sf::Color(r, g, b));
	}
	else if (kolor == false) {
		if (r != 0) {
			r--;
		}
		else if (g != 0) {
			g--;
		}
		else if (b != 0) {
			b--;
		}
			kolor = true;
		menuBackground.setColor(sf::Color(r, g, b));
	}
	window.draw(menuBackground);
	window.draw(title);
}

void Game::drawBackG(sf::RenderWindow& window)
{
	elapsedTime = clock.getElapsedTime();
	if (elapsedTime.asSeconds() >= 6.0f) {
		r = rand() % 256;
		g = rand() % 256;
		b = rand() % 256;
		clock.restart();
	}
	if (kolor == true) {
		if (r != 255) {
			r++;
		}
		else if (g != 255) {
			g++;
		}
		else if (b != 255) {
			b++;
		}
		else
			kolor = false;
		gameBackground.setColor(sf::Color(r, g, b));
	}
	else if (kolor == false) {
		if (r != 0) {
			r--;
		}
		else if (g != 0) {
			g--;
		}
		else if (b != 0) {
			b--;
		}
		kolor = true;
		gameBackground.setColor(sf::Color(r, g, b));
	}
	window.draw(gameBackground);
}

void Game::level(Paddle& pros, Ball& pilka, Invader& wrog, HUD& czas)
{
	if (lvl == 1 && poziom == true)
	{
		pilka.speed.x = 4;
		pilka.speed.y = -5;
		pilka.xS = 4;
		pilka.yS = -5;
		czas.timeLeft = sf::seconds(150);
		pros.setScale(1.f, 1.f);
		pros.speed = 20;
		wrog.speed = 20;
		lvl = 0;
		easy.setFillColor(sf::Color::Black);
		easy.setOutlineColor(sf::Color::Magenta);
		poziom = false;
	}
	if (lvl == 2 && poziom == true)
	{
		pilka.speed.x = 6;
		pilka.speed.y = -7;
		pilka.xS = 6;
		pilka.yS = -7;
		czas.timeLeft = sf::seconds(80);
		pros.setScale(0.6f, 0.6f);
		pros.speed = 10;
		wrog.speed = 40;
		lvl = 0;
		hard.setFillColor(sf::Color::Black);
		hard.setOutlineColor(sf::Color::Magenta);
		poziom = false;
	}
}

void Game::drawMenu(sf::RenderWindow& window)
{
	window.draw(play);
	window.draw(records);
	window.draw(help);
	window.draw(exit);
}

void Game::stopGame(bool& pause, bool& stan, Paddle& pros, Ball& pilka, Invader& wrog, HUD& czas, sf::RenderWindow& window, sf::Event& ev)
{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1) && pause == false) {
			pause = true;
			czas.clock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && pause == true){
			pause = false;
			czas.clock.restart();
		}
		if (pause == true || stan == false)
		{
			pilka.rusz = false;
			pros.rusz = false;
			czas.lec = false;
			wrog.rusz = false;
		}
		else if(stop == false)
		{
			pilka.rusz = true;
			pros.rusz = true;
			czas.lec = true;
			wrog.rusz = true;
		}

		if (stan == true && (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
			stop = true;
		}

		if (stop == true) {
			pilka.rusz = false;
			pros.rusz = false;
			czas.lec = false;
			wrog.rusz = false;
			window.draw(closeGame);
			window.draw(closeGameOp);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				pilka.rusz = true;
				pros.rusz = true;
				pros.setPosition(pros.position);
				czas.lec = true;
				czas.life = 3;
				pilka.pkt = 0;
				czas.timeLeft = sf::seconds(czas.sec);
				pilka.setPosition(pilka.position);
				wrog.invDelete();
				wrog.create();
				czas.create();
				stan = false;
				stop = false;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
				stop = false;
				czas.clock.restart();
			}
		}

		if (czas.hearts.size() == 0 || czas.text.getString() == "0:00" || wrog.invaders[wrog.invaders.size() - 1].getPosition().y >= 543) {
			pilka.rusz = false;
			pros.rusz = false;
			czas.lec = false;
			wrog.rusz = false;
			window.draw(gameOver);
			window.draw(space);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				pilka.rusz = true;
				pros.rusz = true;
				pros.setPosition(pros.position);
				czas.lec = true;
				czas.life = 3;
				pilka.pkt = 0;
				czas.timeLeft = sf::seconds(czas.sec);
				pilka.setPosition(pilka.position);
				wrog.invDelete();
				wrog.create();
				czas.create();
				stan = false;
			}
		}
}

void Game::drawHelp(bool& pause, sf::RenderWindow& window)
{
	if (pause == true || sf::Keyboard::isKeyPressed(sf::Keyboard::F1)){
		window.draw(helpRect);
	}
}

void Game::update(bool& stan, bool& pause, bool& rec, sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) )
	{
		playSelected = true;
		recordsSelected = false;
		helpSelected = false;
		exitSelected = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		playSelected = false;
		recordsSelected = true;
		helpSelected = false;
		exitSelected = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		playSelected = false;
		recordsSelected = false;
		helpSelected = true;
		exitSelected = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		playSelected = false;
		recordsSelected = false;
		helpSelected = false;
		exitSelected = true;
	}
	

	if (playSelected) {

		play.setFillColor(sf::Color::Magenta);
		play.setOutlineColor(sf::Color::Cyan);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			rec = true;
		}
		if (rec == true) {
			window.draw(easy);
			window.draw(hard);
			if (lvl == 1)
			{
				easy.setFillColor(sf::Color::Magenta);
				easy.setOutlineColor(sf::Color::Cyan);
				hard.setFillColor(sf::Color::Black);
				hard.setOutlineColor(sf::Color::Magenta);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					stan = true;
					poziom = true;
					rec = false;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				lvl =2;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				lvl = 1;
			}
			if (lvl == 2)
			{
				hard.setFillColor(sf::Color::Magenta);
				hard.setOutlineColor(sf::Color::Cyan);
				easy.setFillColor(sf::Color::Black);
				easy.setOutlineColor(sf::Color::Magenta);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					stan = true;
					poziom = true;
					rec = false;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				rec = false;
				easy.setFillColor(sf::Color::Black);
				easy.setOutlineColor(sf::Color::Magenta);
				hard.setFillColor(sf::Color::Black);
				hard.setOutlineColor(sf::Color::Magenta);
				lvl = 0;
			}
		}
	}
	else
	{
		play.setFillColor(sf::Color::Black);
		play.setOutlineColor(sf::Color::Magenta);
	}

	if (recordsSelected)
	{
		records.setFillColor(sf::Color::Magenta);
		records.setOutlineColor(sf::Color::Cyan);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			rec = true;
		}
		if (rec == true) {
			std::string line;
			std::string content;
			std::ifstream file(fileName);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					content += line + "\n";
				}
			}
			rank.setString(content);
			file.close();
			window.draw(rank);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			rec = false;
		}
	}
	else
	{
		records.setFillColor(sf::Color::Black);
		records.setOutlineColor(sf::Color::Magenta);
	}


	if (helpSelected)
	{
		help.setFillColor(sf::Color::Magenta);
		help.setOutlineColor(sf::Color::Cyan);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			pause = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
			pause = false;
		}
	}
	else
	{
		help.setFillColor(sf::Color::Black);
		help.setOutlineColor(sf::Color::Magenta);
	}

	if (exitSelected) {

		exit.setFillColor(sf::Color::Magenta);
		exit.setOutlineColor(sf::Color::Cyan);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			window.close();
		}
	
	}
	else
	{
		exit.setFillColor(sf::Color::Black);
		exit.setOutlineColor(sf::Color::Magenta);
	}

}

void Game::winScreen(sf::RenderWindow& window, Invader& enemys, Ball& pilka, Paddle& pros, HUD& czas, bool& stan)
{
	bool enter;
	if (enemys.liczbaInv == pilka.pkt)
	{
		enter = true;
		pilka.rusz = false;
		pros.rusz = false;
		czas.lec = false;
		window.draw(youWin);
		window.draw(space);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && enter == true)
		{
			std::ofstream file;
			file.open("ranking.txt", std::ios_base::app | std::ios_base::out);
			file <<"Player " << l << " Time left: " << czas.timeString << "Life: "<< czas.life << "\n" << std::endl;
			l++;
			file.close();
			stan = false;
			pilka.rusz = true;
			pros.rusz = true;
			czas.lec = true;
			pros.setPosition(pros.position);
			pilka.pkt = 0;
			czas.life = 3;
			czas.timeLeft = sf::seconds(czas.sec);
			pilka.setPosition(pilka.position);
			enemys.create();
			czas.create();
			enter = false;
		}
	}
}
