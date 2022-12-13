#ifndef PIT_H
#define PIT_H

#include "event.hpp"
#include <iostream>
using namespace std;

class pit: public event{
	private:
		char even;
        string encounte;
        string percep;
	public:
		pit();
		string percept();
		string encounter();
        ~pit();
};
	
#endif