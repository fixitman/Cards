#include "include/Card.h"
#include "include/Hand.h"
#include "include/Deck.h"
#include <iostream>
#include <conio.h>


int main(){
    bool done = false;
    char key = ' ';
    Deck* deck = new Deck(6);
    deck->shuffle();
    while(!done){
        Hand hand;
        //hand.playDealer(17,17,*deck,std::cout);
        hand.playPlayer(*deck,std::cout);
        key = _getch();
        if(key == 'q') done = true;
    }

    delete deck;
    return 0;
}