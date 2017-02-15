#include <iostream>
#include <unistd.h>
#include <vector>

#include "chopstick.h"
#include "philosopher.h"

using namespace std;

template <typename T>
void clean_memory(T objects) {
    typename T::const_iterator it;

    for(it = objects.begin(); it != objects.end(); ++it)
        delete *it;

}

void start(philosopher& ph, vector<chopstick*>& chopsticks) {
    int i = ph.get_id();
    int num = 6;

    chopstick* first = chopsticks[i];
    chopstick* second = chopsticks[(i+1)%num];


    if(i == 5) {
        std::swap(first, second);
    }

    ph.set_chopsticks(first, second);

    for (int j = 0; j < 100; ++j) {
        ph.pick_first();
        ph.pick_second();

        ph.eat();

        ph.put_first();
        ph.put_second();

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

    philosopher ph(num);
    start(ph, chopsticks);

    clean_memory(chopsticks);

    return 0;
}