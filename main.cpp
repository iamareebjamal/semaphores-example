#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <sys/mman.h>

using namespace std;

void print_data(int i) {
    for (int j = 0; j < 5; ++j) {
        cout << "Hello, World! " << i << endl;
        usleep(100);
    }
}

int main() {

    sem_t *semaphore = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);

    if(sem_init(semaphore, 1, 1) < 0) {
        cout << "Error Initializing semaphore" << endl;
        return -2;
    }

    int i;
    for (i = 0; i < 5; ++i) {
        int pid = fork();
        if(pid == 0)
            break;
    }

    sem_wait(semaphore);
    print_data(i);
    sem_post(semaphore);

    sem_destroy(semaphore);

    munmap(semaphore, sizeof(sem_t));

    return 0;
}