#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Hand.hpp" 
#include "Deck.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Player.hpp"


Player::Player()
{
	hand_ = Hand();
	score_ = 0;
	opponent_ = nullptr;
	actiondeck_ = new Deck<ActionCard>();
	pointdeck_ = new Deck<PointCard>();
}

Player::~Player()
{
	delete actiondeck_;
	delete pointdeck_;
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
}

void Player::drawPointCard()
{
	if (pointdeck_ == nullptr || pointdeck_->empty())
	{
		return;
	}

	PointCard card = pointdeck_->draw();
	hand_.addCard(std::move(card));
}

void Player::playPointCard()
{
	if (hand_.empty())
	{
		return;
	}
}

void Player::setOpponent(Player* opponent)
{
	opponent_ = opponent;
}

Player* Player::getOpponent()
{
	return opponent;
}


void Player::setActionDeck(Deck<ActionCard>* actiondeck)
{
	actiondeck_ = actiondeck;
}


Deck<ActionCard>* getActionDeck()
{
	return actiondeck_;
}


void Player::setPointDeck(Deck<PointCard>* pointdeck)
{
	pointdeck_ = pointdeck;
}


Deck<PointCard>* getPointDeck()
{
	return pointdeck_;
}

