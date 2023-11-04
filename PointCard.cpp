
#include "PointCard.hpp"


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
