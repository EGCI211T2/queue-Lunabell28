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
    NODE(int x, int y) : ord(x), qty(y), nextPtr(nullptr) {}

    ~NODE() {
        if (ord > 0 && ord <= static_cast<int>(menu_count)) {
            cout << "Removing " << menu[ord - 1] << endl;
        } else {
            cout << "Removing" << endl;
        }
    }

    void set_next(NODE *n) { nextPtr = n; }
    NODE *get_next() { return nextPtr; }

    int get_price() {
        if (ord > 0 && ord <= static_cast<int>(menu_count)) {
            cout << menu[ord - 1] << endl;
            return price[ord - 1] * qty;
        }

        cout << "No Food" << endl;
        return 0;
    }

private:
    static const string menu[];
    static const int price[];
    static const size_t menu_count;
};

const string NODE::menu[] = {"Burger", "Pizza", "Fried Chicken", "French Fries", "Coke"};
const int NODE::price[] = {60, 80, 120, 50, 30};
const size_t NODE::menu_count = sizeof(NODE::price) / sizeof(NODE::price[0]);

#endif
