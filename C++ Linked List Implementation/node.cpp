/******************************************************
** Program: node.cpp
** Author: Brandon Stairs
** Date: 3/14/2021
** Description: Node implimentation class for node
** Input: A node being created
** Output: Where the node object is
******************************************************/
#include <iostream>
#include "node.h"

using namespace std;

/***************************
 * Function: Node()
 * Description: construtor for node
 * Parameters: int val
 * Preconditions: A node object is created
 * Postcondition: A new node
 * *************************/
Node::Node(int val){
    this->val = val;
    this->next = NULL;
}

/***************************
 * Function: Node()
 * Description: constructor for node
 * Parameters: int val, Node* nod
 * Preconditions: A node object is created
 * Postcondition: A new node
 * *************************/
Node::Node(int val, Node * nod){
    this->val = val;
    this->next = nod;
    }

/***************************
 * Function: ~Node
 * Description: Node deconstructor
 * Parameters: none
 * Preconditions: memory is being allocated
 * Postcondition: memory is freed
 * *************************/
Node::~Node(){
};