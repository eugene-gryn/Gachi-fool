#pragma once

#include "SFML_Card.h"

#include <SFML/Graphics.hpp>

#include "Animation.h"
#include <deque>
#include "PairCard.h"

namespace Cards {

	struct shapeElement
	{
		shapeElement(sf::Shape* shape)
		{
			this->shape = shape;
		}

		sf::Shape* shape;
	};

	class CardContainer 
		: public sf::RectangleShape
	{
	public:
		
		CardContainer(sf::Vector2f position, sf::Vector2f ofset);
		CardContainer(const CardContainer&);
		CardContainer();

		void add(sf::RectangleShape* shape);
		
		sf::Vector2f getOffset();
		void setOffset(sf::Vector2f offset);
		
		void setSize(sf::Vector2f size);
		
		int getSizeElms();
		
		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	protected:

		std::deque<shapeElement> container;

		sf::Vector2f offset;


		virtual void updateArrange();
	};

	class CardContainerAnimated
		: public CardContainer {
	public:

		CardContainerAnimated(sf::Vector2f position, sf::Vector2f ofset, std::deque<AnimeteMove>*, int defaultAnimationDuration = 300);
		CardContainerAnimated();

	protected:

		virtual void updateArrange() override;

		std::deque<AnimeteMove>* animations;

		int DefaultAnimationDuration;
	};

}

