#include "PointCard.hpp"

/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Weilin Gao
11/8/2023
PointCard.hpp defines the PointCard class and inherits from the Card Class.
*/
//Construct a new Point Card object(constrcutor)
PointCard::PointCard()
{
	setType(CardType::POINT_CARD);
}


//return true if the card is playable, false otherwis
// For a card to be playable, it has to be drawn and the instruction has to be a valid number
bool PointCard::isPlayable()
{
	if (getDrawn())
	{
		std::string s = getInstruction();
		if (!s.empty())
		{
			for (char c : s)
			{
				if (!std::isdigit(c))
				{
					return false;
				}
			}

			return true;
		}
	}

	return false;
}


//Print the Point Card in the following format:
//* Type: [CardType]
// * Points: [Instruction]
// * Card: 
//* [ImageData]
//* Note: For [ImageData]: If there is no image data, print "No image data" instead
void PointCard::Print() const
{
	std::cout << "Type: " << getType()  << std::endl;
	std::cout << "Points: " << getInstruction()  << std::endl;
	const int* data = getImageData();
	std::cout << "Card: "<< std::endl;
	if (data != nullptr)
	{
		

		for (size_t i = 0; i < 80; i++)
		{
			std::cout << data[i] << " ";
		}

	}

	else
	{
		std::cout << "No image data" << std::endl;
	}
}
