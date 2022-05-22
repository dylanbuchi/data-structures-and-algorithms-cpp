#pragma once

#include <iostream>

template <typename Object>
void print(Object object) {
    std::cout << object << std::endl;
}

template <typename Object>
void printMemoryAddress(Object object) {
    std::cout << &object << std::endl;
}
// prints a new line
void print() {
    std::cout << std::endl;
}

void printArray(int array[], size_t size) {
    std::cout << "[";
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i] << (i < size - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

void print2dArray(int** array, size_t row_size, size_t col_size) {
    for (size_t row = 0; row < row_size; row++) {
        std::cout << "[";
        for (size_t col = 0; col < col_size; col++) {
            std::cout << array[row][col] << (col < col_size - 1 ? ", " : "");
        }
        std::cout << "]";
        print();
    }
}