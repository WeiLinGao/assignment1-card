#include "Card.hpp"

Card::~Card()
{
    if (bitmap_ != nullptr) 
    {
        delete[] bitmap_;
        bitmap_ = nullptr;
    }
}


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


Card::Card(Card&& rhs)
{
    cardType_ = rhs.cardType_;
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
    rhs.bitmap_ = nullptr;

}

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


Card::Card() :cardType_(CardType::POINT_CARD)
{
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;

}

std::string Card::getType() const
{
    if (cardType_ == CardType::POINT_CARD)
    {
        return "POINT_CARD";
    }else {
        return "ACTION_CARD";
    }


 
}

void Card::setType(const CardType& type)
{
    cardType_ = type;
}

const std::string& Card::getInstruction() const
{
    return instruction_;
}

void Card::setInstruction(const std::string& instruction)
{
    instruction_ = instruction;
}

const int* Card::getImageData() const
{
    return bitmap_;
}

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
    }else {
        bitmap_ = nullptr; 
    }
}

bool Card::getDrawn() const
{
    return drawn_;
}

void Card::setDrawn(const bool& drawn)
{
    drawn_ = drawn;
}

