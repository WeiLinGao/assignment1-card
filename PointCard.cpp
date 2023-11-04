#ifndef POINTCARD_HPP
#define POINTCARD_HPP

#include <iostream>
#include <string>
#include "Card.hpp"

class PointCard : public Card
{
    public:
        /**
         * @post: Construct a new Point Card object
         */
        PointCard();
        /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be a valid number
        */
        bool isPlayable() override; 
        /**
         * @post: Print the Point Card in the following format:
         * Type: [CardType]
         * Points: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
        void Print() const override;
};
#endif


PointCard::PointCard()
{
	setType(CardType::POINT_CARD);
}


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


void PointCard::Print() const 
{
	std::cout << "Type: [" << getType() << "]" << std::endl;
	std::cout << "Points: [" << getInstruction() << "]" << std::endl;
	const int* data = getImageData();

	if (data != nullptr)
	{
		std::cout << "Card: [";

		for (size_t i = 0; i < 80; i++)
		{
			std::cout << data[i] << " ";
		}

		std::cout << "]" << std::endl;
	}

	else
	{
		std::cout << "No image data" << std::endl;
	}
}

