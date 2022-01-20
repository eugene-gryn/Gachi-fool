#pragma once

#include "SFML_Card.h"
#include "Container.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <deque>
#include "PairCard.h"

#include "Animation.h"

class FoolTable
{
public:

	FoolTable(sf::RenderWindow* dockWin);

	void loop();

	~FoolTable()
	{
		delete card;
		delete container;
	}

protected:
	sf::RenderWindow* window;
	Cards::SFCard* card;
	Cards::CardPair* pair;


	Cards::CardContainerAnimated* container;

	std::deque<AnimeteMove> animations;
};



