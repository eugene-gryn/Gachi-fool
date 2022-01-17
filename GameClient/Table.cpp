#include "Table.h"

#include <iostream>

FoolTable::FoolTable(sf::RenderWindow * dockWin)
{
	this->window = dockWin;

	card = new Cards::SFCard(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr);
	card->setPosition(20, 20);
	card->setSize(sf::Vector2f(80, 100));


	container = new Cards::CardContainerAnimated(sf::Vector2f(200, 200), sf::Vector2f(100, 0), &animations, 300);

	Cards::SFCard c1(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(80, 100), nullptr);
	Cards::SFCard c2(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(80, 100), nullptr);
	Cards::SFCard c3(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(80, 100), nullptr);

	container->add(c1);
	container->add(c2);
	container->add(c3);
}

void FoolTable::loop()
{
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
				if (event.key.code == sf::Keyboard::PageDown) {
					if (container->getSizeElms() > 0) {
						container->remove(container->getSizeElms() - 1);
					}
				}
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
		window->draw(*card);
		window->draw(*container);

		// Update the window
		window->display();
	}
}
