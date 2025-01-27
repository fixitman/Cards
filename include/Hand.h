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
    std::vector<std::shared_ptr<Card>> mCards;
    bool mIsSoft = false;
    int mValue = 0;
public:
    void draw(Deck& deck);
    void printHand(std::ostream& out);
    void printTotal(std::ostream& out);
    void calculateValue();
    void playDealer(int hardRule, int softRule, Deck& deck, std::ostream& out);
    int playPlayer(Deck& deck, std::ostream& out);
    
};


#endif