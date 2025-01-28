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
        std::shared_ptr<Card> deal();
        std::ostream& printHand(std::ostream& out);
        bool needsShuffle();
    private:
        std::vector<std::shared_ptr<Card>> mCards;
        int mShufflePoint = 0;
};


#endif