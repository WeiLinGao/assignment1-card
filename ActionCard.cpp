#ifndef ACTIONCARD_HPP
#define ACTIONCARD_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include "Card.hpp"

class ActionCard : public Card
{
public:
    /**
     * @post: Construct a new Action Card object
     */
    ActionCard();

    /**
     * @return true if the card is playable, false otherwise
     * For a card to be playable, it has to be drawn and the instruction has to be valid
     * Valid instructions:
     * DRAW x CARD(S) : assume x is a positive integer
     * PLAY x CARD(S) : assume x is a positive integer
     * REVERSE HAND : reverse the order of the cards in the hand
     * SWAP HAND WITH OPPONENT : swap the hand with the opponent
     */
    bool isPlayable() override;

    /**
     * @post: Print the ActionCard in the following format:
     * Type: [CardType]
     * Instruction: [Instruction]
     * Card:
     * [ImageData]
     *
     * Note: For [ImageData]: If there is no image data, print "No image data" instead
     */
    void Print() const override;
};

#endif

ActionCard::ActionCard() : Card()
{
    cardType_ = CardType::ACTION_CARD;
}

bool ActionCard::isPlayable()
{
    if (getDrawn()) {
        std::string instruction = getInstruction();
        std::regex draw("^DRAW \\d+ CARD(S)?$");
        std::regex play("^PLAY \\d+ CARD(S)?$");
        std::regex reverse("^REVERSE HAND$");
        std::regex swap("^SWAP HAND WITH OPPONENT$");

        return (std::regex_match(instruction, draw) || std::regex_match(instruction, play) ||
            std::regex_match(instruction, reverse) || std::regex_match(instruction, swap));
    }

    return false;
}

void ActionCard::Print() const
{
    std::cout << "Type: [" << getType() << "]" << std::endl;
    std::cout << "Instruction: [" << getInstruction() << "]" << std::endl;
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
