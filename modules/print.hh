#include <iostream>

using std::cout;
using std::endl;

template <typename Object>
void print(Object object) {
    cout << object << endl;
}

template <typename Object>
void print_memory_address(Object object) {
    cout << &object << endl;
}
// prints a new line
void print() {
    cout << endl;
}

void print_array(int array[], size_t size) {
    cout << "[";
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << (i < size - 1 ? ", " : "");
    }
    cout << "]";
}

void print_2d_array(int** array, size_t row_size, size_t col_size) {
    for (size_t row = 0; row < row_size; row++) {
        cout << "[";
        for (size_t col = 0; col < col_size; col++) {
            cout << array[row][col] << (col < col_size - 1 ? ", " : "");
        }
        cout << "]";
        print();
    }
}