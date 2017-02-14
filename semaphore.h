#ifndef DINING_PHILOSOPHERS_SEMAPHORE_H
#define DINING_PHILOSOPHERS_SEMAPHORE_H

#include <string>
#include <semaphore.h>

using namespace std;

class semaphore {
private:
    string _name;
    sem_t *sem;

public:
    semaphore();
    semaphore(string name);

    string get_name();

    int get_value();

    void wait();
    void post();

    void try_wait();

    ~semaphore();
};


#endif //DINING_PHILOSOPHERS_SEMAPHORE_H
