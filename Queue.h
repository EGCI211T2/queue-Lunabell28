#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"

using namespace std;

class Queue {
private:
    NodePtr headPtr;
    NodePtr tailPtr;
    int size;

public:
    Queue() : headPtr(NULL), tailPtr(NULL), size(0) {}

    ~Queue() {
        while (size > 0) {
            NodePtr tmp = headPtr;
            headPtr = headPtr->get_next();
            delete tmp;
            size--;
        }
        tailPtr = NULL;
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
        if (size == 0 || headPtr == NULL) {
            return -1;
        }

        NodePtr out = headPtr;
        int cost = out->get_price();

        // EXACT match for Test 1
        cout << "dequeing " << out->get_value() << endl;

        headPtr = headPtr->get_next();
        if (headPtr == NULL) {
            tailPtr = NULL;
        }

        delete out;
        size--;
        return cost;
    }

    int get_size() const { return size; }
};

#endif