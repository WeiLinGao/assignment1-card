#include "Hand.hpp"

/*
CSCI335 Fall 2023
Assignment 1 – Card Game
WeiLin Gao
11/8/2023
Hand.cpp Defines the Hand class.
*/

//Construct a new Hand object(conrstuctor)
Hand::Hand() :cards_{}
{

}

//Destroy the Hand object(Destructor)
Hand::~Hand()
{

	cards_.clear();
}

//Copy Constructor
Hand::Hand(const Hand& other)
{
	cards_ = other.cards_;
}

//Copy Assignment Operator
Hand& Hand::operator=(const Hand& other)
{
	if (this != &other)
	{
		cards_ = other.cards_;
	}

	return *this;
}

//Move Constructor
Hand::Hand(Hand&& other)
{
	cards_ = std::move(other.cards_);
	other.cards_.clear();

}

//Move assignment operator
Hand& Hand::operator=(Hand&& other)
{
	if (this != &other)
	{
		cards_ = std::move(other.cards_);
		other.cards_.clear();
	}

	return *this;
}


//return Hand
const std::deque<PointCard>& Hand::getCards() const
{
	return cards_;
}


//Add a card to the hand , set drawn to true
void Hand::addCard(PointCard&& card)
{
	cards_.push_back(std::move(card));
	card.setDrawn(true);
}


//return true if hand is empty, false otherwise
bool Hand::isEmpty() const
{
	return cards_.empty();
}


//Reverse the hand
void Hand::Reverse()
{

	std::size_t size = cards_.size();
	int l = 0;
	int r = size - 1;
	if (size <= 1) 
	{
		return;
	}
	while(l < r)
	{
		PointCard a = cards_[l];
		cards_[l] = cards_[r];
		cards_[r] = a;

		l++;
		r--;
	}
	
}


//Play the card at the front of the hand, removing it from the hand
//Throws an exception if the hand is empty or the card is not playable
//If the card is not playable, the card is removed from the hand
//return the points earned from playing the card
int Hand::PlayCard()
{
	if (isEmpty())
	{
		throw std::runtime_error("Empty");

	}

	PointCard& card = cards_.front();
	int point =0;

	if (!card.isPlayable())
	{
		cards_.pop_front();
		return point;
	}

	std::string instruction = card.getInstruction();
	bool s = true;

	for (char c : instruction)
	{
		if (!std::isdigit(c))
		{
			s = false;
			break;
		}
	}

	if (s)
	{
		point = std::stoi(instruction);
		cards_.pop_front();
		return point;
	}
	
	cards_.pop_front();
	return point;

}
