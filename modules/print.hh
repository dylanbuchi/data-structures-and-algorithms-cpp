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

void print_array(int array[], int size) {
    cout << "[";
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << (i < size - 1 ? ", " : "");
    }
    cout << "]";
}