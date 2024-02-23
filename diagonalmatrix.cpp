#include <iostream> //18. diagonal matrix
#include <bits/stdc++.h>
#define MAX 20
// Function to print the Principal Diagonal
void printPrincipalDiagonal(int mat[][MAX], int n) {
std::cout << "Principal Diagonal: ";
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
// Condition for principal diagonal
if (i == j)
std::cout << mat[i][j] << ", ";
}
}
std::cout << std::endl;
}
// Function to print the Secondary Diagonal
void printSecondaryDiagonal(int mat[][MAX], int n) {
std::cout << "Secondary Diagonal: ";
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
// Condition for secondary diagonal
if ((i + j) == (n - 1))
std::cout << mat[i][j] << ", ";
}
}
std::cout << std::endl;
}
// Driver code
int main() {
int n;
int a[20][20];
std::cout << "Enter the order of the square matrix: ";
std::cin >> n;
std::cout << "Enter all the elements" << std::endl;
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
std::cout << "input value of a[" << i << "][" << j << "]: "; std::cin >> a[i][j];
}
}
std::cout << "The matrix is\n";
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++)
std::cout << a[i][j] << "\t";
std::cout << std::endl;
}
printPrincipalDiagonal(a, n);
printSecondaryDiagonal(a, n);
return 0;
}
