#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the order of the square matrix: ";
    cin >> n;
    
    int size = n * (n + 1) / 2; // size of 1D array
    int mat[size]; // 1D array to store the upper triangular matrix
    
    cout << "Enter the elements of the symmetric matrix (upper triangular part):\n";
    // Input elements and store them in the upper triangular part of 1D array
    for (int i = 0; i < size; i++) {
        cout << "mat[" << i << "] = ";
        cin >> mat[i];
    }
    
    // Display the symmetric matrix
    cout << "The symmetric matrix is:\n";
    int index = 0; // index for 1D array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                cout << mat[index] << " ";
                index++;
            } else {
                // Since it's symmetric, retrieve values from the lower triangular part
                cout << mat[j * (j + 1) / 2 + i] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

