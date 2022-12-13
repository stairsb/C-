#ifndef BEAR_H
#define BEAR_H
#include "animal.h"

class bear : public animal{
        public:
                bear();
                bear(int ages, int costs, int babies, int foodcosts, int revenues);

};
#endif