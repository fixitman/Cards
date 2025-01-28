#ifndef HAND_H
#define HAND_H

#include <vector>
#include <iostream>
#include <memory>
#include "Card.h"
#include "Deck.h"

class Hand
{
private:    
    bool mIsSoft = false;
    int mValue = 0;
    bool mBlackjack = false;
public:
    void draw(Deck& deck);
    std::vector<std::shared_ptr<Card>> mCards;
    void printHand(std::ostream& out);
    void printTotal(std::ostream& out);
    void calculateValue();
    int playDealer(int hardRule, int softRule, Deck& deck, std::ostream& out);
    int playPlayer(Deck& deck, std::ostream& out);
    bool hasBlackjack();
    int playPlayerSystem1(Deck& deck, std::ostream& out, int dealerCard);
};


#endif