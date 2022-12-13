/******************************************************
** Program: wumpus.cpp
** Author: Brandon Stairs
** Date: 3/1/2021
** Description: events class for wumpus
** Input: none
** Output: event specifics for wumpus
******************************************************/
#include "wumpus.hpp"
/***************************
 * Function: wumpus
 * Description: default constructor
 * Parameters: none
 * Preconditions: object is created
 * Postcondition: the object values can be used
 * *************************/
//default constructor
wumpus::wumpus(){
	alive = true;
	even = 'w';
    percep = "You smell a terrible stench ";
    encounte = "The Wumpus is in the room and eats you!";
}
/***************************
 * Function: getevent()
 * Description: getter for event
 * Parameters: none
 * Preconditions: wumpus event is being used
 * Postcondition: the event
 * *************************/
char wumpus::get_event(){
	return even;
}
/***************************
 * Function: percept
 * Description: getter for percept
 * Parameters: none
 * Preconditions: percept is being used
 * Postcondition: the value for percept
 * *************************/
string wumpus::percept(){
	return percep;
}

/***************************
 * Function: getalive()
 * Description: getter for if the wumpus is alive
 * Parameters: none
 * Preconditions: need to know if wumpus is alive
 * Postcondition: if the wumpus is alive
 * *************************/
bool wumpus::get_alive(){
	return alive;
}

/***************************
 * Function: encounter()
 * Description: getter for encounter
 * Parameters: none
 * Preconditions: needs the wumpus encounter
 * Postcondition: the counter for the wumpus
 * *************************/
string wumpus::encounter(){
	return encounte;
}
/***************************
 * Function: ~wumpus
 * Description: deconstructor
 * Parameters: none
 * Preconditions: memory is being allocated
 * Postcondition: deletes the memory
 * *************************/
wumpus::~wumpus(){
    
}