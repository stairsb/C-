#ifndef ANIMAL_H
#define ANIMAL_H

class animal{
    private:
        int age;
        int cost;
        int babie;
        int foodcost;
        int revenue;
    public:
        animal();
        animal(int ages, int costs, int babies, int foodcosts, int revenues);
        int getage();
        void setage(int ages);
        int getcost();
        void setcost(int costs);
        int getbabies();
        void setbabies(int babies);
        int getfoodcost();
        void setfoodcost(int foodcosts);
        int getrevenue();
        void setrevenue(int revenues);


};
#endif