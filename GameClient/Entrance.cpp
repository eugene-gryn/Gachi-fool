#include "SFML_Card.h"
#include "Container.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() {
	// Create the main window
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode(1092, 614), "SFML window",
		sf::Style::Titlebar | !sf::Style::Resize | !sf::Style::Fullscreen| !sf::Style::Close,
		settings);

	Cards::SFCard mainCard0(false, Cards::CardRunk36::A, Cards::Suits::Hearts, sf::Vector2f(80, 100), nullptr);
	Cards::SFCard mainCard1(false, Cards::CardRunk36::A, Cards::Suits::Hearts, sf::Vector2f(80, 100), nullptr);
	Cards::SFCard mainCard3(false, Cards::CardRunk36::A, Cards::Suits::Hearts, sf::Vector2f(80, 100), nullptr);

	Cards::CardContainer asd(sf::Vector2f(20, 20), sf::Vector2f(100, 0));
	asd.add(mainCard0);
	asd.add(mainCard1);
	asd.add(mainCard3);
	


	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) window.close();
			}
		}
		// Clear screen
		window.clear(sf::Color::White);

		window.draw(asd);

		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}