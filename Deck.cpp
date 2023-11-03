#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.hpp"
#include <random>

template <typename CardType>
class Deck
{
public:
    /**
     * @post: Construct a new Deck object
     */
    Deck();

    /**
     * @post: Destroy the Deck object
     */
    ~Deck();

    /**
     * @post: Add a Card to the Deck
     * @param: const reference to CardType card
     */
    void AddCard(const CardType& card);

    /**
     * @post: Draw a card from the deck
     * @pre: the deck is not empty
     * @return the right hand value of type CardType
     */
    CardType&& Draw();

    /**
     * @return if the deck is empty
     */
    bool IsEmpty() const;

    /**
     * @post: Shuffle the deck
     * Create a random number generator using std::mt19937 with seed 2028358904,
     * then call std::shuffle on the vector of cards, and with the random number generator as the third argument.
     * https://en.cppreference.com/w/cpp/algorithm/random_shuffle
     * https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
     */
    void Shuffle();

    /**
     * @return the size of the deck
     */
    int getSize() const;

    /**
     * @return the vector of cards in the deck
     */
    std::vector<CardType> getDeck() const;

private:
    std::vector<CardType> cards_;
};

#include "Deck.cpp"
#endif


template <typename CardType>
Deck<CardType>::Deck() :cards_{}
{
}

template <typename CardType>
Deck<CardType>::~Deck()
{

	cards_.clear();
}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card)
{
	cards_.push_back(card);
}

template <typename CardType>
CardType&& Deck<CardType>::Draw()
{
	if (!IsEmpty())
	{
		CardType card=std::move(cards_.back());
		cards_.pop_back();
		return card;
	}
    else
    {
        throw std::out_of_range("EMPTY.");
    }
  
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
	return cards_.empty();
}

template <typename CardType>
void Deck<CardType>::Shuffle()
{
	std::mt19937 rd(2028358904);

	std::shuffle(cards_.begin(), cards_.end(),rd);
}


template <typename CardType>
int Deck<CardType>::getSize() const
{
	return cards_.size();
}


template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
	return cards_;
}

