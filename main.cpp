#include "include/Card.h"
#include "include/Hand.h"
#include "include/Deck.h"
#include <iostream>


int main(){
    bool done = false;
    char key = ' ';
    while(!done){
        Deck* deck = new Deck(10);
        deck->shuffle();
        Hand hand;
        hand.playDealer(17,17,*deck,std::cout);
        key = std::cin.get();
        if(key == 'q') done = true;

    }

    
    return 0;
}