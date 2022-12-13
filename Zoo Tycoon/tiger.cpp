/******************************************************
** Program: tiger.cpp
** Author: Brandon Stairs
** Date: 02/14/2021
** Description: child class for tiger 
** Input: the functions from parent class
** Output: the values for each object
******************************************************/
#include <iostream>
#include "tiger.h"
#include "animal.h"

using namespace std;
/***************************
 * Function: tiger()
 * Description: constructor for tiger
 * Parameters: int ages, int costs, int babies, int foodcosts, int revenues) : animal(ages, costs, babies, foodcosts, revenues
 * Preconditions: object with values is created for tiger
 * Postcondition: can use the objects
 * *************************/
tiger::tiger(){

}
/***************************
 * Function: tiger()
 * Description: constructor for tiger
 * Parameters: int ages, int costs, int babies, int foodcosts, int revenues) : animal(ages, costs, babies, foodcosts, revenues
 * Preconditions: object with values is created for tiger
 * Postcondition: can use the objects
 * *************************/
tiger::tiger(int ages, int costs, int babies, int foodcosts, int revenues) : animal(ages, costs, babies, foodcosts, revenues){
    setage(48);
    setcost(15000);
    setbabies(3);
    setfoodcost(5);
    setrevenue(1500);
}