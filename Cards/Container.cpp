#include "pch.h"
#include "Container.h"

#include <SFML/Graphics.hpp>
#include <vector>

Cards::CardContainer::CardContainer(sf::Vector2f position, sf::Vector2f ofset)
{
	this->setPosition(position);
	this->offset = ofset;
}

Cards::CardContainer::CardContainer(const CardContainer& other)
{
	setPosition(other.getPosition());
	this->offset = other.offset;
}

Cards::CardContainer::CardContainer()
	: CardContainer(sf::Vector2f(0,0), sf::Vector2f(0, 0))
{
}

void Cards::CardContainer::add(sf::RectangleShape * shape)
{
	container.push_back(shapeElement(shape));

	updateArrange();
}

sf::Vector2f Cards::CardContainer::getOffset()
{
	return this->offset;
}

void Cards::CardContainer::setOffset(sf::Vector2f offset)
{
	this->offset = offset;
	updateArrange();
}

void Cards::CardContainer::setSize(sf::Vector2f size)
{
	this->offset = sf::Vector2f(size.x / container.size(), size.y / container.size());
	updateArrange();
}

int Cards::CardContainer::getSizeElms()
{
	return container.size();
}



void Cards::CardContainer::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& i : container)
	{
		target.draw(*i.shape);
	}
}

void Cards::CardContainer::updateArrange()
{
	for (size_t i = 0; i < container.size(); i++)
	{
		container[i].shape->setPosition(this->getPosition().x + (offset.x * i), this->getPosition().y + (offset.y * i));
	}
}

Cards::CardContainerAnimated::CardContainerAnimated(sf::Vector2f position, sf::Vector2f ofset, std::deque<AnimeteMove>* animation, int defaultAnimationDuration)
	: CardContainer(position, ofset)
{
	this->animations = animation;
	this->DefaultAnimationDuration = defaultAnimationDuration;
}

Cards::CardContainerAnimated::CardContainerAnimated()
{
	this->animations = nullptr;
	this->DefaultAnimationDuration = 0;
}

void Cards::CardContainerAnimated::updateArrange()
{
	for (size_t i = 0; i < container.size(); i++)
	{
		sf::Vector2f offsetPos(this->getPosition().x + (offset.x * i), this->getPosition().y + (offset.y * i));
		if (container[i].shape->getPosition() != offsetPos) animations->emplace_back(AnimeteMove(container[i].shape, container[i].shape->getPosition(), offsetPos, this->DefaultAnimationDuration));
	}
}
