#include "Hand.hpp"


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
