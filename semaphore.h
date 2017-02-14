#ifndef DINING_PHILOSOPHERS_SEMAPHORE_H
#define DINING_PHILOSOPHERS_SEMAPHORE_H

#include <string>
#include <semaphore.h>

using namespace std;

class semaphore {
private:
    int _id;
    sem_t *sem;

public:
    semaphore();
    semaphore(int id);

    int get_id();

    int get_value();

    void wait();
    void post();

    void try_wait();

    void destroy();

    ~semaphore() {
        destroy();
    }
};


#endif //DINING_PHILOSOPHERS_SEMAPHORE_H
