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

    // Updated destructor to print leftover items
    ~Queue() {
        while (size > 0) {
            dequeue(); 
        }
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
        string name = out->get_name();

        // Prints the food name and "Removing..."
        cout << name << endl;
        if (name != "No Food") {
            cout << "Removing " << name << endl;
        } else {
            cout << "Removing" << endl;
        }

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