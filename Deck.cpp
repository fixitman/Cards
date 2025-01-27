#include "include/Deck.h"
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

Deck::Deck(int size){
    for(int d = 0; d< size; d++){
        for(int s = 0;s < strlen(SUITS); s++){
            for(int f = 0; f< sizeof(VALUES)/sizeof(int);f++){
                std::shared_ptr<Card> c(new Card); 
                c->face=FACES[f];
                c->suit = SUITS[s];
                c->value = VALUES[f];
                mCards.push_back(c);
            }
        }
    }
}

void Deck::shuffle(){
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(mCards), std::end(mCards), std::default_random_engine(seed));
}

shared_ptr<Card> Deck::deal(){

    shared_ptr<Card> c = mCards.back();
    mCards.pop_back();
    return c;
}