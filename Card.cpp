#include "include/Card.h"
#include <memory>
#include <string.h>
#include <algorithm>
#include <random>
#include <iterator>
#include <chrono>
#include <iostream>

using namespace std;



ostream& Card::printCard(ostream& out){
    out << this->face << this->suit << ' ';
    return out;
}

