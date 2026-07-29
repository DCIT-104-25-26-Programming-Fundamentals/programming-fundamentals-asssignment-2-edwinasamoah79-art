// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

bool divide(double a, double b, double &result) {
    if (b == 0) {
        return false;
    }
    result = a / b;
    return true;
}

bool modulo(long long a, long long b, long long &result) {
    if (b == 0) {
        return false;
    }
    result = a % b;
    return true;
}

double exponent(double base, double exp) {
    double result = 1.0;
    for (int i = 0; i < static_cast<int>(exp); i++) {
        result *= base;
    }
    return result;
}

void printMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

int main() {
    int choice;
    bool running = true;

    cout << fixed << setprecision(2);

    while (running) {
        printMenu();
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            running = false;
            continue;
        }

        if (choice < 1 || choice > 6) {
            cout << "Error: Invalid choice. Please select 1-7." << endl;
            continue;
        }

        double a, b;
        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        switch (choice) {
            case 1:
                cout << "Result: " << a << " + " << b << " = " << add(a, b) << endl;
                break;
            case 2:
                cout << "Result: " << a << " - " << b << " = " << subtract(a, b) << endl;
                break;
            case 3:
                cout << "Result: " << a << " * " << b << " = " << multiply(a, b) << endl;
                break;
            case 4: {
                double result;
                if (divide(a, b, result)) {
                    cout << "Result: " << a << " / " << b << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                break;
            }
            case 5: {
                long long result;
                if (modulo(static_cast<long long>(a), static_cast<long long>(b), result)) {
                    cout << "Result: " << a << " % " << b << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                break;
            }
            case 6:
                cout << "Result: " << a << " ^ " << b << " = " << exponent(a, b) << endl;
                break;
        }
    }

    return 0;
}
