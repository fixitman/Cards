#include "include/Cards.h"
#include <memory>
#include <string.h>
#include <algorithm>
#include <random>
#include <iterator>
#include <chrono>
#include <iostream>

Deck::Deck(int size){
    for(int d = 0; d< size; d++){
        for(int s = 0;s < strlen(SUITS); s++){
            for(int f = 0; f< sizeof(VALUES)/sizeof(int);f++){
                std::shared_ptr<Card> c(new Card); 
                c->face=FACES[f];
                c->suit = SUITS[s];
                c->value = VALUES[f];
                cards.push_back(c);
            }
        }
    }
}

void Deck::shuffle(){
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(cards), std::end(cards), std::default_random_engine(seed));
}

shared_ptr<Card> Deck::deal(){

    shared_ptr<Card> c = cards.back();
    cards.pop_back();
    return c;
}

ostream& Card::printCard(ostream& out){
    out << this->face << this->suit << ' ';
    return out;
}

void Hand::printHand(ostream& out){
    for(int i=0; i<this->cards.size(); i++)
    cards.at(i)->printCard(out);

    return;
}

void Hand::draw(Deck& deck){
    cards.push_back(deck.deal());
}

void Hand::printTotal(ostream& out){
    out << "Total: " << computeValue() << " ";
    if(soft){
        out << "Soft ";
    }
}

int Hand::computeValue(){
    int total = 0;
    int v = 0;
    bool hasAce = false;
    
    for(int i = 0; i<cards.size(); i++){
        v = cards.at(i)->value;
        if(v < 11){
            total += v;    
            if(total > 21 && hasAce && !soft){
                total -= 10;
                soft = true;
            }
                 // need to test this part 
        }else{
            hasAce = true;
            if(total > 11 || soft){
                total += 1;
                soft = true;
            }else{
                total += 11;
            }
        }
    }
    return total;
}







