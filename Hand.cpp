#ifndef HAND_HPP
#define HAND_HPP

#include <deque>
#include "PointCard.hpp"

class Hand {
public:
    // Big Five and constructor
    /**
     * @post: Construct a new Hand object
     */
    Hand();
    /**
     * @post: Destroy the Hand object
     */
    ~Hand();
    /**
     * Copy Constructor
     * @param: other Hand object
     */
    Hand(const Hand& other);
    /**
     * Copy Assignment Operator
     * @param: other Hand object
     * @return this Hand
     */
    Hand& operator=(const Hand& other);
    /**
     * Move Constructor
     * @param: other Hand object
     */
    Hand(Hand&& other);
    /**
     * Move assignment operator
     * @param: other Hand object
     * @return this Hand
     */
    Hand& operator=(Hand&& other);

    /**
     * @return Hand
     */
    const std::deque<PointCard>& getCards() const;

    /**
     * @post: Add a card to the hand
     * @param PointCard object
     */
    void addCard(PointCard&& card);

    /**
     * @return true if hand is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * @post: Reverse the hand
     */
    void Reverse();

    /**
     * @post: Play the card at the front of the hand, removing it from the hand
     * Throws an exception if the hand is empty or the card is not playable
     * If the card is not playable, the card is removed from the hand
     * @return the points earned from playing the card
     */
    int PlayCard();

private:
    std::deque<PointCard> cards_;
};

#endif



Hand::Hand() :cards_{}
{

}

Hand::~Hand()
{

	cards_.clear();
}


Hand::Hand(const Hand& other)
{
	cards_ = other.cards_;
}

Hand& Hand::operator=(const Hand& other)
{
	if (this != &other)
	{
		cards_ = other.cards_;
	}

	return *this;
}


Hand::Hand(Hand&& other)
{
	cards_ = std::move(other.cards_);
	other.cards_.clear();

}

Hand& Hand::operator=(Hand&& other)
{
	if (this != &other)
	{
		cards_ = std::move(other.cards_);
		other.cards_.clear();
	}

	return *this;
}


const std::deque<PointCard>&Hand:: getCards() const
{
	return cards_;
}


void Hand::addCard(PointCard&& card)
{
	cards_.push_back(std::move(card));
}


bool Hand::isEmpty() const
{
	return cards_.empty();
}


void Hand::Reverse()
{
	std::reverse(cards_.begin(), cards_.end());
}

/*
int Hand::PlayCard()
{
	if (isEmpty())
	{
		throw std::runtime_error("Empty");
	}

	PointCard& card = cards_.front();
	if (!(card.isPlayable()))
	{
		cards_.pop_fornt();
		return 0;
	}

	else
	{
		int score=
	}

	return 0;
}
