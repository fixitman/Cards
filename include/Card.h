#ifndef CARD_H 
#define CARD_H

#include <vector>
#include <memory>
#include <string.h>

const char FACES[] = "A23456789TJQK";
const char SUITS[] = "DHCS";
const int VALUES[] = {11,2,3,4,5,6,7,8,9,10,10,10,10};

using namespace std;

struct Card{
    char face;
    char suit;
    int value;
    ostream& printCard(ostream &);
};



#endif