#ifndef DECK_H
#define DECK_H
#include <iostream>
#include "card.h"
using namespace std;

class deck{
    private:
        card cards[52]; //static array of 52 cards
        int n_cards; //object for the number of cards
    public:
        deck();
        card getcards(int storedcards);
        int getn_cards()const;
        void setn_cards(int);
        void shuffle();
        void printdeck();
        ~deck();
};
#endif