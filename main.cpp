#include "include/Card.h"
#include "include/Hand.h"
#include "include/Deck.h"
#include <iostream>
#include <conio.h>


int main(){
    const int DECKS = 1;
    
    bool done = false;
    char key = ' ';
    
    int wins = 0, losses = 0, ptotal = 0, dtotal = 0;
    std::ostream& out = std::cout;
    Deck* deck = new Deck(DECKS);
    deck->shuffle();
    while(!done){
        Hand player, dealer;
        dealer.draw(*deck);
        out << "Dealer has: ";
        dealer.printHand(out);
        out << "\n" << "You: ";
        ptotal = player.playPlayer(*deck,out);
        
        if(ptotal > 21){
            //out << "Bust\n";
            losses++;
        }else{
            out << "Dealer  ";
            dtotal = dealer.playDealer(17,17,*deck,out);
            out << "   Total: " << dtotal << "  ";
            if(dtotal > 21 || dtotal < ptotal){
                out << "You win!\n";
                wins++;
            }else{
                out << "You lose!\n";
                losses++;
            }
        }
        out << "wins: " << wins << " Loses: " << losses << "\n\n";

        key = _getch();
        if(key == 'q'){
             done = true;
        }
        else {
            if(deck->needsShuffle()){
                out << "Shuffling... \n\n";
                delete deck;
                deck = new Deck(DECKS);
                deck->shuffle();
            }
        }
    }

    delete deck;
    return 0;
}