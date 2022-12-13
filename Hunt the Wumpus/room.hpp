#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "bat.hpp"
#include "gold.hpp"
#include "pit.hpp"
#include "wumpus.hpp"

class room{
	private:
		event *roomevent;
		char even;
		char player;
	public:
		room();
		void set_event(char);
		char get_event();
		void set_player(char);
		char get_player();
		string percept();
		void get_wumpus();
		~room();
};



#endif