
#include "Player.hpp" 



Player::Player()
{
	hand_ = Hand();
	score_ = 0;
	opponent_ = nullptr;
	actiondeck_ = nullptr;
	pointdeck_ = nullptr;
}

Player::~Player()
{
}



const Hand& Player::getHand() const
{
	return hand_;
}


void Player::setHand(const Hand& hand)
{
	hand_ = hand;
}

int Player::getScore() const
{
	return score_;
}

void Player::setScore(const int& score)
{
	score_ = score;
}


void Player::play(ActionCard&& card)
{
	std::cout << "PLAYING ACTION CARD: [" << card.getInstruction() << "]" << std::endl;
	/*
	if (instruction == "DRAW x CARDS")
	{
		for (int i = 0; i < ; ++i) 
		{
			if (actiondeck_ != nullptr && !actiondeck_->IsEmpty()) 
			{
				ActionCard drawnCard = actiondeck_->Draw();
			}
		}
	}
	else if (instruction == "REVERSE HAND") 
	{

		hand_.Reverse();
	}
	*/

}

void Player::drawPointCard()
{
	if (pointdeck_ == nullptr || pointdeck_->IsEmpty())
	{
		return;
	}

	PointCard card = pointdeck_->Draw();
	hand_.addCard(std::move(card));
}





void Player::playPointCard()
{
	try
	{
		int point = hand_.PlayCard();
		score_ += point;
	}
	catch (const std::runtime_error& e)
	{

	}
}


void Player::setOpponent(Player* opponent)
{
	opponent_ = opponent;
}

Player* Player::getOpponent()
{
	return opponent_;
}


void Player::setActionDeck(Deck<ActionCard>* actiondeck)
{
	actiondeck_ = actiondeck;
}


Deck<ActionCard>* Player::getActionDeck()
{
	return actiondeck_;
}


void Player::setPointDeck(Deck<PointCard>* pointdeck)
{
	pointdeck_ = pointdeck;
}


Deck<PointCard>* Player::getPointDeck()
{
	return pointdeck_;
}
