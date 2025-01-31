#include "include/Hand.h"
#include <conio.h>
#include <iostream>
#include <thread>

using namespace std;

auto SLEEP = 0ms;


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
    mValue = 0;
    int aces = 0;

    for(int i = 0; i<mCards.size(); i++){
        v = mCards.at(i)->value;
        mValue += v;
        if(v == 11){
            aces++;
        }
    }
    while(mValue > 21 && aces > 0){
        mValue -= 10;
        aces--;
    }
    if(aces>0){
        mIsSoft = true;
    }
    return ;
}


int Hand::playDealer(int hardRule, int softRule, Deck& deck, ostream& out){
    bool done = false;
    mCards.at(0)->printCard(out);
    while(!done){
        std::this_thread::sleep_for(SLEEP);
        draw(deck);
        mCards.at(mCards.size()-1)->printCard(out);
        calculateValue();
        if(mValue >= hardRule && !mIsSoft){
            done = true;            
        }else if(mValue >= softRule && mIsSoft){
            done = true;
        }
    }
    
    return mValue;
}

int Hand::playPlayer(Deck& deck, ostream& out){
    
    char c = ' ';
    draw(deck);
    draw(deck);
    calculateValue();
    printHand(out);
    if(this->mValue == 21){
      c = 's';
      mBlackjack = true;
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

bool Hand::hasBlackjack(){
    return mBlackjack;
}

int Hand::playPlayerSystem1(Deck& deck, ostream& out, int dealerCard){
    char c = ' ';
    draw(deck);
    draw(deck);
    calculateValue();
    printHand(out);
    bool done = false;
    while(!done){
        if(mValue < 12){
            draw(deck);
            calculateValue();
            mCards[mCards.size()-1]->printCard(out);
        }else if((mValue >= 17 && !mIsSoft) || (mValue >= 17 && mIsSoft) ){
            done = true;
        }else if(mValue <= 16 && mIsSoft){
            draw(deck);
            calculateValue();
            mCards[mCards.size()-1]->printCard(out);      
        }else if(mValue == 12){
            if(dealerCard > 3 && dealerCard < 7){
                done = true;
            }else{
                draw(deck);
                calculateValue();
                mCards[mCards.size()-1]->printCard(out);
            }
        }else if(mValue > 12 && mValue < 17 && !mIsSoft){
            if(dealerCard > 6){
                draw(deck);
                calculateValue();
                mCards[mCards.size()-1]->printCard(out);
            }else{
                done = true;
            }
        }else{
            out << "you Missed Something";
            done = true;
        }
    }
    out << "\n";
    return mValue;
}