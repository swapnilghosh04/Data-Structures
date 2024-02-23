#include <iostream>

int arr[10], size;

void hashWithLinearProbing() {
    int n, r;
    for (int i = 0; i < 10; i++) // Initialize array elements to -999
        arr[i] = -999;
    for (int i = 0; i < size; i++) {
        std::cout << "Enter value no " << (i + 1) << ": ";
        std::cin >> n;
        r = n % 10;
        while (arr[r] != -999) {
            r++;
            if (r >= 10) // Corrected the condition for wrapping around the array
                r = 0;
        }
        arr[r] = n;
    }
}

void display() {
    std::cout << "The array is" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
}

int main() {
    std::cout << "Enter the size of the array (up to 10): ";
    std::cin >> size;
    if (size > 10 || size <= 0) {
        std::cout << "Invalid size entered. Exiting..." << std::endl;
        return 1;
    }
    hashWithLinearProbing();
    display();
    return 0;
}

