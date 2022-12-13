/******************************************************
** Program: gold.cpp
** Author: Brandon Stairs
** Date: 3/1/2021
** Description: gold event class
** Input: none
** Output: pit event specifics
******************************************************/
#include "gold.hpp"
/***************************
 * Function: gold()
 * Description: defualt constructor
 * Parameters: none
 * Preconditions: object is created
 * Postcondition: values can be used
 * *************************/

Gold::Gold(){
	even = 'g';
    percep = "You see a glimmer nearby ";
    encounte = "You have entered the room with gold";
}

/***************************
 * Function: percept()
 * Description: getter for percepts
 * Parameters: none
 * Preconditions: the percepts are needed
 * Postcondition: allows percepts to be used
 * *************************/
string Gold::percept(){
	return percep;
}


/***************************
 * Function: encounter
 * Description: getter for encounter
 * Parameters: none
 * Preconditions: encounter is needed
 * Postcondition: allows the encounters to be used
 * *************************/
string Gold::encounter(){
	return encounte;
}
/***************************
 * Function: ~gold
 * Description: deconstructor
 * Parameters: none
 * Preconditions: memory is being allocated
 * Postcondition: deletes memory
 * *************************/
Gold::~Gold(){

}