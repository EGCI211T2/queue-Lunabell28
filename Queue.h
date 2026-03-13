#ifndef queue_h
#define queue_h
#include "Node.h"
#include <iostream>

using namespace std;

class Queue {
    NodePtr headPtr, tailPtr;
    int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};

Queue::Queue() {
    headPtr = nullptr;
    tailPtr = nullptr;
    size = 0;
}

Queue::~Queue() {
    // Optional: Only print "Clearing queue" if your test case expects it here
    // cout << "Clearing queue" << endl; 
    while (size > 0) {
        dequeue();
    }
}

void Queue::enqueue(int x) {
    NodePtr new_node = new NODE(x);
    if (new_node) {
        if (size == 0) {
            headPtr = new_node;
        } else {
            tailPtr->set_next(new_node);
        }
        tailPtr = new_node;
        size++;
    }
}

int Queue::dequeue() {
    if (size > 0) {
        NodePtr temp = headPtr;
        int value = temp->get_value();
        
        headPtr = headPtr->get_next();
        if (headPtr == nullptr) {
            tailPtr = nullptr;
        }
        
        size--;
        cout << "dequeing " << value << endl; // Requirement 1
        delete temp;
        return value;
    }
    
    cout << "Empty Queue" << endl; // Requirement 2
    return -1;
}

#endif