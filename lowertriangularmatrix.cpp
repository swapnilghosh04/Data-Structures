#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the order of the square matrix: ";
    cin >> n;
    int mat[n * n];
    cout << "Enter the elements of the lower triangular matrix (both left and right):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                cout << "mat[" << i * n + j << "] = ";
                cin >> mat[i * n + j];
            }
        }
    }
    cout << "The lower triangular matrix (both left and right) is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                cout << mat[i * n + j] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
    return 0;
}
