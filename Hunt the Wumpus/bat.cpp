/******************************************************
** Program: Bats.cpp
** Author: Brandon Stairs
** Date: 3/1/2021
** Description: Bats event class
** Input: none
** Output: bat event specifics
******************************************************/
#include "bat.hpp"
#include "event.hpp"
/***************************
 * Function: bats
 * Description: bats object is created
 * Parameters: none
 * Preconditions: object is created
 * Postcondition: values can be used
 * *************************/

Bats::Bats(){
        even = 'b';
        percep = "You hear wing flapping";
        encounte = "There are super bats in this room! They have carried you to a random room.";
}

/***************************
 * Function: percept
 * Description: getter for percept
 * Parameters: none
 * Preconditions: percept is being used
 * Postcondition: percept is returned
 * *************************/
string Bats::percept(){
    return percep;
    
}

/***************************
 * Function: encounter
 * Description: getter for encounter
 * Parameters: none
 * Preconditions: allows the encounter to be accessed
 * Postcondition: uses the bat encounter
 * *************************/
string Bats::encounter(){
    return encounte;
}
/***************************
 * Function: ~bats
 * Description: deconstructor
 * Parameters: none
 * Preconditions: memory is being allocated
 * Postcondition: delete memory
 * *************************/
Bats::~Bats(){

}

