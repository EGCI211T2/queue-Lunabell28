#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Queue.h"

using namespace std;

int main(int argc, char **argv) {
    Queue q;

    // Start from i=1 to skip the program name (argv[0])
    for (int i = 1; i < argc; i++) {
        
        // Check if the argument is "x" (customer wants to pay/dequeue)
        if (strcmp(argv[i], "x") == 0) {
            int price = q.dequeue();

            if (price > 0) {
                int cash = 0;
                int total_paid = 0;
                cout << "You have to pay " << price << endl;

                
                while (total_paid < price) {
                    cout << "Cash:";
                    
                    
                    if (!(cin >> cash)) {
                        break; 
                    }
                    
                    total_paid += cash;
                }

                cout << "Thank you" << endl;
                
              
                if (total_paid > price) {
                    cout << "Here is your " << (total_paid - price) << " change." << endl;
                }
            } 
            else if (price == 0) {
                // This handles the "No Food" case
                cout << "We don't have that food. You don't have to pay." << endl;
            } 
            else {
                // 
                cout << "Empty queue" << endl;
            }

            cout << "==============" << endl;
        } 
        else {
            /
            if (i + 1 < argc) {
                int order = atoi(argv[i]);
                int qty = atoi(argv[i + 1]);

                q.enqueue(order, qty);

               
                i++;
            }
        }
    }

    cout << "The shop is closed. There are " << q.get_size() << " order(s) left." << endl;

    return 0;
}