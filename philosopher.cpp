#include <iostream>
#include <unistd.h>
#include "philosopher.h"


philosopher::philosopher(int id) : _id(id), eaten(0) { }

void philosopher::set_chopsticks(chopstick *first, chopstick *second) {
    this->first = first;
    this->second = second;
}

int pick(int id, chopstick* chop) {
    cout << "Philosopher " << id << " wants to pick up " << chop->get_id() << endl;
    int result = chop->pick_up();
    cout << "Philosopher " << id << " picked up " << chop->get_id() << endl;

    return result;
}

int philosopher::pick_first() {
    return pick(_id, first);
}

int philosopher::pick_second() {
    return pick(_id, second);
}

int put(int id, chopstick* chop) {
    int result = chop->put_down();

    cout << "Philosopher " << id << " put down " << chop->get_id() << endl;

    return result;
}

int philosopher::put_first() {
    return put(_id, first);
}

int philosopher::put_second() {
    return put(_id, second);
}

int philosopher::get_id() {
    return _id;
}

void philosopher::eat() {
    cout << "Philosopher " << _id << " is eating for " << ++eaten << " time!" << endl;
    usleep(10000);
}