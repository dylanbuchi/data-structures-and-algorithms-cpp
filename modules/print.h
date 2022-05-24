#pragma once

#include <iostream>

template <typename Object>
void Print(Object object) {
    std::cout << object << std::endl;
}

template <typename Object>
void PrintMemoryAddress(Object object) {
    std::cout << &object << std::endl;
}
// prints a new line
void Print() {
    std::cout << std::endl;
}

void PrintArray(int array[], size_t size) {
    std::cout << "[";
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i] << (i < size - 1 ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

void Print2dArray(int** array, size_t row_size, size_t col_size) {
    for (size_t row = 0; row < row_size; row++) {
        std::cout << "[";
        for (size_t col = 0; col < col_size; col++) {
            std::cout << array[row][col] << (col < col_size - 1 ? ", " : "");
        }
        std::cout << "]" << std::endl;
    }
}
template <typename Node>
void PrintLinkedList(Node* head) {
    if (head == nullptr) {
        Print("Empty");
        return;
    }

    while (head) {
        std::cout << "(" << head->data << ") --> ";
        head = head->next;
    }

    Print();
}