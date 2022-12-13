/******************************************************
** Program: bear.cpp
** Author: Brandon Stairs
** Date: 02/14/2021
** Description: child class for bears
** Input: the object values for bears
** Output: allows the values to be used
******************************************************/
#include <iostream>
#include "bear.h"
#include "animal.h"
using namespace std;
/***************************
 * Function: bear()
 * Description: constructor for bear
 * Parameters: int ages, int costs, int babies, int foodcosts, int revenues) : animal(ages, costs, babies, foodcosts, revenues
 * Preconditions: object with values is created for bear
 * Postcondition: can use the objects
 * *************************/
bear::bear(){

}
/***************************
 * Function: bear()
 * Description: constructor for bear
 * Parameters: int ages, int costs, int babies, int foodcosts, int revenues) : animal(ages, costs, babies, foodcosts, revenues
 * Preconditions: object with values is created for bear
 * Postcondition: can use the objects
 * *************************/
bear::bear(int ages, int costs, int babies, int foodcosts, int revenues) : animal(ages, costs, babies, foodcosts, revenues){
    setfoodcost(3);
    setcost(6000);
}