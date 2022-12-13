/******************************************************
** Program: event.cpp
** Author: Brandon Stairs
** Date: 3/1/2021
** Description: parent class to the events
** Input: each event
** Output: the contents to the event classes
******************************************************/
#include "event.hpp"
/***************************
 * Function: event()
 * Description: default constuctor
 * Parameters: none
 * Preconditions: object for event is created
 * Postcondition: the objects can be used
 * *************************/

event::event(){
	even = ' ';
	percep = " ";
    encounte = " ";
}
/***************************
 * Function: percept
 * Description: getter for percept
 * Parameters: none
 * Preconditions: event is needed
 * Postcondition: the event that is being called
 * *************************/

string event::percept(){
    return 0;
}

/***************************
 * Function: enocounter
 * Description: getter for encounters
 * Parameters: none
 * Preconditions: encounter is needed
 * Postcondition: returns the situation specific encounter
 * *************************/

string event::encounter(){
    return encounte;
}
/***************************
 * Function: ~event()
 * Description: event deconstructor
 * Parameters: none
 * Preconditions: memory is being allocated
 * Postcondition: deletes the memory
 * *************************/
event::~event(){

}

