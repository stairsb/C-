#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include "tiger.h"
#include "sealion.h"
#include "bear.h"

using namespace std;

class zoo{
    private:
        int bank;
        int month;
        sealion *lions;
        bear *bears;
        tiger *tigers;
        int n_lions;
        int n_bears;
        int n_tigers;
    
    public:
        zoo();
        int getbank();
        void setbank(int);
        void start();
        void choosebuy();
        void increaseage();
        void buyanimal();
        void goaddanimals(int again, int enter);
        void addtiger();
        void addbear();
        void addlion();
        void age();
        void revenue();
        void foodcost();
        void addfoodcosts(int oldcost);
        void special();
        void sick();
        void babies();
        void attendance();
       
        
        
        ~zoo();



};
#endif