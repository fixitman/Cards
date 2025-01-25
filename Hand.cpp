#include "include/Hand.h"

void Hand::printHand(ostream& out){
    for(int i=0; i<this->mCards.size(); i++)
    mCards.at(i)->printCard(out);

    return;
}

void Hand::draw(Deck& deck){
    mCards.push_back(deck.deal());
}

void Hand::printTotal(ostream& out){
    out << "Total: " << computeValue() << " ";
    if(mIsSoft){
        out << "Soft ";
    }
}

int Hand::computeValue(){
    int total = 0;
    int v = 0;
    bool hasAce = false;
    
    for(int i = 0; i<mCards.size(); i++){
        v = mCards.at(i)->value;
        if(v < 11){
            total += v;    
            if(total > 21 && hasAce && mIsSoft){
                total -= 10;
                mIsSoft = false;
            }
                 // need to test this part 
        }else{
            hasAce = true;
            if(total > 10 || mIsSoft){
                total += 1;
                mIsSoft = false;
            }else{
                total += 11;
                mIsSoft = true;
            }
        }
    }
    return total;
}