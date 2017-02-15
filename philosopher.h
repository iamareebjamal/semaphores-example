#ifndef DINING_PHILOSOPHERS_PHILOSOPHER_H
#define DINING_PHILOSOPHERS_PHILOSOPHER_H


#include "chopstick.h"

class philosopher {
private:
    int _id;
    int eaten;
    chopstick* first;
    chopstick* second;

public:
    philosopher(int id);

    void set_chopstick(chopstick* first);

    int pick_first();
    int try_pick_second(chopstick* second);

    int put_first();
    int put_second();

    int get_id();

    void eat();

};


#endif //DINING_PHILOSOPHERS_PHILOSOPHER_H
