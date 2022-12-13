/******************************************************
** Program: play.cpp
** Author: Brandon Stairs
** Date: 3/1/2021
** Description: lets the player play throught the game
** Input: each event and rooms
** Output: the game being played
******************************************************/
#include "play.hpp"

/***************************
 * Function: play()
 * Description: default constructor
 * Parameters: none
 * Preconditions: a play object being created
 * Postcondition: game starts
 * *************************/

play::play(){
	grid_size = 4;
	arrows = 3;
	start_x = 0;
	start_y = 0;
	player_x = 0;
	player_y = 0;	
	wumpus_dead = 1;
	hasgold = false;
	alive = false;
	win = false;
}
/***************************
 * Function: play()
 * Description: constructor for play
 * Parameters: int size
 * Preconditions: a play object being created
 * Postcondition: the game is started
 * *************************/

play::play(int size){
	grid_size = size;
	for (int i = 0; i < size; i++){
		vector<room*> row;
		for (int j = 0; j < size; j++){
			row.push_back(new room);
		}
		grid.push_back(row);
	}

		arrows = 3;
        start_x = 0;
        start_y = 0;
        player_x = 0;
        player_y = 0;
        wumpus_dead = 1;
        hasgold = false;
		alive = false;
}

/***************************
 * Function: setPlayer()
 * Description: adds the player to the grid
 * Parameters: none
 * Preconditions: a grid is created
 * Postcondition: the player is added
 * *************************/
void play::setPlayer(){
	srand (time(NULL));	
	player_x = rand() % (grid_size-1);
	player_y = rand() & (grid_size-1);
	start_x = player_x;
	start_y = player_y;
}

/***************************
 * Function: setrandomevents()
 * Description: adds the event to the grid
 * Parameters: none
 * Preconditions: a grid has been created
 * Postcondition: the evens are on the grid
 * *************************/
void play::setRandomEvents(){
	int wumpus = 0, gold = 0, bats = 0, pit = 0;
	srand (time(NULL));	

	for (int i = 0; i < grid_size; i++){
        for (int j = 0; j < grid_size; j++){
        	if( i == player_x && j == player_y){

			}

			else{

	   		int num = rand() % 5;		
		
			if(num == 1){
					if (wumpus == 0){
						grid[i][j]->set_event('w');
						wumpus ++;
					}
					else
						grid[i][j]->set_event(' ');	
			}
			if(num == 2){
					if (gold == 0){
						grid[i][j]->set_event('g');
						gold ++;
					}
					else
                        grid[i][j]->set_event(' ');
            
			}
			if(num == 3){
					if (bats < 2){
					grid[i][j]->set_event('b');
					bats++;
					}
			}
			if(num == 4){
					if (pit < 2){
					grid[i][j]->set_event('p');		
					pit++;
					}
			}
			if(num == 5){
					grid[i][j]->set_event(' ');
			}
			}
		} 
	}
}

/***************************
 * Function: checkinput()
 * Description: makes sure the user entered a valid input
 * Parameters: none
 * Preconditions: the user has to input a letter
 * Postcondition: the users input
 * *************************/
char play::checkinput(){
	char input;
	cout << "Which direction would you like to move?" << endl;
	cout << "w - North" << endl;
	cout << "a - West" << endl;
	cout << "s = South" << endl;
	cout << "d - East" << endl;
	cin >> input;
	while (cin.fail() || cin.get() != '\n' || (input != 'w' && input!= 'a' && input != 's' && input != 'd')){
		cout << endl << "Invalid input!" << endl;
        cout << endl;
                
		cin.clear();
        cout << "Enter your choice: ";
        cin >> input;
    }
	return input;
}
/***************************
 * Function: playermove()
 * Description: moves the player around the board
 * Parameters: none
 * Preconditions: the player is moving
 * Postcondition: the player is in a new postition
 * *************************/
void play::playerMove(){
	char input = checkinput();
	if(input == 'd'){
                if(player_x<0|| player_x>grid_size-1|| player_y+1<0|| player_y+1>grid_size-1){
                        cout << "Out of bounds! Try again" << endl;
                	playerMove();
		}
		else{
            player_y++;
		}
    }
	if(input == 'w'){
		if(player_x-1<0|| player_x-1>grid_size-1|| player_y<0|| player_y>grid_size-1){
			cout << "Out of bounds! Try again" << endl;
			playerMove();
		}
		else{
			player_x--;
		}
	} 
	if(input == 's'){
        if(player_x+1<0|| player_x+1>grid_size-1|| player_y<0|| player_y>grid_size-1){
            cout << "Out of bounds! Try again" << endl;
         	playerMove();
	 	}
	    else{
            player_x++;
		}	
	}
	if(input == 'a'){
        if(player_x<0|| player_x>grid_size-1|| player_y-1<0|| player_y-1>grid_size-1){
            cout << "Out of bounds! Try again" << endl;
            playerMove();
		}
		else{
            player_y--;
		}
	}
}
/***************************
 * Function: arrowup()
 * Description: lets the player shoot an arrow up
 * Parameters: none
 * Preconditions: the user shoots an arrow up
 * Postcondition: if the arrow hit the wumpus
 * *************************/
int play::arrowup(int wake){
	for (int i = 1; i <= 3; i++){
			if(player_x - i < 0){
				cout << "You missed the Wumpus!" << endl;
                wake++;
			   	wakeWumpus();
				break;
			}
			else if (grid[player_x - i][player_y]->get_event() == 'w'){
				wumpus_dead = 0;
				cout << "You have killed the Wumpus!" << endl;
				grid[player_x - i][player_y]->set_event(' ');
				break;
			}
			else{  
				if (wumpus_dead != 0){ 
                	wumpus_dead = 1;
                }	
			}
		}
		if (wake == 0 && wumpus_dead == 1){
            cout << "You missed the Wumpus!" << endl;
            wakeWumpus();
		}
		return wake;
}
/***************************
 * Function: arrowdown()
 * Description: the user shoots an arrow down
 * Parameters: int wake
 * Preconditions: the user wants to shoot an arrow down
 * Postcondition: if the user hit the wumpus
 * *************************/
int play::arrowdown(int wake){
	for (int i = 1; i <= 3; i++){
		if(player_x + i >= grid_size){
            cout << "You missed the Wumpus!" << endl;
            wakeWumpus();
        			wake++; 
					break;
	            }
	            else if (grid[player_x + i][player_y]->get_event() == 'w'){
                    wumpus_dead = 0;
                    cout << "You have killed the Wumpus!" << endl;
         			grid[player_x + i][player_y]->set_event(' ');
	                break;
                }
        		else{
                    wumpus_dead = 1; 
				}
	}
    if (wake == 0 && wumpus_dead == 1){
        cout << "You missed the Wumpus!" << endl;
        wakeWumpus();
    }
	return wake;
}
/***************************
 * Function: arrowleft
 * Description: int wake
 * Parameters: int wake
 * Preconditions: the user wants to shoot an arrow left
 * Postcondition: if the user hit the wumpus
 * *************************/
int play::arrowleft(int wake){
	for (int i = 1; i <= 3; i++){
				if(player_y - i < 0){
                    cout << "You missed the Wumpus!" << endl;
         			wake++;
	                wakeWumpus();
         			break;
	            }
	            else if (grid[player_x][player_y - i]->get_event() == 'w'){
                    wumpus_dead = 0;
                    cout << "You have killed the Wumpus!" << endl;
         			grid[player_x][player_y - i]->set_event(' ');
	                break;
                }
	       		else{   
                    wumpus_dead = 1;
                }
		
			}
			if (wake == 0 && wumpus_dead == 1){
            	cout << "You missed the Wumpus!" << endl;
            	wakeWumpus();
        	}	
			return wake;
}
/***************************
 * Function: arrowright()
 * Description: the user wants to shoot an arrow to the right
 * Parameters: int wake
 * Preconditions: the user wants to shoot an arrow to the right
 * Postcondition: if the user hit the wumpus
 * *************************/
int play::arrowright(int wake){
	for (int i = 1; i <= 3; i++){
				if((player_y + i) >= grid_size){
                    cout << "You missed the Wumpus!" << endl;
                    wakeWumpus();
                    wake++;
					break;
				}
                else if (grid[player_x][player_y + i]->get_event() == 'w'){
                    wumpus_dead = 0;
                    cout << "You have killed the Wumpus!" << endl;
 					grid[player_x][player_y + i]->set_event(' ');
                    break;
                }
	       		else{   
                    wumpus_dead = 1;
                }
		
			}
		if (wake == 0 && wumpus_dead == 1){
            cout << "You missed the Wumpus!" << endl;
            wakeWumpus();
        }
	return wake;
}
/***************************
 * Function: shootarrow
 * Description: allows the user to shoot an arrow
 * Parameters: none
 * Preconditions: the user choosing to shoot an arrow
 * Postcondition: if the user hit the wumpus
 * *************************/
void play::shootArrow(){
	arrows --;
	char fire;
	int wake = 0;
	wumpus_dead = 0;
	cout << "Which direction would you like to fire the arrow?" << endl;
        cout << "w - North" << endl;
        cout << "a - West" << endl;
        cout << "s = South" << endl;
        cout << "d - East" << endl;
	cin >> fire;
	if (fire == 'w'){
		wake = arrowup(wake);
	}
       else if (fire == 'a'){
            wake = arrowleft(wake);
        }
       else if (fire == 's'){
            wake = arrowdown(wake);
		}
        else if (fire == 'd'){
            wake = arrowright(wake);
	}
	cin.clear();
}

/***************************
 * Function: wakewumpus
 * Description: checks to see if the wumpus was woken up
 * Parameters: none
 * Preconditions: an arrow has been shot
 * Postcondition: if the wumpus moves
 * *************************/
void play::wakeWumpus(){
	srand (time(NULL));
	int wake = rand() % 4;
	int moveX = rand() % grid_size;
	int moveY = rand() % grid_size;
	if (wake == 1){
		cout << "The Wumpus is asleep still" << endl;
	}
	
	else{
		cout << "You have woken up the Wumpus" << endl;
		cout << "The Wumpus moved to another room" << endl;
		for (int i = 0; i < grid_size; i++){
	        for (int j = 0; j < grid_size; j++){
            	if (grid[i][j]->get_event() == 'w'){
					grid[i][j]->set_event(' ');
				}
			}
        }

		if(moveX == player_x && moveY == player_y){
			moveX = rand() % grid_size;
        	moveY = rand() % grid_size;
		}	
		
		grid[moveX][moveY]->set_event('w');					
	}

}

/***************************
 * Function: checkroom(0)
 * Description: checks if there is an event in the room
 * Parameters: int debug
 * Preconditions: the user moves to a different room
 * Postcondition: if an event is in the room
 * *************************/
void play::checkRoom(int debug){
	if(grid[player_x][player_y]->get_event() == 'w'){
		cout << Wumpus.encounter() << endl;
		alive = true;
	}

	if(grid[player_x][player_y]->get_event() == 'g'){
		cout << gold.encounter() << endl;
		hasgold = true;
		grid[player_x][player_y]->set_event(' ');
	}
	if(grid[player_x][player_y]->get_event() == 'p'){
		cout << Pit.encounter() << endl;
		alive = true;
	}
	if(grid[player_x][player_y]->get_event() == 'b'){
		cout << bats.encounter() << endl;
		batsRoom(debug);
	}
}


/***************************
 * Function: batsroom
 * Description: moves the player
 * Parameters: int debug
 * Preconditions: the user entered the event
 * Postcondition: the user is in a new location
 * *************************/
void play::batsRoom(int debug){
	srand (time(NULL));
	int moveX = rand() % grid_size;
    int moveY = rand() % grid_size;	

	grid[player_x][player_y]->set_event(' ');
	player_x = moveX;
	player_y = moveY;

	if (debug == 1)
		printGrid();
}


/***************************
 * Function: eventnearby
 * Description: warns the user of the events nearby
 * Parameters: none
 * Preconditions: the user is next to an event
 * Postcondition: 
 * *************************/
void play::eventNearby(){
	for(int i = player_x-1; i < player_x+1; i++){
		for(int j = player_y-1; j < player_y+1; j++){
			if(i >=0 && i < grid_size && j >=0 && j < grid_size){
					if (grid[i][j]->get_event() == 'w'){
						cout << Wumpus.percept() << endl;
					}
					if (grid[i][j]->get_event() == 'g'){
						cout << gold.percept() << endl;
					}
					if (grid[i][j]->get_event() == 'p'){
						cout << Pit.percept() << endl;
					}
					if (grid[i][j]->get_event() == 'b'){
						cout << bats.percept() << endl;
					}
			}
		}
	}	              
}

/***************************
 * Function: printgrid
 * Description: lets the user see the board
 * Parameters: none
 * Preconditions: the board is created
 * Postcondition: the user can see the board
 * *************************/
void play::printGrid(){
	cout << endl;
	for (int i = 0; i < grid_size; i++){
		for (int j = 0; j < grid_size; j++){
			cout << " | ";
			if (i == player_x && j == player_y){
				cout << "x";
			}
			else if (i == start_x && j == start_y){
				cout << "s";
			}
			else
				cout << grid[i][j]->get_event();
		}
		cout << " | " << endl;
	}
	cout << endl;
}
/***************************
 * Function: move
 * Description: gets the action the user would like to perform
 * Parameters: none
 * Preconditions: the game is not over
 * Postcondition: what the user chooses to do
 * *************************/
void play::move(){
	int move;
	cout << "To move to a different room enter 0" << endl;
	cout << "If you would like to shoot an arrow enter 1" << endl;
	cin >> move;
	
	if (move == 0){
		playerMove();
	}
	if (move == 1){
		if (arrows != 0)
			shootArrow();
		else{
			cout << "You ran out of arrows!" << endl;
			playerMove();		
		}
	}
}
/***************************
 * Function: rungame
 * Description: plays through the game
 * Parameters: int debug
 * Preconditions: the funciton is called in main
 * Postcondition: the game is over
 * *************************/
void play::runGame(int debug){
	eventNearby();
	move();
	cin.clear();
	if (debug == 1){
		printGrid();
	}
	checkRoom(debug);
	if (player_x == start_x && player_y == start_y)
		back2start = true;
	else
		back2start = false;
	if (hasgold !=0 && back2start !=0){
            cout << "You found the gold and managed to escaped! " << endl;
     }
	if (alive == 0 && (hasgold ==0 || back2start == 0)){
		runGame(debug);
	}
}

/***************************
 * Function: ~play()
 * Description: destructor for play
 * Parameters: none
 * Preconditions: there is memory being used
 * Postcondition: the memory is no longer being allocated
 * *************************/
play::~play(){
}