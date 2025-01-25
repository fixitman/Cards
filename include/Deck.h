#ifndef DECK_H
#define DECK_H

#include <memory>
#include <iostream>
#include "Card.h"

class Deck {
    public:    
        Deck(int size);
        Deck();
        void shuffle();
        shared_ptr<Card> deal();
        ostream& printHand(ostream& out);
    private:
        vector<shared_ptr<Card>> cards;
};


#endif