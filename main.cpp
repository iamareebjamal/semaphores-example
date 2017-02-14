#include <iostream>
#include <unistd.h>
#include <vector>

#include "semaphore.h"

using namespace std;

template <typename T>
void clean_memory(T objects) {
    typename T::const_iterator it;

    for(it = objects.begin(); it != objects.end(); ++it)
        delete *it;

}

int eat_time = 0;

void philosopher(int i, vector<semaphore*>& chopsticks) {
    int num = 6;

    semaphore* first = chopsticks[i];
    semaphore* second = chopsticks[(i+1)%num];

    if(i == 5) {
        std::swap(first, second);
    }

    for (int j = 0; j < 100; ++j) {
        cout << "Philosopher " << i << " wants to pick up " << first->get_id() << endl;
        first->wait();
        cout << "Philosopher " << i << " picked up " << first->get_id() << endl;
        cout << "Philosopher " << i << " wants to pick up " << second->get_id() << endl;
        second->wait();
        cout << "Philosopher " << i << " picked up " << second->get_id() << endl;
        cout << "Philosopher " << i << " is eating for " << ++eat_time << " time!" << endl;
        usleep(1000000);
        first->post();
        cout << "Philosopher " << i << " put down " << second->get_id() << endl;
        second->post();
        cout << "Philosopher " << i << " put down " << first->get_id() << endl << endl;
    }
}

int main() {
    vector<semaphore*> chopsticks;

    try {
        for (int i = 0; i < 6; ++i)
            chopsticks.push_back(new semaphore(i + 1));

    } catch (string error) {
        cout << error << endl;
        return 0;
    }

    int num;
    for (num = 0; num < 5; ++num) {
        int pid = fork();
        if (pid == 0)
            break;
    }

    philosopher(num, chopsticks);

    clean_memory(chopsticks);

    return 0;
}