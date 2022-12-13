/******************************************************
** Program: driver.cpp
** Author: Brandon Stairs
** Date: 02/14/2021
** Description: runs the program
** Input: none
** Output: if the user wants to play again
******************************************************/
#include <iostream>
#include "zoo.h"
#include "animal.h"
#include "bear.h"
#include "sealion.h"
#include "tiger.h"

using namespace std;
/***************************
 * Function: int main()
 * Description: starts and runs the program
 * Parameters: none
 * Preconditions: the program has been ran
 * Postcondition: the game is over
 * *************************/
int main(){
    int over;
    do{
    zoo z1;
    z1.start();
    cout << endl;
    cout << "There is no longer any money in the bank " << endl;
    cout << endl;
    cout << "Would you like to play again? [1] Yes [2] No" << endl;
    cout << "GAME OVER" << endl;
    cin >> over;
    }while(over == 1);
    cout << "Bye" << endl;
}