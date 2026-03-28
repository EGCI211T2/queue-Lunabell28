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

            // Handle the Empty Queue case first to pass Test 2
            if (price == -1) {
                cout << "Empty Queue" << endl;
            } 
            else if (price == 0) {
                cout << "We don't have that food. You don't have to pay." << endl;
                cout << "===============================" << endl;
            } 
            else if (price > 0) {
                int cash = 0;
                int total_paid = 0;
                cout << "You have to pay " << price << endl;

                while (total_paid < price) {
                    cout << "Cash:";
                    if (!(cin >> cash)) break; 
                    total_paid += cash;
                }

                cout << "Thank you" << endl;
                
                if (total_paid > price) {
                    cout << "Here is your " << (total_paid - price) << " change." << endl;
                }
                cout << "===============================" << endl;
            }
        } 
        else {
            // Enqueue logic: takes the ID and the next argument as Quantity
            if (i + 1 < argc) {
                int order = atoi(argv[i]);
                int qty = atoi(argv[i + 1]);
                q.enqueue(order, qty);
                i++; // Skip the quantity argument in the next loop iteration
            }
        }
    }

    // Final summary for leftover orders
    int leftover = q.get_size();
    if (leftover > 0) {
        cout << "The shop is closed. There are " << leftover << " left." << endl;
    }

    return 0;
}