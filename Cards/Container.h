#pragma once

#include "SFML_Card.h"

#include <SFML/Graphics.hpp>
#include <vector>

#include "Animation.h"
#include <deque>

namespace Cards {

	class CardContainer : public sf::Drawable {
	public:
		
		CardContainer(sf::Vector2f position, sf::Vector2f ofset);
		

		void add(sf::RectangleShape& card);
		void add(sf::RectangleShape* card);
		void remove(int index);
		void changePosition(int From_index, int To_index);

		sf::Vector2f getOffset();
		void setOffset(sf::Vector2f offset);

		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f pos);

		sf::Vector2f getSize();
		void setSize(sf::Vector2f size);

		int getSizeElms();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	protected:

		std::vector<sf::RectangleShape> container;

		sf::Vector2f position;
		sf::Vector2f offset;


		virtual void updateArrange();
	};


	class CardContainerAnimated
		: public CardContainer {
	public:

		CardContainerAnimated(sf::Vector2f position, sf::Vector2f ofset, std::deque<AnimeteMove>*, int defaultAnimationDuration = 300);

	protected:

		virtual void updateArrange() override;

		std::deque<AnimeteMove>* animations;

		int DefaultAnimationDuration;
	};

}

