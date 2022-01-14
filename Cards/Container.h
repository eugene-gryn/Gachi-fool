#pragma once

#include "SFML_Card.h"

#include <SFML/Graphics.hpp>
#include <vector>

namespace Cards {
	class CardContainer : public sf::Drawable {
	public:
		
		CardContainer(sf::Vector2f position, sf::Vector2f ofset);
		
		void add(SFCard& card);
		void remove(int index);
		void changePosition(int From_index, int To_index);

		sf::Vector2f getOffset();
		void setOffset(sf::Vector2f offset);

		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f pos);

		sf::Vector2f getSize();
		void setSize(sf::Vector2f size);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	protected:


		std::vector<SFCard> container;

		sf::Vector2f position;
		sf::Vector2f offset;


		void updateArrange();
	};
}