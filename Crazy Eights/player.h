#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "player.h"
#include "hand.h"

using namespace std;



class player{
    private:
        hand Hand; //object for players hands
        string name; //object for players name
    public:
        player();
        string getname();
        hand gethand();
        int getn_cards();
        void setname(string);
        int selectCard();
        void playCard(int);
        void drawcard(int, int);
        void printhand();
        int picksuit();
        ~player();

};
#endif