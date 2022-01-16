#pragma once

#include <SFML/Graphics.hpp>

class AnimeteMove
{
public:

	AnimeteMove(sf::Shape* shape, sf::Vector2f startPos, sf::Vector2f endPos, int durationMilis);

	bool update();

protected:
	sf::Shape* shape;

	sf::Vector2f destPosition;

	sf::Vector2f animationOffset;

	int duration;
	sf::Clock myClock;
};
