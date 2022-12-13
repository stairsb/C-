/******************************************************
** Program: sealion.cpp
** Author: Brandon Stairs
** Date: 02/14/2021
** Description: child class for sea lions
** Input: values for sea lions
** Output: objects when called
******************************************************/
#include <iostream>
#include "sealion.h"
#include "animal.h"

using namespace std;
/***************************
 * Function: sealion()
 * Description: default constructor
 * Parameters: none
 * Preconditions: object for sea lion has been created
 * Postcondition: can use the objects
 * *************************/
sealion::sealion(){

}
/***************************
 * Function: sealion()
 * Description: constructor for sealion
 * Parameters: int ages, int costs, int babies, int foodcosts, int revenues) : animal(ages, costs, babies, foodcosts, revenues
 * Preconditions: object with values is created for sea lion
 * Postcondition: can use the objects
 * *************************/
sealion::sealion(int ages, int costs, int babies, int foodcosts, int revenues) : animal(ages, costs, babies, foodcosts, revenues){
    setfoodcost(1);
    setcost(800);
}