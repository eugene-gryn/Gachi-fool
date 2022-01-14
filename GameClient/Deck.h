#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "SFML_Card.h"

class Deck : public sf::Drawable
{
public:
	Deck();

	Cards::SFCard pickUp();
	void shuffle();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	void initTrump();

	std::vector<Cards::SFCard> deck;
	Cards::Suits trumpSuit;

	sf::RectangleShape deckObj;
};