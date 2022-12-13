/****************************
 * Program: card.cpp
 * Author: Brandon Stairs
 * Date: 1/28/2021
 * Description: creates the rank and suit for the cards
 * Input: none
 * Output:integers for rank and suit
 * *************************/
#include <iostream>
#include <string>
#include "card.h"

using namespace std;

/***************************
 * Function: card
 * Description: card default constructor
 * Parameters: none
 * Preconditions: creates a card object
 * Postcondition: sets the rank and suit to 0
 * *************************/

card::card(){
    this -> suit = 0; //both rank and suit are set to 0
    this -> rank = 0;

}
/***************************
 * Function: card
 * Description: card constructor
 * Parameters: none
 * Preconditions: creates a card object
 * Postcondition: sets ranks and suit to 0
 * *************************/

card::card(int new_suit, int new_rank){
   this -> suit = new_suit;
   this -> rank = new_rank;
}
/***************************
 * Function: ~card()
 * Description: desctructor
 * Parameters: none
 * Preconditions: card object
 * Postcondition: deletes the object at the memory location
 * *************************/

card::~card(){
}
/***************************
 * Function: getsuit()
 * Description: accessor for suit
 * Parameters: none
 * Preconditions: card object for suit
 * Postcondition: returns the suit
 * *************************/

int card::getsuit()const{
   //string suit[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
    return this -> suit;
}
/***************************
 * Function: setsuit()
 * Description: sets the rank
 * Parameters: value for suit
 * Preconditions: integer
 * Postcondition: value for suit is changed
 * *************************/

void card::setsuit(int new_suit){
    this -> suit = new_suit;
}
/***************************
 * Function: getrank()
 * Description: gets the suit
 * Parameters: none
 * Preconditions: card object for rank
 * Postcondition: returns rank
 * *************************/

int card::getrank()const{
    return this -> rank;
}
/***************************
 * Function: setrank()
 * Description: sets the rank
 * Parameters: none
 * Preconditions: card object for rank
 * Postcondition: changes the integer stored in suit
 * *************************/

void card::setrank(int new_rank){
    this -> rank = new_rank;
}
/***************************
 * Function: printrank()
 * Description: prints out the rank of a card
 * Parameters: none
 * Preconditions: has to be a valid rank
 * Postcondition: the user can see the rank
 * *************************/



void card::printrank(){
    if(rank == 1){
        cout << "Ace of " << endl;
    }
    else if(rank == 11){
        cout << "Jack of " << endl;
    }
    else if (rank == 12){
        cout << "Queen of " << endl;
    }
    else if(rank == 13){
        cout << "King of " << endl;
    }
    else{
        cout << rank << " of " << endl; //value for rank will print out a number at the memory address
    }
}
/***************************
 * Function: printsuit
 * Description: print out the suit
 * Parameters: none
 * Preconditions: valid suit
 * Postcondition: prints out the rank for the user to see
 * *************************/

void card::printsuit(){
    if(suit == 1){
        cout << "Clubs" << endl;
    }
    else if(suit == 2){
        cout << "Hearts" << endl;
    }
    else if(suit == 3){
        cout << "Diamonds" << endl;
    }
    else{
        cout << "Spades" << endl;
    }
}