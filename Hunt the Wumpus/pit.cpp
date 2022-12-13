/******************************************************
** Program: pit.cpp
** Author: Brandon Stairs
** Date: 3/1/2021
** Description: pit event class
** Input: none
** Output: the event specifics for put
******************************************************/
#include "pit.hpp"
/***************************
 * Function: pit()
 * Description: default constructor
 * Parameters: none
 * Preconditions: object is created
 * Postcondition: the objects can be used
 * *************************/

pit::pit(){
	even = 'p';
    percep = "You feel a breeze " ;
    encounte = "You fell down a pit and died there alone.";
}

/***************************
 * Function: percept()
 * Description: getter for percept
 * Parameters: none
 * Preconditions: the percept needs to be used
 * Postcondition: returns the pit percept
 * *************************/
string pit::percept(){
	return percep;
}


/***************************
 * Function: encounter
 * Description: getter for encounter
 * Parameters: none
 * Preconditions: encounter is needed for pit
 * Postcondition: returns the pit encounter
 * *************************/
string pit::encounter(){
	return encounte;
}
/***************************
 * Function: ~pit
 * Description: desctructor
 * Parameters: none
 * Preconditions: memory is being allocated
 * Postcondition: deletes memory
 * *************************/
pit::~pit(){

}

