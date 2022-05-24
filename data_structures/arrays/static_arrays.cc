#include <iostream>

#include "print.h"

using std::cout;
using std::endl;

// resize the array in place
void resizeArray(int*& old_array, size_t& old_array_size) {
    size_t new_size = old_array_size * 2;
    int* new_array = new int[new_size];

    for (size_t i = 0; i < old_array_size; i++) {
        new_array[i] = old_array[i];
    }

    for (size_t i = old_array_size; i < new_size; i++) {
        new_array[i] = 0;
    }

    delete[] old_array;

    old_array = new_array;
    old_array_size = new_size;
}

int main() {
    // static array of integers created on the stack memory
    int array[5] = {1, 2, 3, 4, 5};

    // calculate the size of the array
    size_t array_size = sizeof array / sizeof *array;

    PrintArray(array, array_size);

    Print();

    // static array of integers created on the heap memory
    int* array_2 = new int[5];
    size_t array_2_size = 5;

    for (size_t i = 0; i < array_2_size; i++) {
        array_2[i] = (i + 1) * 2;
    }

    PrintArray(array_2, array_2_size);
    Print();

    resizeArray(array_2, array_2_size);

    PrintArray(array_2, array_2_size);
    Print();

    delete[] array_2;
    array_2 = nullptr;
}