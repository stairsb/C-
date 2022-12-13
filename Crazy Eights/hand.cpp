/****************************
 * Program: hand.cpp
 * Author: Brandon Stairs
 * Date: 1/29/2021
 * Description: creates a hand class
 * Input: none
 * Output: creates a dynamic array that can allow the cards to swap positions
 * *************************/
#include "hand.h"
#include "card.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>

using namespace std;
/***************************
 * Function: hand()
 * Description: default constructor for hand class
 * Parameters: none
 * Preconditions: hand object
 * Postcondition: able to access the array of cards and number of cards in the array
 * *************************/
hand::hand(){
  //  cout << "hand constructed" << endl;
    this -> cards = NULL;
    this -> n_cards = 0;
}
/***************************
 * Function: hand()
 * Description: hand copy constructor
 * Parameters: hand
 * Preconditions: copy of hand is created
 * Postcondition: makes a copy of a hand object
 * *************************/
hand::hand(const hand& old){
  //  cout << "hand copy constructor is running" << endl;
    this -> n_cards = old.n_cards;
    this -> cards = new card[n_cards]; //creates a array to store the copy
    for(int i = 0; i < n_cards; i++){
        this -> cards[i] = old.cards[i]; //adds the cards from the old array to new array
    }
}
/***************************
 * Function: getn_cards()
 * Description: getter for the number of cards in the array
 * Parameters: none
 * Preconditions: hand object
 * Postcondition: returns how many cards are in a players hand
 * *************************/
int hand::getn_cards()const{
    return this -> n_cards;
}
/***************************
 * Function: setn_cards()
 * Description: setter for the number of cards
 * Parameters: new_cards
 * Preconditions: getter returns number of cards
 * Postcondition: sets the number of cards in a players hand
 * *************************/
void hand::setn_cards(int new_cards){
   // cout << "set cards" << endl;
     this -> n_cards = new_cards;
}
/***************************
 * Function: 
 * Description: 
 * Parameters: none
 * Preconditions:
 * Postcondition: 
 * *************************/
card* hand::getcards()const{
   // cout << "get cards function" << endl;
    return this -> cards;
}
/***************************
 * Function: hand operator
 * Description: assignment operator overload
 * Parameters: hand
 * Preconditions: can deal with mutiple objects set equal to eachother
 * Postcondition: sends information through objects
 * *************************/
hand& hand::operator = (const hand old){
//    cout << "hand assignment operator" << endl;
    if(this != &old){      //checks to see if the objects are the same
        this -> n_cards = old.n_cards;
        delete [] this -> cards;
        this -> cards = new card[n_cards]; //creates an array for the cards
        for(int i = 0; i < n_cards; i++){
            cards[i] = old.cards[i];            //adds cards from old array to new
        }
    }
    return *this;
}
/***************************
 * Function: addcard()
 * Description: adds a card to the top of the deck
 * Parameters: int
 * Preconditions: the cards that the user want to play
 * Postcondition: adds a card to the top of the deck
 * *************************/
void hand::addcard(int location){
    --n_cards;
  //  cout << "here" << endl;
    card *arr = new card[n_cards];
    for(int i = 0; i < n_cards; i++){
        if (i >= location){
            arr[i] = cards[i+1];  //
        }
        else{
            arr[i] = cards[i];
        }
    }
    delete [] cards;
    cards = arr;
    arr = NULL;
}
/***************************
 * Function: drawcard()
 * Description: draws a card from the deck
 * Parameters: int, int
 * Preconditions: the player has to draw a card
 * Postcondition: the player gets a new card in their hand
 * *************************/
void hand::drawcard(int rank, int suit){
 //   cout << "drawcard function" << endl;
    if(n_cards == 0){
        cards = new card[1];
        cards[0].setrank(rank);
        cards[0].setsuit(suit);
        ++n_cards;
    }
    else{
        ++n_cards;
        card *arr = new card[n_cards];
        for(int i = 0; i < n_cards; i++){
            if(i == n_cards - 1){
                arr[i].setrank(rank);
                arr[i].setsuit(suit);
            }
            else{
                arr[i] = cards[i];
            }
        }
        delete [] cards;
        cards = arr;
        arr = NULL;
    }
}
/***************************
 * Function: printhand()
 * Description: prints the players hand
 * Parameters: none
 * Preconditions: the player has cards in their hand
 * Postcondition: the player can see what cards are in their hand
 * *************************/
void hand::printhand()const{
    //cout << "print hand" << endl;
    for(int a = 0; a < n_cards; a++){
    
        cout << "(" << a + 1 << ")";
        cards[a].printrank();
        cards[a].printsuit();
    }
}
/***************************
 * Function: ~hand()
 * Description: destructor for hand
 * Parameters: none
 * Preconditions: hand object that needs to be deleted
 * Postcondition: memory location for the objects gets deleted
 * *************************/
hand::~hand(){
   // cout << "Hand desctrutor is running" << endl;
    delete [] cards;
    cards = NULL;
}