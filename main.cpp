#include "include/Card.h"
#include "include/Hand.h"
#include "include/Deck.h"
#include <iostream>



int main(){
    Deck* deck = new Deck(10);
    deck->shuffle();
    Hand hand;
    hand.draw(*deck);
    hand.draw(*deck);
    hand.draw(*deck);
    hand.printHand(cout);
    hand.printTotal(cout);
    
    return 0;
}