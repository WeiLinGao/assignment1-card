#include "Player.hpp" 


//Construct a new Player object(constructor)
Player::Player()
{
	hand_ = Hand();
	score_ = 0;
	opponent_ = nullptr;
	actiondeck_ = new Deck<ActionCard>();  
	pointdeck_ = new Deck<PointCard>();
}

//Destroy the Player object(Destructor)
Player::~Player()
{

}


//return the player's hand
const Hand& Player::getHand() const
{
	return hand_;
}

//Set the player's hand
void Player::setHand(const Hand& hand)
{
	hand_ = hand;
}

//return the Player's current score
int Player::getScore() const
{
	return score_;
}

//Set the player's score
void Player::setScore(const int& score)
{
	score_ = score;
}


//Play a given action card
void Player::play(ActionCard&& card)
{

	std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;

	std::string instruction = card.getInstruction();

	if (instruction.find("DRAW") != std::string::npos)                        //If "DRAW" exist in the string instruction
	{
		size_t pos = instruction.find_first_of(' ');               
		int numDraw = std::stoi(instruction.substr(pos + 1));             // Find the number located after the first ' ' and conevrt to int 
		for (int i = 0; i < numDraw; i++)
		{
			if (pointdeck_ && !pointdeck_->IsEmpty())
			{
				drawPointCard();                                   // Draw x cards
				
			}
		}
	}
	else if (instruction.find("PLAY") != std::string::npos)                      // If "PLAY" exist in the string instruction
	{
		size_t pos = instruction.find_first_of(' ');                           
		int numPlay = std::stoi(instruction.substr(pos + 1));                // Find the number located after the first ' ' and conevrt to int 
		for (int i = 0; i < numPlay; i++)
		{
			if (!hand_.isEmpty())                                         // Play x cards
			{
				playPointCard();
			}

		}

	}
	else if (instruction == "REVERSE HAND")
	{
		hand_.Reverse();

	}
	else if (instruction == "SWAP HAND WITH OPPONENT" && opponent_ != nullptr)
	{
		Hand a = hand_;
		hand_ = opponent_->getHand();
		opponent_->setHand(a);
	}

}


//Draw a point card and place it in the player's hand
void Player::drawPointCard()
{
	if (!pointdeck_ || pointdeck_->IsEmpty())
	{
		std::cout << "Empty deck" << std::endl;
		return;
	}

	PointCard card = pointdeck_->Draw();
	hand_.addCard(std::move(card));



}


//Play a point card from the player's hand and update the player's score
void Player::playPointCard()
{
	if (!hand_.isEmpty())
	{
		int points = hand_.PlayCard();
		score_ += points;
	}

}

//Set the opponent of the player
void Player::setOpponent(Player* opponent)
{
	opponent_ = opponent;
}

//return a pointer to the player's opponent
Player* Player::getOpponent()
{
	return opponent_;
}

//set the action deck of the player 
void Player::setActionDeck(Deck<ActionCard>* actiondeck)
{
	actiondeck_ = actiondeck;
}

//return a pointer to the player's action deck
Deck<ActionCard>* Player::getActionDeck()
{
	return actiondeck_;
}

//set the point deck of the player
void Player::setPointDeck(Deck<PointCard>* pointdeck)
{
	pointdeck_ = pointdeck;
}

//return a pointer to the player's point deck
Deck<PointCard>* Player::getPointDeck()
{
	return pointdeck_;
}
