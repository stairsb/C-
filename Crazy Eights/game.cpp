/****************************
 * Program: deck.cpp
 * Author: Brandon Stairs
 * Date: 1/29/2021
 * Description: creates a deck class
 * Input: suit
 * Output: who won the game
 * *************************/
#include <iostream>
#include<cstdlib>
#include "game.h"
#include "player.h"
#include "deck.h"
#include "card.h"

using namespace std;

/***************************
 * Function: game()
 * Description: default game constructor
 * Parameters: none
 * Preconditions: objects were initialized for players and top card on the deck
 * Postcondition: the players names, the shuffled deck, the top card on the deck, and players cards
 * *************************/
game::game(){
	string player1;
	Players[0].setname("Players");
	Players[1].setname("Computer");

	cards.shuffle();
	dealplayers();

	settopcard(cards.getcards(14)); //"draw" one last card to start the pile
	cardslo = 15; //we are now at the 15th card in the deck (technically the 16th, but array sees this as 15)
}
/***************************
 * Function: dealplayers()
 * Description: deals cards to each player
 * Parameters: none
 * Preconditions: the deck of cards
 * Postcondition: each player has 7 cards 
 * *************************/
void game::dealplayers(){
	for(int a = 0; a < 14; a = a + 2){ //iterate by 2 because 1 card is drawn for player and 1 for computer
		int playerank = cards.getcards(a).getrank(); //player
		int playersuit = cards.getcards(a).getsuit(); //player
		int comrank = cards.getcards(a + 1).getrank(); //computer; add 1 to ensure we don't draw the same card twice
		int comsuit = cards.getcards(a + 1).getsuit(); //computer; add 1 to ensure we don't draw the same card twice
		Players[0].drawcard(playerank, playersuit);
		Players[1].drawcard(comrank, comsuit);
	}

}
/***************************
 * Function: gettopcard()
 * Description: getter for the card on top of the deck
 * Parameters: none
 * Preconditions: object for the card on top of the deck
 * Postcondition: returns the top card
 * *************************/
card game::gettopcard() const{
	return this -> topcard;
}

/***************************
 * Function: getlocation()
 * Description: gets the location of the cards 
 * Parameters: none
 * Preconditions: object for the card location
 * Postcondition: returns where the cards are in the deck
 * *************************/
int game::getlocation() const{
	return this -> cardslo;
}

/***************************
 * Function: settopcard()
 * Description: setter for the top card in the deck
 * Parameters: card
 * Preconditions: getter has found the top card
 * Postcondition: changes the value to the top card
 * *************************/
void game::settopcard(card new_card){
	this -> topcard = new_card;
}

/***************************
 * Function: setlocation()
 * Description: setter for the card location in the deck
 * Parameters: int
 * Preconditions: getter has found the cards location
 * Postcondition: the card location is updated
 * *************************/
void game::setlocation(int new_location){
	this -> cardslo = new_location;
}
/***************************
 * Function: printg()
 * Description: prints out what the top card is and the players hand
 * Parameters: none
 * Preconditions: the game can be played. Information in the arrays can be accessed
 * Postcondition: the player can see what is happening in the game
 * *************************/
void game::printg(){
	cout << endl;
	 cout <<  "Top card: " << endl;
	topcard.printrank();
	topcard.printsuit();
	cout << endl;
	cout << "Player hand:" << endl;
	Players[0].printhand();
	cout << endl;
}
/***************************
 * Function: checkplayer()
 * Description: checks if the players has a card that matches the top card
 * Parameters: int, int
 * Preconditions: the players cards and the top card on the deck
 * Postcondition: if the player can still play
 * *************************/
int game::checkplayer(int num, int end){
	int toprank = topcard.getrank();
	int topsuit = topcard.getsuit();
	int valid;
	do{
		valid = 3;
		int a;
		int n_cards = Players[num].getn_cards();
		for(a = 0; a < n_cards; a++){
			int cardrank;
			int cardsuit;
			cardrank = Players[num].gethand().getcards()[a].getrank();
			cardsuit = Players[num].gethand().getcards()[a].getsuit();
			if(cardrank == toprank || cardsuit == topsuit || cardrank == 8){
				valid = 3;
				break;
			} 
			else{
				valid = 4;
			}

		}	
			checkwin(num, end, valid, n_cards);

	}while(valid == 4);
	return end;
}
/***************************
 * Function: checkwin()
 * Description: checks to see if the game is over
 * Parameters: int, int, int, int
 * Preconditions: both players hands and the deck of cards
 * Postcondition: if the game is over
 * *************************/
int game::checkwin(int num, int end, int valid, int n_cards){	
	if(valid == 4){
		if(cardslo == 52){ //makes sure there are cards in the deck
			cout << "Game Over, no more cards left" << endl;
			if(Players[0].gethand().getn_cards() < Players[1].gethand().getn_cards()){ //checks if the player won
				cout << Players[0].getname() << "Won" << endl;
			}
			else if(Players[0].gethand().getn_cards() == Players[1].gethand().getn_cards()){ //check if the computer won
				cout << "Computer won " << endl;
			}
			else if(Players[0].gethand().getn_cards() == Players[1].gethand().getn_cards()){ //checks if it is tie
				cout << "It's a Tie" << endl;
			}
			end = 3;
			return end;
		}
		else{
			card card = cards.getcards(cardslo); //gets a card from the deck
				if(num == 0){ 
					cout << "Unable to play a card. Draw (" << n_cards + 1 << ")"; //tells the user to draw cards
					card.printrank();
					card.printsuit();
				}
				int rank = card.getrank();
				int suit = card.getsuit();
				Players[num].drawcard(rank, suit); 
				++cardslo; 
		}
	}
	return end; //not sure if this is what should be returned
}
/***************************
 * Function: playCard()
 * Description: makes sure cards can be played and allows the user to change the suit
 * Parameters: int
 * Preconditions: the cards in the deck and both players hands
 * Postcondition: playable hand
 * *************************/
void game::playCard(int num){
	//if the player only has one card in their hand and they can play it then they win the game
	int cardRank, cardSuit;
	int can_play = 3;
	do{
		int card_number;
		card_number = Players[num].selectCard(); //selectCard() in player verifies input is valid
		cardRank = Players[num].gethand().getcards()[card_number].getrank();
		cardSuit = Players[num].gethand().getcards()[card_number].getsuit();
		int pileRank = topcard.getrank();
		int pileSuit = topcard.getsuit();

		if(cardRank == pileRank || cardSuit == pileSuit || cardRank == 8){
			can_play = 3; 
			Players[num].playCard(card_number); //takes a card from the hand
			if(cardRank == 8){
				cout << "Choose a suit. Select (1)diamonds (2)hearts (3)spades (4)clubs: " << endl;
				int valid_input;
				string s;
				do{
					valid_input = 3;
					getline(cin, s);
					cardSuit = atoi(s.c_str());
					if(cardSuit < 1 || cardSuit > 4){
						cout << "Invalid input. ";
						valid_input = 4;
					}
				}while(valid_input == 4);
			}
		}
		else{
			cout << "Error: you can't play that card" << endl;
			can_play = 4;
		}
    }while(can_play == 4);
	topcard.setrank(cardRank);
	topcard.setsuit(cardSuit);
	cout << endl; 
	cout << "Top Card: " << endl;
	topcard.printrank();
	topcard.printsuit();
}
/***************************
 * Function: computerplayer
 * Description: decides for the computer what card to play
 * Parameters: int
 * Preconditions: the computer's hand
 * Postcondition: what card the computer is going to play
 * *************************/
void game::computerplayer(int num){
	cout << endl;
	cout << "Computer's turn." << endl;
	int top = topcard.getrank(); //gets the top rank
	int topsuit = topcard.getsuit(); //get the top suit
	int cardRank, cardSuit;
	for(int a = 0; a < Players[num].gethand().getn_cards(); a++){ 
		cardRank = Players[num].gethand().getcards()[a].getrank(); 
		cardSuit = Players[num].gethand().getcards()[a].getsuit();
		if(cardRank == top || cardSuit == topsuit || cardRank == 8){ //looks through the computers cards
			Players[num].playCard(a); 
			if(cardRank == 8){
				cardSuit = Players[num].picksuit(); //computer picks a suit if it plays an 8
			}
			break;
		}
	}
	topcard.setrank(cardRank);
	topcard.setsuit(cardSuit);
}
/***************************
 * Function: turn()
 * Description: changes the players turn
 * Parameters: int
 * Preconditions: the game is not over
 * Postcondition: it will be a new players turn
 * *************************/
int game::turn(int num){
	int end = 4;
	end = checkplayer(num, end);
	
	
	if(end == 4){
		if(Players[num].getn_cards() == 1){
			cout << Players[num].getname() << " wins! "; //prints the name of the player who won
			end = 3; 
		}
		else if(num == 0){
			playCard(num); //players turn
		}
		else if(num == 1){
			computerplayer(num); //computers turn
		}
	}
	return end;
}
    

/***************************
 * Function: ~game()
 * Description: game objects destructor
 * Parameters: none
 * Preconditions: memory objects needs to be deleted
 * Postcondition: deletes a memory object in game class
 * *************************/
game::~game(){
	//deletes static objects
}

