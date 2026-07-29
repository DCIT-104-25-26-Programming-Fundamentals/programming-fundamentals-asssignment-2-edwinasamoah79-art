// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//

#include <iostream>
using namespace std;

void printFibonacciTerms(int n) {
    long long a = 0, b = 1;

    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a;
        if (i != n - 1) {
            cout << " ";
        }
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

bool isFibonacci(int num) {
    if (num < 0) {
        return false;
    }

    long long a = 0, b = 1;

    if (num == 0) {
        return true;
    }

    while (a <= num) {
        if (a == num) {
            return true;
        }
        long long next = a + b;
        a = b;
        b = next;
    }
    return false;
}

int main() {
    int n;

    cout << "How many terms? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Number of terms must be a positive integer." << endl;
    } else {
        printFibonacciTerms(n);
    }

    int number;
    cout << "\nEnter a number to check: ";
    cin >> number;

    if (isFibonacci(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
