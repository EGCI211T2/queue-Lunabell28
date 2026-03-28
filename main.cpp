#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Queue.h"

using namespace std;

int main(int argc, char **argv) {
    Queue q;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "x") == 0) {
            int price = q.dequeue();

            if (price > 0) {
                int cash = 0;
                int total_paid = 0;
                cout << "You have to pay " << price << endl;

                while (total_paid < price) {
                    cout << "Cash:";
                    cin >> cash;
                    total_paid += cash;
                }

                cout << "Thank you" << endl;
                
                if (total_paid > price) {
                    cout << "Here is your " << (total_paid - price) << " change." << endl;
                }
                cout << "===============================" << endl;
            } 
            else if (price == 0) {
                cout << "We don't have that food. You don't have to pay." << endl;
                cout << "===============================" << endl;
            } 
        } 
        else {
            // Check if there's a quantity following the order ID
            if (i + 1 < argc && strcmp(argv[i+1], "x") != 0) {
                int order = atoi(argv[i]);
                int qty = atoi(argv[i + 1]);
                q.enqueue(order, qty);
                i++; 
            }
        }
    }

    // This part triggers the final sequence in your screenshot
    int leftover = q.get_size();
    if (leftover > 0) {
        cout << "The shop is closed. There are " << leftover << " left." << endl;
    }

    return 0;
}