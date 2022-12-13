#ifndef GAME_H
#define GAME_H

#include<iostream>
#include "player.h"
#include "deck.h"
#include "card.h"

using namespace std;

class game{
	private:
		player Players[2]; //array to store each player
		deck cards;  //gets a deck of cards
		card topcard;  //gets the top card on the deck
		int cardslo; //object to access the cards location
	public:
		game(); 
		void dealplayers();
		card gettopcard()const;
		int getlocation()const;
		void settopcard(card); 
		void setlocation(int);
		card drawCard(); 
		void printg();
		int checkplayer(int, int); 
		int checkwin(int, int, int, int);
		void playCard(int); 
		void computerplayer(int); 
		int turn(int); 
		~game(); 
};

#endif 
