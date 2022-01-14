#include "pch.h"

#include "Card.h"
#include "CardRank.h"

Cards::Card::Card(bool isTrump, CardRunk36 runk, Suits suit)
{
	this->isTrump = isTrump;
	this->runk = runk;
	this->suit = suit;
}

bool Cards::Card::canBeat(const Card & beat, const Card & beaten)
{
	if (beat.isTrump && !beaten.isTrump) return true;
	else
	{
		if (beat.runk > beaten.runk && beat.suit == beaten.suit) return true;
		else return false;
	}
}

bool Cards::Card::SameRunk(const Card & one, const Card & another)
{
	return one.runk == another.runk;
}

void Cards::Card::setTrump(bool trump)
{
	this->isTrump = trump;
}

bool Cards::Card::getTrump()
{
	return isTrump;
}

Cards::Suits Cards::Card::getSuit()
{
	return this->suit;
}


