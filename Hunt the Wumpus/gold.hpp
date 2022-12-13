#ifndef GOLD_H
#define GOLD_H

#include "event.hpp"
#include <iostream>
using namespace std;


class Gold: public event{
	private:
		char even;
        string percep;
        string encounte;
	public:
		Gold();
		~Gold();
		string percept();
		string encounter();
};
#endif

