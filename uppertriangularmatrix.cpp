#include <iostream>
using namespace std;

class UpperTriangularMatrix {
private:
    int n; // size of matrix
    int* arr; // 1-D array to store upper triangular matrix elements

public:
    UpperTriangularMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2]; // size of upper triangular matrix
    }

    // Function to set value at given row and column
    void set(int row, int col, int val) {
        if (row <= col) {
            arr[row * (row - 1) / 2 + col - 1] = val;
        }
        else {
            cout << "Invalid Index\n";
        }
    }

    // Function to get value at given row and column
    int get(int row, int col) {
        if (row <= col) {
            return arr[row * (row - 1) / 2 + col - 1];
        }
        else {
            return 0; // Return 0 for indices where row > col
        }
    }

    // Function to display the upper triangular matrix
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }

    ~UpperTriangularMatrix() {
        delete[] arr; // deallocating memory
    }
};

int main() {
    int size;
    cout << "Enter size of matrix: ";
    cin >> size;

    UpperTriangularMatrix matrix(size);

    cout << "Enter elements of upper triangular matrix:\n";
    for (int i = 1; i <= size; i++) {
        for (int j = i; j <= size; j++) {
            int val;
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> val;
            matrix.set(i, j, val);
        }
    }

    cout << "\nUpper Triangular Matrix:\n";
    matrix.display();

    return 0;
}

