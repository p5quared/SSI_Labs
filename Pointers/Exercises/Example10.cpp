#include <iostream>
#include <cstdlib>
#include <ctime>

void initializeArray(int** arr, int rows, int cols) {
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void printArray(const int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void freeMemory(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    // Dynamically allocate memory for the 2D array
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // Initialize the array with random values
    initializeArray(arr, rows, cols);

    // Print the array
    std::cout << "Array:" << std::endl;
    printArray((const int**)arr, rows, cols);

    // Free the allocated memory
    freeMemory(arr, rows);

    return 0;
}
