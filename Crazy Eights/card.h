#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

class card{
    private: 
        int suit;  //object for each suit
        int rank;  //object for each rank

    public:
        card();
        card(int su, int ra);
        ~card();
        int getsuit()const;
        int getrank()const;
        void setsuit(int new_suit);
        void setrank(int new_rank);
        void printrank();
        void printsuit();

};

#endif