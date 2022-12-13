/******************************************************
** Program: linklist.cpp
** Author: Brandon Stairs
** Date: 3/14/2021
** Description: where the number are entered and sorted
** Input: The numbers the user wants to use
** Output: The sorted numbers and prime numbers
******************************************************/
#include <iostream>
#include "linklist.h"

using namespace std;
/***************************
 * Function: Link_List()
 * Description: constructor
 * Parameters: none
 * Preconditions: object is created
 * Postcondition: variables can be used
 * *************************/
Linked_List::Linked_List(){
    length = 0;
    head = NULL;
    sorting = true;

}
/***************************
 * Function: get_length()
 * Description: getter for length
 * Parameters: none
 * Preconditions: length object
 * Postcondition: length object can be used
 * *************************/
int Linked_List::get_length(){
    return length;
}
/***************************
 * Function: get_sorting()
 * Description: getter for sorting
 * Parameters: none
 * Preconditions: sorting object created
 * Postcondition: object can be used
 * *************************/
bool Linked_List::get_sorting(){
    return sorting;
}
/***************************
 * Function: print()
 * Description: prints out number for user to see
 * Parameters: none
 * Preconditions: the user entered numbers
 * Postcondition: the printed out list
 * *************************/
void Linked_List::print(){
    Node *where = head;
    cout << "Your linked list is: ";
    for (unsigned int i = 0; i < length; i++){
         cout << where->val << ' ';
        where = where->next;
    }
}
/***************************
 * Function: clear()
 * Description: gets ride of nodes
 * Parameters: none
 * Preconditions: nodes need to be deleted
 * Postcondition: nodes are deleted
 * *************************/

void Linked_List::clear(){
    while (length != 0){
        Node *where = head;
        for(unsigned int i = 0; i < length - 1; i++)
            where = where->next;
        delete where->next;
        length--;
    }
    length = 0;
}

/***************************
 * Function: push_front()
 * Description: adds a number to the front
 * Parameters: int val
 * Preconditions: node needs to be added
 * Postcondition: nodes is added
 * *************************/
unsigned int Linked_List::push_front(int val){
    Node *temp = head;
    head = new Node(val, temp);
    length++;
    return length;
}
/***************************
 * Function: push_back()
 * Description: numbers is added to back of list
 * Parameters: int val
 * Preconditions: number needs to be added
 * Postcondition: number is added
 * *************************/
unsigned int Linked_List::push_back(int val){
    if (head == NULL)
        head = new Node(val);
    else{
        Node *where = head;
        while (where->next != NULL){
            where = where->next;
        }
        where->next = new Node(val);
    }
    length++;
    return length;
}

/***************************
 * Function: insert()
 * Description: inserts a new node
 * Parameters: int val, unsigned int index
 * Preconditions: a new node needs to be added
 * Postcondition: new node is added
 * *************************/
unsigned int Linked_List::insert(int val, unsigned int index){
    cout <<endl;
    if (index == 0){
        return push_front(val);
    }
    if (index == length){
        return push_back(val);
    }
    cout <<endl;
    Node *where = head;
    for (unsigned int i = 0; i < index - 1; i++){
        where = where->next;
    }
    cout << endl;
    Node *next = where->next;
    where->next = new Node(val, next);
    length++;
    return length;
}

/***************************
 * Function: sort_ascending()
 * Description: sorts nodes lowest to highest
 * Parameters: none
 * Preconditions: numbers need to be sorted in ascending order
 * Postcondition: numbers are sorted
 * *************************/
void Linked_List::sort_ascending(){
    sorting = true;
    merge(&(head));
}
/***************************
 * Function: sort_descending()
 * Description: numbers need to be sorted highest to lowest
 * Parameters: none
 * Preconditions: the numbers need to be sorted by descending value
 * Postcondition: the numbers are sorted
 * *************************/
void Linked_List::sort_descending(){
    sorting = false;
    merge(&(head));
}
/***************************
 * Function: getnumber()
 * Description: gets the number from the user
 * Parameters: none
 * Preconditions: the user wants to enter a number
 * Postcondition: the numbers are added to nodes and sorted
 * *************************/
void Linked_List::getnumber(){
    int in;
    char input = ' ';
    do {
        cout << "Please enter a number: ";
        cin >> in;
        push_back(in);

        cout << "Do you want another num (y or n): ";
        cin >> input;
    } while (input != 'n');

    do{
        cout << "Sort ascending or descending? (a or d)? ";
        cin >> input;
    } while (input != 'a' && input != 'd');
    if(input == 'a'){
        sort_ascending();
    }
    else{
        sort_descending();
    }
}
/***************************
 * Function: merge()
 * Description: uses merge sorting
 * Parameters: Node ** begin
 * Preconditions: numbers need to be sorted
 * Postcondition: numbers are sorted using merge sort
 * *************************/
void Linked_List::merge(Node ** begin){
    Node * start = *begin;
    Node * n1;
    Node * n2;
    if (start == NULL || start->next == NULL){
        return;
    }
    Node * node1 = start->next;
    Node * node2 = start;

    while(node1 != NULL){
        node1 = node1->next;
        if(node1 != NULL){
            node1 = node1->next;
            node2 = node2->next;
        }
    }
    n1 = start;
    n2 = node2->next;
    node2->next = NULL;
    merge(&n1);
    merge(&n2);
    *begin = mergeLR(n1, n2);
}
/***************************
 * Function: mergeLR()
 * Description: sorts the nodes depending on type of sorting
 * Parameters: Node* n1, Node * n2
 * Preconditions: the nodes are split
 * Postcondition: nodes are sorted
 * *************************/
Node * Linked_List::mergeLR(Node * n1, Node * n2){
    Node * sorted = NULL;
    if (n1 == NULL){
        return n2;
    }
    if (n2 == NULL){
        return n1;
    }
     if (sorting){
        if (n1->val <= n2->val){
            sorted = n1;
            sorted->next = mergeLR(n1->next, n2);
        }
        else{
            sorted = n2;
            sorted->next = mergeLR(n1, n2->next);
        }
    }
    else{
        if (n1->val >= n2->val){
            sorted = n1;
            sorted->next = mergeLR(n1->next, n2);
        }
        else{
            sorted = n2;
            sorted->next = mergeLR(n1, n2->next);
        }
    }
    return sorted;
}

/***************************
 * Function: count_primes()
 * Description: counts the number of prime numbers
 * Parameters: none
 * Preconditions: there are nodes
 * Postcondition: how many prime numbers there are
 * *************************/
int Linked_List::count_primes(){
        int num_prime = 0;
        Node* where = head;
        for (unsigned int i =0;i < length; i++){
                for (int j = 2; j <= where-> val; j++){
                        if (j == where-> val){
                                num_prime++;
                                break;
                        }else if (where->val % j == 0){
                                break;
                        }
                }
                where = where->next;
        }
        return num_prime;
}
/***************************
 * Function: ~Linked_List()
 * Description: class deconstructor
 * Parameters: None
 * Preconditions: memory needs to be freed
 * Postcondition: memory is free
 * *************************/
Linked_List::~Linked_List(){
    delete head;
    head = NULL;
}