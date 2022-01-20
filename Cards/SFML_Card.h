#pragma once

#include <SFML/Graphics.hpp>
#include "Card.h"

namespace Cards {
	class SFCard 
		: public Card, public sf::RectangleShape  {
	public:

		SFCard(bool isTrump, CardRunk36 runk, Suits suit, sf::Vector2f size, sf::Texture* texture = nullptr);

		SFCard();

		SFCard(const SFCard& other);

	protected:

	};
}