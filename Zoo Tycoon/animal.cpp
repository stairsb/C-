/******************************************************
** Program: animal.cpp
** Author: Brandon Stairs
** Date: 2/14/2021
** Description: parent class for each animal
** Input: the animal object values
** Output: returns the values when called
******************************************************/
#include <iostream>
#include "animal.h"

using namespace std;

/***************************
 * Function: animal()
 * Description: default constructor for animal class
 * Parameters: none
 * Preconditions: object is created
 * Postcondition: objects can be used
 * *************************/
animal::animal(){
    age = 0;
    cost = 0;
    babie = 0;
    foodcost = 0;
    revenue = 0;
}
/***************************
 * Function: animal()
 * Description: allows the objects to be changed
 * Parameters: int ages, int costs, int babies, int foodcosts, int revenues
 * Preconditions: the objects exist
 * Postcondition: the objects can get used
 * *************************/
animal::animal(int ages, int costs, int babies, int foodcosts, int revenues){
    age = ages;
    cost = costs;
    babie = babies;
    foodcost = foodcosts;
    revenue = revenues;
}
/***************************
 * Function: getage()
 * Description: getter for age
 * Parameters: none
 * Preconditions: the object is initialized
 * Postcondition: returns age
 * *************************/
int animal::getage(){
    return age;
}
/***************************
 * Function: setage()
 * Description: sets the value for age
 * Parameters: int age
 * Preconditions: the object is initialized
 * Postcondition: the object is set
 * *************************/
void animal::setage(int ages){
  this -> age = ages;
}
/***************************
 * Function: getcost
 * Description: getter for cost
 * Parameters: none
 * Preconditions: the object has been set
 * Postcondition: returns the object
 * *************************/
int animal::getcost(){
    return cost;
}
void animal::setcost(int costs){
    this -> cost = costs;
}
/***************************
 * Function: getbabies
 * Description: getter for babies
 * Parameters: none
 * Preconditions: the object has been set
 * Postcondition: return babies
 * *************************/
int animal::getbabies(){
    return babie;
}
/***************************
 * Function: setbabies()
 * Description: setter for babies 
 * Parameters: int babies
 * Preconditions: object for babies has been created
 * Postcondition: sets the value for babies
 * *************************/
void animal::setbabies(int babies){
    this -> babie = babies;
}
/***************************
 * Function: getfoodcosts()
 * Description: getter for food costs
 * Parameters: none
 * Preconditions: setter for food costs
 * Postcondition: returns the food cost
 * *************************/
int animal::getfoodcost(){
    return foodcost;
}
/***************************
 * Function: setfoodcost
 * Description: sets the value for food costs
 * Parameters: int foodcosts
 * Preconditions: object for foodcost have been created
 * Postcondition: the value for food cost has been set
 * *************************/
void animal::setfoodcost(int foodcosts){
    this -> foodcost = foodcosts;
}
/***************************
 * Function: getrevenue()
 * Description: getter for revenue
 * Parameters: none
 * Preconditions: object has been set
 * Postcondition: returns the revenue
 * *************************/
int animal::getrevenue(){
    return revenue;
}
/***************************
 * Function: setrevenue()
 * Description: setter for revenue
 * Parameters: int revenues
 * Preconditions: object has been created for revenue
 * Postcondition: a value has been set
 * *************************/
void animal::setrevenue(int revenues){
    this -> revenue = revenues;
}

