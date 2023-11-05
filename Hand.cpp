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


const std::deque<PointCard>& Hand::getCards() const
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
	//deque<PointCard>cards_;
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


int Hand::PlayCard() 
{
	if (isEmpty()) 
	{
		throw std::runtime_error("Empty");
	}

	PointCard card = cards_.front();
	int point = 0;

	if (card.isPlayable()) 
	{
		std::string instruction = card.getInstruction();
		
		try 
			{
				point = std::stoi(instruction);
			} 
		catch (const std::invalid_argument& e) 
			{
        
			}
		
	}

	cards_.pop_front();

	return point;
}
