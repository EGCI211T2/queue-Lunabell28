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
        int remaining = size;
        while (size > 0) {
            NodePtr tmp = headPtr;
            headPtr = headPtr->get_next();
            delete tmp;
            size--;
        }
        tailPtr = NULL;
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
        if (size == 0 || headPtr == NULL) {
            return -1;
        }

        NodePtr out = headPtr;
        int cost = out->get_price();

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