/******************************************************
** Program: node.h
** Author: Brandon Stairs
** Date: 3/14/2021
** Description: Class to hold the nodes
** Input: Where the node is moving
** Output: Where the node is found
******************************************************/
#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node(int val);
        Node(int val, Node *nod);
        ~Node();
};

#endif
                    