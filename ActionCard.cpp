#include "ActionCard.hpp"


ActionCard::ActionCard() : Card()
{
    cardType_ = CardType::ACTION_CARD;
}
/*
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
*/
