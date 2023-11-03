#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>
#include <vector>


enum CardType
{
    POINT_CARD,
    ACTION_CARD
};

class Card
{
public:
    // Big Five and Constructor
    /**
     * Destructor
     * @post: Destroy the Card object
    */
    ~Card();
    /**
     * Copy Constructor
     * @post: Construct a new Card object
     * @param: const reference to a Card object
    */
    Card(const Card& rhs);
    /**
     * Copy Assignment Operator
     * @param const reference to a Card object
     * @return this Card object
     */
    Card& operator=(const Card& rhs);
    /**
     * Move Constructor
     * @param: rvalue reference to a Card object
    */
    Card(Card&& rhs);
    /**
     * Move assignment operator
     * @param: rvalue reference to a Card object
     * @return this card object
    */
    Card& operator=(Card&& rhs);
    /**
     * Default Constructor
     * @post: Construct a new Card object
     */
    Card();

    /**
     * @return the string representation of the card type
     */
    std::string getType() const;
    /**
     * @post: set the card type
     * @param const reference to a CardType object
     */
    void setType(const CardType& type);

    /**
     * @return the string representation of the card instruction
    */
    const std::string& getInstruction() const;
    /**
     * @post: set the card instruction
     * @param: const reference to an instruction
     */
    void setInstruction(const std::string& instruction);

    /**
     * @return the image data
     */
    const int* getImageData() const;
    /**
     * @post: Set the image data
     * @param pointer to an array of integers
     */
    void setImageData(int* data);

    /**
     * @return the drawn status of the card
    */
    bool getDrawn() const;
    /**
     * @post: set the drawn status of the card
     *
     * @param: const reference to a boolean
     */
    void setDrawn(const bool& drawn);

    // Pure Virtual Functions
    virtual void Print() const = 0;
    virtual bool isPlayable() = 0;

private:
    CardType cardType_;
    std::string instruction_;
    int* bitmap_;
    bool drawn_;
};
#endif
Card::~Card()
{
    delete[] bitmap_;
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
    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = std::move(rhs.bitmap_);
    drawn_ = std::move(rhs.drawn_);
    rhs.bitmap_ = nullptr;

}

Card& Card::operator=(Card&& rhs)
{
    if (this != &rhs)
    {
        cardType_= std::move(rhs.cardType_);
        instruction_ = std::move(rhs.instruction_);
        drawn_ = std::move(rhs.drawn_);
        delete[] bitmap_;
        bitmap_ = std::move(rhs.bitmap_);
        rhs.bitmap_ = nullptr;


        

    }

    return *this;
}


Card::Card():cardType_(CardType::POINT_CARD)
{
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;

}

string Card::getType() const
{
    if (cardType_ == CardType::POINT_CARD)
    {
        return "POINT_CARD";
    }
    else if(cardType_== CardType::ACTION_CARD)
    {
        return "ACTION_CARD";
    }


    return "";
}

void Card::setType(const CardType& type)
{
    cardType_ = type;
}

const std::string& Card:: getInstruction() const
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
        std::copy(data, data + 80,bitmap_);
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


virtual void Print() const = 0;
virtual bool isPlayable() = 0;
