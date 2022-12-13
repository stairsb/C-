/****************************
 * Program: deck.cpp
 * Author: Brandon Stairs
 * Date: 1/29/2021
 * Description: initializes the game, asks if the user would like to keep playing
 * Input: if they would like to play again
 * Output: who won, game
 * *************************/
#include<iostream>
#include<cstdlib>
#include "game.h"
#include "hand.h"
#include "player.h"
#include "card.h"

int main(){

	int again;
	string s;
	
	
	do{ //loops through the whole program
		again = 2;	
		game start;
		
		int end;
		do{ 
			end = 3;
			start.printg(); 
			end = start.turn(0); 
			if(end == 4){ 
				end = start.turn(1); 
			}
		}while(end == 4);


		int input;
		do{ 
			cout << "Would you like to play again? " << endl;
			cout << "Enter 1 for yes and 2 for no" << endl;
			input = 3;
			getline(cin, s);
			again = atoi(s.c_str());
			if(again < 1 || again > 2){
				cout << "Error: Input is not valid" << endl;
				input = 4;
			}
		}while(input == 4);

	}while(again == 1);

	return 0;
}
    