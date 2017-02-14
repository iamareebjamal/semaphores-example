#include "semaphore.h"

#include <sys/mman.h>

semaphore::semaphore() : _id(0) {
    sem = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);

    if(sem_init(sem, 1, 1) < 0)
        throw "Error initializing semaphore " + _id;
}

semaphore::semaphore(int id) : _id(id) {
    sem = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);

    if(sem_init(sem, 1, 1) < 0)
        throw "Error initializing semaphore " + _id;
}

int semaphore::get_id() {
    return _id;
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

void semaphore::destroy() {
    sem_destroy(sem);

    munmap(sem, sizeof(sem_t));
}