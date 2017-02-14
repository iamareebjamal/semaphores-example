#include <iostream>
#include <unistd.h>

#include "semaphore.h"

using namespace std;

void print_data(int i) {
    for (int j = 0; j < 5; ++j) {
        cout << "Hello, World! " << i << endl;
        usleep(100);
    }
}

int main() {

    try {

        semaphore sem;

        int i;
        for (i = 0; i < 5; ++i) {
            int pid = fork();
            if (pid == 0)
                break;
        }

        sem.wait();
        print_data(i);
        sem.post();

    } catch (string error) {
        cout << error << endl;
    }

    return 0;
}