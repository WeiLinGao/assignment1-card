#include "Card.hpp"


// destructor;
Card::~Card()
{
    if (bitmap_ != nullptr) 
    {
        delete[] bitmap_;
        bitmap_ = nullptr;
    }
}

//Copy constructor
Card::Card(const Card& rhs)
{
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;

    if (rhs.bitmap_ != nullptr)
    {
        bitmap_ = new int[80];

        for (int i = 0; i < 80; i++)
        {
            bitmap_[i] = rhs.bitmap_[i];
        }

    }

    else
    {
        bitmap_ = nullptr;
    }



}


//Copy assignemnt
Card& Card:: operator=(const Card& rhs)
{
    if (this != &rhs)
    {
        delete[] bitmap_;
        cardType_ = rhs.cardType_;
        drawn_ = rhs.drawn_;
        instruction_ = rhs.instruction_;

        if (rhs.bitmap_ != nullptr)
        {
            bitmap_ = new int[80];

            for (int i = 0; i < 80; i++)
            {
                bitmap_[i] = rhs.bitmap_[i];
            }
        }

        else
        {
            bitmap_ = nullptr;
        }



    }

    return *this;
}


// move constructor
Card::Card(Card&& rhs)
{
    cardType_ = rhs.cardType_;
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
    rhs.bitmap_ = nullptr;

}


//move assignment
Card& Card::operator=(Card&& rhs)
{
    if (this != &rhs)
    {
        delete[] bitmap_;
        cardType_ = rhs.cardType_;
        instruction_ = std::move(rhs.instruction_);
        drawn_ = rhs.drawn_;
        bitmap_ = rhs.bitmap_;
        rhs.bitmap_ = nullptr;
        rhs.drawn_ = false;




    }

    return *this;
}


//Constructor
Card::Card()
{
    cardType_= CardType::POINT_CARD;
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;

}



// Return cardtype in string
std::string Card::getType() const
{
    if (cardType_ == CardType::POINT_CARD)
    {
        return "POINT_CARD";
    }
    else 
    {
        return "ACTION_CARD";
    }


 
}


// set the card type
void Card::setType(const CardType& type)
{
    cardType_ = type;
}


// Return instruction in string
const std::string& Card::getInstruction() const
{
    return instruction_;
}


//Set set the card instruction
void Card::setInstruction(const std::string& instruction)
{
    instruction_ = instruction;
}


// return array of integer
const int* Card::getImageData() const
{
    return bitmap_;
}

//set image data
void Card::setImageData(int* data)
{
    if (bitmap_ != nullptr) 
    {
        delete[] bitmap_;
        bitmap_ = nullptr; 
    }

    if (data != nullptr) 
    {
        bitmap_ = new int[80];
        std::copy(data, data + 80, bitmap_);
    }
    else
    {
        bitmap_ = nullptr; 
    }
}


//return the drawn status of the card
bool Card::getDrawn() const
{
    return drawn_;
}



//set the drawn status of the card
void Card::setDrawn(const bool& drawn)
{
    drawn_ = drawn;
}
