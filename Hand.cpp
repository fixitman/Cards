#include "include/Hand.h"

void Hand::printHand(ostream& out){
    for(int i=0; i<this->mCards.size(); i++)
    mCards.at(i)->printCard(out);
    printTotal(out);

    return;
}

void Hand::draw(Deck& deck){
    mCards.push_back(deck.deal());
}

void Hand::printTotal(ostream& out){
    int val = computeValue();
    out << "Total: " << val << " ";
    if(mIsSoft){
        if(val == 21 && mCards.size() == 2){
            out << "BlackJack!!";            
        }else{
            out << "Soft ";
        }
    }
    if(val > 21){
        out << "BUST! ";
    }
    out << "\n";
}

int Hand::computeValue(){
    int total = 0;
    int v = 0;
    bool hasAce = false;
    
    for(int i = 0; i<mCards.size(); i++){
        v = mCards.at(i)->value;
        if(v < 11){
            total += v;    
            if(total > 21 && mIsSoft){
                total -= 10;
                mIsSoft = false;
            }
                 // need to test this part 
        }else{
            if(total > 10 ){
                total += 1;
                mIsSoft = false;
            }else {
                total += 11;
                mIsSoft = true;
            }
            hasAce = true;
        }
    }
    return total;
}


void Hand::playDealer(int hardRule, int softRule, Deck& deck, ostream& out){
    bool done = false;
    while(!done){
        draw(deck);
        int value = this->computeValue();
        if(value >= hardRule && !mIsSoft){
            done = true;            
        }else if(value >= softRule && mIsSoft){
            done = true;
        }
    }
    printHand(out);
}