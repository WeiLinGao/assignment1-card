#include "Deck.hpp"

/*
CSCI335 Fall 2023
Assignment 1 – Card Game
WeiLinGao
11/8/2023
Deck.cpp //defines the Deck class.
*/


// Construct a new Deck object(Constructor)
template <typename CardType>
Deck<CardType>::Deck()
{

}

//Destroy the Deck object (Destructor)
template <typename CardType>
Deck<CardType>::~Deck() 
{

}

//Add a Card to the Deck
template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card) 
{
    cards_.push_back(card);
}


//Draw a card from the deck
   //  *  the deck is not empty
    // *  return the right hand value of type CardType
template <typename CardType>
CardType&& Deck<CardType>::Draw() 
{
    if (IsEmpty()) 
    {
        throw std::runtime_error("EMPTY.");
      
     
    }
   
    CardType&& card = std::move(cards_.back());
    cards_.pop_back();
    card.setDrawn(true);
    return std::move(card);
    
}

//return if the deck is empty
template <typename CardType>
bool Deck<CardType>::IsEmpty() const 
{
    return cards_.empty();
}

//Shuffle the deck
   //  * using std::mt19937 with seed 2028358904,
    // * then call std::shuffle on the vector of cards, and with the random number generator as the third argument.
template <typename CardType>
void Deck<CardType>::Shuffle() 
{
    std::mt19937 rd(2028358904);
    std::shuffle(cards_.begin(), cards_.end(), rd);
}

//return the size of the deck
template <typename CardType>
int Deck<CardType>::getSize() const 
{
    return cards_.size();
}
//return the vector of cards in the deck
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const 
{
    return cards_;
}
