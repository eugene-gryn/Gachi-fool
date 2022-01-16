#pragma once

#include "SFML_Card.h"
#include "Container.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <deque>

#include "Animation.h"

class FoolTable
{
public:

	FoolTable(sf::RenderWindow* dockWin);

	void loop();

	~FoolTable()
	{
		delete card;
	}

protected:
	sf::RenderWindow* window;

	Cards::SFCard* card;

	std::deque<AnimeteMove> animations;
};



