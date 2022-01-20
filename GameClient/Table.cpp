#include "Table.h"
#include "PairCard.h"

#include <iostream>

FoolTable::FoolTable(sf::RenderWindow * dockWin)
{
	this->window = dockWin;


	container = new Cards::CardContainerAnimated(sf::Vector2f(200, 200), sf::Vector2f(150, 0), &animations, 300);
	

	Cards::SFCard beaten(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(80, 100), nullptr);
	Cards::SFCard beats(false, Cards::CardRunk36::Q, Cards::Suits::Clubs, sf::Vector2f(80, 100), nullptr);
	beats.setFillColor(sf::Color::Green);

	pair = new Cards::CardPair(sf::Vector2f(100, 100), sf::Vector2f(20, 20), beaten);
	pair->beat(beats);
	pair->setPosition(200, 400);

	

	container->add(new Cards::SFCard(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(80, 100), nullptr));
	container->add(new Cards::SFCard(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(80, 100), nullptr));
	container->add(new Cards::SFCard(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(80, 100), nullptr));

	container->add(pair);
	pair->updatePos();


}

void FoolTable::loop()
{
	sf::Clock clock;
	while (window->isOpen())
	{
		// Process events
		sf::Event event;
		while (window->pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) window->close();
				if (event.key.code == sf::Keyboard::PageUp) container->add(new Cards::SFCard(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(80, 100), nullptr));
				if (event.key.code == sf::Keyboard::Num1) container->setOffset(sf::Vector2f(100, 0));
				if (event.key.code == sf::Keyboard::Num2) container->setOffset(sf::Vector2f(200, 0));
			}
		}
		// Clear screen
		window->clear(sf::Color::White);

		//Animation
		for (size_t i = 0; i < animations.size(); i++)
		{
			if (animations[i].update()) {
				animations.erase(animations.begin() + i);
			}
		}

		//Draw
		window->draw(*container);

		// Update the window
		window->display();

		window->setTitle(std::to_string((1000000 / clock.getElapsedTime().asMicroseconds())) + " fps");
		clock.restart();
	}
}
