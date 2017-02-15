#include <iostream>
#include <unistd.h>
#include <vector>

#include "chopstick.h"

using namespace std;

template <typename T>
void clean_memory(T objects) {
    typename T::const_iterator it;

    for(it = objects.begin(); it != objects.end(); ++it)
        delete *it;

}

int eat_time = 0;

void philosopher(int i, vector<chopstick*>& chopsticks) {
    int num = 6;

    chopstick* first = chopsticks[i];
    chopstick* second = chopsticks[(i+1)%num];

    if(i == 5) {
        std::swap(first, second);
    }

    for (int j = 0; j < 100; ++j) {
        usleep(100);
        cout << "Philosopher " << i << " wants to pick up " << first->get_id() << endl;
        first->pick_up();
        cout << "Philosopher " << i << " picked up " << first->get_id() << endl;
        cout << "Philosopher " << i << " wants to pick up " << second->get_id() << endl;
        second->pick_up();
        cout << "Philosopher " << i << " picked up " << second->get_id() << endl;
        cout << "Philosopher " << i << " is eating for " << ++eat_time << " time!" << endl;
        usleep(10000);
        first->put_down();
        cout << "Philosopher " << i << " put down " << second->get_id() << endl;
        second->put_down();
        cout << "Philosopher " << i << " put down " << first->get_id() << endl << endl;
        usleep(100);
    }
}

int fork_processes() {
    int num;
    for (num = 0; num < 5; ++num) {
        int pid = fork();
        if (pid == 0)
            break;
    }

    return num;
}


int main() {
    vector<chopstick*> chopsticks;

    try {

        for (int i = 0; i < 6; ++i)
            chopsticks.push_back(new chopstick(i + 1));

    } catch (string error) {
        cout << error << endl;
        return 0;
    }

    int num = fork_processes();

    philosopher(num, chopsticks);

    clean_memory(chopsticks);

    return 0;
}