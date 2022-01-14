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
