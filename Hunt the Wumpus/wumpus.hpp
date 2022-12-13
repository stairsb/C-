#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.hpp"
#include <iostream>
using namespace std;

class wumpus: public event{
	private:
		bool alive;
		char even;
        string percep;
        string encounte;
	public:
		wumpus();
		string percept();
		bool get_alive();
		string encounter();
		char get_event();
        ~wumpus();
};
#endif


