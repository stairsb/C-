/******************************************************
** Program: zoo.cpp
** Author: Brandon Stairs
** Date: 2/14/2021
** Description: The game is played inside of this class
** Input: the objects for each class
** Output: Who has won the game
******************************************************/
#include <iostream>
#include <cstdlib>
#include "zoo.h"
#include "tiger.h"

using namespace std;
/***************************
 * Function: zoo()
 * Description: zoo default constructor
 * Parameters: none
 * Preconditions: a zoo object is created
 * Postcondition: creates the objects for zoo class
 * *************************/

zoo::zoo(){
    month = 0;
    bank = 100000;
    n_lions = 0;
    n_bears = 0;
    n_tigers = 0;
    
    //creates dynamic arrays for all the animals
    tigers = new tiger[50];
    bears = new bear[50];
    lions = new sealion[50];
    

}
/***************************
 * Function: getbank()
 * Description: getter for bank
 * Parameters: none
 * Preconditions: a bank object is created
 * Postcondition: returns bank
 * *************************/
int zoo::getbank(){
   return bank;
}
/***************************
 * Function: setbank()
 * Description: setter for bank
 * Parameters: none
 * Preconditions: bank object is created
 * Postcondition: set bank equal the value passed in
 * *************************/
void zoo::setbank(int){
    bank = bank;
}
/***************************
 * Function: start()
 * Description: calls the functions to play the game
 * Parameters: none
 * Preconditions: the game isn't over
 * Postcondition: the player has played through one turn of the game
 * *************************/
void zoo::start(){
    do{
        cout << endl;
        cout << "Your balance is: " << bank << endl;
        cout << "Your zoo contains: " << endl; //lets the user see what has happened in the game after every turn
        cout << "Tigers:" << n_tigers << endl;
        cout << "Bears: " << n_bears << endl;
        cout << "SeaLions: " << n_lions << endl;
        cout << endl;
        if(month >= 1){ //does call all functions until the second turn
        age();
        revenue();
        special();
        }
        cout << "Your balance is: " << bank << endl;
        choosebuy();
        foodcost();
        month++; //increases the time after every turn
    }while(bank >= 1);
    cout << "You are in debt, Your balance is: " << bank << endl;
}
/***************************
 * Function: choosebuy()
 * Description: asks the player if they would like to buy an animal
 * Parameters: none
 * Preconditions: none
 * Postcondition: where the owner want to buy an animal
 * *************************/
void zoo::choosebuy(){
    int input;
    int again;
    string s;
    cout << "would you like to buy a animal? [1] Yes [2] No: "<< endl;
	do{
		input = 1;
		getline(cin, s);
		again = atoi(s.c_str());
		if(again < 1 || again > 2){ //makes sure the input is valid
		    cout << "Invalid input: [1] Yes [2] No " << endl;
		    input = 0;
        }
	}while(input == 0);
    if(again == 1){
        buyanimal();
    }
    else{

    }
}
/***************************
 * Function: addtiger()
 * Description: adds a tiger to the array
 * Parameters: none
 * Preconditions: the user wants to add a tiger
 * Postcondition: a tiger has been added
 * *************************/
void zoo::addtiger(){
    tiger t1;   
    tigers[n_tigers] = t1;
    n_tigers++; //increases the number of tigers
    bank = bank - 15000;
}
/***************************
 * Function: addbear()
 * Description: adds a bear to the users zoo
 * Parameters: none
 * Preconditions: the user wants to add a bear
 * Postcondition: a bear has been added
 * *************************/
void zoo::addbear(){
    n_bears++; //increases the amount of bears in the zoo
    bank = bank - 6000;
}
/***************************
 * Function: addlion()
 * Description: add a sealion to the zoo
 * Parameters: none
 * Preconditions: the user wants to add a sealion
 * Postcondition: a sea lion has been added
 * *************************/
void zoo::addlion(){
    n_lions++; //increases the amount of sea lions
    bank = bank - 800;
}
/***************************
 * Function: age()
 * Description: increases the age of all the animals
 * Parameters: none
 * Preconditions: a new month
 * Postcondition: all the animals are one month older
 * *************************/
void zoo::age(){
    for(int i = 0; i < n_tigers; i++){
        tigers[i].setage(tigers[i].getage()+1); //gets the age of the animals from their respective class
    }
    for(int i = 0; i < n_bears; i++){
        bears[i].setage(bears[i].getage()+1);
    }
    for(int i = 0; i < n_lions; i++){
        lions[i].setage(lions[i].getage()+1);
    }  
}
/***************************
 * Function: buyanimal()
 * Description: asks what animal the user wants to buy
 * Parameters: none
 * Preconditions: the user wants to buy an animal
 * Postcondition: what animal they chose
 * *************************/
void zoo::buyanimal(){
    string s;
    int again;
    int input;
    cout << "What animal would you like to buy?" << endl;
    cout << "Enter number: [1] Tiger: $15,000, [2] black bear: $6,000, [3] sealion: $800" << endl;
    do{
		input = 1;
		getline(cin, s);
		again = atoi(s.c_str());
		if(again < 1 || again > 3){  //error handling for the input
		    cout << "Invalid input: [1] Tiger, [2] black bear, [3] sealion " << endl;
		    input = 0;
        }
	}while(input == 0);

    int enter;
    string a;
    cout << "How many would you like to buy?: " << endl;
    cout << "Enter 1 for one and 2 for two: " << endl;
    do{
        input = 1;
		getline(cin, a);
		enter = atoi(a.c_str());
		if(enter < 1 || enter > 2){
		    cout << "Invalid input: Enter 1 for one and 2 for two: " << endl;
		    input = 0;
        }
	}while(input == 0);
  
    goaddanimals(again, enter); //passes in the users choices
    
}
/***************************
 * Function: goaddanimals()
 * Description: adds the animal to the zoo
 * Parameters: int again, int enter
 * Preconditions: the user wanted to buy an animal
 * Postcondition: the animal is now added
 * *************************/
void zoo::goaddanimals(int again, int enter){
    if (enter == 1){ //enters the if statement if the user wanted one animal
        if(again == 1){
            if (bank >= 15001){ //makes sure the user has enough funds
                addtiger();
                tigers[n_tigers - 1].setage(48);
            }
            else{
                cout << "Not enough money to buy a tiger" << endl;
            }
        }
        else if(again == 2){
            if(bank >= 6001){
                addbear();
                bears[n_bears - 1].setage(48); //set the age to four years
            }
            else{
                cout << "not enough money to buy a bear " << endl;
            }
        }
        else{
            if(bank >= 801){
            addlion();
            lions[n_lions -1].setage(48);
            }
            else{
                cout << "Not enough money to buy a sea lion" << endl;
            }
        }
    }
    else{ //enter the else statement if the user wanted two animals
        if(again == 1){
            if(bank >= 30000){
                addtiger();
                addtiger();
                tigers[n_tigers - 1].setage(48);
                tigers[n_tigers -2].setage(48);
            }
            else{
                cout << "Insuficient funds to buy two tigers" << endl;
            }
        }
        else if(again == 2){
            if(bank >= 12000){
                addbear();
                addbear();
                bears[n_bears - 1].setage(48);
                bears[n_bears -2].setage(48);
            }
            else{
                cout << "Insuficient funds to buy two bears" << endl;
            }
        }
        else{
            if(bank >= 1600){
                addlion();
                addlion();
                lions[n_lions - 1].setage(48);
                lions[n_lions -2].setage(48);
            }
            else{
                cout << "Insuficient funds to buy two sea lions" << endl;
            }
        }
    }
}
/***************************
 * Function: revenue()
 * Description: adds money to the bank for every animal
 * Parameters: none
 * Preconditions: the user has animals
 * Postcondition: the bank is increased
 * *************************/
void zoo::revenue(){
    int rev = 0;
    for(int i = 0; i < n_tigers; i++){ //loops through for each animal
        if(tigers[i].getage() <= 6){ // accounts for babies make more
            bank = bank + 3000; //adds the revenue to the bank
            rev = rev + 3000; 
        }
        else{
            bank = bank + 1500;
            rev = rev + 1500;
        }
    }
    for(int i = 0; i < n_bears; i++){
        if(bears[i].getage() <= 6){
            bank = bank + 1200;
            rev = rev + 1200;
        }
        else{
            bank = bank + 600;
            rev = rev + 600;
        }
    }
    for(int i = 0; i < n_lions; i++){
        if(lions[i].getage() <= 6){
            bank = bank + 240;
            rev = rev + 240;
        }
        else{
            bank = bank + 120;
            rev = rev + 120;
        }
    }
    cout << "Your total revenue for the month was: " << rev << endl; //lets the user know how much total money they made
}
/***************************
 * Function: foodcost()
 * Description: subtracts the cost of food from the bank
 * Parameters: none
 * Preconditions: the user has animals
 * Postcondition: the amount the user loses
 * *************************/
void zoo::foodcost(){
    int times = 0;
    srand(time(NULL));
    int fcost = rand() % 40 + 80; //random amount between 80-120
    float total = ((float)fcost/100); //allows for decimal numbers
    float oldcost;
    if(times == 0){
         oldcost = (total * 80);
    }
    else{
        oldcost = total * oldcost; //based off of the old base cost
    }
    times++;
    addfoodcosts(oldcost);
}
/***************************
 * Function: addfoodcosts()
 * Description: subtracts the food cost depending on the animal
 * Parameters: int oldcost
 * Preconditions: the old base cost 
 * Postcondition: the food cost has been subtracted
 * *************************/
void zoo::addfoodcosts(int oldcost){
    int foodcoss = 0;
    tigers[n_tigers].setfoodcost(5);
    int tcost = tigers[n_tigers].getfoodcost(); //getter for food cost
    bears[n_bears].setfoodcost(3); //setter for food cost
    int bcost = bears[n_bears].getfoodcost();
    lions[n_lions].setfoodcost(80);
    int lcost = lions[n_lions].getfoodcost();
    for(int i = 0; i < n_tigers; i++){ //loops through for every animal
        bank = bank - (oldcost*tcost);
        foodcoss = foodcoss + (oldcost*tcost);
    }
    for(int i = 0; i < n_bears; i++){
        bank = bank - (oldcost*bcost);
        foodcoss = foodcoss + (oldcost*bcost);
    }
    for(int i = 0; i < n_lions; i++){
        bank = bank - (oldcost*lcost);
        foodcoss = foodcoss + (oldcost*lcost);
    }
    cout << "Your total food cost for the month is: " << foodcoss << endl; //lets the user see the total food cost
}
/***************************
 * Function: special()
 * Description: chooses what special event will happen
 * Parameters: none
 * Preconditions: a new turn
 * Postcondition: a special event is chosen
 * *************************/
void zoo::special(){
    srand(time(NULL));
    int ran = rand() % 4 + 1; //randomly chooses a special event
    if(ran == 1){
        sick();
    }
    else if(ran == 2){
       babies();
    }
    else if(ran == 3){
        attendance();
    }
    else{
        cout << "No special event this month " << endl;
    }
}
/***************************
 * Function: sick()
 * Description: if a animal gets sick the user pays or the animal dies
 * Parameters: none
 * Preconditions: the user has animals
 * Postcondition: the user paid or the animal is removed from the zoo
 * *************************/
void zoo::sick(){
    srand(time(NULL));
   int ran = rand() % 3 + 1;

    if(ran == 1){
        if(n_tigers >= 1){
            cout << "One of your tigers is sick! " << endl;
            tigers[n_tigers].setcost(15000); //getter for cost
            int tcost = tigers[n_tigers].getcost();//setter for cost
            if(tigers[0].getage() <= 6){ //check if the animal is a baby
                cout << "The sick tiger was a baby " << endl;
                cout << "Unfortunately you have to pay $15,000 " << endl; 
             if(bank <= 15000){ //makes sure the user has enough money to pay
                cout << "You don't even enough money to save the tiger" << endl;
                cout << "The tiger is now dead" << endl;
                n_tigers--;  //removes the animal
             }
             else{
                 bank = bank -tcost; //subtracts the cost of the animal from the bank
             }
          }
         else{ //option if the animal is an adult
              cout << "The sick tiger was an adult " << endl;
              cout << "Unfortunately you have to pay $7,500 " << endl; 
             if(bank <= 7500){
                cout << "You don't even enough money to save the baby tiger" << endl;
                cout << "The baby tiger is now dead" << endl;
                n_tigers--;  
             }
             else{
                 bank = bank - (tcost/2);
             }    
            }
        }   
    }
    else if(ran == 2){
        if(n_bears >= 1){
        cout << "One of your bears is sick! " << endl;
        bears[n_bears].setcost(6000);
        int bcost = bears[n_bears].getcost();
        if(bears[0].getage() <= 6){
            cout << "The sick bear was a baby: " << endl;
            cout << "Unfortunately you have to pay $6000 " << endl;
            if(bank <= 6000){ 
                cout << "You don't even enough money to save the bear" << endl;
                cout << "The bear is now dead" << endl;
                n_bears--;
            }
            else{
                bank = bank - bcost;
            }
        }
        else{
            cout << "The sick bear was an adult: " << endl;
            cout << "Unfortunately you have to pay $3,000 " << endl; 
            if(bank <= 3000){ 
                cout << "You don't even enough money to save the baby bear" << endl;
                cout << "The baby bear is now dead" << endl;
                n_bears--;
            }
            else{
                cout << bank << endl;
                bank = bank - (bcost/2);
                cout << bank << endl;
            }
        }
        }
    }
    else{
        if(n_lions >= 1){
        cout << "One of your sea lions is sick! " << endl;
        lions[n_lions].setcost(800);
        int lcost = lions[n_lions].getcost();
        if(lions[0].getage() <= 6){
            cout << "The sick sealion was a baby: " << endl;
            cout << "Unfortunately you have to pay $800 " << endl;    
            if(bank <= 800){
                cout << "You don't even enough money to save the sea lion" << endl;
                cout << "The sea lion is now dead" << endl;
                n_lions--;  
             }
             else{
                 bank = bank - lcost;
             }  
        }
        else{
            cout << "The sick sealion was an adult: " << endl;
            cout << "Unfortunately you have to pay $400 " << endl;  
           if(bank <= 400){
                cout << "You don't even enough money to save the baby sea lion" << endl;
                cout << "The baby sea lion is now dead" << endl;
                n_lions--;  
            }
             else{
                 bank = bank - (lcost/2);
             }    
        }
        }
    }
}
/***************************
 * Function: babies()
 * Description: adds a baby to the zoo
 * Parameters: none
 * Preconditions: the special event happens
 * Postcondition: the user now has a new baby animal
 * *************************/
void zoo::babies(){
    srand(time(NULL));
    int ran = (rand() % 3 + 1);
    if(ran == 1){
        if(n_tigers >= 1){
            for(int i = 0; n_tigers; i++){
                if(tigers[i].getage() >= 48){ //loops through the array until an adult is found
                    for(int i = 0; i < 3; i++){
                        addtiger();//adds a new tiger
                        tigers[n_tigers-1].setage(0); //sets the tigers age to 0
                        bank = bank + 15000;
                    }
                    break; //get out of the loop
                }
            }
        cout << "One of your tigers had a baby! " << endl;
        cout << "You now have: " << n_tigers << " Tigers " << endl; //shows the user how many of the animal they have
        }
    }
    else if(ran == 2){
        if(n_bears >= 1){
          for(int i = 0; n_bears; i++){
                if(bears[i].getage() >= 48){
                    for(int i = 0; i < 2; i++){
                    addbear();
                    bears[n_bears-1].setage(0);
                    bank = bank + 6000;
                    }
                    break;
                }
            }
        cout << "One of your bears had a baby! " << endl;
        cout << "You now have: " << n_bears << " Bears " << endl;
        }
    }
    else{
        if(n_lions >= 1){
            for(int i = 0; n_lions; i++){
                if(lions[i].getage() >= 48){
                    addlion();
                    lions[n_lions-1].setage(0);
                    bank = bank + 800;
                    break;
                }
            }
        cout << "One of your Sea lions had a baby! " << endl;
        cout << "You now have: " << n_lions + 1 << " Sea lions " << endl;
        }
    }
}
/***************************
 * Function: attendance()
 * Description: increases the month earning
 * Parameters: none
 * Preconditions: the special event is chosen
 * Postcondition: the user has an increased profit
 * *************************/
void zoo::attendance(){
    if(n_lions >= 1){
    srand(time(NULL));
    int ran = (rand() % 250 + 150); //chooses an increase between 150 -400
    bank = bank + (ran*n_lions);
    cout << "There was a boom in attendance this month! " << endl;
    cout << "Your sales increased by $" << ran*n_lions << endl; //allows the user to see how much of an increase in profits
    }
}
/***************************
 * Function: ~zoo
 * Description: zoo desctructor
 * Parameters: none
 * Preconditions: the game is over
 * Postcondition: there is no left over memory
 * *************************/
zoo::~zoo(){
	delete [] tigers;
    delete [] bears;
    delete [] lions;
}