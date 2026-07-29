// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_DIM = 10;

void readMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols, const string &label) {
    cout << label << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX_DIM][MAX_DIM], int rows, int cols,
                      int result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[MAX_DIM][MAX_DIM], int b[MAX_DIM][MAX_DIM],
                  int rows, int cols, int result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_DIM][MAX_DIM], int b[MAX_DIM][MAX_DIM],
                       int m, int n, int p, int result[MAX_DIM][MAX_DIM]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

void doTranspose() {
    int matrix[MAX_DIM][MAX_DIM];
    int result[MAX_DIM][MAX_DIM];
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix, rows, cols);
    transposeMatrix(matrix, rows, cols, result);

    cout << endl;
    displayMatrix(matrix, rows, cols, "Original Matrix:");
    cout << endl;
    displayMatrix(result, cols, rows, "Transposed Matrix:");
}

void doAddition() {
    int a[MAX_DIM][MAX_DIM], b[MAX_DIM][MAX_DIM], result[MAX_DIM][MAX_DIM];
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter Matrix A:" << endl;
    readMatrix(a, rows, cols);
    cout << "\nEnter Matrix B:" << endl;
    readMatrix(b, rows, cols);

    addMatrices(a, b, rows, cols, result);

    cout << endl;
    displayMatrix(a, rows, cols, "Matrix A:");
    cout << endl;
    displayMatrix(b, rows, cols, "Matrix B:");
    cout << endl;
    displayMatrix(result, rows, cols, "A + B:");
}

void doMultiplication() {
    int a[MAX_DIM][MAX_DIM], b[MAX_DIM][MAX_DIM], result[MAX_DIM][MAX_DIM];
    int m, n, n2, p;

    cout << "Enter rows of Matrix A (M): ";
    cin >> m;
    cout << "Enter columns of Matrix A (N): ";
    cin >> n;

    cout << "\nEnter Matrix A:" << endl;
    readMatrix(a, m, n);

    cout << "\nEnter rows of Matrix B (must equal N = " << n << "): ";
    cin >> n2;
    cout << "Enter columns of Matrix B (P): ";
    cin >> p;

    if (n2 != n) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
        return;
    }

    cout << "\nEnter Matrix B:" << endl;
    readMatrix(b, n2, p);

    multiplyMatrices(a, b, m, n, p, result);

    cout << endl;
    displayMatrix(a, m, n, "Matrix A:");
    cout << endl;
    displayMatrix(b, n2, p, "Matrix B:");
    cout << endl;
    displayMatrix(result, m, p, "A x B:");
}

int main() {
    int choice;

    cout << "Matrix Operations" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            doTranspose();
            break;
        case 2:
            doAddition();
            break;
        case 3:
            doMultiplication();
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
