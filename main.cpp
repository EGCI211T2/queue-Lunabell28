#include <cstdlib>
#include <cstring>
#include <iostream>

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
            } else if (price == 0) {
                cout << "We don't have that food. You don't have to pay." << endl;
            } else {
                cout << "No pending order." << endl;
            }

            cout << "==============" << endl;
        } else {
            if (i + 1 >= argc) {
                cout << "Ignored incomplete order input at end of command line." << endl;
                break;
            }

            int order = atoi(argv[i]);
            int qty = atoi(argv[i + 1]);
            q.enqueue(order, qty);
            i++;
        }
    }

    cout << "The shop is closed. There are " << q.get_size() << " order(s) left." << endl;
    return 0;
}
