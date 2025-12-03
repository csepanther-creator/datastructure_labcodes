
#include <iostream>
using namespace std;


void reverseArray() {
    int n;
    cout << "\n--- Reverse Array ---\n";
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


void multiplyMatrices() {
    int m, n, r, p;
    cout << "\n--- Matrix Multiplication ---\n";
    cout << "Enter rows and columns of first matrix (m n): ";
    cin >> m >> n;
    cout << "Enter rows and columns of second matrix (r p): ";
    cin >> r >> p;

    if (n != r) {
        cout << "Matrix multiplication not possible (columns of A ? rows of B)\n";
        return;
    }

    int A[10][10], B[10][10], C[10][10] = {0};

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];

   
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];

    cout << "Result after multiplication:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}


void transposeMatrix() {
    int rows, cols;
    cout << "\n--- Matrix Transpose ---\n";
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[100][100], transpose[100][100];

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transpose[j][i] = matrix[i][j];

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            cout << transpose[i][j] << " ";
        cout << endl;
    }
}


int main() {
    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Reverse Array\n";
        cout << "2. Matrix Multiplication\n";
        cout << "3. Transpose Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                reverseArray();
                break;
            case 2:
                multiplyMatrices();
                break;
            case 3:
                transposeMatrix();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1-4.\n";
        }

    } while (choice != 4);

    return 0;
}

