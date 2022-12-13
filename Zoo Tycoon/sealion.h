#ifndef SEALION_H
#define SEALION_H
#include "animal.h"

class sealion : public animal{

public:
        sealion();
        sealion(int ages, int costs, int babies, int foodcosts, int revenues);
};
#endif