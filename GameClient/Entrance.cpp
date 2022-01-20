#include "SFML_Card.h"
#include "Container.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>

#include "Table.h"




int main() {
	// Create the main window
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	sf::RenderWindow window(sf::VideoMode(1092, 614), "SFML window",
		sf::Style::Titlebar | !sf::Style::Resize | !sf::Style::Fullscreen| !sf::Style::Close,
		settings);


	FoolTable foolGame(&window);
	foolGame.loop();


	return EXIT_SUCCESS;
}