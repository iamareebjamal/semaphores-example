#include <iostream>
#include <unistd.h>
#include <vector>

#include "semaphore.h"

using namespace std;

void print_data(int i) {
    for (int j = 0; j < 5; ++j) {
        cout << "Hello, World! " << i << endl;
        usleep(100);
    }
}

template <typename T>
void clean_memory(T objects) {
    typename T::const_iterator it;

    for(it = objects.begin(); it != objects.end(); ++it)
        delete *it;

}

int main() {
    vector<semaphore*> chopsticks;

    try {

        for (int i = 0; i < 6; ++i)
            chopsticks.push_back(new semaphore);

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

    chopsticks[0]->wait();
    print_data(num);
    chopsticks[0]->post();

    clean_memory(chopsticks);


    return 0;
}