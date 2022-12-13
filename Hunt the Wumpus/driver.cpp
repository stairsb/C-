/******************************************************
** Program: driver.cpp
** Author: Brandon Stairs
** Date: 3/1/2021
** Description: function that starts the program
** Input: size and mode in command line
** Output: starts the game
******************************************************/
#include "play.hpp"
#include <cstring>
#include <stdio.h>
/***************************
 * Function: firstplay
 * Description: lets the player play the game
 * Parameters: none
 * Preconditions: the size of the board
 * Postcondition: the game has been player
 * *************************/
int firstplay(int size, bool show){
    int choice;
    if (show == true){
        play game(size);
        game.setPlayer();
        game.setRandomEvents();
        //game.setranevents();
        game.printGrid();
        game.runGame(1);
    }
    if (show == false){
        play game(size);
        game.setPlayer();
        game.setRandomEvents();
        game.runGame(0);
    }
    cout << "Would you like to play again?" << endl;
        cout << "(1) Yes " << endl;
        cout << "(0) No " << endl;
        cin >> choice;
        return choice;
}
/***************************
 * Function: second play
 * Description: lets the user play the game again
 * Parameters: none
 * Preconditions: the size of the board
 * Postcondition: the game has been played
 * *************************/
void secondplay(){
    int debug;
    int size;
    cout << "What size grid?" << endl;
    cin >> size;
    play game2(size);
    cout << "Would you like to play in debug mode?" << endl;
    cout << "(1) Yes" << endl;
    cout << "(0) No" << endl;
    cin >> debug;
    if (debug == 1){
        game2.setPlayer();
        game2.setRandomEvents();
        game2.printGrid();
        game2.runGame(1);
    }
    if (debug == 0){
        game2.setPlayer();
        game2.setRandomEvents();
        game2.runGame(0);
    }
}
/***************************
 * Function: int main
 * Description: main function that runs the program
 * Parameters: none
 * Preconditions: the size of board and mode
 * Postcondition: the game is over
 * *************************/
int main(int argc, char **argv){
        int choice;
        if(argc != 3){
                cout << "Error, invalid command line" << endl;
                cout << "Restart program" << endl;
                return 1;
        }
        int size = atoi(argv[1]);
        char compare[] = "true";
        bool show = false;
        if(!strcmp(argv[2], compare)){
            show = true;
        }
        do{
            choice = firstplay(size, show);
        }while(choice == 1);

        if (choice == 2){
             secondplay();   
        }
        cout << "GAME OVER" << endl;
}