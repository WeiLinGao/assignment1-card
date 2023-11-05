
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
	
	std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
	std::string instruction = card.getInstruction();

	display();
	displayAction(card);
	if (instruction.find("DRAW") != std::string::npos) 
	{
		size_t pos = instruction.find_first_of(' ');
		int numDraw = std::stoi(instruction.substr(pos + 1));
		for (int i = 0; i < numDraw; i++) 
		{
			if (!actiondeck_ || actiondeck_->IsEmpty()) 
			{
				std::cout << "Empty Deck" << std::endl;
				break;  
			}
			
			ActionCard drawnCard = actiondeck_->Draw();
			displayAction(drawnCard);
			drawPointCard();
			std::cout << "Drew a Point Card." << std::endl;
			display();
			displayAction(card);

		
		}
		display();
		displayAction(card);
	}
	else if (instruction.find("PLAY") != std::string::npos) 
	{
		size_t pos = instruction.find_first_of(' ');
		int numPlay = std::stoi(instruction.substr(pos + 1));
		for (int i = 0; i < numPlay; i++) 
		{
			drawPointCard();
			playPointCard();
			std::cout << "Played a Point Card." << std::endl;
		}

		display();
		displayAction(card);
	}
	else if (instruction == "REVERSE HAND") 
	{
		hand_.Reverse();
		std::cout << "Reversed." << std::endl;
		display();
		displayAction(card);

	}
	else if (instruction == "SWAP HAND WITH OPPONENT" && opponent_ != nullptr)
	{
		Hand a = hand_;
		hand_ = opponent_->getHand();
		opponent_->setHand(a);

		std::cout << "Swapped." << std::endl;
		display();
		displayAction(card);
		
		
	}
	else
	{
		std::cout << "invalid" << std::endl;
		display();
		displayAction(card);

	}
	

	display();
	displayAction(card);

	

}

void Player::display() 
{
	std::cout << "Score: " << score_ << std::endl;
	const auto& cards = hand_.getCards();
	for (const auto& card : cards) 
	{
		std::cout << "Card Type: " << card.getType() << std::endl; 
	
	}

			
}

void Player::displayAction(const ActionCard& card) 
{
	std::cout << "Card Type: " << card.getType() << std::endl;
}

void Player::drawPointCard()
{
	if (!pointdeck_ || pointdeck_->IsEmpty()) 
	{
		std::cout << "Empty deck" << std::endl;
		return;
	}
	
	PointCard card = pointdeck_->Draw();
	hand_.addCard(std::move(card));
	card.Print();

	
}


void Player::playPointCard()
{
	if (!hand_.isEmpty()) 
	{
		int points = hand_.PlayCard();
		score_ += points;
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
