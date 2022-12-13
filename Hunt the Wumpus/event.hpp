#ifndef EVENT_H
#define EVENT_H
#include <cstring>
#include <string>
using namespace std;



class event{
	private:
		string even;
		string percep;
        string encounte;
	public: 
		event();
		~event();
		virtual string percept();
		virtual string encounter();
};

#endif