#include "Table.h"

#include <iostream>

FoolTable::FoolTable(sf::RenderWindow * dockWin)
{
	this->window = dockWin;

	card = new Cards::SFCard(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr);
	card->setPosition(20, 20);
	card->setSize(sf::Vector2f(80, 100));

	animations.emplace_back(AnimeteMove(card, card->getPosition(), sf::Vector2f(100, 100), 300));
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
			}
		}
		// Clear screen
		window->clear(sf::Color::White);

		//Animation
		for (size_t i = 0; i < animations.size(); i++)
		{
			if (animations[i].update()) {
				animations.erase(animations.begin() + i);
				std::cout << "Deleted" << std::endl;
			}
		}

		//Draw
		window->draw(*card);

		// Update the window
		window->display();
	}
}
