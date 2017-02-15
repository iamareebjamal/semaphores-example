#include <iostream>
#include <unistd.h>
#include <vector>
#include <cmath>

#include "chopstick.h"
#include "philosopher.h"

using namespace std;

template <typename T>
void clean_memory(T objects) {
    typename T::const_iterator it;

    for(it = objects.begin(); it != objects.end(); ++it)
        delete *it;

}

void start(philosopher& ph, vector<chopstick*>& local, vector<chopstick*> table) {
    int id = ph.get_id();

    chopstick* first = local[ (int) floor( (id-1) /2) ];

    ph.set_chopstick(first);

    for (int j = 0; j < 100; ++j) {
        ph.pick_first();

        for (vector<chopstick*>::iterator it = table.begin(); it != table.end(); ++it) {

            if(ph.try_pick_second(*it) == 0) break;

            if(it == table.end()) it = table.begin();
        }

        ph.eat();

        ph.put_first();
        ph.put_second();

        usleep(100);
    }
}

int fork_processes() {
    int id;
    for (id = 0; id < 5; ++id) {
        int pid = fork();
        if (pid == 0)
            break;
    }

    return id;
}

int main() {
    vector<chopstick*> among_philosophers;
    vector<chopstick*> on_table;

    try {

        for (int i = 0; i < 3; ++i)
            among_philosophers.push_back(new chopstick(i + 1));

        for (int i = 0; i < 4; ++i)
            on_table.push_back(new chopstick(3 + i + 1));

    } catch (string error) {
        cout << error << endl;
        return 0;
    }

    int id = fork_processes();

    philosopher ph(id+1);
    start(ph, among_philosophers, on_table);

    clean_memory(among_philosophers);
    clean_memory(on_table);

    return 0;
}