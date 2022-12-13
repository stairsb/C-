/******************************************************
** Program: driver.cpp
** Author: Brandon Stairs
** Date: 3/14/2021
** Description: file that runs the program
** Input: None
** Output: the sorted numbers to the user
******************************************************/
#include <iostream>
#include "node.h"
#include "linklist.h"

using namespace std;
/***************************
 * Function: int main()
 * Description: functiont that the program starts and ends with
 * Parameters: none
 * Preconditions: the game is being played
 * Postcondition: if the user wants to play again and objects created
 * *************************/
int main(){
    char in;
    do{

        Linked_List l1;
        l1.getnumber();
        l1.print();
        cout << endl;
        cout << "You have " << l1.count_primes() << " prime number(s) in your list. " << endl;
        l1.clear();
        do{
            cout << endl << "Do you want to do this again (y or n)? ";
            cin >> in;
        }while(in != 'y' && in != 'n');
    }while(in == 'y');

    return 0;
}