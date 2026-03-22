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

                // Payment Loop: Keep asking for cash until the bill is covered
                while (total_paid < price) {
                    cout << "Cash:";
                    cin >> cash;
                    total_paid += cash;
                }

                cout << "Thank you" << endl;
                
                // Only give change if they paid MORE than the price
                if (total_paid > price) {
                    cout << "Here is your " << (total_paid - price) << " change." << endl;
                }
            } 
            else if (price == 0) {
                // This handles the "No Food" case from get_price()
                cout << "We don't have that food. You don't have to pay." << endl;
            } 
            else {
                // This handles the "Empty Queue" case (price is -1)
                cout << "No pending order." << endl;
            }

            cout << "==============" << endl;
        } 
        else {
          
            if (i + 1 < argc) {
                int order = atoi(argv[i]);
                int qty = atoi(argv[i + 1]);
                
                q.enqueue(order, qty);
                
                // IMPORTANT: skip the next argument because we used it as qty
                i++; 
            }
        }
    }

   

    return 0;
}