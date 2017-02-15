#include "chopstick.h"

#include <sys/mman.h>

void chopstick::initialize_semaphore() {
    sem = (sem_t*) mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);

    if(sem_init(sem, 1, 1) < 0)
        throw "Error initializing chopstick " + _id;
}

chopstick::chopstick() : _id(0) {
    initialize_semaphore();
}

chopstick::chopstick(int id) : _id(id) {
    initialize_semaphore();
}

int chopstick::get_id() {
    return _id;
}

int chopstick::get_value() {
    int val;
    sem_getvalue(sem, &val);

    return val;
}

int chopstick::pick_up() {
    return sem_wait(sem);
}

int chopstick::put_down() {
    return sem_post(sem);
}

int chopstick::try_to_pick() {
    return sem_trywait(sem);
}

void chopstick::destroy() {
    sem_destroy(sem);

    munmap(sem, sizeof(sem_t));
}