#include "Deck.h"
// -------
#include <SFML/Graphics.hpp>
#include <vector>

#include "SFML_Card.h"

void CardsInit(std::vector<Cards::SFCard>& deck) {
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N6, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N7, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N8, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N9, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N10, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::J, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::Q, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::K, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::A, Cards::Suits::Clubs, sf::Vector2f(0, 0), nullptr));

	// ------------------------

	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N6, Cards::Suits::Diamonds, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N7, Cards::Suits::Diamonds, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N8, Cards::Suits::Diamonds, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N9, Cards::Suits::Diamonds, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N10, Cards::Suits::Diamonds, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::J, Cards::Suits::Diamonds, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::Q, Cards::Suits::Diamonds, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::K, Cards::Suits::Diamonds, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::A, Cards::Suits::Diamonds, sf::Vector2f(0, 0), nullptr));

	// ------------------------

	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N6, Cards::Suits::Hearts, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N7, Cards::Suits::Hearts, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N8, Cards::Suits::Hearts, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N9, Cards::Suits::Hearts, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N10, Cards::Suits::Hearts, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::J, Cards::Suits::Hearts, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::Q, Cards::Suits::Hearts, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::K, Cards::Suits::Hearts, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::A, Cards::Suits::Hearts, sf::Vector2f(0, 0), nullptr));

	// ------------------------

	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N6, Cards::Suits::Spades, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N7, Cards::Suits::Spades, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N8, Cards::Suits::Spades, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N9, Cards::Suits::Spades, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::N10, Cards::Suits::Spades, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::J, Cards::Suits::Spades, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::Q, Cards::Suits::Spades, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::K, Cards::Suits::Spades, sf::Vector2f(0, 0), nullptr));
	deck.push_back(Cards::SFCard(false, Cards::CardRunk36::A, Cards::Suits::Spades, sf::Vector2f(0, 0), nullptr));

}

// set Trump Cards
void Deck::initTrump()
{
	srand(time(0) % 12 + 5 - 16);

	// Trump
	trumpSuit = (Cards::Suits)(rand() % 4);

	for (auto& i : deck)
	{
		if (i.getSuit() == trumpSuit) i.setTrump(true);
	}
}


Deck::Deck()
{
	CardsInit(deck);
	initTrump();

	std::random_shuffle(deck.begin(), deck.end());
}

Cards::SFCard Deck::pickUp()
{
	Cards::SFCard pickUpCard = deck.at(deck.size() - 1);

	deck.pop_back();

	return pickUpCard;
}

void Deck::shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}

void Deck::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(deckObj);
}


