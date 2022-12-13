#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "room.hpp"
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

class play: public room{
	private:
		vector<vector<room*> > grid;
		int grid_size, arrows;
		int start_x, start_y, player_x, player_y;	
		bool back2start, alive, win, hasgold, wumpus_dead;
		wumpus Wumpus;
		Bats bats;
		Gold gold;
		pit Pit;
	public:
		play();
		play(int);
		~play();
		void setPlayer();
		void playerMove();
		void wakeWumpus();
		void shootArrow();
		void batsRoom(int);
		void checkRoom(int);
		void escape();
		void eventNearby();
		void printGrid();
        void setranevents();
		void setRandomEvents();
        void seteachevent();
		void runGame(int);
        char checkinput();
        int arrowup(int wake);
        int arrowdown(int wake);
        int arrowleft(int wake);
        int arrowright(int wake);
		void setboard();
		void move();
        
};

#endif
