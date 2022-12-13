/****************************
 * Program: player.cpp
 * Author: Brandon Stairs
 * Date: 1/30/2021
 * Description: creates a player class
 * Input: none
 * Output: who is playing and what their hand is
 * *************************/
#include <iostream>
#include <cstdlib>
#include "player.h"
#include "hand.h"
#include "deck.h"

/***************************
 * Function: player()
 * Description: default constructor
 * Parameters: none
 * Preconditions: player object
 * Postcondition: none
 * *************************/
player::player(){

}
/***************************
 * Function: getname()
 * Description: gets the name of the player
 * Parameters: none
 * Preconditions: object for a players name
 * Postcondition: returns the name of a player
 * *************************/
string player::getname(){
    return name;
}
/***************************
 * Function: gethand()
 * Description: gets the hand of a player
 * Parameters: none
 * Preconditions: object is created for hand
 * Postcondition: returns the hand of a player
 * *************************/
hand player::gethand(){
    return Hand;
}
/***************************
 * Function: getn_cards()
 * Description: gets the number of cards in a hand
 * Parameters: none
 * Preconditions: the number of cards in a hand
 * Postcondition: returns how many cards are in the hand
 * *************************/
int player::getn_cards(){
    return Hand.getn_cards();
}
/***************************
 * Function: setname()
 * Description: sets the name of the player
 * Parameters: string
 * Preconditions: getter gets the players name
 * Postcondition: the players name is changed to the correct name 
 * *************************/
void player::setname(string pname){
    name = pname;
}
/***************************
 * Function: selectCard()
 * Description: gets the card the user want to play from their hand
 * Parameters: none
 * Preconditions: the user has cards in their hand
 * Postcondition: the card that the user want to play
 * *************************/
int player::selectCard(){
	int var;
	//int var = 0;
	int input;
	do{
		input = 1;
		cout << "Enter the number for the card you would like to play: " << endl;
		//cin >> var;
		string s;
		getline(cin,s);
		var = atoi(s.c_str()); 
		if(var > Hand.getn_cards()|| var < 1){
			cout << "You did not enter one of the cards in your hand " << endl;
			input = 2;
		}
	}while(input == 2);
	
	return var - 1; 
}
/***************************
 * Function: playCard()
 * Description: gets the card from the players hand that they want to play
 * Parameters: int
 * Preconditions: the card the player wants to play
 * Postcondition: the card location of the card the player wants to play
 * *************************/
void player::playCard(int card_location){
	Hand.addcard(card_location);
}
/***************************
 * Function: drawcard()
 * Description: adds a card to the players hand
 * Parameters: int, int
 * Preconditions: there are cards left in the deck
 * Postcondition: the player has a new card
 * *************************/
void player::drawcard(int rank, int suit){
	Hand.drawcard(rank, suit);
}
/***************************
 * Function: printhand()
 * Description: prints out the players hand
 * Parameters: none
 * Preconditions: the player has cards in their hand
 * Postcondition: the player can see their hand
 * *************************/
void player::printhand(){
	Hand.printhand();
}
/***************************
 * Function: picksuit()
 * Description: changed the suit
 * Parameters: none
 * Preconditions: the suit can be changed
 * Postcondition: the suit that was picked
 * *************************/
int player::picksuit(){
	int suit;
	srand(time(NULL));
	suit = (rand() % 4) + 1; //mod 4 gives numbers 0-3, we want 1-4
	if(suit == 1){
		cout << "New suit: diamonds" << endl;
	}
	else if(suit == 2){
		cout << "New suit: hearts" << endl;
	}
	else if(suit == 3){
		cout << "New suit: spades" << endl;
	}
	else if(suit == 4){
		cout << "New suit: clubs" << endl;
	}
	return suit;
}
/***************************
 * Function: ~player()
 * Description: destructor for player objects
 * Parameters: none
 * Preconditions: player object needs to get deleted
 * Postcondition: the object at the memory location is deleted
 * *************************/
player::~player(){

}