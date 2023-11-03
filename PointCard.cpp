#ifndef POINTCARD_HPP
#define POINTCARD_HPP
#include <iostream>
#include <string>
#include "Card.hpp"
#include "PointCard.hpp"

PointCard::PointCard():Card()
{
	cardType_ = CardType::POINT_CARD;
}


bool PointCard::isPlayable() override
{
	if (getDrawn())
	{
		std::string a = getInstruction();
		if (!a.empty())
		{
			for (char c : a)
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


void PointCard::Print() const override
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