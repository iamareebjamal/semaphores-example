#ifndef DINING_PHILOSOPHERS_SEMAPHORE_H
#define DINING_PHILOSOPHERS_SEMAPHORE_H

#include <string>
#include <semaphore.h>

using namespace std;

class chopstick {
private:
    int _id;
    sem_t *sem;

    void initialize_semaphore();

public:
    chopstick();
    chopstick(int id);

    int get_id();

    int get_value();

    int pick_up();
    int try_to_pick();

    int put_down();

    void destroy();

    ~chopstick() {
        destroy();
    }
};


#endif //DINING_PHILOSOPHERS_SEMAPHORE_H
