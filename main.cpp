#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    int pid = fork();

    if(pid == 0) {
        cout << "Child Process: " << endl;
    } else {
        cout << "Parent Process: " << endl;
    }

    cout << "\tHello, World!\n" << endl;
    return 0;
}