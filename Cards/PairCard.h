#pragma once

#include "Container.h"
#include "SFML_Card.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>

namespace Cards {
	class CardPair
		: public sf::RectangleShape
	{
	public:
		CardPair(sf::Vector2f position, sf::Vector2f offset, Cards::SFCard beaten);

		CardPair();

		CardPair(const CardPair& other);

		void setPosition(const sf::Vector2f& pos);
		void setPosition(float x, float y);

		bool beat(Cards::SFCard&);


		void updatePos();

	protected:

		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		sf::Vector2f offset;

		enum Sides
		{
			Beaten,
			Beats
		};

		Cards::SFCard card[2];
	};
}