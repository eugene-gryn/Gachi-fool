#include "pch.h"
#include "SFML_Card.h"
#include <SFML/Graphics.hpp>


Cards::SFCard::SFCard(bool isTrump, CardRunk36 runk, Suits suit, sf::Vector2f size, sf::Texture* texture) :
	Card(isTrump, runk, suit), RectangleShape(size)
{
	if (texture == nullptr) {
		this->setFillColor(sf::Color::Red);
	}
	else {
		this->setTexture(texture);
	}
}

Cards::SFCard::SFCard()
	: Card(false, Cards::CardRunk36::N6, Cards::Suits::Hearts), RectangleShape(sf::Vector2f(0, 0))
{
	this->setFillColor(sf::Color::Red);
}

Cards::SFCard::SFCard(const SFCard & other)
	: Card(other.isTrump, other.runk, other.suit), RectangleShape(static_cast<RectangleShape>(other))
{
}
