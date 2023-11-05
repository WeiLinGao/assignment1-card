
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
    std::string instruction = card.getInstruction();
    std::cout << "PLAYING ACTION CARD: " << instruction << std::endl;

    if (card.isPlayable()) 
    {
        if (instruction.find("DRAW") != std::string::npos) 
	{
        
            std::regex draw(R"(^DRAW (\d+) CARD\(S?\)$)");
            std::smatch match;
            if (std::regex_search(instruction, match, draw)) 
	    {
                int numCards = std::stoi(match[1].str());
                for (int i = 0; i < numCards; ++i) 
		{
                    if (pointdeck_ != nullptr && !pointdeck_->IsEmpty())
		    {
                        PointCard drawnCard = pointdeck_->Draw();
                        hand_.addCard(std::move(drawnCard));
                    }
                }
            }
        } 
	else if (instruction.find("PLAY") != std::string::npos) 
	{
           
            std::regex play(R"(^PLAY (\d+) CARD\(S?\)$)");
            std::smatch match;
            if (std::regex_search(instruction, match, play)) 
	    {
                int numCards = std::stoi(match[1].str());
                for (int i = 0; i < numCards; ++i) 
		{
                    if (hand_.isEmpty()) 
		    {
                        break; 
                    }
                    int pointsEarned = hand_.PlayCard();
                    score_ += pointsEarned;
                }
            }
        } 
	else if (instruction.find("REVERSE HAND") != std::string::npos) 
	{
            
            hand_.Reverse();
        } 
	else if (instruction.find("SWAP HAND WITH OPPONENT") != std::string::npos) 
	{
            
            if (opponent_ != nullptr) 
	    {
                std::deque<PointCard> temp = hand_.getCards();
                hand_.setCards(opponent_->getHand().getCards());
                opponent_->setHand(temp);
            }
        } 
	else 
	{
            std::cout << "Unknown instruction: " << instruction << std::endl;
        }
    } 
    else 
    {
        
        std::cout << "Invalid action card instruction: " << instruction << std::endl;
    }
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
