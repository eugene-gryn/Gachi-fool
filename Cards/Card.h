#pragma once
#include <SFML/Graphics.hpp>

class Card
{
public:

	Card()
	{
	}

	sf::RectangleShape* Shape;

	~Card()
	{
		delete Shape;
	}
	

protected:

};