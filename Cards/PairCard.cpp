#include "pch.h"
#include "PairCard.h"

#include "pch.h"
#include "PairCard.h"
#include <iostream>



Cards::CardPair::CardPair(sf::Vector2f position, sf::Vector2f offset, Cards::SFCard beaten)
{
	card[Sides::Beaten] = beaten;
	this->setPosition(position);
	this->offset = offset;
}

Cards::CardPair::CardPair()
	: CardPair(sf::Vector2f(0, 0), sf::Vector2f(0, 0), Cards::SFCard())
{
}

Cards::CardPair::CardPair(const CardPair & other)
{
	this->card[Sides::Beaten] = other.card[Sides::Beaten];
	this->offset = other.offset;
	this->setPosition(other.getPosition());
}

void Cards::CardPair::setPosition(const sf::Vector2f & pos)
{
	card[Sides::Beaten].setPosition(pos);
	card[Sides::Beats].setPosition(pos + this->offset);
}

void Cards::CardPair::setPosition(float x, float y)
{
	sf::Vector2f pos(x, y);
	card[Sides::Beaten].setPosition(pos);
	card[Sides::Beats].setPosition(pos + this->offset);
}

bool Cards::CardPair::beat(Cards::SFCard& beats)
{
	bool res = Cards::SFCard::canBeat(beats, card[Sides::Beaten]);


	if (res) {
		card[Sides::Beats] = Cards::SFCard(beats);
		setPosition(card[Sides::Beaten].getPosition());
	}

	return res;
}

void Cards::CardPair::updatePos()
{
	this->setPosition(sf::RectangleShape::getPosition());
}

void Cards::CardPair::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(card[Sides::Beaten], states);
	target.draw(card[Sides::Beats], states);
}



