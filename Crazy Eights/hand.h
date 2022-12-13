#ifndef HAND_H
#define HAND_H

#include <iostream>
#include "card.h"

using namespace std;

class hand{
    private:
        card *cards;
        int n_cards;

    public:
        hand();
        int getn_cards()const;
        void setn_cards(int new_cards);
        card* getcards()const;
        hand(const hand&);
        hand& operator = (const hand);
        void addcard(int location);
        void drawcard(int rank, int suit);
        void printhand()const;
        ~hand();
};
#endif