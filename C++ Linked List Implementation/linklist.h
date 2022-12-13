/******************************************************
** Program: linklist.h
** Author: Brandon Stairs
** Date: 3/14/2021
** Description: header file for linklist
** Input: Nodes from node class
** Output: program sorting functionallity
******************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

using namespace std;

class Linked_List{
    private:
        unsigned int length;
        Node *head;
        bool sorting;

    public:
        Linked_List();
        ~Linked_List();
        int get_length();
        void print();
        void clear();
        unsigned int push_front(int);
        unsigned int push_back(int);
        unsigned int insert(int val, unsigned int index);
        void sort_ascending();
        void sort_descending();
        bool get_sorting();
        void getnumber();
        void merge(Node **);
        Node * mergeLR(Node *, Node*);
        int count_primes(); 
    
};

#endif