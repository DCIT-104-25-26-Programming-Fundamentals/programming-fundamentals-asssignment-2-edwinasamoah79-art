// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//

#include <iostream>
using namespace std;

void printTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << number << " x " << i << " = " << (number * i) << endl;
    }
}

void printTablesUpTo(int n) {
    for (int i = 1; i <= n; i++) {
        printTable(i);
        if (i != n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << endl;
    printTable(number);

    int n;
    cout << "\nEnter N to print tables from 1 to N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 1;
    }

    cout << endl;
    printTablesUpTo(n);

    return 0;
}
