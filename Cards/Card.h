#pragma once

#include "CardRank.h"
#include "CardsSuits.h"

namespace Cards {

	class Card
	{
	public:

		Card(bool isTrump, CardRunk36 runk, Suits suit);

		static bool canBeat(const Card& beat, const Card& beaten);

		static bool SameRunk(const Card& one, const Card& another);

		void setTrump(bool trump);
		bool getTrump();

		Suits getSuit();

	protected:

		bool isTrump;
		
		CardRunk36 runk;
		Suits suit;
	};
}