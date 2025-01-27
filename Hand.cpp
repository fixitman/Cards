#include "include/Hand.h"
#include <conio.h>
#include <iostream>

using namespace std;

void Hand::printHand(ostream& out){
    for(int i=0; i< mCards.size(); i++){
        mCards.at(i)->printCard(out);
    }
    return;
}

void Hand::draw(Deck& deck){
    mCards.push_back(deck.deal());
}

void Hand::printTotal(ostream& out){
    
    out << "Total: " << mValue << " ";
    if(mIsSoft){
        if(mValue == 21 && mCards.size() == 2){
            out << "BlackJack!!";            
        }else{
            out << "Soft ";
        }
    }
    if(mValue > 21){
        out << "BUST! ";
    }

    out << '\n';
    
    
}

void Hand::calculateValue(){
    
    int v = 0;
    bool hasAce = false;
    mValue = 0;
    for(int i = 0; i<mCards.size(); i++){
        v = mCards.at(i)->value;
        if(v < 11){
            mValue += v;    
            if(mValue > 21 && mIsSoft){
                mValue -= 10;
                mIsSoft = false;
            }
                 // need to test this part 
        }else{
            if(mValue > 10 ){
                mValue += 1;
                mIsSoft = false;
            }else {
                mValue += 11;
                mIsSoft = true;
            }
            hasAce = true;
        }
    }
    return ;
}


void Hand::playDealer(int hardRule, int softRule, Deck& deck, ostream& out){
    bool done = false;
    while(!done){
        draw(deck);
        calculateValue();
        if(mValue >= hardRule && !mIsSoft){
            done = true;            
        }else if(mValue >= softRule && mIsSoft){
            done = true;
        }
    }
    printHand(out);
}

int Hand::playPlayer(Deck& deck, ostream& out){
    
    char c = ' ';
    draw(deck);
    draw(deck);
    calculateValue();
    printHand(out);
    if(this->mValue == 21){
      c = 's';
      printTotal(out);
      return mValue;
    }    
    while(c != 's'){
        c = _getch();
        if(c == 'h'){
            draw(deck);
            shared_ptr<Card> card = mCards[mCards.size()-1];
            card->printCard(out);
            calculateValue();
            if(mValue >= 21) c = 's';
        }
    }
    printTotal(out);
    return mValue;
}