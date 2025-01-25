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
    vector<shared_ptr<Card>> cards;
    bool soft = false;
public:
    void draw(Deck& deck);
    void printHand(ostream& out);
    void printTotal(ostream& out);
    int computeValue();
    

};


#endif