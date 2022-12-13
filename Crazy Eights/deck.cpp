/****************************
 * Program: deck.cpp
 * Author: Brandon Stairs
 * Date: 1/29/2021
 * Description: creates a deck class
 * Input: none
 * Output: a static array representing the deck
 * *************************/
#include <iostream>
#include <cstdlib>
#include "deck.h"
#include "card.h"


using namespace std;

/***************************
 * Function: deck()
 * Description: deck default constructor
 * Parameters: none
 * Preconditions: deck object
 * Postcondition: creates a deck of 52 cards
 * *************************/
deck::deck(){
int num = 0;
	for(int i = 1; i <= 13; i++){
		for(int j = 1; j <= 4; j++){
			cards[num].setrank(i); 
			cards[num].setsuit(j);
			num++; 
		}
	}
}
/***************************
 * Function: getcards()
 * Description: gets the cards stored in the array
 * Parameters: none
 * Preconditions: deck object
 * Postcondition: returns where cards are in the deck
 * *************************/
card deck::getcards(int storedcards){
    return this -> cards[storedcards];
}
/***************************
 * Function: getn_cards()
 * Description: gets the number of cards in the deck
 * Parameters: none
 * Preconditions: deck object
 * Postcondition: returns how many cards are left in the deck
 * *************************/
int deck::getn_cards()const{
    return this -> n_cards;
}
/***************************
 * Function: setn_cards()
 * Description: sets the number of cards to a value
 * Parameters: none
 * Preconditions: getter returns a card object
 * Postcondition: sets the value for cards in the deck
 * *************************/
void deck::setn_cards(int n_cards){
   this -> n_cards = n_cards;
}
/***************************
 * Function: shuffle()
 * Description: shuffles the deck of cards
 * Parameters: none
 * Preconditions: deck array
 * Postcondition: deck is shuffled
 * *************************/
void deck::shuffle(){
    int ran = 0;
    card yes;
    srand(time(NULL));
    for(int i = 0; i < 52; i++){
        ran = i + (rand()%(52-i));
        yes = cards[i];
        cards[i] = cards[ran];
        cards[ran] = yes;
    
    }
}
/***************************
 * Function: printdeck()
 * Description: prints the deck for the user to see
 * Parameters: none
 * Preconditions: deck array full of cards
 * Postcondition: deck of cards is printed
 * *************************/
void deck::printdeck(){
        for(int i = 0; i < 52; i++){
            cards[i].printrank();
            cards[i].printsuit();
        }
        
}
/***************************
 * Function: ~deck()
 * Description: desctuctor for objects in deck
 * Parameters: none
 * Preconditions: deck object
 * Postcondition: memory for deck object is deleted
 * *************************/
deck::~deck(){

}