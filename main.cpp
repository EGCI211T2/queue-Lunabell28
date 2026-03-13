#include <iostream>
#include <cstring>
#include "Queue.h"
using namespace std;

int main(int argc, char **argv) {
    Queue q;
    
    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "x") == 0) {
            // dequeue() handles the "dequeing X" or "Empty Queue" print
            q.dequeue();
        } else {
            q.enqueue(atoi(argv[i]));
        }
    }

    // According to your desired output, a "Clearing queue" message 
    // appears before the final batch of dequeues.
    cout << "Clearing queue" << endl;

    return 0;
}