#ifndef BATS_H
#define BATS_H

#include "event.hpp"
#include <iostream>
using namespace std;

class Bats: public event{
	private:
		string even;
        string percep;
        string encounte;
	public: 
		Bats();
		~Bats();
		string percept();
		string encounter();
};

#endif