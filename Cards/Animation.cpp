#include "pch.h"

#include "Animation.h"
#include <SFML/Graphics/Vertex.hpp>

AnimeteMove::AnimeteMove(sf::Shape* shape, sf::Vector2f startPos, sf::Vector2f endPos, int durationMiliSec)
{
	this->shape = shape;

	this->destPosition = endPos;

	this->animationOffset = endPos - startPos;

	this->duration = durationMiliSec;
}

bool AnimeteMove::update()
{
	float perc = myClock.getElapsedTime().asMilliseconds() / (float)duration;

	if (perc <= 1) {
		shape->setPosition(destPosition - ((1 - perc) * animationOffset));
		return false;
	}
	else {
		shape->setPosition(destPosition);
		return true;
	}	
}
