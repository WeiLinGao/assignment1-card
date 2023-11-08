#include "ActionCard.hpp"

// defines the ActionCard class and inherits from the Card Class.

ActionCard::ActionCard()
{
    setType(CardType::ACTION_CARD);          // set card type to actioncard
}

bool ActionCard::isPlayable()
{
    if (getDrawn())                                                               
    {
        std::string instruction = getInstruction();           //  Using regular expressions to match different types of instructions for an action card.                
        std::regex draw(R"(^DRAW \d+ CARD\(S?\)$)");
        std::regex play(R"(^PLAY \d+ CARD\(S?\)$)"); 
        std::regex reverse("^REVERSE HAND$");
        std::regex swap("^SWAP HAND WITH OPPONENT$");


        return (std::regex_match(instruction, draw) || std::regex_match(instruction, play) || std::regex_match(instruction, reverse) || std::regex_match(instruction, swap));     // return true if match.
    }

    return false;
}

void ActionCard::Print() const
{
    std::cout << "Type: "  << getType()   << std::endl;
    std::cout << "Instruction: " << getInstruction()  << std::endl;                 //  Print out type
    const int* data = getImageData();                                               //  Print out instruction
    std::cout << "Card:" << std::endl;                                              //  [ImageData]
    
                                                                                     // Printing out [ImageData]: If there is no image data, print "No image data" instead
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
