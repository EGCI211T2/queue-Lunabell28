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

    static const string menu[];
    static const int price[];
    static const int menu_count = 3; 

public:
    NODE(int x, int y) : ord(x), qty(y), nextPtr(NULL) {}
    ~NODE() {}

    void set_next(NODE *n) { nextPtr = n; }
    NODE *get_next() { return nextPtr; }
    int get_value() { return ord; } 

    // New helper to get the food name
    string get_name() {
        if (ord >= 1 && ord <= menu_count) {
            return menu[ord - 1];
        }
        return "No Food";
    }

    int get_price() {
        if (ord >= 1 && ord <= menu_count) {
            return price[ord - 1] * qty;
        }
        return 0;
    }
};

const string NODE::menu[] = {"Ramen", "Somtum", "Fried Chicken"};
const int NODE::price[] = {100, 20, 50};

typedef NODE* NodePtr;

#endif