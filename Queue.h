#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
private:
    using NodePtr = NODE *;
    NodePtr headPtr;
    NodePtr tailPtr;
    int size;

public:
    Queue() : headPtr(nullptr), tailPtr(nullptr), size(0) {}

    ~Queue() {
        int remaining = size; // Store count before clearing
        while (size > 0) {
           
            NodePtr tmp = headPtr;
            headPtr = headPtr->get_next();
            delete tmp; // This prints "Removing [Food]"
            size--;
        }
        tailPtr = nullptr;
        // The very last output of the program
        cout << "The shop is closed. There are " << remaining << " order(s) left." << endl;
    }

    void enqueue(int x, int y) {
        NodePtr new_node = new NODE(x, y);
        if (size == 0) {
            headPtr = new_node;
        } else {
            tailPtr->set_next(new_node);
        }
        tailPtr = new_node;
        size++;
    }

    int dequeue() {
        if (size == 0 || headPtr == nullptr) {
            return -1; // Indicates empty queue
        }

        NodePtr out = headPtr;
        int cost = out->get_price();

        headPtr = headPtr->get_next();
        if (headPtr == nullptr) {
            tailPtr = nullptr;
        }

        delete out; 
        size--;
        return cost;
    }

    int get_size() const { return size; }
};

#endif