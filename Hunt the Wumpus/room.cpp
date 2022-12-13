/******************************************************
** Program: room.cpp
** Author: Brandon Stairs
** Date: 3/1/2021
** Description: allows player to set events
** Input: the getters from event class
** Output: the events
******************************************************/
#include "room.hpp"
/***************************
 * Function: room(0)
 * Description: constructor for room
 * Parameters: none
 * Preconditions: a room object is created
 * Postcondition: room can be used
 * *************************/

room::room(){
	even = ' ';
	player = 'x';	
}

/***************************
 * Function: setevent
 * Description: set the events
 * Parameters: char even
 * Preconditions: event needs to be set
 * Postcondition: the event is set
 * *************************/
void room::set_event(char evens){
	if (evens == 'w'){
		roomevent = new wumpus;
		even = evens;
	}
	if (evens == 'b'){
        	roomevent = new Bats;
        	even = evens;
	}
	if (evens == 'p'){
        	roomevent = new pit;
        	even = evens;
	}
	if (evens == 'g'){
        	roomevent = new Gold;
		even = evens;
        }
	if (evens == ' '){
		even = ' ';
	}
}
/***************************
 * Function: getevent
 * Description: getter for events
 * Parameters: none
 * Preconditions: an event need to be used
 * Postcondition: the event is accessed
 * *************************/

char room::get_event(){
	return even;
}
/***************************
 * Function: setplayer
 * Description: setter for players
 * Parameters: char p
 * Preconditions: allows for the players to be set
 * Postcondition: the player is set
 * *************************/

void room::set_player(char p){
	player = p;
}
/***************************
 * Function: getplayer
 * Description: getter for players
 * Parameters: none
 * Preconditions: player needs to be used
 * Postcondition: player is accessed
 * *************************/

char room::get_player(){
	return player;
}
/***************************
 * Function: percept()
 * Description: getter for percepts
 * Parameters: none
 * Preconditions: percept needs to be used
 * Postcondition: percept is accessed
 * *************************/

 string room::percept(){
	return roomevent->percept();
}
/***************************
 * Function: ~room()
 * Description: deletes memory
 * Parameters: none
 * Preconditions: memory is being allocated
 * Postcondition: memory is deleted
 * *************************/
room::~room(){
	delete [] roomevent;
}