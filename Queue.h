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
        while (headPtr != nullptr) {
            NodePtr tmp = headPtr;
            headPtr = headPtr->get_next();
            delete tmp;
        }

        tailPtr = nullptr;
        size = 0;
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
            return -1;
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
