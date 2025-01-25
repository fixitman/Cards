#include "include/Hand.h"

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
            if(total > 10 || soft){
                total += 1;
                soft = true;
            }else{
                total += 11;
            }
        }
    }
    return total;
}