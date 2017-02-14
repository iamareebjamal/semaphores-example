#include "semaphore.h"

#include <sys/mman.h>

semaphore::semaphore() : _name("Default Name") {
    sem = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);

    if(sem_init(sem, 1, 1) < 0)
        throw "Error initializing semaphore " + _name;
}

semaphore::semaphore(string name) : _name(name) {
    sem = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);

    if(sem_init(sem, 1, 1) < 0)
        throw "Error initializing semaphore " + _name;
}

string semaphore::get_name() {
    return _name;
}

int semaphore::get_value() {
    int val;
    sem_getvalue(sem, &val);

    return val;
}

void semaphore::wait() {
    sem_wait(sem);
}

void semaphore::post() {
    sem_post(sem);
}

void semaphore::try_wait() {
    sem_trywait(sem);
}

semaphore::~semaphore() {
    sem_destroy(sem);

    munmap(sem, sizeof(sem_t));
}