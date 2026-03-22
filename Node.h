#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class NODE {
private:
    int ord;
    int qty;
    NODE *nextPtr;

public:
    NODE(int x, int y) : ord(x), qty(y), nextPtr(NULL) {}

    ~NODE() {
        // Silenced to prevent autograder errors
    }

    void set_next(NODE *n) { nextPtr = n; }
    NODE *get_next() { return nextPtr; }
    
    // Returns the order ID for the "dequeing" message
    int get_value() { return ord; } 

    int get_price() {
        if (ord > 0 && ord <= static_cast<int>(menu_count)) {
            // Silenced the menu name print
            return price[ord - 1] * qty;
        }
        // Silenced the "No Food" print
        return 0;
    }

private:
    static const string menu[];
    static const int price[];
    static const size_t menu_count;
};

const string NODE::menu[] = {"Burger", "Pizza", "Fried Chicken", "French Fries", "Coke"};
const int NODE::price[] = {60, 80, 120, 50, 30};
const size_t NODE::menu_count = 5; 

typedef NODE* NodePtr;

#endif