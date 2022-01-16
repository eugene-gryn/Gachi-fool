#include "pch.h"
#include "Container.h"

#include <SFML/Graphics.hpp>
#include <vector>


Cards::CardContainer::CardContainer(sf::Vector2f position, sf::Vector2f ofset)
{
	this->position = position;
	this->offset = ofset;
}

void Cards::CardContainer::add(sf::RectangleShape & card)
{
	container.emplace_back(card);

	updateArrange();
}

void Cards::CardContainer::remove(int index)
{
	auto i = container.begin();
	std::advance(i, index);
	container.erase(i);

	updateArrange();
}

void Cards::CardContainer::changePosition(int From_index, int To_index)
{
	auto from = container.at(From_index);
	auto i = container.begin();
	std::advance(i, To_index);

	remove(From_index);


	container.emplace(i, from);

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

sf::Vector2f Cards::CardContainer::getPosition()
{
	return position;
}

void Cards::CardContainer::setPosition(sf::Vector2f pos)
{
	position = pos;
	updateArrange();
}

sf::Vector2f Cards::CardContainer::getSize()
{
	auto endPoint = container.at(container.size() - 1).getPosition();
	return sf::Vector2f(std::abs(endPoint.x - position.x), std::abs(endPoint.y - position.y));
}

void Cards::CardContainer::setSize(sf::Vector2f size)
{
	offset = sf::Vector2f(size.x / container.size(), size.y / container.size());
	updateArrange();
}

void Cards::CardContainer::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& i : container)
	{
		target.draw(i);
	}
}



void Cards::CardContainer::updateArrange()
{
	for (size_t i = 0; i < container.size(); i++)
	{
		container[i].setPosition(position.x + (offset.x * i), position.y + (offset.y * i));
	}
}



