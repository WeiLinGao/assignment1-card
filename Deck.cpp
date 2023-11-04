#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.hpp"
#include <random>
#include "Deck.hpp"

template <typename CardType>
Deck<CardType>::Deck():cards_{}
{
    
}
template <typename CardType>
Deck<CardType>::~Deck()
{
    cards_.clear();
}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card)
{
    cards_.push_back(card);
}

template <typename CardType>
CardType&& Deck<CardType>::Draw()
{
    if (!IsEmpty())
    {
        return std::move(cards_.back());
    }
    else
    {
        throw std::out_of_range("EMPTY.");
    }
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
    return cards_.empty();
}

template <typename CardType>
void Deck<CardType>::Shuffle()
{
    std::mt19937 rd(2028358904);
    std::shuffle(cards_.begin(), cards_.end(), rd);
}

template <typename CardType>
int Deck<CardType>::getSize() const
{
    return cards_.size();
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
    return cards_;
}

